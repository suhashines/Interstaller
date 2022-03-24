# include "iGraphics.h"
# include "gl.h"

#define scrnwidth 1200
#define scrnheight 1000

int sx=520,sy=100; //size of the spaceship 160 , 158

int bulletmode=0;

float bulletx=sx+80,bullety=sy+158;

float cx=sx+200,cy=1000 ,comangle ,comdy ;





char spaceship[30]="bmp images\\spaceship.bmp";
char commet[30]="bmp images\\commet.bmp";
char asteroid1[30]="bmp images\\asteroid1.bmp";
char asteroid2[30]="bmp images\\asteroid2.bmp";
char alien1[30]="bmp images\\alien1.bmp";
char alien2[30]="bmp images\\alien2.bmp";
char alien3[30]="bmp images\\alien3.bmp";

void iDraw()
{
	//place your drawing codes here

	iClear();
	//iShowBMP(0,0,"C:\\IGraphics-master\\bmp pictures\\bcspace.bmp");
    iShowBMP2(sx,sy, spaceship , 0x00ffffff);
    iSetColor(120,200,150);
    iFilledCircle(bulletx,bullety,10,100);
    //iText(x-15,y+65,"Suhas & Prithu",GLUT_BITMAP_HELVETICA_18);
    iShowBMP2(cx,cy, commet , 0x00ffffff);

    if(bulletmode==1)
    {
        iFilledCircle(sx+80,sy+158,10,100);
    }


}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here

}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	/*if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here

		x = mx - 50;
		y = my - 50;
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		r=0; g=0; b=0 ;
	}   */
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	//place your codes for other keys here */

    if((key=='w' || key=='W')  && sy<755){
           sy+=10;
           bullety+=10;      }

    else if((key=='s' || key=='S')  && sy>45){
           sy-=10;
           bullety-=10;       }

    else if((key=='a' || key=='A')  && sx>10){
           sx-=10;
           bulletx-=10;   }

    else if((key=='d' || key=='D')  && sx<1040){
           sx+=10;
           bulletx+=10;       }

    if(key=='m')
       {
           bulletmode=1;

       }


}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	//place your codes for other keys here
}

void animation()
{

   //commet that targets the spaceship
    float targetx=600;
    float targety=100;
    float xdiff = cx-targetx;
    float ydiff = cy - targety ;
    float comdx=0.2;

    if(xdiff==0)
        xdiff++;

    comangle=ydiff/xdiff ;

    cx-=comdx;

    comdy=comdx*comangle ;

    cy-=comdy;

    if(cx<0 || cy<-122)
    {
        cx=sx+600;
        cy=1000;
        targetx=sx+80;

    }




    if(bulletmode==1)
    {
        bullety+=5 ;

        if(bullety==1000)
        {
            bullety=sx+158;
            bulletmode=0;
        }

    }

}


int main()
{
//    PlaySound((LPCSTR) "C:\\Users\\Public\\Music\\Sample Music\\Sleep Away.mp3", NULL, SND_FILENAME | SND_ASYNC);
//    DWORD dwError = GetLastError();

	//place your own initialization codes here.
	iSetTimer(10,animation);

	iInitialize(1200, 1000, "Spacehship Demo");

	return 0;
}

