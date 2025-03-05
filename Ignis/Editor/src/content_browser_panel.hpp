#pragma once

#include "core/types.hpp"
#include <imgui.h>
#include <vector>

class Scene;

struct SelectionWithDeletion : ImGuiSelectionBasicStorage
{
    int apply_deletion_pre_loop(ImGuiMultiSelectIO *ms_io, i32 items_count)
    {
        if (Size == 0)
            return -1;
        const i32 focused_idx = static_cast<i32>(ms_io->NavIdItem);
        if (ms_io->NavIdSelected == false)
        {
            ms_io->RangeSrcReset = true;
            return focused_idx;
        }

        for (i32 idx = focused_idx + 1; idx < items_count; ++idx)
        {
            if (!Contains(GetStorageIdFromIndex(idx)))
                return idx;
        }

        for (i32 idx = std::min(focused_idx, items_count) - 1; idx >= 0; --idx)
        {
            if (!Contains(GetStorageIdFromIndex(idx)))
                return idx;
        }

        return -1;
    }

    template<typename ITEM_TYPE>
    void apply_deletion_post_loop(ImGuiMultiSelectIO *ms_io, std::vector<ITEM_TYPE> &items, i32 item_curr_idx_to_select)
    {
        std::vector<ITEM_TYPE> new_items;
        new_items.reserve(items.size() - Size);
        i32 item_next_idx_to_select = -1;
        for (i32 idx = 0; idx < items.size(); ++idx)
        {
            if (!Contains(GetStorageIdFromIndex(idx)))
                new_items.push_back(items[idx]);
            if (item_curr_idx_to_select == idx)
                item_next_idx_to_select = new_items.size() - 1;
        }
        items.swap(new_items);

        Clear();
        if (item_next_idx_to_select != -1 && ms_io->NavIdSelected)
            SetItemSelected(GetStorageIdFromIndex(item_next_idx_to_select), true);
    }
};

struct ContentData
{
    ImGuiID id;
    i32 type;

    ContentData(ImGuiID id, i32 type)
        : id(id), type(type)
    {
    }


    static const ImGuiTableSortSpecs *s_current_sort_specs;

    static void sort_with_sort_specs(ImGuiTableSortSpecs *sort_specs, ContentData *items, i32 items_count)
    {
        s_current_sort_specs = sort_specs;
        if (items_count > 1)
            qsort(items, static_cast<size_t>(items_count), sizeof(items[0]), ContentData::compare_with_sort_specs);
        s_current_sort_specs = nullptr;
    }

    static i32 compare_with_sort_specs(const void *lhs, const void *rhs)
    {
        const ContentData *a = (const ContentData *)lhs;
        const ContentData *b = (const ContentData *)rhs;
        for (i32 n = 0; n < s_current_sort_specs->SpecsCount; ++n)
        {
            const ImGuiTableColumnSortSpecs *sort_spec = &s_current_sort_specs->Specs[n];
            i32 delta = 0;
            if (sort_spec->ColumnIndex == 0)
                delta = (i32)a->id - (i32)b->id;
            else if (sort_spec->ColumnIndex == 1)
                delta = a->type - b->type;
            
            if (delta > 0)
                return (sort_spec->SortDirection == ImGuiSortDirection_Ascending) ? +1 : -1;
            else if (delta < 0)
                return (sort_spec->SortDirection == ImGuiSortDirection_Ascending) ? -1 : +1;
        }

        return a->id - b->id;
    }
};

class ContentBrowserPanel
{
public:
    ContentBrowserPanel() = default;
    
    void render();

private:
    // options
    bool m_show_type_overlay = true;
    bool m_allow_sorting = true;
    bool m_allow_box_select = true;
    bool m_allow_drag_unselected = false;
    f32  m_icon_size = 32.0f;
    i32  m_icon_spacing = 10;
    i32  m_icon_hit_spacing = 4;
    bool m_stretch_spacing = true;

    // state
    std::vector<ContentData> m_items;
    SelectionWithDeletion m_selection;
    ImGuiID m_next_item_id = 0;

    bool m_request_delete = false;
    bool m_request_sort = false;
    f32  m_zoom_wheel_accum = 0.0f;

    ImVec2 m_layout_item_size;
    ImVec2 m_layout_item_step;
    f32    m_layout_item_spacing = 0.0f;
    f32    m_layout_selectable_spacing = 0.0f;
    f32    m_layout_outer_padding = 0.0f;
    i32    m_layout_column_count = 0;
    i32    m_layout_line_count = 0;

    void add_items(i32 count);
    void clear_items();

    void update_layout_sizes(f32 avail_width);

    Scene *m_scene;
};