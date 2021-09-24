#include "GB_Palette.h"


Palette::Palette(int x, int y)
{
    srand((unsigned)time(0));
    ChangeRand();
    this->x = x;
    this->y = y;
    for (int i = 0; i < BTNS; i++)
    {
        BTN btn;
        btn.rect.left = x;
        btn.rect.top = y;
        btn.rect.right = x + BTN_size;
        btn.rect.bottom = y + BTN_size;

        x += BTN_size + BTN_gap;

        btn.brsh = CreateSolidBrush(cols[i]);
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
}

void Palette::print(HDC hdc)
{
    SelectObject(hdc, CreatePen(PS_SOLID, 2, RGB(192, 192, 192)));
    for (int i = 0; i < btns.size(); i++)
    {
        SelectObject(hdc, btns[i].brsh);
        Rectangle(hdc, btns[i].rect.left, btns[i].rect.top, btns[i].rect.right, btns[i].rect.bottom);
    }
}


int Palette::is_press(LPARAM lParam)
{
    POINT po;
    po.x = LOWORD(lParam);
    po.y = HIWORD(lParam);

    for (int i = 0; i < this->btns.size(); i++)
        if (PtInRect(&this->btns[i].rect, po))
            return i;

    return -1;
}
void Palette::ChangeRand() {
        //문제점 : srand에서 오류가 난다

            //현재 코드를 실행하면 창을 실행할 때마다 랜덤값이 바뀌어서 나오지 않음
            //rand()함수만 사용했을 때의 전형적인 문제점.

        int rr = rand() % 255; //클래스 내에 변수를 선언하니 오류가 발생, static으로 선언하니 오류는 
        int gg = rand() % 255; //해결됐습니다.
        int bb = rand() % 255;
        
        this->ran = RGB(rr, gg, bb);
    }
