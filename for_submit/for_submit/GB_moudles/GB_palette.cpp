#include "GB_Palette.h"


Palette::Palette(int x, int y)
{
<<<<<<< HEAD
    srand((unsigned)time(0));
    ChangeRand();
=======
    RECT rec;
    srand((unsigned)time(NULL));
    
>>>>>>> e3ff4fa29a8c6f8e3713f2efa5a29491aa1385e9
    this->x = x;
    this->y = y;
    this->pen = CreatePen(PS_SOLID, 2, RGB(192, 192, 192));
    for (int i = 0; i < BTNS; i++)
    {
        BTN btn;
        btn.rect.left = x;
        btn.rect.top = y;
        btn.rect.right = x + BTN_size;
        btn.rect.bottom = y + BTN_size;

        x += BTN_size + BTN_gap;

        btn.brsh = CreateSolidBrush(cols[i]);
        btn.col = cols[i];
        btns.push_back(btn);
    }
    BTN btn;
    btn.rect.left = x;
    btn.rect.top = y;
    btn.rect.right = x + BTN_size;
    btn.rect.bottom = y + BTN_size;

    x += BTN_size + BTN_gap;

    btn.brsh = CreateSolidBrush(this->ran);
    btns.push_back(btn);
    this->boundary_x = x + BTN_size;
    this->boundary_y = y + BTN_size;


    // 랜덤 색상을 저장 할 버튼 생성
    rec.left = x;
    rec.top = y;
    rec.right = x + BTN_size;
    rec.bottom = y + BTN_size;

    this->btn_ran.rect = rec;
    x += BTN_size + BTN_gap;
    this->ChangeRand();

    // 바운더리 영역 확장
    this->boundary_x += x + BTN_size;
}

void Palette::print(HWND hWnd, HDC hdc)
{
    RECT temp;
    SelectObject(hdc, this->pen);
    for (auto i : btns)
    {
        SelectObject(hdc, i.brsh);
        Rectangle(hdc, i.rect.left, i.rect.top, i.rect.right, i.rect.bottom);
    }

    // 랜덤 버튼 출력
    temp = btn_ran.rect;
    SelectObject(hdc, this->btn_ran.brsh);
    Rectangle(hdc, temp.left, temp.top, temp.right, temp.bottom);
}


COLORREF Palette::is_press(LPARAM lParam)
{
    POINT po;
    po.x = LOWORD(lParam);
    po.y = HIWORD(lParam);

    for (int i = 0; i < this->btns.size(); i++)
        if (PtInRect(&this->btns[i].rect, po))
            return btns[i].col;
    if (PtInRect(&this->btn_ran.rect, po))
        return btn_ran.col;

    return -1;
}
<<<<<<< HEAD
void Palette::ChangeRand() {
        //문제점 : srand에서 오류가 난다

            //현재 코드를 실행하면 창을 실행할 때마다 랜덤값이 바뀌어서 나오지 않음
            //rand()함수만 사용했을 때의 전형적인 문제점.

        int rr = rand() % 255; //클래스 내에 변수를 선언하니 오류가 발생, static으로 선언하니 오류는 
        int gg = rand() % 255; //해결됐습니다.
        int bb = rand() % 255;
        
        this->ran = RGB(rr, gg, bb);
    }
=======

// 색상을 랜덤값으로 읽어와 저장하는 함수
COLORREF Palette::ChangeRand() {

    int rr = rand() % 256;
    int gg = rand() % 256;
    int bb = rand() % 256;

    this->btn_ran.col = RGB(rr, gg, bb);
    if (this->btn_ran.brsh != NULL)
        DeleteObject(this->btn_ran.brsh);
    this->btn_ran.brsh = CreateSolidBrush(this->btn_ran.col);

    return this->btn_ran.col;
}
>>>>>>> e3ff4fa29a8c6f8e3713f2efa5a29491aa1385e9
