/*
    Original Author: S. M. Shahriar Nirjon
    Last Modified by: Mohammad Saifur Rahman
    last modified: October 13, 2015
    Version: 2.0
*/




# include "iGraphics.h"
int mposx,  mposy;
int scrx = 300, scry = 300,width=350,height=300;
bool box1 = false, box2 = false, box3 = false, box4 = false, box5 = false, box6 = false, box7 = false, box8 = false, box9 = false;
int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0, turncount = 0, i,a=0;
char image[2][30] = { "sources\\cross.bmp", "sources\\zero.bmp" };
int image_count[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
int playerx[4] = { 0, 0, 0, 0 };
int playero[5] = { 0, 0, 0, 0, 0 };
int gameplay[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int l,m,n,o,p;//free loop runner
int gamewin[8][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 4, 7, 2, 5, 8, 3, 6, 9, 1, 5, 9, 3, 5, 7 }, gamex = 0, gameo = 0, gamerow, flag=0, stop = 0, btnclick=0;
char strike[4][30] = { "sources\\strike_hor.bmp", "sources\\strike_ver.bmp", "sources\\maj_diag.bmp", "sources\\min_diag.bmp" };
//gamewin 7th row is major diagonal and 8th row is minor diagonal


/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	iLine(scrx / 3, 0, scrx / 3, scry);
	iLine(2 * scrx / 3, 0, 2 * scrx / 3, scry);
	iLine(0, 2 * scry / 3, scrx, 2 * scry / 3);
	iLine(0, scry / 3, scrx, scry / 3);
	iLine(0, scry , scrx, scry );
	iText(scrx/3-20, scry+20, "Press 'R' to replay", GLUT_BITMAP_HELVETICA_18);

	if (box1)
	{
		count1 = 1;
		turncount = count1 + count2 + count3 + count4 + count5 + count6 + count7 + count8 + count9;
		i = turncount % 2;
		if (image_count[1] < 0)
		{
			image_count[1] = i;
		}
		iShowBMP(0, 202, image[image_count[1]]);
	}
	if (box2)
	{
		count2 = 1;
		turncount = count1 + count2 + count3 + count4 + count5 + count6 + count7 + count8 + count9;
		i = turncount % 2;
		if (image_count[2] < 0)
		{
			image_count[2] = i;
		}
		iShowBMP(102, 202, image[image_count[2]]);
	}
	if (box3)
	{
		count3 = 1;
		turncount = count1 + count2 + count3 + count4 + count5 + count6 + count7 + count8 + count9;
		i = turncount % 2;
		if (image_count[3] < 0)
		{
			image_count[3] = i;
		}
		iShowBMP(202, 202, image[image_count[3]]);
	}


	//2nd row


	if (box4)
	{
		count4 = 1;
		turncount = count1 + count2 + count3 + count4 + count5 + count6 + count7 + count8 + count9;
		i = turncount % 2;
		if (image_count[4] < 0)
		{
			image_count[4] = i;
		}
		iShowBMP(0, 102, image[image_count[4]]);
	}
	if (box5)
	{
		count5 = 1;
		turncount = count1 + count2 + count3 + count4 + count5 + count6 + count7 + count8 + count9;
		i = turncount % 2;
		if (image_count[5] < 0)
		{
			image_count[5] = i;
		}
		iShowBMP(102, 102, image[image_count[5]]);
	}
	if (box6)
	{
		count6 = 1;
		turncount = count1 + count2 + count3 + count4 + count5 + count6 + count7 + count8 + count9;
		i = turncount % 2;
		if (image_count[6] < 0)
		{
			image_count[6] = i;
		}
		iShowBMP(202, 102, image[image_count[6]]);
	}


	//3rd row


	if (box7)
	{
		count7 = 1;
		turncount = count1 + count2 + count3 + count4 + count5 + count6 + count7 + count8 + count9;
		i = turncount % 2;
		if (image_count[7] < 0)
		{
			image_count[7] = i;
		}
		iShowBMP(0, 0, image[image_count[7]]);
	}
	if (box8)
	{
		count8 = 1;
		turncount = count1 + count2 + count3 + count4 + count5 + count6 + count7 + count8 + count9;
		i = turncount % 2;
		if (image_count[8] < 0)
		{
			image_count[8] = i;
		}
		iShowBMP(102, 0, image[image_count[8]]);
	}
	if (box9)
	{
		count9 = 1;
		turncount = count1 + count2 + count3 + count4 + count5 + count6 + count7 + count8 + count9;
		i = turncount % 2;
		if (image_count[9] < 0)
		{
			image_count[9] = i;
		}
		iShowBMP(202, 0, image[image_count[9]]);
	}
	//  turn of x .. 1,3,5,7
	
	// turn of o .. 0,2,4,6,8
	for (l = 1, m = 0; l < 9; l=l+2, m++)
	{
		playerx[m] = gameplay[l];
	}
	for (l = 0, m = 0; l < 9; l = l + 2, m++)
	{
		playero[m] = gameplay[l];
	}
	if (playero[2]>0 && flag==0 && stop==0){
		for (l = 0; l < 8 && stop==0; l++){
			gameo = 0;
			for (m = 0; m < 3 && stop == 0; m++){
				for (n = 0; n < 5 && stop == 0; n++){
					if (playero[n] == gamewin[l][m]){
						gameo++;
						if (gameo == 3){
							printf("player o wins");
							gamerow = l;
							flag = 1;
							stop = 1;
							btnclick = 1;
							break;
						}
					}
				}
			}
		}



		for (l = 0; l < 8 && stop == 0; l++){
			gamex = 0;
			for (m = 0; m < 3 && stop == 0; m++){
				for (n = 0; n < 4 && stop == 0; n++){
					if (playerx[n] == gamewin[l][m]){
						gamex++;
						if (gamex == 3){
							printf("player x wins");
							gamerow = l;
							flag = 1;
							stop = 1;
							btnclick = 1;
							break;
						}
					}
				}
			}
		}
	}
	if (gamex == 3 || gameo == 3)
	{
		if (gamerow == 0){
			iShowBMP2(0,  2*scry / 3, strike[0],0);
		}
		if (gamerow == 1){
			iShowBMP2(0,  scry / 3, strike[0], 0);
		}
		if (gamerow == 2){
			iShowBMP2(0, 0, strike[0], 0);
		}
		if (gamerow == 3){
			iShowBMP2(0, 0, strike[1], 0);
		}
		if (gamerow == 4){
			iShowBMP2(scrx/3, 0, strike[1], 0);
		}
		if (gamerow == 5){
			iShowBMP2(2*scrx/3 , 0, strike[1], 0);
		}
		if (gamerow == 6){
			iShowBMP2(0,0, strike[2], 0);
		}
		if (gamerow == 7){
			iShowBMP2(0, 0, strike[3], 0);
		}

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
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && btnclick==0)
	{
		if (my > 2 * scry / 3 && my < scry)//row1
		{
			if (mx >= 0 && mx<scrx / 3)//1st box
			{
				if (box1 == false){
					gameplay[a] = 1;
					a++;
				}
				box1 = true;
				printf("box1 turn=%d\t{", a);
				for (l = 0; l<9; l++){
					printf("%d ", gameplay[l]);
				}
				printf("}\tx={");
				for (l = 0; l<4;l++)
				{
					printf("%d ", playerx[l]);
				}
				printf("}\ty={");
				for (l = 0; l<5; l++)
				{
					printf("%d ", playero[l]);
				}
				printf("} gameO= %d    gameX= %d    gamerow= %d\n",gameo,gamex,gamerow);
			}
			if (mx >scrx / 3 && mx<2 * scrx / 3)//2nd box
			{
				if (box2 == false){
					gameplay[a] = 2;
					a++;
				}
				box2 = true;
				printf("box2 turn=%d\n",a);
			}
			if (mx >2 * scrx / 3 && mx<scrx)//3rd box
			{
				if (box3 == false){
					gameplay[a] = 3;
					a++;
				}
				box3 = true;
				printf("box3 turn=%d\n", a);
			}

		}


		if (my > scry / 3 && my < 2*scry/3)//row2
		{
			if (mx >= 0 && mx<scrx / 3)//4th box
			{
				if (box4 == false){
					gameplay[a] = 4;
					a++;
				}
				box4 = true;
				printf("box4 turn=%d\n", a);
			}
			if (mx >scrx / 3 && mx<2 * scrx / 3)//5th box
			{
				if (box5 == false){
					gameplay[a] = 5;
					a++;
				}
				box5 = true;
				printf("box5 turn=%d\n",a);
			}
			if (mx >2 * scrx / 3 && mx<scrx)//6th box
			{
				if (box6 == false){
					gameplay[a] = 6;
					a++;
				}
				box6 = true;
				printf("box6 turn=%d\n", a);
			}

		}


		if (my > 0 && my < scry / 3)//row3
		{
			if (mx >= 0 && mx<scrx / 3)//4th box
			{
				if (box7 == false){
					gameplay[a] = 7;
					a++;
				}
				box7 = true;
				printf("box7 turn=%d\n",a);
			}
			if (mx >scrx / 3 && mx<2 * scrx / 3)//5th box
			{
				if (box8 == false){
					gameplay[a] = 8;
					a++;
				}
				box8 = true;
				printf("box8 turn=%d\n", a);
			}
			if (mx >2 * scrx / 3 && mx<scrx)//6th box
			{
				if (box9 == false){
					gameplay[a] = 9;
					a++;
				}
				box9 = true;
				printf("box9 turn=%d\n", a);
			}

		}

		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}


void restart_game()
{
	
	
	 box1 = false, box2 = false, box3 = false, box4 = false, box5 = false, box6 = false, box7 = false, box8 = false, box9 = false;
	 count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0, turncount = 0, a = 0;
	 for (i = 0; i < 10; i++)
	 {
		 image_count[i] = -1;
	 }
	 for (i = 0; i < 4; i++)
	 {
		 playerx[i] = 0;
	 }
	 for (i = 0; i < 5; i++)
	 {
		 playero[i] = 0;
	 }
	 for (i = 0; i < 9; i++)
	 {
		 gameplay[i] = 0;
	 }
	 gamex = 0, gameo = 0, gamerow=-1, flag=0, stop = 0, btnclick = 0;
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'd')
	{
		printf("\nbox1 turn=%d\t{", a);
		for (l = 0; l<9; l++){
			printf("%d ", gameplay[l]);
		}
		printf("}\tx={");
		for (l = 0; l<4; l++)
		{
			printf("%d ", playerx[l]);
		}
		printf("}\ty={");
		for (l = 0; l<5; l++)
		{
			printf("%d ", playero[l]);
		}
		printf("} gameO= %d    gameX= %d    gamerow= %d\n", gameo, gamex, gamerow);
		//do something with 'q'
	}
	if (key == 'r')
	{
		restart_game();
	}
	//place your codes for other keys here
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

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}
//

int main()
{
	//place your own initialization codes here.
	iInitialize(height, width, "Tic Tac Toe");
	return 0;
	
}
