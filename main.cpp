#include<windows.h>
#include<stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <string>
#include<fstream>
#include<sstream>

using namespace std;
///text display
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;
const int font2=(int)GLUT_BITMAP_HELVETICA_18 ;
const int font3=(int)GLUT_BITMAP_8_BY_13;
const int font4=(int)GLUT_BITMAP_9_BY_15;


///Score

int score=0;
int highScore=0;

/// Speed of our main car
int carSpeed=50;

/// Game switches
bool gameOver=true;
bool gameStarted=false;



/// Dividers and their index
int topDividerIndex=0;
int midDividerIndex=0;
int bottomDividerIndex=0;

///Positional variables of our main car

int xAxisMainCar=27; //
int yAxisMainCar=0;



///Positional variables of the opposite cars and other things

int xAxisCarA=12;
int yAxisCarA=100;

int xAxisCarB=27;
int yAxisCarB=100;

int xAxisCarC=42;
int yAxisCarC=100;

int xAxisCarD=35;
int yAxisCarD=100;

int home1Index=100;
int home2Index=100;

int markerIndex=100;

int dividerIndex1=100;
int dividerIndex2=100;
int dividerIndex3=100;

void renderBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void homePage() { string dd;

                                           ifstream FS;
                                                       FS.open("Highscore.txt");
                                                        while(!FS.eof())
                                                              {
                                                                       getline(FS,dd);
                                                              }


                                                              FS.close();


stringstream sd;
sd<<dd;

sd>>highScore;

///Highscore read from the text file







if(score>highScore)
    { highScore=score;

    ofstream wq;
      wq.open("Highscore.txt");  ///Storing new highscore into the text file
      wq<<highScore;
      wq.close();


    }





    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);


glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(10.0f,0.0f);
    glVertex2f(10.0f,100.0f);
    glVertex2f(90.0f,100.0f);
    glVertex2f(90.0f,0.0f);
    glEnd();


glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,0.0f);
    glVertex2f(0.0f,100.0f);
    glVertex2f(10.0f,100.0f);
    glVertex2f(10.0f,0.0f);
    glEnd();


glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(90.0f,0.0f);
    glVertex2f(90.0f,100.0f);
    glVertex2f(100.0f,100.0f);
    glVertex2f(100.0f,0.0f);
    glEnd();

    if(gameStarted==true)
    {
glColor3f(1.0f, 0.0f, 0.0f);
                renderBitmapString(44,85,(void *)font1,"GAME OVER");  ///Title

                renderBitmapString(46,75,(void *)font1,"Try Again");
    }

    else{
                glColor3f(1.0f, 0.0f, 0.0f);
                renderBitmapString(39,85,(void *)font1,"RACING    CAR    GAME");  ///Title

                renderBitmapString(41,75,(void *)font1,"By Rifat and Shahriar");

           }


glColor3f(1.0f, 1.0f, 0.0f);
   renderBitmapString(30,55,(void *)font1,"Instruction : Directional buttons (UP, DOWN, LEFT and RIGHT)"); ///Instructions




glColor3f(0.0f, 1.0f, 0.0f); /// Highscore

 char HS[50];
    sprintf (HS, "Highscore: %d", highScore);

    renderBitmapString(44,45,(void *)font1,HS);
///


if(gameOver==true)
{
 glColor3f(1.0f, 1.0f, 0.0f); /// Score

 char HS[50];
    sprintf (HS, "Score: %d", score);

    renderBitmapString(46,35,(void *)font1,HS);
}

 if(gameStarted==true)
    {

            glColor3f(0.0f, 0.5f, 1.0f);
            renderBitmapString(42,25,(void *)font1,"Press Space to Restart "); ///Restart instruction

    }

    else{
                glColor3f(0.0f, 0.5f, 1.0f);
                renderBitmapString(42,25,(void *)font1,"Press Space to Start "); ///Start instruction


           }

           glColor3f(1.0f, 0.0f, 0.0f);
                renderBitmapString(77,95,(void *)font3,"PRESS X TO EXIT"); ///Start instruction




	 glFlush();
}


