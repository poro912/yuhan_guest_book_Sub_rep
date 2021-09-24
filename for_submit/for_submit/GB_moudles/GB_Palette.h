#pragma once
#include"GB_moudles.h"

// 파레트
#define BTNS 18        // 색상 버튼 갯수
#define S_BTN_x 650     // 색상 버튼 시작 x위치
#define S_BTN_y 30      // 색상 버튼 시작 y위치
#define BTN_gap 3       // 버튼 간격
#define BTN_size 30     // 버튼 크기

typedef struct btn      //색상 버튼내용을 저장할 구조체
{
    RECT rect;
    COLORREF col;
    HBRUSH brsh;
    HPEN pen;
    //HWND Wnd;
}BTN;



class Palette
{

public:
    COLORREF ran;
    int x;
    int y;
    int boundary_x;
    int boundary_y;
    std::vector<BTN> btns;

    Palette(int x, int y);
    void print(HDC hdc);
    int is_press(LPARAM lParam);

    void ChangeRand();
};