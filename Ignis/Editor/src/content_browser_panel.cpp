#include "content_browser_panel.hpp"

const ImGuiTableSortSpecs *ContentData::s_current_sort_specs;


void ContentBrowserPanel::render()
{
    if (!ImGui::Begin("Content Browser", nullptr, 0))
    {
        ImGui::End();
        return;
    }

#if 0 
    if (m_allow_sorting)
    {
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, {0.0f, 0.0f});
        ImGuiTableFlags table_flags_for_sort_specs = ImGuiTableFlags_Sortable | ImGuiTableFlags_SortMulti | ImGuiTableFlags_SizingFixedFit | ImGuiTableFlags_Borders;
        if (ImGui::BeginTable("for_sort_specs_only", 2, table_flags_for_sort_specs, {0.0f, ImGui::GetFrameHeight()}))
        {
            ImGui::TableSetupColumn("Index");
            ImGui::TableSetupColumn("Type");

            ImGui::TableHeadersRow();
            if (ImGuiTableSortSpecs *sort_specs = ImGui::TableGetSortSpecs())
            {
                if (sort_specs->SpecsDirty || m_request_sort)
                {
                    ContentData::sort_with_sort_specs(sort_specs, m_items.data(), m_items.size());
                    sort_specs->SpecsCount = m_request_sort = true;
                }
            }
            ImGui::EndTable();
        }
        ImGui::PopStyleVar();
    }

    ImGuiIO &io = ImGui::GetIO();
    ImGui::SetNextWindowContentSize({0.0f, m_layout_outer_padding + m_layout_line_count * (m_layout_item_size.y + m_layout_item_spacing)});
    if (ImGui::BeginChild("Asset", {0.0f, -ImGui::GetTextLineHeightWithSpacing()}, ImGuiChildFlags_Borders, ImGuiWindowFlags_NoMove))
    {
        ImDrawList *draw_list = ImGui::GetWindowDrawList();
        const f32 avail_width = ImGui::GetContentRegionAvail().x;
        update_layout_sizes(avail_width);

        ImVec2 start_pos = ImGui::GetCursorScreenPos();
        start_pos = ImVec2(start_pos.x + m_layout_outer_padding, start_pos.y + m_layout_outer_padding);
        ImGui::SetCursorScreenPos(start_pos);

        ImGuiMultiSelectFlags ms_flags = ImGuiMultiSelectFlags_ClearOnEscape | ImGuiMultiSelectFlags_ClearOnClickVoid;
        if (m_allow_box_select)
        {
            ms_flags |= ImGuiMultiSelectFlags_BoxSelect2d;
        }

        if (m_allow_drag_unselected)
        {
            ms_flags |= ImGuiMultiSelectFlags_SelectOnClickRelease;
        }

        ms_flags |= ImGuiMultiSelectFlags_NavWrapX;

        ImGuiMultiSelectIO *ms_io = ImGui::BeginMultiSelect(ms_flags, m_selection.Size, m_items.size());
        m_selection.UserData = this;
        //m_selection.AdapterIndexToStorageId = [](ImGuiSelectionBasicStorage *self_, i32 idx) { }

        ImGui::EndChild();
    }
#endif

    ImGui::End();
}

void ContentBrowserPanel::add_items(i32 count)
{
    if (m_items.empty())
    {
        m_next_item_id = 0;
    }
    
    m_items.reserve(m_items.size() + count);
    for (i32 n = 0; n < count; ++n, ++m_next_item_id)
    {
        m_items.push_back(ContentData(m_next_item_id, (m_next_item_id % 20) < 15 ? 0 : (m_next_item_id % 20) < 18 ? 1 : 2));
    }
    m_request_sort = true;
}

void ContentBrowserPanel::clear_items()
{
    m_items.clear();
}

void ContentBrowserPanel::update_layout_sizes(f32 avail_width)
{
    m_layout_item_spacing = static_cast<f32>(m_icon_spacing);
    if (m_stretch_spacing == false)
    {
        avail_width += floorf(m_layout_item_spacing * 0.5f);
    }

    m_layout_item_size = ImVec2(floorf(m_icon_size), floorf(m_icon_size));
    m_layout_column_count = std::max(static_cast<i32>(avail_width / (m_layout_item_size.x + m_layout_item_spacing)), 1);
    m_layout_line_count = (m_items.size() + m_layout_column_count - 1) / m_layout_column_count;

    if (m_stretch_spacing && m_layout_column_count > 1)
    {
        m_layout_item_spacing = floorf(avail_width - m_layout_item_size.x * m_layout_column_count) / m_layout_column_count;
    }

    m_layout_item_step = ImVec2(m_layout_item_size.x + m_layout_item_spacing, m_layout_item_size.y + m_layout_item_spacing);
    m_layout_selectable_spacing = std::max(floorf(m_layout_item_spacing) - m_icon_hit_spacing, 0.0f);
    m_layout_outer_padding = floorf(m_layout_item_spacing * 0.5f);
}