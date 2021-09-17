#include "GB_Palette.h"


Palette::Palette(int x, int y)
{
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