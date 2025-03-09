#pragma once

#include "core/window.hpp"
#include "ignis.hpp"

#include <Windows.h>
#include <commdlg.h>
#include <string>

static std::string filedialog_open_file(const char* filter)
{
    OPENFILENAMEA ofn;
    CHAR szFile[260] = { 0 };
    CHAR currentDir[256] = { 0 };
    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = IgnisEditor::get()->get_window()->get_native_handle();
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);
    
    if (GetCurrentDirectoryA(256, currentDir))
        ofn.lpstrInitialDir = currentDir;

    ofn.lpstrFilter = filter;
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;

    if (GetOpenFileNameA(&ofn) == TRUE)
        return ofn.lpstrFile;

    return {};
}

static std::string filedialog_save_file(const char* filter)
{
    OPENFILENAMEA ofn;
    CHAR szFile[260] = { 0 };
    CHAR currentDir[256] = { 0 };
    ZeroMemory(&ofn, sizeof(OPENFILENAME));
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = IgnisEditor::get()->get_window()->get_native_handle();
    ofn.lpstrFile = szFile;
    ofn.nMaxFile = sizeof(szFile);

    if (GetCurrentDirectoryA(256, currentDir))
        ofn.lpstrInitialDir = currentDir;

    ofn.lpstrFilter = filter;
    ofn.nFilterIndex = 1;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT | OFN_NOCHANGEDIR;

    // sets the default extension by extracting it from the filter
    ofn.lpstrDefExt = strchr(filter, '\0') + 1;

    if (GetSaveFileNameA(&ofn) == TRUE)
        return ofn.lpstrFile;

    return {};
}