void playGame() {

gameStarted=true;
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 255, 0,1);

	///road
  glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(20.0f,0.0f);
    glVertex2f(20.0f,100.0f);
    glVertex2f(80.0f,100.0f);
    glVertex2f(80.0f,0.0f);
    glEnd();







    ///Top divider
  glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(47,dividerIndex1-20);
    glVertex2i(47,dividerIndex1);
    glVertex2i(53,dividerIndex1);
    glVertex2i(53,dividerIndex1-20);
    glEnd();

dividerIndex1--;
if(dividerIndex1==0) {  score++; dividerIndex1=120;}

 ///Middle divider
  glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(47,dividerIndex2-60);
    glVertex2i(47,dividerIndex2-40);
    glVertex2i(53,dividerIndex2-40);
    glVertex2i(53,dividerIndex2-60);
    glEnd();

dividerIndex2--;

if(dividerIndex2==40) {   score++; dividerIndex2=160;}

///Bottom divider
  glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(47,dividerIndex3-100);
    glVertex2i(47,dividerIndex3-80);
    glVertex2i(53,dividerIndex3-80);
    glVertex2i(53,dividerIndex3-100);
    glEnd();

dividerIndex3--;

if(dividerIndex3==80) {   score++; dividerIndex3=200;}


    ///Left border of road
  glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(20.0f,0.0f);
    glVertex2f(20.0f,100.0f);
    glVertex2f(23.0f,100.0f);
    glVertex2f(23.0f,0.0f);
    glEnd();

     ///Red markings on left border
     ///1
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(20,markerIndex-100);
    glVertex2i(20,markerIndex-90);
    glVertex2i(23,markerIndex-90);
    glVertex2i(23,markerIndex-100);
    glEnd();

  ///2
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(20,markerIndex-80);
    glVertex2i(20,markerIndex-70);
    glVertex2i(23,markerIndex-70);
    glVertex2i(23,markerIndex-80);
    glEnd();


     ///3
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(20,markerIndex-60);
    glVertex2i(20,markerIndex-50);
    glVertex2i(23,markerIndex-50);
    glVertex2i(23,markerIndex-60);
    glEnd();

     ///4
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(20,markerIndex-40);
    glVertex2i(20,markerIndex-30);
    glVertex2i(23,markerIndex-30);
    glVertex2i(23,markerIndex-40);
    glEnd();

     ///5
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(20,markerIndex-20);
    glVertex2i(20,markerIndex-10);
    glVertex2i(23,markerIndex-10);
    glVertex2i(23,markerIndex-20);
    glEnd();


    ///Right border of road
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(77,0);
    glVertex2i(77,100);
    glVertex2i(80,100);
    glVertex2i(80,0);
    glEnd();


    ///Red markings on right border
     ///1
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(77,markerIndex-100);
    glVertex2i(77,markerIndex-90);
    glVertex2i(80,markerIndex-90);
    glVertex2i(80,markerIndex-100);
    glEnd();

  ///2
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(77,markerIndex-80);
    glVertex2i(77,markerIndex-70);
    glVertex2i(80,markerIndex-70);
    glVertex2i(80,markerIndex-80);
    glEnd();


     ///3
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(77,markerIndex-60);
    glVertex2i(77,markerIndex-50);
    glVertex2i(80,markerIndex-50);
    glVertex2i(80,markerIndex-60);
    glEnd();

     ///4
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(77,markerIndex-40);
    glVertex2i(77,markerIndex-30);
    glVertex2i(80,markerIndex-30);
    glVertex2i(80,markerIndex-40);
    glEnd();

     ///5
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(77,markerIndex-20);
    glVertex2i(77,markerIndex-10);
    glVertex2i(80,markerIndex-10);
    glVertex2i(80,markerIndex-20);
    glEnd();





markerIndex--;
if(markerIndex==0) {markerIndex=200;}

/// Home to the right side of the road
///Roof
glColor3f(0.1f, 0.0f, 0.0f); ///Brown
    glBegin(GL_POLYGON);
    glVertex2i(85,home2Index - 60);
    glVertex2i(95,home2Index - 60);
    glVertex2i(90,home2Index - 50);
    glEnd();

    ///Walls
    glColor3f(1.0f, 0.5f, 0.0f); ///Orange
    glBegin(GL_POLYGON);
    glVertex2i(85,home2Index - 60);
    glVertex2i(95,home2Index - 60);
    glVertex2i(95,home2Index - 70);
    glVertex2i(85,home2Index - 70);
    glEnd();

    ///Door
