#pragma once
// 프로그램 전체에서 사용하는 구조체와 함수를 저장하는 헤더파일

#include<vector>
#include<ctime>
#include<string>
#include "resource.h"
#include "framework.h"

#define WINDOW_COLOR RGB(230,230,230)

#define SAVE_MENU ID_32771
#define LOAD_MENU ID_32772

//서명란 범위
#define BOUNDARY_TOP 120
#define BOUNDARY_LEFT 50
#define BOUNDARY_RIGHT 1225
#define BOUNDARY_BOTTOM 600

// 앞으로 바뀔 수 있는 값들
#define FILE_PATH L"../../data"


typedef struct point_info
{
    LPARAM          lparm;      //좌표  
    int             cWidth;     //굵기
    COLORREF        color;      //색상
    DWORD           ctime;      //시간
    UINT            state;      //상태{WM_LBUTTONDOWN }
}PINFO;

static COLORREF cols[] = {
                    RGB(0,0,0),         //검정
                    RGB(255,255,255),   //흰색
                    RGB(192,192,192),   //회색
                    RGB(238,45,54),     //빨간색
                    RGB(255,127,39),    //주황색
                    RGB(255,242,0),     //노란색
                    RGB(113,222,22),    //연두색
                    RGB(14,190,98),     //초록색
                    RGB(23,186,255),    //하늘색
                    RGB(64,125,217),    //파란색
                    RGB(163,73,164),    //보라색
                    RGB(255,174,201),   //연분홍
                    RGB(251,117,190),   //분홍
                    RGB(185,122,87),    //갈색
};

// 색상을 저장하는 배열      // ↓배열의 0번에 해당하는 부분이 프로그램에서 표시되지 않음

