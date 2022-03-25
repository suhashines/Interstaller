# include "iGraphics.h"
# include "gl.h"
// These two header files are necessary for playing music
# include "windows.h"
# include "mmsystem.h"

#define scrnwidth 1080
#define scrnheight 1920

int sx=520,sy=100; //size of the spaceship 160 , 158

int bulletmode=0;

float bulletx=sx+80,bullety=sy+158;

float cx=sx+200,cy=1000 ,comangle ,comdy ;
float targetx=600 , targety=100;

//coordinate place korar age ettu image er height width gula check kore nish calculation er jonno




char spaceship[50]="bmp images\\spaceship.bmp";
char commet[50]="bmp images\\commet.bmp";

// nicher chobigula edit korte hobe
char asteroid1[50]="bmp images\\asteroid1.bmp";
char asteroid2[50]="bmp images\\asteroid2.bmp";
char alien1[50]="bmp images\\alien1.bmp";
char alien2[50]="bmp images\\alien2.bmp";
char alien3[50]="bmp images\\alien3.bmp";
// I can't see how I can crop these images even more.
char eight[50]="eightyears.wav";
char intro[50]="Menu Background\\Intro1.bmp";
char page[50]="Menu Background\\Page 2-3.bmp";
char inspage[50]="Menu Background\\Instruction Page2.bmp";
char highpage[50]="Menu Background\\High score page2.bmp";
char credpage[50]="Menu Background\\Credit Page2.bmp";
char newgame[50]="Menu Icons\\New Game2.bmp";
char instructions[50]="Menu Icons\\Instructions2.bmp";
char highscores[50]="Menu Icons\\High Scores2.bmp";
char credits[50]="Menu Icons\\Credits2.bmp";
char exits[50]="Menu Icons\\Exit2.bmp";

int mode=0;

void iDraw()
{
	//place your drawing codes here

	iClear();
    // Worked with the menu
    // You'll need to adjust the coordinates again if you change the window size
	if(mode==0) {
        iShowBMP(0,0,intro);
	}
	if(mode==1) {
        iShowBMP(0,0,page);
        iShowBMP(340,875,newgame);
        iShowBMP(340,668,instructions);
        iShowBMP(340,461,highscores);
        iShowBMP(340,254,credits);
        iShowBMP(340,47,exits);
	}
	if(mode==2) {
        iShowBMP(0,0,"bmp images\\background.bmp");
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
	if(mode==3) iShowBMP(275,0,inspage);
	if(mode==4) iShowBMP(275,0,highpage);
	if(mode==5) iShowBMP(275,0,credpage);
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

    // This is a blessing. Just click anywhere on the game and watch the corresponding coordinates get printed onto the terminal.
	printf("%d %d\n",mx,my);

    if(mode==0){
        if(mx>=405 && mx<=673 && my>=301 && my<=392) mode=1;
    }

    if(mode==1){
        if(mx>=340 && mx<=619 && my>=875 && my<=955) mode=2;
        if(mx>=340 && mx<=619 && my>=668 && my<=748) mode=3;
        if(mx>=340 && mx<=619 && my>=461 && my<=541) mode=4;
        if(mx>=340 && mx<=619 && my>=254 && my<=334) mode=5;
        if(mx>=340 && mx<=619 && my>=47 && my<=127) mode=0;
    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	//place your codes for other keys here */
    if(mode==2){
        if((key=='w' || key=='W')  && sy<700){
               sy+=10;
               bullety+=10;      }

               // spaceship er movement ami set kore disi. tor ar change korar dorkar nai

        else if((key=='s' || key=='S')  && sy>45){
               sy-=10;
               bullety-=10;       }

        else if((key=='a' || key=='A')  && sx>10){
               sx-=10;
               bulletx-=10;   }

        else if((key=='d' || key=='D')  && sx<900){
               sx+=10;
               bulletx+=10;       }

        if(key == 'm');
           {
               bulletmode=1;
           }

        // Kindly draw an iText in the bottom to let the users know how they can return to the main menu
        if((key=='x') || (key=='X')) mode=1;
    }
    if(mode>2){
    if((key=='x') || (key=='X')) mode=1;
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

	// There's no ENTER key available, but the instructions imply that the user must press ENTER to shoot.

}

void animation()
{

   //commet that targets the spaceship
    if(mode==2){
        float xdiff = cx - targetx;
        float ydiff = cy - targety ;
        float comdx=1;

        if(ydiff==0)
            ydiff++;

        comangle=ydiff/xdiff ;

        cx-=comdx;

        comdy=comdx*comangle ;

        cy-=comdy;

        if(cy==122)
        {
            cx=sx+600;
            cy=1000;
            targetx=sx;
            targety=sy;
            // commet ta ken jani y=0 te jawar por o x axis borabor move korte thake bujhtesi na. ettu dekhish to
            // (resolved)
        }



        // bullet ektar por ekta kemne shoot hobe eta partesi na
        // I couldn't resolve this either
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
}


int main()
{
//    PlaySound((LPCSTR) "C:\\Users\\Public\\Music\\Sample Music\\Sleep Away.mp3", NULL, SND_FILENAME | SND_ASYNC);
//    DWORD dwError = GetLastError();

	//place your own initialization codes here.
	iSetTimer(10,animation);
	srand(time(NULL)); // This line is necessary to play the music and run the game simultaneously
    PlaySound("eightyears.wav",NULL,SND_LOOP | SND_ASYNC);
    // If you get an error while using the PlaySound function, go to Project -> Build Options -> Linker Settings -> Type winmm -> Add
	iInitialize(1200, 1000, "Spacehship Demo");

	return 0;
}