glColor3f(0.1f, 0.0f, 0.0f); ///Brown
    glBegin(GL_POLYGON);
    glVertex2i(89,home2Index - 70);
    glVertex2i(89,home2Index - 67);
    glVertex2i(91,home2Index - 67);
    glVertex2i(91,home2Index - 70);
    glEnd();


     ///1st Window
glColor3f(0.1f, 0.0f, 0.0f); ///Brown
    glBegin(GL_POLYGON);
    glVertex2i(86,home2Index - 64);
    glVertex2i(86,home2Index - 62);
    glVertex2i(88,home2Index - 62);
    glVertex2i(88,home2Index - 64);
    glEnd();


      ///2nd Window
glColor3f(0.1f, 0.0f, 0.0f); ///Brown
    glBegin(GL_POLYGON);
    glVertex2i(92,home2Index - 64);
    glVertex2i(92,home2Index - 62);
    glVertex2i(94,home2Index - 62);
    glVertex2i(94,home2Index - 64);
    glEnd();


home2Index -=1 ;

if(home2Index==0){ home2Index=157;}

/// Home to the left side of the road
///Roof
glColor3f(0.1f, 0.0f, 0.0f); ///Brown
    glBegin(GL_POLYGON);
    glVertex2i(15, home1Index - 30);
    glVertex2i(5,home1Index - 30);
    glVertex2i(10,home1Index - 20);
    glEnd();

    ///Walls
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f); ///Yellow
    glBegin(GL_POLYGON);
    glVertex2i(15,home1Index - 30);
    glVertex2i(5,home1Index - 30);
    glVertex2i(5,home1Index - 40);
    glVertex2i(15,home1Index - 40);
    glEnd();

       ///Door
glColor3f(0.1f, 0.0f, 0.0f); ///Brown
    glBegin(GL_POLYGON);
    glVertex2i(11,home1Index - 40);
    glVertex2i(11,home1Index - 37);
    glVertex2i(9,home1Index - 37);
    glVertex2i(9,home1Index - 40);
    glEnd();


     ///1st Window
glColor3f(0.1f, 0.0f, 0.0f); ///Brown
    glBegin(GL_POLYGON);
    glVertex2i(14,home1Index - 34);
    glVertex2i(14,home1Index - 32);
    glVertex2i(12,home1Index - 32);
    glVertex2i(12,home1Index - 34);
    glEnd();


      ///2nd Window
glColor3f(0.1f, 0.0f, 0.0f); ///Brown
    glBegin(GL_POLYGON);
    glVertex2i(8,home1Index - 34);
    glVertex2i(8,home1Index - 32);
    glVertex2i(6,home1Index - 32);
    glVertex2i(6,home1Index - 34);
    glEnd();

home1Index --;

if(home1Index ==0) { home1Index =137;}


/// Opposite Car A
    ///Car's body
glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);

    glVertex2f(23 + xAxisCarA,yAxisCarA-30);

    glVertex2f(21 + xAxisCarA,yAxisCarA-32);
    glVertex2f(21 + xAxisCarA,yAxisCarA-40);
    glVertex2f(25 + xAxisCarA,yAxisCarA-40);
    glVertex2f(25 + xAxisCarA,yAxisCarA-32);
    glEnd();


///Wheel (Top right)

     glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(25 + xAxisCarA,yAxisCarA-32);
    glVertex2f(25 + xAxisCarA,yAxisCarA-34);
    glVertex2f(26 + xAxisCarA,yAxisCarA-34);
    glVertex2f(26 + xAxisCarA,yAxisCarA-32);

    glEnd();

    ///Wheel (Top left)

      glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(21 + xAxisCarA,yAxisCarA-32);
    glVertex2f(21 + xAxisCarA,yAxisCarA-34);
    glVertex2f(20 + xAxisCarA,yAxisCarA-34);
    glVertex2f(20 + xAxisCarA,yAxisCarA-32);

    glEnd();


     ///Wheel (Bottom left)

       glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(21 + xAxisCarA,yAxisCarA-38);
    glVertex2f(21 + xAxisCarA,yAxisCarA-40);
    glVertex2f(20 + xAxisCarA,yAxisCarA-40);
    glVertex2f(20 + xAxisCarA,yAxisCarA-38);

    glEnd();


    ///Wheel (Bottom right)

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(25 + xAxisCarA,yAxisCarA-38);
    glVertex2f(25 + xAxisCarA,yAxisCarA-40);
    glVertex2f(26 + xAxisCarA,yAxisCarA-40);
    glVertex2f(26 + xAxisCarA,yAxisCarA-38);


    yAxisCarA--;

      if(  abs(xAxisCarA-xAxisMainCar)<=5     ) { if(abs(yAxisCarA - yAxisMainCar)<=49 && abs(yAxisCarA - yAxisMainCar)>=30  ){Sleep(100); gameOver=true;}       }



    if(  yAxisCarA==0)
        {
           xAxisCarA=xAxisMainCar;
           yAxisCarA=140;
        }
    glEnd();
