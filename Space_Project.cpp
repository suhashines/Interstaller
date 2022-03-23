# include "iGraphics.h"
# include "gl.h"

//Shonibar ghurte ay Basundhara

//B for bonchito


/*
	function iDraw() is called again and again by the system.
*/
// sending pull request to prithu
int x=284,y=150;
int r=255,g=255,b=255,temp;


void iDraw()
{
	//place your drawing codes here

	iClear();
	iShowBMP(0,0,"C:\\IGraphics-master\\bmp pictures\\bcspace.bmp");
    iShowBMP2(x,y, "C:\\IGraphics-master\\bmp pictures\\space.bmp" , 0x00ffffff);
    iSetColor(255,255,0);
    iText(x-15,y+65,"Suhas & Prithu",GLUT_BITMAP_HELVETICA_18);


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
{   if(key== GLUT_KEY_UP && y<855){
           y+=10;       }

    else if(key== GLUT_KEY_DOWN && y>45){
           y-=10;       }

    else if(key== GLUT_KEY_LEFT && x>10){
           x-=10;   }

     else if(key== GLUT_KEY_RIGHT && x<650){
           x+=10;       }



	//place your codes for other keys here
}


int main()
{
//    PlaySound((LPCSTR) "C:\\Users\\Public\\Music\\Sample Music\\Sleep Away.mp3", NULL, SND_FILENAME | SND_ASYNC);
//    DWORD dwError = GetLastError();

	//place your own initialization codes here.
	//PlaySound((LPCSTR) "C:\\IGraphics-master\\eightyears.wav", NULL, SND_FILENAME | SND_ASYNC);
    //DWORD dwError = GetLastError();

	iInitialize(1200, 1000, "Spacehship Demo");

	return 0;
}

