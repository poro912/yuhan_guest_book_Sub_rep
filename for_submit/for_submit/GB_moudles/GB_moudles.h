#pragma once
// 모듈에 대한 정의를 하는 헤더파일
#include "../for_submit.h"
#include<vector>

//---------------GB_Button--------------------
//---------------GB_File_io--------------------
#include"GB_File_io.h"


//---------------GB_Graphics--------------------
// 벡터의 내용을 그대로 출력한다.
void draw_vector(
    HWND                hWnd,
    HDC                 hdc,
    std::vector<struct point_info>& Pinfo
);
//---------------GB_Keyboard--------------------

//---------------GB_Mouse--------------------

//---------------GB_Graphics--------------------
#include "GB_Palette.h"