///

   /// Opposite Car B
    ///Car's body
   glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);

    glVertex2f(xAxisCarB + 23,yAxisCarB -40);

    glVertex2f(xAxisCarB +21,yAxisCarB -42);
    glVertex2f(xAxisCarB +21,yAxisCarB -50);
    glVertex2f(xAxisCarB +25,yAxisCarB -50);
    glVertex2f(xAxisCarB +25,yAxisCarB -42);
    glEnd();


///Wheel (Top right)

     glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(xAxisCarB +25,yAxisCarB -42);
    glVertex2f(xAxisCarB +25,yAxisCarB -44);
    glVertex2f(xAxisCarB +26,yAxisCarB -44);
    glVertex2f(xAxisCarB +26,yAxisCarB -42);

    glEnd();

    ///Wheel (Top left)

      glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(xAxisCarB +21,yAxisCarB -42);
    glVertex2f(xAxisCarB +21,yAxisCarB -44);
    glVertex2f(xAxisCarB +20,yAxisCarB -44);
    glVertex2f(xAxisCarB +20,yAxisCarB -42);

    glEnd();


     ///Wheel (Bottom left)

       glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(xAxisCarB +21,yAxisCarB -48);
    glVertex2f(xAxisCarB +21,yAxisCarB -50);
    glVertex2f(xAxisCarB +20,yAxisCarB -50);
    glVertex2f(xAxisCarB +20,yAxisCarB -48);

    glEnd();


    ///Wheel (Bottom right)

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(xAxisCarB +25,yAxisCarB -48);
    glVertex2f(xAxisCarB +25,yAxisCarB -50);
    glVertex2f(xAxisCarB +26,yAxisCarB -50);
    glVertex2f(xAxisCarB +26,yAxisCarB -48);

    glEnd();


    yAxisCarB--;


if(  abs(xAxisCarB-xAxisMainCar)<=5     ) { if(abs(yAxisCarB - yAxisMainCar)<=58 && abs(yAxisCarB - yAxisMainCar)>=41 ){Sleep(100); gameOver=true;}      }

    if(yAxisCarB==40) { yAxisCarB=200; xAxisCarB=xAxisMainCar;} ///Red One
///


/// Opposite Car C
    ///Car's body
glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);


    if(xAxisCarC>50) { xAxisCarC=50;}

    glVertex2f(23 + xAxisCarC,yAxisCarC - 15);

    glVertex2f(21 + xAxisCarC,yAxisCarC - 17);
    glVertex2f(21 + xAxisCarC,yAxisCarC - 25);
    glVertex2f(25 + xAxisCarC,yAxisCarC - 25);
    glVertex2f(25 + xAxisCarC,yAxisCarC - 17);
    glEnd();


