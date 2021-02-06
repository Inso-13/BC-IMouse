/*
 **************************************************
 *   版本号：1.0
 *   作者：往届学长（由黄子昊修改）
 *   生成日期：2020-9-4
 *   说明：与鼠标相关的部分函数
 **************************************************
 */

#include"IMouse.h"
#include<GRAPHICS.H>
#include<DOS.H>

void IMouseInit(void)
{
    _IMouseReset();
    IMouseNormalCursor();
    _IMouseSetLimit(MAX_X-1,MAX_Y-1);
    _IMouseSetXY(0,0);
    IMouseShow();
}
void _IMouseReset(void)
{
    union REGS regs; 
    regs.x.ax=0;
    int86(0x33,&regs,&regs);
}
void IMouseShow()
{
    union REGS regs; 
    regs.x.ax=1;
    int86(0x33,&regs,&regs);
}
void IMouseHide()
{
    union REGS regs; 
    regs.x.ax=2;
    int86(0x33,&regs,&regs);
}
void _IMouseGetXY(int* x,int* y)    
{
    union REGS regs; 
    regs.x.ax=3;
    int86(0x33,&regs,&regs);
    *x=regs.x.cx;
    *y=regs.x.dx;
}
int _ILeftPress()
{
    union REGS regs; 
    regs.x.ax=3;
    int86(0x33,&regs,&regs);
    return(regs.x.bx&1);
}
int _IRightPress()
{
    union REGS regs; 
    regs.x.ax=3;
    int86(0x33,&regs,&regs);
    return(regs.x.bx&2);
}
void _IMouseSetXY(int x,int y)    
{
    union REGS regs; 
    regs.x.ax=4;
    regs.x.cx=x;
    regs.x.dx=y;
    int86(0x33,&regs,&regs);
}
int _IMouseLeftRelease()
{
    union REGS regs; 
    regs.x.ax=6;
    regs.x.bx=0;
    int86(0x33,&regs,&regs);
    return(regs.x.ax&1);
}
void _IMouseSetLimit(int xMax,int yMax)
{
    union REGS regs; 
    regs.x.ax=7;
    regs.x.cx=0;
    regs.x.dx=xMax;
    int86(0x33,&regs,&regs);
    regs.x.ax=8;
    regs.x.cx=0;
    regs.x.dx=yMax;
    int86(0x33,&regs,&regs);
}
void IMouseNormalCursor()
{
    int mask[32]={0xffff,0xbfff,0x9fff,0x8fff,0x87ff,0x83ff,0x81ff,0x80ff,0x807f,0x81ff,0x83ff,0xb9ff,0xf9ff,0xfcff,0xfcff,0xffff,\
    0xc000,0xe000,0xf000,0xf800,0xfc00,0xfe00,0xff00,0xff80,0xffc0,0xff00,0xfe00,0xef00,0xcf00,0x0780,0x0780,0x0380};
    union REGS regs; 

#if defined(__LARGE__) || defined(__HUGE__) || defined(__COMPACT__)
    struct SREGS sregs;
    regs.x.ax=9;
    regs.x.bx=0;
    regs.x.cx=0;
    sregs.es=(int)((long)mask>>16);
    regs.x.dx=(int)mask;
    int86x(0x33,&regs,&regs,&sregs);
#else
    regs.x.ax=9;
    regs.x.bx=0;
    regs.x.cx=0;
    regs.x.dx=(int)mask;
    int86(0x33,&regs,&regs);
#endif
}
void IMouseClickCursor()
{
    int mask[32]=\
    {0xffff,0xffff,0xfdff,0xfdff,0xfdff,0xfd7f,0xf52f,0xe40f,0xe40f,0xf00f,0xf80f,0xfc0f,0xfc0f,0xfc0f,0xfe1f,0xffff,\
    0x0000,0x0600,0x0700,0x0700,0x07c0,0x07f0,0x17f8,0x3ff8,0x3ff8,0x1ff8,0x1ff8,0x0ff8,0x0ff8,0x07f8,0x07f0,0x03e0};
    union REGS regs; 

#if defined(__LARGE__) || defined(__HUGE__) || defined(__COMPACT__)
    struct SREGS sregs;
    regs.x.ax=9;
    regs.x.bx=0;
    regs.x.cx=0;
    sregs.es=(int)((long)mask>>16);
    regs.x.dx=(int)mask;
    int86x(0x33,&regs,&regs,&sregs);
#else
    regs.x.ax=9;
    regs.x.bx=0;
    regs.x.cx=0;
    regs.x.dx=(int)mask;
    int86(0x33,&regs,&regs);
#endif
}
void IMouseTextCursor()
{
    int mask[32]=\
    {0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,0xffff,\
     0x0000,0x0380,0x0100,0x0100,0x0100,0x0100,0x0100,0x0100,0x0100,0x0100,0x0100,0x0100,0x0100,0x0380,0x0000,0x0000};
    union REGS regs; 

#if defined(__LARGE__) || defined(__HUGE__) || defined(__COMPACT__)
    struct SREGS sregs;
    regs.x.ax=9;
    regs.x.bx=0;
    regs.x.cx=0;
    sregs.es=(int)((long)mask>>16);
    regs.x.dx=(int)mask;
    int86x(0x33,&regs,&regs,&sregs);
#else
    regs.x.ax=9;
    regs.x.bx=0;
    regs.x.cx=0;
    regs.x.dx=(int)mask;
    int86(0x33,&regs,&regs);
#endif
}
int IMouseHover(int x1,int y1,int x2,int y2)
{
    int x,y;

    _IMouseGetXY(&x,&y);
    return x>x1&&x<x2&&y>y1&&y<y2;
}
int IMouseLeftPress(int x1,int y1,int x2,int y2)
{
    int x,y;

    if(_ILeftPress())
    {
        delay(10);
        if(_ILeftPress())
        {
            _IMouseGetXY(&x,&y);
            if(x>x1&&x<x2&&y>y1&&y<y2)
            {
                while(_ILeftPress());
                return 1;
            }
        }
    }
    return 0;
}
int IMouseRightPress(int x1,int y1,int x2,int y2)
{
    int x,y;

    if(_IRightPress())
    {
        delay(10);
        if(_IRightPress())
        {
            _IMouseGetXY(&x,&y);
            if(x>x1&&x<x2&&y>y1&&y<y2)
            {
                while(_IRightPress());
                return 1;
            }
        }
    }
    return 0;
}
int IMouseDoubleLeftPress(int x1,int y1,int x2,int y2)
{
    int x,y;

    if(_ILeftPress())
    {
        delay(90);
        if(!_ILeftPress())
        {
            delay(100);
            if(_ILeftPress())
            {
		        _IMouseGetXY(&x,&y);
                if(x>x1&&x<x2&&y>y1&&y<y2)
                {
                    while(_ILeftPress());
                    return 1;
                }
            }
        }
    }
    return 0;
}