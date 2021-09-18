#pragma once
// 프로그램 전체에서 사용하는 구조체와 함수를 저장하는 헤더파일

#include<vector>
#include<ctime>
#include<string>
#include <stdlib.h>
#include <time.h>
#include "resource.h"
#include "framework.h"


typedef struct point_info
{
    LPARAM          lparm;      //좌표  
    int             cWidth;     //굵기
    COLORREF        color;      //색상
    DWORD           ctime;      //시간
    UINT            state;      //상태{WM_LBUTTONDOWN }
}PINFO;


srand(time(NULL)); //문제점 : srand에서 오류가 난다

    //현재 코드를 실행하면 창을 실행할 때마다 랜덤값이 바뀌어서 나오지 않음
    //rand()함수만 사용했을 때의 전형적인 문제점.

static int rr = rand() % 255; //클래스 내에 변수를 선언하니 오류가 발생, static으로 선언하니 오류는 
static int gg = rand() % 255; //해결됐습니다.
static int bb = rand() % 255; 




static COLORREF cols[] = { RGB(255,0 ,255), //표시되지 않는 색(검정색 앞부분을 클릭하면 색이 변경되는거로 보아 프로그램상으로 구현은 되어있습니다)
                    RGB(0,0,0),         //검정
                    RGB(255,255,255),   //흰색
                    RGB(192,192,192),   //회색
                    RGB(255,0,0),       //빨간색
                    RGB(255,155,0),     //주황색
                    RGB(255,255,0),     //노란색
                    RGB(155,255,0),     //연두색
                    RGB(0,255,0),       //초록색
                    RGB(0,255,255),     //하늘색
                    RGB(0,0,255),       //파란색
                    RGB(155,0,255),     //자주색
                    RGB(255,0,255),     //보라색
                    RGB(255,0,155),     //연분홍
                    RGB(255,0,105),     //분홍색
                    RGB(150,75,0),      //갈색
                    RGB(128,0,0),       //적갈색
                    RGB(rr,gg,bb)       //랜덤색
};

// 색상을 저장하는 배열      // ↓배열의 0번에 해당하는 부분이 프로그램에서 표시되지 않음