///Wheel (Top right)

     glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(25 + xAxisCarC,yAxisCarC - 17);
    glVertex2f(25 + xAxisCarC,yAxisCarC - 19);
    glVertex2f(26 + xAxisCarC,yAxisCarC - 19);
    glVertex2f(26 + xAxisCarC,yAxisCarC - 17);

    glEnd();

    ///Wheel (Top left)

      glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(21 + xAxisCarC,yAxisCarC - 17);
    glVertex2f(21 + xAxisCarC,yAxisCarC - 19);
    glVertex2f(20 + xAxisCarC,yAxisCarC - 19);
    glVertex2f(20 + xAxisCarC,yAxisCarC - 17);

    glEnd();


     ///Wheel (Bottom left)

       glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(21 + xAxisCarC,yAxisCarC - 23);
    glVertex2f(21 + xAxisCarC,yAxisCarC - 25);
    glVertex2f(20 + xAxisCarC,yAxisCarC - 25);
    glVertex2f(20 + xAxisCarC,yAxisCarC - 23);

    glEnd();


    ///Wheel (Bottom right)

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(25 + xAxisCarC,yAxisCarC - 23);
    glVertex2f(25 + xAxisCarC,yAxisCarC - 25);
    glVertex2f(26 + xAxisCarC,yAxisCarC - 25);
    glVertex2f(26 + xAxisCarC,yAxisCarC - 23);

    glEnd();


    yAxisCarC--;


  if(  abs(xAxisCarC-xAxisMainCar)<=5     ) { if(abs(yAxisCarC - yAxisMainCar)<=34 && abs(yAxisCarC - yAxisMainCar)>=15 ){Sleep(100); gameOver=true;}        }


    if(yAxisCarC==15)
        {yAxisCarC=145;   xAxisCarC=xAxisMainCar +10;} ///Pink one





///

 /// Opposite Car D
    ///Car's body
glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);

    if(xAxisCarD<4) { xAxisCarD=4;}


    glVertex2f(xAxisCarD+23,yAxisCarD - 25);

    glVertex2f(xAxisCarD+21,yAxisCarD - 27);
    glVertex2f(xAxisCarD+21,yAxisCarD - 35);
    glVertex2f(xAxisCarD+25,yAxisCarD - 35);
    glVertex2f(xAxisCarD+25,yAxisCarD - 27);
    glEnd();


///Wheel (Top right)

     glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(xAxisCarD+25,yAxisCarD - 27);
    glVertex2f(xAxisCarD+25,yAxisCarD - 29);
    glVertex2f(xAxisCarD+26,yAxisCarD - 29);
    glVertex2f(xAxisCarD+26,yAxisCarD - 27);

    glEnd();

    ///Wheel (Top left)

      glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(xAxisCarD+21,yAxisCarD - 27);
    glVertex2f(xAxisCarD+21,yAxisCarD - 29);
    glVertex2f(xAxisCarD+20,yAxisCarD - 29);
    glVertex2f(xAxisCarD+20,yAxisCarD - 27);

    glEnd();


     ///Wheel (Bottom left)

       glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(xAxisCarD+21,yAxisCarD - 33);
    glVertex2f(xAxisCarD+21,yAxisCarD - 35);
    glVertex2f(xAxisCarD+20,yAxisCarD - 35);
    glVertex2f(xAxisCarD+20,yAxisCarD - 33);

    glEnd();


    ///Wheel (Bottom right)

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(xAxisCarD+25,yAxisCarD - 33);
    glVertex2f(xAxisCarD+25,yAxisCarD - 35);
    glVertex2f(xAxisCarD+26,yAxisCarD - 35);
    glVertex2f(xAxisCarD+26,yAxisCarD - 33);

    glEnd();


    yAxisCarD--;

 if(  abs(xAxisCarD-xAxisMainCar)<=5     ) { if(abs(yAxisCarD )<=44 && abs(yAxisCarB - yAxisMainCar)>=25){Sleep(100);  gameOver=true; }     }


     if(yAxisCarD==25) {   yAxisCarD=147; xAxisCarD=xAxisMainCar-10; } ///Cyan one
///





  /// Main Car
    ///Car's body
glColor3f(0.0f, 1.0f, 0.0f); ///Blue
    glBegin(GL_POLYGON);

 if(yAxisMainCar>=100){   yAxisMainCar=90;  }
 else if(yAxisMainCar<=0){   yAxisMainCar=0;  }

    glVertex2i(23 + xAxisMainCar,yAxisMainCar+10);

    glVertex2i(21 + xAxisMainCar,yAxisMainCar+8);
    glVertex2i(21 + xAxisMainCar,yAxisMainCar );
    glVertex2i(25+ xAxisMainCar,yAxisMainCar);
    glVertex2i(25+ xAxisMainCar,yAxisMainCar+8);
    glEnd();


///Wheel (Top right)

glColor3f(1.0f, 0.0f, 0.0f); ///Red
    glBegin(GL_POLYGON);
    glVertex2f(25+ xAxisMainCar,yAxisMainCar+8);
    glVertex2f(25+ xAxisMainCar,yAxisMainCar+6);
    glVertex2f(26+ xAxisMainCar,yAxisMainCar+6);
    glVertex2f(26+ xAxisMainCar,yAxisMainCar+8);

    glEnd();

    ///Wheel (Top left)

