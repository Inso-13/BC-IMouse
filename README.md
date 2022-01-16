# BC - IMouse
- Pure interrupt mouse for BC
- 作者：Inso
- 修改日期：2021.2.2
- 版本号：1.1.0  
  

# 注意
***经测试，IMouse在科技楼新的xp系统上无法正常显示，请勿轻易直接使用！！！***

希望大家将其看作对鼠标中断的实现示例代码

2022年1月

<br>

# 使用方法：
1. 将lib\IMouse.c添入工程  
   
2. 将lib\IMouse.h放入工程的Include目录中  
   
3. 在需要使用鼠标的文件中 #include<IMouse.h> 即可  
   
<br>

# 具体使用方法：
+ 先调用IMouseInit()初始化鼠标，然后就可以使用
```    
    左键单击: int IMouseLeftPress(int x1,int y1,int x2,int y2);
    右键单击: int IMouseRightPress(int x1,int y1,int x2,int y2);
    左键双击: int IMouseDoubleLeftPress(int x1,int y1,int x2,int y2);
    悬浮进入：int IMouseHover(int x1,int y1,int x2,int y2);
```
+ 提供三种不同鼠标形状
```
    使用默认鼠标图案：void IMouseNormalCursor(void);
    使用点击鼠标图案：void IMouseClickCursor(void);
    使用文本鼠标图案：void IMouseTextCursor(void);    
    
    详情见demo\main.c中的示例(用bc打开IMouse.prj)
```
<br>

# 特性：
1. 完全使用dos中断，不使用任何显式的全局变量
2. 不会出现从第二次run开始鼠标异常的现象，比较稳定  
   
<br>

# 注意事项：
+ 由于VGA等显示模式的特性，请不要使用`setbkcolor()`函数，如需更改背景色，请像示例一样**使用以下代码之后，再初始化鼠标**
```c
    	setfillstyle(SOLID_FILL,WHITE);
    	bar(0,0,MAX_X-1,MAX_Y-1);
```

+ 如使用其他分辨率，请调整IMouse.h中的宏定义
```c
	    #define MAX_X 640
	    #define MAX_Y 480
```
+ 鼠标默认使用调色板中15号颜色，若需要更换鼠标颜色，请调整15号调色板。如将15号颜色调整为白色 RGB = (255,255,255)。
```c
        outportb(0x3C8, 15);
        outportb(0x3C9, 255);
        outportb(0x3C9, 255);
        outportb(0x3C9, 255);
```

<br>

**如有问题或其他需要请联系我**  
