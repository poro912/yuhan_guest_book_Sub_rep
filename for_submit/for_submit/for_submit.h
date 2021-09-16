#pragma once
// 프로그램 전체에서 사용하는 구조체와 함수를 저장하는 헤더파일

#include<vector>
#include<ctime>
#include<string>
#include "resource.h"
#include "framework.h"


typedef struct point_info
{
    LPARAM          lparm;      //좌표  
    int             cWidth;     //굵기
    COLORREF        color;      //색상
    DWORD           ctime;      //시간
    UINT            state;      //상태{WM_LBUTTONDOWN, }
}PINFO;



