#include"IMouse.h"
#include<GRAPHICS.H>
#include<CONIO.H>

int main()
{
    int graphdriver=VGA;
	int graphmode=VGAHI;
    char flag1=0,flag2=0,flag3=0;

	initgraph(&graphdriver,&graphmode,"C:\\BorlandC\\BGI");
    setfillstyle(SOLID_FILL,WHITE);
    bar(0,0,MAX_X-1,MAX_Y-1);
    IMouseInit();

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(100,100,200,200);
    outtextxy(100,150,"left click");

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(300,100,400,200);
    outtextxy(300,150,"right click");

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(500,100,600,200);   
    outtextxy(500,150,"double click");

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(100,300,200,400);
    outtextxy(100,350,"hover in");

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(300,300,400,400);
    outtextxy(300,350,"I'm a text");

    setfillstyle(SOLID_FILL,LIGHTGRAY);
    bar(500,300,600,400);   
    outtextxy(500,350,"I'm a button");


    while(1)
    {
        if(kbhit())
            break;
        if(IMouseLeftPress(100,100,200,200))
        {
            IMouseHide();
            setfillstyle(SOLID_FILL,BLUE);
            bar(100,100,200,200);
            outtextxy(100,150,"clicked");
            IMouseShow();
        }
        if(IMouseRightPress(300,100,400,200))
        {
            IMouseHide();
            setfillstyle(SOLID_FILL,BLUE);
            bar(300,100,400,200);
            outtextxy(300,150,"clicked");
            IMouseShow();
        }
        if(IMouseDoubleLeftPress(500,100,600,200))
        {
            IMouseHide();
            setfillstyle(SOLID_FILL,BLUE);
            bar(500,100,600,200);   
            outtextxy(500,150,"clicked");
            IMouseShow();
        }
        if(!flag1&&IMouseHover(100,300,200,400))
        {
            IMouseHide();
            setfillstyle(SOLID_FILL,BLUE);
            bar(100,300,200,400);
            outtextxy(100,350,"hovered");
            flag1=1;
            IMouseShow();
        }
        else if(flag1&&!IMouseHover(100,300,200,400))
        {
            IMouseHide();
            setfillstyle(SOLID_FILL,LIGHTGRAY);
            bar(100,300,200,400);
            outtextxy(100,350,"hover in");
            flag1=0;
            IMouseShow();
        }
        if(!flag2&&IMouseHover(300,300,400,400))
        {
            IMouseHide();
            IMouseTextCursor();
            flag2=1;
            IMouseShow();
        }
        else if(flag2&&!IMouseHover(300,300,400,400))
        {
            IMouseHide();
            IMouseNormalCursor();
            flag2=0;
            IMouseShow();
        }
        if(!flag3&&IMouseHover(500,300,600,400))
        {
            IMouseHide();
            IMouseClickCursor();
            flag3=1;
            IMouseShow();
        }
        else if(flag3&&!IMouseHover(500,300,600,400))
        {
            IMouseHide();
            IMouseNormalCursor();
            flag3=0;
            IMouseShow();
        }
    };
    closegraph();
    return 0;
}
