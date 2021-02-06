#ifndef __IMOUSE_H_
#define __IMOUSE_H_

#define MAX_X 640
#define MAX_Y 480


void _IMouseSetXY(int,int);    
void _IMouseReset(void);
void _IMouseSetLimit(int,int);
void _IMouseGetXY(int* x,int* y);
int _ILeftPress(void);
int _IRightPress(void);

void IMouseShow(void);
void IMouseHide(void);

void IMouseInit(void);

void IMouseNormalCursor(void);
void IMouseClickCursor(void);
void IMouseTextCursor(void);

int IMouseHover(int x1,int y1,int x2,int y2);
int IMouseLeftPress(int x1,int y1,int x2,int y2);
int IMouseRightPress(int x1,int y1,int x2,int y2);
int IMouseDoubleLeftPress(int x1,int y1,int x2,int y2);

#endif