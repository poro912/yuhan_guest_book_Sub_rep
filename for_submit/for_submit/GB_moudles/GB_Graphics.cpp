#pragma once

#include "../for_submit.h"
#include "GB_moudles.h"



void draw_vector(HWND hWnd ,HDC hdc ,std::vector<struct point_info> & Pinfo)
{
    HPEN open = NULL, npen = NULL;
    int x, y;
    for (int i = 0; i < Pinfo.size(); i++)
    {
        switch (Pinfo[i].state)
        {
        case WM_LBUTTONDOWN:
            //MessageBox(hWnd, L"실행", L"L버튼", MB_OK);
            DeleteObject(npen);
            npen = CreatePen(PS_SOLID, Pinfo[i].cWidth, Pinfo[i].color);
            SelectObject(hdc, npen);

            x = LOWORD(Pinfo[i].lparm);
            y = HIWORD(Pinfo[i].lparm);

            MoveToEx(hdc, x, y, NULL);
            LineTo(hdc, x + 1, y + 1);  //점찍기
            break;

        case WM_MOUSEMOVE:
        case WM_LBUTTONUP:

            LineTo(hdc, LOWORD(Pinfo[i].lparm), HIWORD(Pinfo[i].lparm));
            break;

        default:
            break;
        }
    }

}