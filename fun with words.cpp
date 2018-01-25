// fun with words.cpp : Defines the entry point for the console application.

#include<bios.h>
#include<dos.h>
#include<iostream.h>
#include<graphics.h>
#include<process.h>
#include<conio.h>
#include<string.h>

int x1 = 50, y1 = 360, x2 = 180, y2 = 410, s;
char s1[10][10] = {"Polite", "Kind", "Far", "Tall", "Small" };
char s2[30][30] = { "Big", "Near", "Impolite", "Cruel", "Short" };
char s3[30][30] = { "Polite", "Impolite", "Kind", "Cruel", "Far", "Near" "Tall", "Short", "Small", "Big" };

void moving()
{
	setcolor(8);
	char ch;
	rectangle(x1, y1, x2, y2);
	ch = getch();

	if (ch == 77)
	{
		setcolor(BLACK);
		rectangle(x1, y1, x2, y2);
		if (x2 <= 50)
		{
			x1 = 400;
			x2 = 500;
		}
		else
		{
			x1 += 20;
			x2 += 20;
		}
		delay(50);
		setcolor(8);
		rectangle(x1, y1, x2, y2);
	}

	if (ch == 75)
	{
		setcolor(BLACK);
		rectangle(x1, y1, x2, y2);
		if (x1 >= 400)
		{
			x1 = 50;
			x2 = 150;
		}
		else
		{
			x1 -= 20;
			x2 -= 20;
		}
		delay(50);
		setcolor(8);
		rectangle(x1, y1, x2, y2);
	}
}


void answer(char a[], char b[])
{
	int f = 0;
	for (int w = 0, o = 1; w < 10, o < 10; w += 2, o += 2)
	{
		if (strcmp(s3[w], a) == 0 && strcmp(s3[o], b) == 0)
		{
			f = 1;
			break;
		}
	}

	if (f == 1)
	{
		setcolor(RED);
		outtextxy(100, 15, "RIGHT ANSWER!!!");
		outtextxy(100, 35, "GOOD JOB!!!");
		delay(80);
		setcolor(BLACK);
		outtextxy(100, 15, "RIGHT ANSWER!!!");
		outtextxy(100, 35, "GOOD JOB!!!");
		s = 100;
	}

	else
	{
		setcolor(RED);
		outtextxy(100, 15, "WRONG ANSWER!!!");
		outtextxy(100, 35, "BETTER LUCK NEXT TIME!!!");
		delay(80);
		setcolor(BLACK);
		outtextxy(100, 15, "WRONG ANSWER!!!");
		outtextxy(100, 35, "BETTER LUCK NEXT TIME!!!");
	}
}


void displayMenu()
{
	int ch;
	setbkcolor(14);
	setcolor(BLUE);
	outtextxy(1, 1, "QWERTYUIOPPLKJHGFDSAZXCVBNMSDFGHJMMMKLPOIUYTREWQAZQAZXSWEDCVFRTGBNHYUJMMMDFGMCVGBMTGMKIOPL");
	outtextxy(1, 465, "QWERTYUIOPPLKJHGFDSAZXCVBNMSDFGHJMMMKLPOIUYTREWQAZQAZXSWEDCVFRTGBNHYUJMMMDFGMCVGBMTGMKIOPL");
	settextstyle(11, 1, 1);
	outtextxy(9, 8, "QWERTYUIOPPLKJHGFDSAZXCVBNMSDFGHJMMMKLPOIUYTREWQAZQAZXSWEDCVFRTGBNHYUJMMMDFGMCVGBMTGMKIOPL");
	outtextxy(640, 8, "QWERTYUIOPPLKJHGFDSAZXCVBNMSDFGHJMMMKLPOIUYTREWQAZQAZXSWEDCVFRTGBNHYUJMMMDFGMCVGBMTGMKIOPL");
	setcolor(4);
	settextstyle(7, 0, 7);
	outtextxy(17, 10, "FUN WITH WORDS");

	setcolor(6);
	setlinestyle(1, 1, 3);
	line(16, 80, 608, 80);
	setcolor(8);
	setfillstyle(5,13);
	ellipse(185, 240, 70, 320, 160, 80);
	fillellipse(185, 240, 160, 80);
	setcolor(BLUE);
	settextstyle(7, 0, 2);
	outtextxy(90, 170, "CREATED BY");
	outtextxy(70, 230, "RADHIKA SHARMA");
	setcolor(GREEN);
	outtextxy(400, 200, "....................MENU....................");
	setcolor(BLUE);
	outtextxy(400, 230, "=> START");
	outtextxy(400, 260, "=> ESCAPE");
	setcolor(CYAN);
	settextstyle(7, 0, 1);
	outtextxy(300, 310, "PRESS ENTER TO START");
	outtextxy(300, 310, "PRESS ESC TO ESCAPE");
	ch = getch();
	if (ch == 13)
		cleardevice();
	else if (ch == 27)
		exit(0);
}


void game()
{
	setbkcolor(GREEN);
	setcolor(RED);
	settextstyle(7,0,3);

	int x = 400, y = 100;
	int i = 0, g = 0, r1;
	int x3 = 100, t;
	char a[10], b[10];
	rectangle(x1, y1, x2, y2);
	
	for (g = 0; bioskey(0) && g < 5; g++)
	{
		for (t = 100, t < 380; t += 10)
		{
			if ((bioskey(1)))
			{
				moving();
			}
			setcolor(WHITE);
			outtextxy(x3, t, s1[g]);
			delay(100);
			setcolor(BLACK);
			outtextxy(x3, t, s1[g]);
			delay(100);

			if (x3 >= x1 && x3 <= x2 && t >= y1 && t <= y2)
				strcpy(a, s1[g]);
		}

		r1 = 1;
		y = 100;
		i = 0;
		t = 100;

		do
		{
			for (y = 100; y < 450; y += 10)
			{
				if ((bioskey(1)))
				{
					moving();
				}
				setcolor(WHITE);
				outtextxy(x, y, s2[i]);
				delay(100);
				setcolor(BLACK);
				outtextxy(x, y, s2[i]);
				delay(100);

				if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
				{
					strcpy(b, s2[i]);
					answer(a, b);
					r1 = 6;
				}
			}

			r1++;
			i++;
			y = 100;
		} while (r1 <= 5);
	}

	for (i = 0; i < 1; i++)
	{
		//clean up
		cleardevice();
		setbkcolor(MAGENTA);
		setcolor(BLUE);
		settextstyle(7, 0, 7);
		cout<< "GOOD ATTEMPT";
		cout << "YOUR SCORE IS" << s;
		cout << "BYE";
	}

}


int main(void)
{
	clrscr();
	int gdriver = DETECT, gmode;
	initgraph(&gdriver. &gmode, "Turbo00.BGI");

	displayMenu();

	game();

	getch();
	closegraph();

    return 0;
}

