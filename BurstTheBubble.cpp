/*
Project title :- Burst the Bubble.
Developer     :- Ajith
Algorithms used :- Mid-point Circle Algorithm.
Platform:- OpenGL 
IDE	:-Microsoft Visual Stdio for C++
*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<iostream>
#include<glut.h>
using namespace std;


int circleZero4=0,circleOne4=0,circleTwo4=0,circleThree4=0,circleFour4=0,circleFive4=0,circleSix4=0,circleSeven4=0,circleEight4=0,circleNine4=0,circleTen4=0,circleEleven4=0,circleTwelve4=0,circleThirteen4=0,circleFourteen4=0,circleFifteen4=0;
void *currentfont;
int index,i,xc=612,yc=395,r=50,xc3=533,yc3=234,count=0,j,count3=0,xc4=458,yc4=159,count4=0,lives=5,bubbles=0,score=0;
int circleZero=0,circleOne=0,circleTwo=0,circleThree=0;
int circle1zero=0,circle1one=0,circle1two=0,circle1three=0,circle1four=0,circle1five=0,circle1six=0,circle1seven=0,circle1eight=0;
char numTochar[100];
char zero='0';
void delay();
void setFont(void *);
void drawstring(float ,float ,float ,char *);
void frontscreen(void);
void menu(void);
void display2(void);
void display3(void);
void display1(void);
void display4(void);
void gameover(void);


void intToChar(int number,float x,float y,float z)//Method to convert integer to character.
{
	int counter=0,copy;
    copy=number;
    while(copy)
    {
        copy/=10;
        counter++;
    }

    numTochar[counter+1]='\0';
    copy=number;
    while(copy)
    {
            numTochar[--counter]=copy%10+zero;
            copy/=10;
    }
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	 glColor3f(1.0,0,0);
	drawstring(x,y,z,numTochar);
    
}

void plotpixel(int x,int y)//To plot pixels according to the x and y co-ordinates.
{
		glColor3f(0.5,0,1.0);
		glPointSize(2);
		glBegin(GL_POINTS);
			glVertex2i(x,y);
		glEnd();
		
}

void drawcircle(int x0,int y0,int radius)//To draw Bubbles(Mid-point Circle Algorithm)
{
	int x=radius,y=0,decision=1-radius;
	while(y<=x){
		plotpixel(x+x0,y+y0);
		plotpixel(y+x0,x+y0);
		plotpixel(-y+x0,x+y0);
		plotpixel(-x+x0,y+y0);
		plotpixel(-x+x0,-y+y0);
		plotpixel(-y+x0,-x+y0);
		plotpixel(y+x0,-x+y0);
		plotpixel(x+x0,-y+y0);
		y++;
		if(decision<=0)
			decision+=2*y+1;
		else{
			x--;
			decision+=2*(y-x)+1;
		}
	}
}

void mesh2()//To draw mesh of matrix 2x2.
{
	glColor3f(1.0,0.80,0);
	glBegin(GL_QUADS);
		glPointSize(5);
		glVertex2i(530,620);
		glVertex2i(530,320);
		glVertex2i(860,320);
		glVertex2i(860,620);
	glEnd();
	glFlush();
	glBegin(GL_LINES);
	glLineWidth(5);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(530,470);
		glVertex2i(860,470);
		glVertex2i(695,320);
		glVertex2i(695,620);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glLineWidth(10);
	glPointSize(10);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(530,620);
		glVertex2i(530,320);
		glVertex2i(860,320);
		glVertex2i(860,620);
	glEnd();
	score=count;

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.6,0,0.7);
	drawstring(210.0,200.0,0.0,"Press Q to exit or R to restart the game");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.6,0,0.7);
	drawstring(210.0,700.0,0.0,"SCORE:");
	 intToChar(count,300,700,0);
	if((bubbles-count)>=4)
	{
		
		glutDisplayFunc(gameover);
		glutPostRedisplay();
	}	 


	glFlush();
}

void mesh3()//To draw mesh of matrix 3x3.
{
	glColor3f(1.0,0.80,0);
	glBegin(GL_QUADS);
		glPointSize(5);
		glVertex2i(458,159);
		glVertex2i(908,159);
		glVertex2i(908,609);
		glVertex2i(458,609);
	glEnd();
	glFlush();
	glBegin(GL_LINES);
		glLineWidth(5);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(458,309);
		glVertex2i(908,309);
		glVertex2i(458,459);
		glVertex2i(908,459);
		glVertex2i(608,159);
		glVertex2i(608,609);
		glVertex2i(758,609);
		glVertex2i(758,159);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glPointSize(10);
		glVertex2i(458,159);
		glVertex2i(908,159);
		glVertex2i(908,609);
		glVertex2i(458,609);
	glEnd();

	score=count3;

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.6,0,0.7);
	drawstring(210.0,100.0,0.0,"Press Q to exit or R to restart the game");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
		glColor3f(0.6,0,0.7);
		drawstring(210.0,700.0,0.0,"SCORE:");
		 intToChar(count3,300,700,0);

		 if((bubbles-score)>=4)
	{
		
		glutDisplayFunc(gameover);
		glutPostRedisplay();
	}	 

	glFlush();
}

void mesh4()//To draw mesh of matrix 4x4.
{

	glColor3f(1.0,0.80,0);
	glBegin(GL_QUADS);
		glPointSize(5);
		glVertex2i(383,84);
		glVertex2i(383,684);
		glVertex2i(983,684);
		glVertex2i(983,84);
	glEnd();

	glBegin(GL_LINES);
	glLineWidth(15);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(383,534);
		glVertex2i(983,534);
		glVertex2i(383,384);
		glVertex2i(983,384);
		glVertex2i(383,234);
		glVertex2i(983,234);
		glVertex2i(533,684);
		glVertex2i(533,84);
		glVertex2i(683,684);
		glVertex2i(683,84);
		glVertex2i(833,684);
		glVertex2i(833,84);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glLineWidth(10);
	glPointSize(10);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(383,84);
		glVertex2i(383,684);
		glVertex2i(983,684);
		glVertex2i(983,84);
	glEnd();

	score=count4;
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.6,0,0.7);
	drawstring(210.0,50.0,0.0,"Press Q to exit or R to restart the game");

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0.6,0,0.7);
	drawstring(210.0,700.0,0.0,"SCORE:");
	 intToChar(count4,300,700,0);

	 if((bubbles-score)>=4)
	{
		glutDisplayFunc(gameover);
		glutPostRedisplay();
	}	 

	glFlush();
}

void drawBubbles2(void )//Randomn generation of Bubbles for 2x2 matrix.
{	
    ++bubbles;
	printf("%d\n",bubbles);
	j=rand()%4;
	if(j==0)
	{	
		circleZero=1;
		for(i=0;i<=50;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc,yc,i);
			glFlush();
			delay();
		}
	}
	else if(j==1)
	{
		circleOne=1;
		for(i=0;i<=50;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc,yc+150,i);
			glFlush();
			delay();
		}
	}
	else if(j==2)
	{
		circleTwo=1;
		for(i=0;i<=50;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc+150,yc,i);
			glFlush();
			delay();
		}
	}
	else if(j==3)
	{	
		circleThree=1;
		for(i=0;i<=50;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc+150,yc+150,i);
			glFlush();
			delay();
		}
	}
}

void drawBubbles3(void )//Randomn generation of Bubbles for 3x3 matrix.
{	++bubbles;
     int j=0; 
	j=rand()%9;
	if(j==0)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc3,yc3,i);
			glFlush();
			delay();
			}
		circle1zero=1;
	}
	if(j==1)
	{
		
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc3,yc3+150,i);
			glFlush();
			delay();	
		}
		circle1one=1;
	}
	 if(j==2)
	{
		
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc3,yc3+300,i);
			glFlush();
			delay();
			}
		circle1two=1;
	}
	if(j==3)
	{	
		
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc3+150,yc3,i);
			glFlush();
			delay();
			}
		circle1three=1;
	}
	if(j==4)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc3+150,yc3+150,i);
			glFlush();
			delay();
			}
		circle1four=1;
	}
	if(j==5)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc3+150,yc3+300,i);
			glFlush();
			delay();	
		}
		circle1five=1;
	}
	if(j==6)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc3+300,yc3,i);
			glFlush();
			delay();	
		}
		circle1six=1;
	}
	if(j==7)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc3+300,yc3+150,i);
			glFlush();
			delay();	
		}
		circle1seven=1;
	}
	if(j==8)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc3+300,yc3+300,i);
			glFlush();
			delay();
		}
		circle1eight=1;
	}
}





void drawBubbles4(void )//Randomn generation of Bubbles for 4x4 matrix.
{	++bubbles;
   int j=0; 
	j=rand()%16;
	if(j==0)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.583,0.0);
			drawcircle(xc4,yc4,i);
			glFlush();
			delay();
			}
		circleZero4=1;
	}
	else if(j==1)
	{
		
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.583,0.0);
			drawcircle(xc4,yc4+150,i);
			glFlush();
			delay();	
		}
		circleOne4=1;
	}
	else if(j==2)
	{
		
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.583,0.0);
			drawcircle(xc4,yc4+300,i);
			glFlush();
			delay();
			}
		circleTwo4=1;
	}
	else if(j==3)
	{	
		
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.583,0.0);
			drawcircle(xc4+150,yc4,i);
			glFlush();
			delay();
			}
		circleThree4=1;
	}
	else if(j==4)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.583,0.0);
			drawcircle(xc4+150,yc4+150,i);
			glFlush();
			delay();
			}
		circleFour4=1;
	}
	else if(j==5)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.583,0.0);
			drawcircle(xc4+150,yc4+300,i);
			glFlush();
			delay();	
		}
		circleFive4=1;
	}
	else if(j==6)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc4+300,yc4,i);
			glFlush();
			delay();	
		}
		circleSix4=1;
	}
	else if(j==7)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc4+300,yc4+150,i);
			glFlush();
			delay();	
		}
		circleSeven4=1;
	}
	else if(j==8)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc4+300,yc4+300,i);
			glFlush();
			delay();
		}
		circleEight4=1;
	}
	else if(j==9)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc4,yc4+450,i);
			glFlush();
			delay();
		}
		circleNine4=1;
	}
	else if(j==10)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc4+150,yc4+450,i);
			glFlush();
			delay();
		}
		circleTen4=1;
	}
	else if(j==11)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc4+300,yc4+450,i);
			glFlush();
			delay();
		}
		circleEleven4=1;
	}
	else if(j==12)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc4+450,yc4+450,i);
			glFlush();
			delay();
		}
		circleTwelve4=1;
	}
	else if(j==13)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc4+450,yc4+300,i);
			glFlush();
			delay();
		}
		circleThirteen4=1;
	}
	else if(j==14)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc4+450,yc4+150,i);
			glFlush();
			delay();
		}
		circleFourteen4=1;
	}
	else if(j==11)
	{	
		for(i=0;i<=40;i++){
			glColor3f(1.0,0.5,0.0);
			drawcircle(xc4+450,yc4,i);
			glFlush();
			delay();
		}
		circleFifteen4=1;
	}
}

void setFont(void *font)//Setting up the current font for rendering.
{
	currentfont=font;
}
void delay()//Time delay function for about approx 300 milli seconds.
{
  	int p,q;
  p=2500;
	while(p!=0)
	{
		p--;
		q=2500;
		while(q!=0)
		{
			q--;
			
		}
		
	}
	if(p==0&&q==0)
		glutPostRedisplay();
	

}
void drawstring(float x,float y,float z,char *string)//To draw strings on screen.
{
	char *c;
	glRasterPos3f(x,y,z);
	for(c=string;*c!='\0';c++)
	{	
		glutBitmapCharacter(currentfont,*c);
	}
}

void frontscreen(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 setFont(GLUT_BITMAP_TIMES_ROMAN_24);
 glColor3f(0.6,0,0.7);
 drawstring(500.0,690.0,0.0,"PES");
 glColor3f(1,0,0);
 drawstring(543.0,690.0,0.0," Institute of Technology and Management ");
 glColor3f(0,0,1);
 drawstring(600.0,660.0,0.0,"Shivamogga "); 
 glColor3d(0,0,0);
 drawstring(500,620,0.0,"Department of Computer Science and Engineering");
 
 setFont(GLUT_BITMAP_TIMES_ROMAN_24);
 glColor3f(1.0,0.5,0.0);
 drawstring(600,580,0.0,"A Mini Project ");
 glColor3f(1.0,0.5,0.0);
 drawstring(650,550,0.0,"On");
 glColor3f(1,0,0);
 
 setFont(GLUT_BITMAP_TIMES_ROMAN_24);
 drawstring(560,500,0.0,"BUBBLE BURST GAME");
 
 setFont(GLUT_BITMAP_TIMES_ROMAN_24);
 glColor3f(1,0.5,0);
 drawstring(610,450,0.0,"Submitted By");
 setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0.5,0,0.5);
 drawstring(510,400,0.0,"Mr. AJITH H                            [4PM13CS003]");
 glColor3f(0.5,0,0.5);
 
 drawstring(510,350,0.0,"Ms. KAVYASHREE M B        [4PM13CS034]");
 glColor3f(1,0.5,0);
 
 setFont(GLUT_BITMAP_TIMES_ROMAN_24);
 drawstring(590,300,0.0,"Under The Guidance of");
 setFont(GLUT_BITMAP_TIMES_ROMAN_24);

 glColor3d(0.5,0.2,0.2);

 drawstring(490,250,0.0,"Mrs. PRATHIBA S ");
 glColor3d(0.5,0.2,0.2);

 drawstring(790,250,0.0,"Mr. DEVARAJ F V ");
 setFont(GLUT_BITMAP_8_BY_13);
 glColor3d(0.5,0.2,0.2);
 drawstring(530,220,0.0,"B.E.,M.Tech.");
 drawstring(830,220,0.0,"B.E.,M.Tech.");
 setFont(GLUT_BITMAP_9_BY_15);
 glColor3d(0.5,0.2,0.2);
 drawstring(500,200,0.0,"Assistant Professor");
  
 drawstring(800,200,0.0,"Assistant Professor");
 
 
 setFont(GLUT_BITMAP_HELVETICA_18);
 glColor3d(1.0,0.1,1.0);
 drawstring(950,150,0.0,"Press S To Start");
 glColor3d(1,0.1,0);
 drawstring(950,100,0.0,"Press Q To Exit");
 glFlush();

}


void menu() // To draw the polygons for the menu box  
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.741,1.0,0.0,0.0);
	glBegin(GL_POLYGON);  //GAME 2x2 Menu
	glColor3f(0.5f,0.5f,0.5f);
    glVertex2i(600,600);
	glVertex2i(750,600);
	glVertex2i(750,650);
    glVertex2i(600,650);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);  
	glColor3f(0.5f,0.5f,0.5f); // GAME 3x3 Menu
    glVertex2i(600,550);
	glVertex2i(600,500);
	glVertex2i(750,500);
    glVertex2i(750,550);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);  // GAME 4x4 Menu
	glColor3f(0.5f,0.5f,0.5f);
    glVertex2i(600,450);
	glVertex2i(750,450);
	glVertex2i(750,400);
    glVertex2i(600,400);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);  // EXIT
	glColor3f(0.5f,0.5f,0.5f);
    glVertex2i(600,350);
	glVertex2i(750,350);
	glVertex2i(750,300);
    glVertex2i(600,300);
	glEnd();
	glFlush();
	
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(0.0,0.0,1.0);
	drawstring(530.0,720.0,1.0,"* * * * *WELCOME TO BUBBLE BURST * * * * *");
	glColor3f(0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.0);
	drawstring(620.0,625.0,1.0,"GAME 2x2");
	glColor3f(0.0,0.0,0.0);
	drawstring(620.0,525.0,1.0,"GAME 3x3");
	glColor3f(0.0,0.0,0.0);
	drawstring(620.0,425.0,1.0,"GAME 4x4");
	glColor3f(0.0,0.0,0.0);
	drawstring(620.0,325.0,1.0,"EXIT");
	glFlush();
}		

void mykeyboard(unsigned char key,int x,int y)// Keyboard function to get inputs.
{
	
	if(key=='s'||key=='S'||key==13)
	{
		glutDisplayFunc(display1);
		glutPostRedisplay();
	}
	else if(key=='q' || key=='Q' || key==27)
	{
		exit(0);
	}
	else if (key=='c' || key=='C')
	{
		frontscreen();
	}
	else if(key=='r'||key=='Q')
	{
		bubbles=0;
		score=0;
		count=0;
		glClear(GL_COLOR_BUFFER_BIT);
		glutDisplayFunc(display1);
		glutPostRedisplay();
	}
}


void myMouse2(int btn,int state,int x, int y)//Mouse function to get inputs.
{	
	y=768-y;
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
		if(circleZero)
		{
			int d = ((x-xc)*(x-xc))+((y-yc)*(y-yc))-(r*r);
			if(d<=0){
			    count++;
			}
			circleZero=0;
		}
		if(circleOne)
		{
			int d = ((x-xc)*(x-xc))+((y-(yc+150))*(y-(yc+150)))-(r*r);
			if(d<=0){
				count++;
			}	
			circleOne=0;
		}
		if(circleTwo)
		{
			int d = ((x-(xc+150))*(x-(xc+150))+((y-yc)*(y-yc)))-(r*r);
			if(d<=0){
				count++;
			}	
			circleTwo=0;
		}
		if(circleThree)
		{
			int d = ((x-(xc+150))*(x-(xc+150)))+((y-(yc+150))*(y-(yc+150)))-(r*r);
			if(d<=0){
				count++;
			}
			circleThree=0;
		}
	}
	glutPostRedisplay();
}


void myMouse3(int btn,int state,int x, int y)//Mouse function to get inputs.
{	
	y=768-y;
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
		if(circle1zero)
		{
			int d = ((x-xc3)*(x-xc3))+((y-yc3)*(y-yc3))-(r*r);
			if(d<=0){
			count3++;
			}
			circle1zero=0;
		}
		if(circle1one)
		{
			int d = ((x-xc3)*(x-xc3))+((y-(yc3+150))*(y-(yc3+150)))-(r*r);
			if(d<=0){
			count3++;
			}	
			circle1one=0;
		}
		if(circle1two)
		{
			int d = ((x-xc3)*(x-xc3)+((y-(yc3+300))*(y-(yc3+300))))-(r*r);
			if(d<=0){
				count3++;
			}	
				circle1two=0;
		}
		if(circle1three)
		{
			int d = ((x-(xc3+150))*(x-(xc3+150)))+((y-yc3)*(y-yc3))-(r*r);
			if(d<=0){
			count3++;
			}
			circle1three=0;
		}
		if(circle1four)
		{
			int d = ((x-(xc3+150))*(x-(xc3+150)))+((y-(yc3+150))*(y-(yc3+150)))-(r*r);
			if(d<=0){
				
			count3++;
			}
			circle1four=0;
		}
		if(circle1five)
		{
			int d = ((x-(xc3+150))*(x-(xc3+150)))+((y-(yc3+300))*(y-(yc3+300)))-(r*r);
			if(d<=0){
				
			count3++;
			}
			circle1five=0;
		}
		if(circle1six)
		{
			int d = ((x-(xc3+300))*(x-(xc3+300)))+((y-yc3)*(y-yc3))-(r*r);
			if(d<=0){
				
			count3++;
			}
			circle1six=0;
		}
		if(circle1seven)
		{
			int d = ((x-(xc3+300))*(x-(xc3+300)))+((y-(yc3+150))*(y-(yc3+150)))-(r*r);
			if(d<=0){
				
			count3++;
			}
			circle1seven=0;
		}
		if(circle1eight)
		{
			int d = ((x-(xc3+300))*(x-(xc3+300)))+((y-(yc3+300))*(y-(yc3+300)))-(r*r);
			if(d<=0){
			count3++;
			}
			circle1eight=0;
		}
	}
	glutPostRedisplay();
}







void myMouse4(int btn,int state,int x, int y)//Mouse function to get inputs.
{	
	y=768-y;
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
		if(circleZero4)
		{
			int d = ((x-xc4)*(x-xc4))+((y-yc4)*(y-yc4))-(r*r);
			if(d<=0){
			count4++;
			}
			circleZero4=0;
		}
		else if(circleOne4)
		{
			int d = ((x-xc4)*(x-xc4))+((y-(yc4+150))*(y-(yc4+150)))-(r*r);
			if(d<=0){
			count4++;
			}	
			circleOne4=0;
		}
		else if(circleTwo4)
		{
			int d = ((x-xc4)*(x-xc4)+((y-(yc4+300))*(y-(yc4+300))))-(r*r);
			if(d<=0){
				count4++;
			}	
				circleTwo4=0;
		}
		else if(circleThree4)
		{
			int d = ((x-(xc4+150))*(x-(xc4+150)))+((y-yc4)*(y-yc4))-(r*r);
			if(d<=0){
			count4++;
			}
			circleThree4=0;
		}
		else if(circleFour4)
		{
			int d = ((x-(xc4+150))*(x-(xc4+150)))+((y-(yc4+150))*(y-(yc4+150)))-(r*r);
			if(d<=0){
				
			count4++;
			}
			circleFour4=0;
		}
		else if(circleFive4)
		{
			int d = ((x-(xc4+150))*(x-(xc4+150)))+((y-(yc4+300))*(y-(yc4+300)))-(r*r);
			if(d<=0){
				
			count4++;
			}
			circleFive4=0;
		}
		else if(circleSix4)
		{
			int d = ((x-(xc4+300))*(x-(xc4+300)))+((y-yc4)*(y-yc4))-(r*r);
			if(d<=0){
				
			count4++;
			}
			circleSix4=0;
		}
		else if(circleSeven4)
		{
			int d = ((x-(xc4+300))*(x-(xc4+300)))+((y-(yc4+150))*(y-(yc4+150)))-(r*r);
			if(d<=0){
				
			count4++;
			}
			circleSeven4=0;
		}
		else if(circleEight4)
		{
			int d = ((x-(xc4+300))*(x-(xc4+300)))+((y-(yc4+300))*(y-(yc4+300)))-(r*r);
			if(d<=0){
			count4++;
			}
			circleEight4=0;
		}

		else if(circleNine4)
		{
			int d = ((x-(xc4))*(x-(xc4)))+((y-(yc4+450))*(y-(yc4+450)))-(r*r);
			if(d<=0){
			count4++;
			}
			circleNine4=0;
		}

		else if(circleTen4)
		{
			int d = ((x-(xc4+150))*(x-(xc4+150)))+((y-(yc4+450))*(y-(yc4+450)))-(r*r);
			if(d<=0){
			count4++;
			}
			circleTen4=0;
		}

		else if(circleEleven4)
		{
			int d = ((x-(xc4+300))*(x-(xc4+300)))+((y-(yc4+450))*(y-(yc4+450)))-(r*r);
			if(d<=0){
			count4++;
			}
			circleEleven4=0;
		}

		else if(circleTwelve4)
		{
			int d = ((x-(xc4+450))*(x-(xc4+450)))+((y-(yc4+450))*(y-(yc4+450)))-(r*r);
			if(d<=0){
			count4++;
			}
			circleTwelve4=0;
		}

		else if(circleThirteen4)
		{
			int d = ((x-(xc4+450))*(x-(xc4+450)))+((y-(yc4+300))*(y-(yc4+300)))-(r*r);
			if(d<=0){
			count4++;
			}
			circleThirteen4=0;
		}

		else if(circleFourteen4)
		{
			int d = ((x-(xc4+450))*(x-(xc4+450)))+((y-(yc4+150))*(y-(yc4+150)))-(r*r);
			if(d<=0){
			count4++;
			}
			circleFourteen4=0;
		}
		else if(circleFifteen4)
		{
			int d = ((x-(xc4+450))*(x-(xc4+450)))+((y-(yc4))*(y-(yc4)))-(r*r);
			if(d<=0){
			count4++;
			}
			circleFifteen4=0;
		}

	}
	glutPostRedisplay();
}

void game2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	mesh2();
	drawBubbles2();
}

void game3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	mesh3();
	drawBubbles3();
	
} 
void game4()
{
	glClear(GL_COLOR_BUFFER_BIT);
	mesh4();
	drawBubbles4();
}


void myMouse(int btn, int state, int x, int y)//Mouse function to get inputs.
{

	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		
		y=(768-y);
		if ((x>=600 && x<=750) && (y>=600 && y<=650 ))// (2*2)
		{	
			glutDisplayFunc(display2);
			glutPostRedisplay();
			
				
		}
		if ((x>=600 && x<=750) && (y>=500 && y<=550 ))// 3*3 menu
		{
			glutDisplayFunc(display3);
			glutPostRedisplay();
		}
		if((x>=600 && x<=750) && (y>=400 && y<=450 ))  //  4*4 menu
		{
			glutDisplayFunc(display4);
			glutPostRedisplay();
		}
		if((x>=600 && x<=750) && (y>=300 && y<=350 ))  // exit menu
		{
			exit(0);
		}
		
	}
}


void init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1366.0,0.0,768.0);
	glMatrixMode(GL_PROJECTION);
}
void gameover(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
       glBegin(GL_QUADS);
               glColor3f(0.5f, 0.0f, 1.0f); // make this vertex purple
               glVertex2f(0, 0);
               glColor3f(1.0f, 0.0f, 0.0f); // make this vertex red
               glVertex2f(0, 768);
               glColor3f(0.0f, 1.0f, 0.0f); // make this vertex green
               glVertex2f(1366, 768);
               glColor3f(1.0f, 1.0f, 0.0f); // make this vertex yellow
               glVertex2f(1366, 0);
       glEnd();

	   setFont(GLUT_BITMAP_TIMES_ROMAN_24);
		glColor3f(0,0,0);
		drawstring(553.0,584.0,0.0,"GAME OVER!!!");

		setFont(GLUT_BITMAP_TIMES_ROMAN_24);
		glColor3f(0,0,0);
		drawstring(600.0,484.0,0.0,"Your Score:");
		intToChar(score,730,484,0);
		score=0;
		bubbles=0;
		count=0;
		count4=0;
		count3=0;
		setFont(GLUT_BITMAP_TIMES_ROMAN_24);
		glColor3f(0,0,0);
		drawstring(450.0,380.0,0.0,"Press Q to exit or R to restart the game");
		glFlush();
}

void display4(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	game4();
	glutMouseFunc(myMouse4);
	glutSwapBuffers();
}
void display3(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	game3();
	glutMouseFunc(myMouse3);
	glutSwapBuffers();
}

void display2(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	game2();
	glutMouseFunc(myMouse2);
	glutSwapBuffers();
}
void display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	menu();
	glutMouseFunc(myMouse);
	
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	frontscreen();
	
}

void main(int argc,char **argv)//Main function call.
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1366,768);
	glutCreateWindow("BUBBLE BURST");
	glutDisplayFunc(display);
	glutKeyboardFunc(mykeyboard);
	init();
	glutMainLoop();
}