glColor3f(1.0f, 0.0f, 0.0f); ///Red
    glBegin(GL_POLYGON);
    glVertex2f(21 + xAxisMainCar,yAxisMainCar+8);
    glVertex2f(21 + xAxisMainCar,yAxisMainCar+6);
    glVertex2f(20+ xAxisMainCar,yAxisMainCar+6);
    glVertex2f(20+ xAxisMainCar,yAxisMainCar+8);

    glEnd();


     ///Wheel (Bottom left)

glColor3f(1.0f, 0.0f, 0.0f); ///Red
    glBegin(GL_POLYGON);
    glVertex2f(21 + xAxisMainCar,yAxisMainCar+2);
    glVertex2f(21 + xAxisMainCar,yAxisMainCar );
    glVertex2f(20+ xAxisMainCar,yAxisMainCar );
    glVertex2f(20+ xAxisMainCar,yAxisMainCar+2);

    glEnd();


    ///Wheel (Bottom right)

glColor3f(1.0f, 0.0f, 0.0f); ///Red
    glBegin(GL_POLYGON);
    glVertex2f(25+ xAxisMainCar,yAxisMainCar+2);
    glVertex2f(25+ xAxisMainCar,yAxisMainCar );
    glVertex2f(26+ xAxisMainCar,yAxisMainCar );
    glVertex2f(26+ xAxisMainCar,yAxisMainCar+2);

    glEnd();
///


///Score board
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2i(80,100);
    glVertex2i(100,100);
    glVertex2i(100,88);
    glVertex2i(80,88);
    glEnd();



    ///score

char scoreString[50];
    sprintf (scoreString, "SCORE : %d", score);
glColor3f(1.0f, 0.5f, 0.0f);
    renderBitmapString(82,95,(void *)font2,scoreString);

    if(score>highScore)
    {
                glColor3f(1.0f, 0.5f, 0.0f);
                renderBitmapString(82,90,(void *)font4,"NEW HIGHSCORE REACHED");  ///Title
    }
	glFlush();   // Render now
}

void movement(int key, int x, int y)
{
switch (key) {

         case GLUT_KEY_LEFT:
  {
              if(xAxisMainCar>=4)
             {
                 xAxisMainCar-=3;
             }
            break;
  }

          case GLUT_KEY_RIGHT:
  {
       if(xAxisMainCar<=50)
             {
              xAxisMainCar+=3;
             }
            break;
  }

    case GLUT_KEY_UP:
  {

                if(carSpeed<=150)
                {carSpeed+=10;}







break;
  }


    case GLUT_KEY_DOWN:
  {


            if(carSpeed>=50)
                {carSpeed-=15;}







break;
  }






        default: { break; }

        }



}









void primaryCommands(unsigned char key, int x, int y) {

      switch (key)
            {
                case ' ':
            if(gameOver==true)
                {



                    xAxisCarA=12;
                    yAxisCarA=100;
                    xAxisCarB=27;
                    yAxisCarB=100;

                    xAxisCarC=42;
                    yAxisCarC=100;

                    xAxisCarD=35;
                    yAxisCarD=100;

                    home1Index=100;
                    home2Index=100;

                    markerIndex=100;

                    dividerIndex1=100;
                    dividerIndex2=100;
                    dividerIndex3=100;

                    score=0;
                    carSpeed=50;




                    gameOver=false;
            }
             break;

             case 'x':
                 {exit(0);
             break;}




             default:
                {break;}
        }
}





void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(gameOver==false){

        glClearColor(0, 392, 0,1);
        playGame();
    }

    else{
        homePage();
    }
    glFlush();
    glutSwapBuffers();
}




void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/carSpeed,timer,0);
}
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
 glutInit(&argc, argv);

    glutInitWindowSize(1100,650);
    glutInitWindowPosition(200,20);
    glutCreateWindow("Racing Car Game by Rifat and Shahriar");

    glutDisplayFunc(display);// Register display callback handler for window re-paint
 glutSpecialFunc(movement);
 glutKeyboardFunc(primaryCommands);


 glutTimerFunc(1000,timer,0);

    glOrtho(0,100,0,100,-1,1);
    glClearColor(0, 255, 0,1);


	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
