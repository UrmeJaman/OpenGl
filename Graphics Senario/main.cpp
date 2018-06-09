#include<windows.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <math.h>
#include <stdlib.h>
#include <cmath>
//#include <iomanip>
//#include <mmsystem.h>


void input(int, int, int);

using namespace std;



int meghStatus = 0;
int sunStatus = 0;
int moonStatus = 0;
int flagStatus = 0;
int lightStatus = 0;



float sunX = 0;
float sunY = 0;

float moonX = 0;
float moonY = 0;

float cloudX = 0;
float cloudY = 0;
float flagX=0;
float flagY=0;
int carStatus = 0;
float carX=0;
float carY=0;
float lightX=0;
float lightY=0;








void DrawCircle(float cx, float cy, float r, int num_segments) {

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}



void drawSun(int x)
{

    glColor3f(1.000, 0.843, 0.000);
    DrawCircle(900, 1300, 110, 1300);
}
void drawMoon(int x) {
    glColor3f(.9, .9, .9);
    DrawCircle(900, 200, 80, 1300);
}
void moveMoon()
{

if (moonStatus == 0)
    {

        if (moonY >= 1100)
        {
            moonY = 1100;

        }
        else
        {
            moonY +=.6;

        }

    }


    glPushMatrix();

    glTranslatef(moonX, moonY, 0);

    drawMoon(1);
    glPopMatrix();

}



void cloud(int x) {
    if (sunY <= -350)
    {
        glColor3f(.7, .7, .7);
    }
    else {
        glColor3f(1.0, 1.0, 1.0);
    }
    DrawCircle(100, 1300, 60, 2000);//1
    DrawCircle(150, 1350, 60, 2000);//2
    DrawCircle(150, 1250, 60, 2000);//3
    DrawCircle(200, 1300, 80, 2000);//4


    DrawCircle(250, 1250, 60, 2000);//5
    DrawCircle(250, 1350, 60, 2000);//6
    DrawCircle(300, 1300, 55, 2000);//7

    DrawCircle(700, 1300, 60, 2000);//1
    DrawCircle(800, 1300, 80, 2000);//2
    DrawCircle(900, 1300, 55, 2000);//3

    if (sunY <= -350)
    {
        glColor3f(.7, .7, .7);
    }
    else { glColor3f(1.0, 1.0, 1.0); }

    int transfer = 1200;
    DrawCircle(100 + transfer, 1300, 60, 2000);//1
    DrawCircle(150 + transfer, 1350, 60, 2000);//2
    DrawCircle(150 + transfer, 1250, 60, 2000);//3


    DrawCircle(200 + transfer, 1300, 80, 2000);//4
    DrawCircle(250 + transfer, 1250, 60, 2000);//5
    DrawCircle(250 + transfer, 1350, 60, 2000);//6
    DrawCircle(300 + transfer, 1300, 55, 2000);//7
    if (sunY <= -350)
    {
        glColor3f(.7, .7, .7);
    }
    else { glColor3f(1.0, 1.0, 1.0); }
    transfer = 1000;
    DrawCircle(700 + transfer, 1300, 60, 2000);//1
    DrawCircle(800 + transfer, 1300, 80, 2000);//2
    DrawCircle(900 + transfer, 1300, 55, 2000);//3




}
void moveCloud()

{
    if (meghStatus == 0)
    {
        cloudX += .1;
    }
    glPushMatrix();
    glTranslatef(cloudX, cloudY, 0);
    cloud(0.5);
    glPopMatrix();



}

void sky() {

    glBegin(GL_POLYGON); //Sky
    glColor3f(0.34, 0.808, 1.0);
    glVertex2i(2000, 1500);
    glVertex2i(0, 1500);
    glColor3f(2.49, 1.87, 1.0);
    glVertex2i(0, 970);
    glVertex2i(2000, 970);
    glEnd();
  //glColor3f(0.34, 0.808, 1.0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    //glColor3f(0,0,0);
    glVertex2i(0, 0);
    glVertex2i(2000, 0);
    glVertex2i(2000, 970);
    glVertex2i(0,970);
    glEnd();


}
void tree()
{
    //////////////////////////////////////pata
   glColor3ub (51, 204, 51);
    DrawCircle(150, 660, 110, 5000);//1
    DrawCircle(150, 720,80, 6000);//1
    glEnd();
    glFlush();
    ////////////////////////////////majher daal
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(140, 355);
    glVertex2i(160, 355);
    glVertex2i(160, 345);
    glVertex2i(140, 345);
    glEnd();

    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(140, 345);
    glVertex2i(160, 345);
    glVertex2i(160, 570);
    glVertex2i(140, 570);
    glEnd();
    //////////////////////////////////bam daal
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(140, 570);
    glVertex2i(150, 570);
    glVertex2i(140, 610);
    glVertex2i(130, 610);
    glEnd();
    /////////////////////////////////right daal
    glColor3ub (180, 180, 40);
    glBegin(GL_QUADS);
    glVertex2i(150, 570);
    glVertex2i(160, 570);
    glVertex2i(170, 610);
    glVertex2i(160, 610);
    glEnd();
   glFlush();

    /////////////////////////////////////////////////tree shadow
  glColor3ub (77, 77, 51);
    glBegin(GL_QUADS);
    glVertex2i(100, 300);
    glVertex2i(115, 300);
    glVertex2i(150, 344);
    glVertex2i(165, 344);
    glEnd();

    glColor3ub (179, 89, 0);
    DrawCircle(130,300,30,1000);







}
void house()
{
///   left triangle or chal
    glColor3ub (181, 158, 90);
    glBegin(GL_TRIANGLES);
    glVertex2i(20, 400);
    glVertex2i(40, 450);
    glVertex2i(60, 400);
    glEnd();
    //////////////line of chal
    glColor3ub (170, 140, 70);
    glBegin(GL_LINES);
    glVertex2i(25, 400);
    glVertex2i(45, 450);
        //glVertex2i(70, 250);
    //glVertex2i(70, 200);

    glEnd();
    ///////////////////right  chal
    glColor3ub (219, 183, 72);
    glBegin(GL_QUADS);
    glVertex2i(60, 400);
    glVertex2i(140, 400);
    glVertex2i(120, 450);
    glVertex2i(40, 450);
    glEnd();
    //glFlush ();
    ////////////////// left body
    glColor3ub (153, 153, 153);
    glBegin(GL_QUADS);
    glVertex2i(25, 350);
    glVertex2i(60, 350);
    glVertex2i(60, 400);
    glVertex2i(25, 400);
    glEnd();
    ///////////right body
   glColor3ub (180, 180, 180);
    glBegin(GL_QUADS);
    glVertex2i(60, 350);
    glVertex2i(135, 350);
    glVertex2i(135, 400);
    glVertex2i(60, 400);
    glEnd();

    ///////////////////right body janala (left)
    glColor3ub (90, 90, 90);
    glBegin(GL_QUADS);
    glVertex2i(65, 360);
    glVertex2i(80, 360);
    glVertex2i(80, 387);
    glVertex2i(65, 387);
    glEnd();
    /////////////////////right body janala (right)
   glColor3ub (90, 90, 90);
    glBegin(GL_QUADS);
    glVertex2i(115, 360);
    glVertex2i(110, 360);
    glVertex2i(110, 387);
    glVertex2i(115, 387);
    glEnd();
    ////////////left body janala
    glColor3ub (90, 90, 90);
    glBegin(GL_QUADS);
    glVertex2i(35, 360);
    glVertex2i(50, 360);
    glVertex2i(50, 387);
    glVertex2i(35, 387);
    glEnd();
    //glFlush ();
    ////right body door
    glColor3ub (90, 90, 90);
    glBegin(GL_QUADS);
    glVertex2i(100, 355);
    glVertex2i(115, 355);
    glVertex2i(115, 390);
    glVertex2i(100, 390);
    glEnd();

    /////////////////////////////////////////
    ////////////////////////////////////////////////////left home shadow
    glColor3ub (179, 89, 0);
    glBegin(GL_QUADS);
    glVertex2i(10, 300);
    glVertex2i(120, 300);
    glVertex2i(135, 350);
    glVertex2i(25, 350);
    glEnd();
   // glFlush ();
    ////
    ////////////////////////////////////////////////////////////////right home
    /////////////front side
    glColor3ub (180, 180, 180);
    glBegin(GL_QUADS);
    glVertex2i(160, 270);
    glVertex2i(260, 270);
    glVertex2i(260, 330);
    glVertex2i(160, 330);
    glEnd();
    ///////////////////front door
    glColor3ub (153, 1, 153);
    glBegin(GL_QUADS);
    glVertex2i(200, 275);
    glVertex2i(220, 275);
    glVertex2i(220, 310);
    glVertex2i(200, 310);
    glEnd();
    ////////////////////////left janala
    glColor3ub (153, 1, 153);
    glBegin(GL_QUADS);
    glVertex2i(170, 285);
    glVertex2i(180, 285);
    glVertex2i(180, 305);
    glVertex2i(170, 305);
    glEnd();
    ///////////////////////////right janala
    glColor3ub (153, 1, 153);
    glBegin(GL_QUADS);
    glVertex2i(240, 285);
    glVertex2i(250, 285);
    glVertex2i(250, 305);
    glVertex2i(240, 305);
    glEnd();
    glFlush();
     //////////////right  side
    glColor3ub (153, 153, 153);
    glBegin(GL_QUADS);
    glVertex2i(260, 270);
    glVertex2i(290, 320);
    glVertex2i(290, 380);
    glVertex2i(260, 330);
    glEnd();
    glFlush();
    /////////////////down roof
    glColor3ub (219, 183, 72);
    glBegin(GL_QUADS);
    glVertex2i(160, 330);
    glVertex2i(260, 330);
    glVertex2i(265, 350);
    glVertex2i(165, 350);
    glEnd();
    glFlush();
    ///////////////////upper body
    glColor3ub (180, 180, 180);
    glBegin(GL_QUADS);
    glVertex2i(165, 350);
    glVertex2i(265, 350);
    glVertex2i(265, 380);
    glVertex2i(165, 380);
    glEnd();
    glFlush();
    /////////////////////////upper body janala
    glColor3ub (153, 1, 153);
    glBegin(GL_QUADS);
    glVertex2i(190, 360);
    glVertex2i(240, 360);
    glVertex2i(240, 370);
    glVertex2i(190, 370);
    glEnd();
    glFlush();
     ///////////////////////////////////right upper side
    glColor3ub (153, 153, 153);
    glBegin(GL_POLYGON);
    glVertex2i(265, 350);
    glVertex2i(260, 330);
    glVertex2i(290, 380);
    glVertex2i(290, 420);
    glVertex2i(265, 380);
    glEnd();
    glFlush();
    ///////////////////////////////top roof
    glColor3ub (219, 183, 72);
    glBegin(GL_QUADS);
    glVertex2i(165, 380);
    glVertex2i(265, 380);
    glVertex2i(275, 430);
    glVertex2i(180, 430);
    glEnd();
    glFlush();
    ///////////////////top triangle
    glColor3ub (153, 153, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(265, 380);
    glVertex2i(275, 430);
    glVertex2i(290, 420);
    glEnd();
    glFlush();
    //////////////////lines
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(165, 350);
    glVertex2i(265, 350);
    glEnd();
    glFlush();

}




void car(int x)
{


    glColor3ub(255, 0, 0);///////////back
    glBegin(GL_QUADS);
    glVertex2i(20, 120);
    glVertex2i(20, 140);
    glVertex2i(10, 170);
    glVertex2i(10, 150);
    glEnd();
    ////////////////////////////////line
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(20, 120);
    glVertex2i(20, 140);

    glVertex2i(20, 140);
    glVertex2i(10, 170);

    glVertex2i(10, 170);
    glVertex2i(10, 150);

    glVertex2i(10, 150);
    glVertex2i(20, 120);
    glEnd();

    glColor3ub(255,0,0);/////////////dikki
    glBegin(GL_QUADS);
    glVertex2i(20, 140);
    glVertex2i(40, 140);
    glVertex2i(29, 170);
    glVertex2i(10, 170);
    glEnd();
    //////////////////////////////////line
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(20, 140);
    glVertex2i(40, 140);

    glVertex2i(40, 140);
    glVertex2i(29, 170);

    glVertex2i(29, 170);
    glVertex2i(10, 170);

    glVertex2i(20, 140);
    glVertex2i(10, 170);
    glEnd();
    /////////////////
    glColor3ub(255, 255, 255);/////////back window
    glBegin(GL_QUADS);
    glVertex2i(40, 140);
    glVertex2i(55, 160);
    glVertex2i(43, 190);
    glVertex2i(29, 170);
    glEnd();
    ///////////////////////////////line
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(40, 140);
    glVertex2i(55, 160);

    glVertex2i(55, 160);
    glVertex2i(43, 190);

    glVertex2i(43, 190);
    glVertex2i(29, 170);

    glVertex2i(29, 170);
    glVertex2i(40, 140);
    glEnd();

    ///////////////
    glColor3ub(255,0,0);/////////roof
    glBegin(GL_QUADS);
    glVertex2i(55, 160);
    glVertex2i(91, 160);
    glVertex2i(77, 190);
    glVertex2i(43, 190);
    glEnd();
    ///////////////////////////////////////line

    glColor3ub(0,0,0);
    //glLineWidth(20.0f);
    glBegin(GL_LINES);
    glVertex2i(55, 160);
    glVertex2i(91, 160);

    glVertex2i(91, 160);
    glVertex2i(77, 190);

    glVertex2i(77, 190);
    glVertex2i(43, 190);

    glVertex2i(43, 190);
    glVertex2i(55, 160);
    glEnd();

    /////////////
    glColor3ub(255,0,0);/////////door er nicher ongsho
    glBegin(GL_QUADS);
    glVertex2i(20, 120);
    glVertex2i(140, 120);
    glVertex2i(140, 140);
    glVertex2i(20, 140);
    glEnd();
    ////////////////////////lines
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(20, 120);
    glVertex2i(140, 120);

    glVertex2i(140, 120);
    glVertex2i(140, 140);

    glVertex2i(140, 140);
    glVertex2i(20, 140);

    glVertex2i(20, 140);
    glVertex2i(20, 120);
    glEnd();
    //////////

    glColor3ub(255,0,0);/////////bonet
    glBegin(GL_QUADS);
    glVertex2i(100, 140);
    glVertex2i(140, 140);
    glVertex2i(124, 170);
    glVertex2i(86, 170);
    glEnd();
    ///////////////////////////////////lines
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2i(100, 140);
    glVertex2i(140, 140);

    glVertex2i(124, 170);
    glVertex2i(140, 140);

    glVertex2i(86, 170);
    glVertex2i(124, 170);

    glVertex2i(86, 170);
    glVertex2i(100, 140);
    glEnd();

    glColor3ub (227, 247, 244);    /////////doors
    glBegin(GL_POLYGON);
    glVertex2i(40, 140);
    glVertex2i(100, 140);
    glVertex2i(91, 160);
    glVertex2i(55, 160);
    glEnd();
    ///////////////////////////lines
    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(40, 140);
    glVertex2i(100, 140);

    glVertex2i(100, 140);
    glVertex2i(91, 160);

    glVertex2i(91, 160);
    glVertex2i(55, 160);

    glVertex2i(55, 160);
    glVertex2i(40, 140);

    glVertex2i(72, 140);
    glVertex2i(72, 160);
    glEnd();
    carStatus=0;
}
void river()
{


    glColor3ub (142, 227, 227);
    glBegin(GL_QUADS);
    glVertex2i(0, 550);
    glVertex2i(2000, 550);
    glVertex2i(2000, 750);
    glVertex2i(0, 750);
    glEnd();




}

void hills()
{
    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);///////// gradually from left
    glVertex2i(190, 750);
    glVertex2i(230, 790);
    glVertex2i(270, 750);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(190, 750);
    glVertex2i(230, 790);

    glVertex2i(230, 790);
    glVertex2i(270, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(250, 750);
    glVertex2i(280, 780);
    glVertex2i(310, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(290, 750);
    glVertex2i(380, 750);
    glVertex2i(335, 800);
    glEnd();
    //////////////line shape


    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(370, 750);
    glVertex2i(430, 800);
    glVertex2i(490, 750);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(370, 750);
    glVertex2i(430, 800);

    glVertex2i(430, 800);
    glVertex2i(490, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(480, 750);
    glVertex2i(530, 775);
    glVertex2i(580, 750);

    glEnd();


    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);///////// gradually from left
    glVertex2i(590, 750);
    glVertex2i(630, 790);
    glVertex2i(670, 750);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(690, 750);
    glVertex2i(630, 790);

    glVertex2i(630, 790);
    glVertex2i(670, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(650, 750);
    glVertex2i(680, 780);
    glVertex2i(710, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(690, 750);
    glVertex2i(780, 750);
    glVertex2i(735, 800);
    glEnd();
    //////////////line shape


    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(770, 750);
    glVertex2i(830, 800);
    glVertex2i(890, 750);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(770, 750);
    glVertex2i(830, 800);

    glVertex2i(830, 800);
    glVertex2i(890, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(880, 750);
    glVertex2i(930, 775);
    glVertex2i(980, 750);

    glEnd();





    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);///////// gradually from left
    glVertex2i(290, 750);
    glVertex2i(330, 790);
    glVertex2i(370, 750);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(390, 750);
    glVertex2i(330, 790);

    glVertex2i(330, 790);
    glVertex2i(370, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(350, 750);
    glVertex2i(380, 780);
    glVertex2i(410, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(390, 750);
    glVertex2i(480, 750);
    glVertex2i(435, 800);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);


    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(470, 750);
    glVertex2i(530, 800);
    glVertex2i(590, 750);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(470, 750);
    glVertex2i(530, 800);

    glVertex2i(530, 800);
    glVertex2i(590, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(580, 750);
    glVertex2i(630, 775);
    glVertex2i(680, 750);

    glEnd();



       glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);///////// gradually from left
    glVertex2i(1190, 750);
    glVertex2i(1230, 790);
    glVertex2i(1270, 750);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(1290, 750);
    glVertex2i(1230, 790);

    glVertex2i(1230, 790);
    glVertex2i(1270, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(1250, 750);
    glVertex2i(1280, 780);
    glVertex2i(1310, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(1290, 750);
    glVertex2i(1380, 750);
    glVertex2i(1335, 800);
    glEnd();
    //////////////line shape
//line shape


       glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);///////// gradually from left
    glVertex2i(890, 750);
    glVertex2i(930, 790);
    glVertex2i(970, 750);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(990, 750);
    glVertex2i(930, 790);

    glVertex2i(930, 790);
    glVertex2i(970, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(950, 750);
    glVertex2i(980, 780);
    glVertex2i(1010, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(990, 750);
    glVertex2i(1080, 750);
    glVertex2i(1035, 800);
    glEnd();
    //////////////line shape



    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(1070, 750);
    glVertex2i(1130, 800);
    glVertex2i(1190, 750);
    glEnd();
    //////////////line shape
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2i(1170, 750);
    glVertex2i(1130, 800);

    glVertex2i(1130, 800);
    glVertex2i(1190, 750);
    glEnd();

    glColor3ub(0, 0, 153);
    glBegin(GL_TRIANGLES);
    glVertex2i(1180, 750);
    glVertex2i(1130, 775);
    glVertex2i(1180, 750);

    glEnd();


    glFlush();
}
///////////

void star()
{
    int x = 0;int y = 0;
    for (x = 0, y = 0;x < 1000, y < 500;x = x + 110, y = y + 60)
    {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(100.0 + x, 1085.0 + y);
        glVertex2f(85.0 + x, 1115.0 + y);
        glVertex2f(115.0 + x, 1115.0 + y);

        glEnd();


        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        glVertex2f(100.0 + x, 1125.0 + y);
        glVertex2f(85.0 + x, 1100.0 + y);
        glVertex2f(115.0 + x, 1100.0 + y);
        glEnd();
    }
        for (x = 900, y = 0;x<2000, y<500;x = x + 110, y = y + 60)
        {
            glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_TRIANGLES);
            glVertex2f(100.0 + x, 1085.0 + y);
            glVertex2f(85.0 + x, 1115.0 + y);
            glVertex2f(115.0 + x, 1115.0 + y);

            glEnd();

            glColor3f(1.0, 1.0, 1.0);
            glBegin(GL_TRIANGLES);
            glVertex2f(100.0 + x, 1125.0 + y);
            glVertex2f(85.0 + x, 1100.0 + y);
            glVertex2f(115.0 + x, 1100.0 + y);
            glEnd();
        }


}

void field (){


glColor3ub (0, 255, 64);
    glBegin(GL_QUADS);
    glVertex2i(0, 250);
    glVertex2i(2000, 250);
    glVertex2i(2000, 550);
    glVertex2i(0, 550);
    glEnd();
    glFlush();
    //////////////




}


void mainfield()
{
//road

glColor3ub (87, 81, 92);
    glBegin(GL_QUADS);
    glVertex2i(0, 0);
    glVertex2i(2000, 0);
    glVertex2i(2000, 250);
    glVertex2i(0, 250);
    glEnd();
    glFlush();
    //////////////////////////////////////roads i-land

    /////////////////////////////////road er majher daag
    glColor3ub (252, 252, 252);
    //glLineWidth(20.0f);
    glBegin(GL_LINES);
    glVertex2i(0, 125);
    glVertex2i(40, 125);
    glVertex2i(80, 125);
    glVertex2i(120, 125);
    glVertex2i(160, 125);
    glVertex2i(200, 125);
    glVertex2i(240, 125);
    glVertex2i(280, 125);
    glVertex2i(320, 125);
    glVertex2i(360, 125);
    glVertex2i(400, 125);
    glVertex2i(440, 125);
    glVertex2i(480, 125);
    glVertex2i(520, 125);
    glVertex2i(560, 125);
    glVertex2i(600, 125);
    glVertex2i(640, 125);
    glVertex2i(680, 125);
    glVertex2i(720, 125);
    glVertex2i(760, 125);
    glVertex2i(800, 125);
    glVertex2i(840, 125);
    glVertex2i(880, 125);
    glVertex2i(920, 125);
    glVertex2i(960, 125);
     glVertex2i(1000, 125);
    glVertex2i(1040, 125);
     glVertex2i(1080, 125);
    glVertex2i(1120, 125);
     glVertex2i(1160, 125);
    glVertex2i(1200, 125);
     glVertex2i(1240, 125);
    glVertex2i(1280, 125);
     glVertex2i(1320, 125);
    glVertex2i(1360, 125);
     glVertex2i(1400, 125);
    glVertex2i(1440, 125);
     glVertex2i(1480, 125);
    glVertex2i(1520, 125);
     glVertex2i(1540, 125);
    glVertex2i(1580, 125);
     glVertex2i(1620, 125);
    glVertex2i(1660, 125);
     glVertex2i(1700, 125);
    glVertex2i(1740, 125);
     glVertex2i(1780, 125);
    glVertex2i(1820, 125);
     glVertex2i(1860, 125);
    glVertex2i(1900, 125);
     glVertex2i(1940, 125);
    glVertex2i(1980, 125);

    glEnd();
    glFlush();



}

void skynight() {

    if (sunY <= -500)
    {
        glColor3f(0.0, 0.0, 0.0);


    }


    else if (sunY <= -150)//Green Yellow
    {
        glColor3f(1.000, 0.843, 0.00);
    }


    glBegin(GL_POLYGON); //Sky

    glVertex2i(2000, 1500);
    glVertex2i(0, 1500);
    glColor3f(2.49, 1.87, 1.0);
    glVertex2i(0, 970);
    glVertex2i(2000, 970);
    glEnd();


}

void moveSun()
{


    if (sunStatus == 0)

    {
        sunY -= .50;

    }

    glPushMatrix();

    glTranslatef(sunX, sunY, 0);

    drawSun(1);
    glPopMatrix();

}

void ship(int x ){

glBegin(GL_QUADS);

   ///ultra instinct gray
   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0f, 0.0f, 0.0f);
   glVertex2i(200, 550);
   glVertex2i(400, 550);
    glVertex2i(600, 650);
   glVertex2i(0, 650);
   glEnd();

   glBegin(GL_QUADS);
  glColor3ub(115, 77, 38);
   glVertex2i(50, 650);
   glVertex2i(550, 650);
   glVertex2i(550, 700);
   glVertex2i(50, 700);

    //glVertex2i(250, 700);
   //glVertex2i(450, 700);
glEnd();




glBegin(GL_QUADS);
glColor3ub(115, 38, 38);

   glVertex2i(285, 650);
   glVertex2i(315, 650);
   glVertex2i(315, 695);
   glVertex2i(285, 695);
   glEnd();

   //saparate 2nd flor

glBegin(GL_QUADS);
  glColor3f(0.5f, 0.5f, 0.5f);

   glVertex2i(150, 700);
   //glVertex2i(150, 700);
   glVertex2i(450, 700);

    glVertex2i(450, 750);
    glVertex2i(150, 750);
   //glVertex2i(450, 700);
glEnd();

glBegin(GL_QUADS);
glColor3ub(115, 77, 38);

   glVertex2i(295, 750);
   glVertex2i(305, 750);
   glVertex2i(305, 840);

    glVertex2i(295, 840);
    glEnd();




    glBegin(GL_QUADS);
glColor3ub(64, 255, 0);

   glVertex2i(300, 790);
   glVertex2i(340, 790);
   glVertex2i(340, 840);
   glVertex2i(300, 840);
    glEnd();
   glColor3ub(255, 0, 0);
    DrawCircle(320, 810, 8, 13);







glFlush();


}
void movecar()
{
    if (carStatus ==1)
    {

        carX -= 3;

        if (carX<10)
    {
        carX = 0;
    }
         ///////speed
    }
    else if (carStatus==2){


        carX+=4;
        //PlaySound(TEXT("sound"), NULL, SND_ASYNC | SND_FILENAME);
    }
    if (carX>1980)
    {
        carX = 0;

    }


    glPushMatrix();
    glTranslatef(carX, carY, 0);
    car(1);

    glPopMatrix();
}
void SpecialKey(int key,int carX,int carY){

switch (key){

case GLUT_KEY_LEFT:

    carStatus=1;

     glutPostRedisplay();
    break;

case   GLUT_KEY_RIGHT:

     carStatus=2;
    glutPostRedisplay();
    break;

case GLUT_KEY_HOME:
     PlaySound(TEXT("hiss"),NULL,SND_ASYNC|SND_FILENAME);
     break;
case GLUT_KEY_UP:
     lightStatus=1;
    glutPostRedisplay();
    break;
case GLUT_KEY_DOWN:
     lightStatus=0;
    glutPostRedisplay();
break;

default:
  carX=0;

}

}


void moveShip()
{


    if (flagStatus == 0)

    {
        flagX += .50;

    }
 if (flagX>1990){
        flagX=0;
    }
    glPushMatrix();

    glTranslatef(flagX, flagY, 0);


    ship(1);
    glPopMatrix();

}


void lampPost()
{
    //verticle
    glColor3ub(222,250,50);
    //glColor3ub (0, 255, 64);


    glBegin(GL_QUADS);
    glVertex2i(334, 250);
    glVertex2i(344, 250);
    glVertex2i(344, 520);
    glVertex2i(334,520);
    glEnd();



    glBegin(GL_QUADS);
    glVertex2i(334, 520);
    glVertex2i(434, 520);
    glVertex2i(434, 530);
    glVertex2i(334, 530);
    glEnd();
glBegin(GL_TRIANGLES);
     glColor3ub(222,250,50);
    glVertex2i(404, 510);
    glVertex2i(444, 510);
    glVertex2i(424, 530);
    glEnd();

//2nd
     glBegin(GL_QUADS);
    glVertex2i(668, 250);
    glVertex2i(678, 250);
    glVertex2i(678, 520);
    glVertex2i(668, 520);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(668, 520);
    glVertex2i(778, 520);
    glVertex2i(778, 530);
    glVertex2i(668, 530);
    glEnd();
    glBegin(GL_TRIANGLES);
     glColor3ub(222,250,50);
    glVertex2i(748, 510);
    glVertex2i(788, 510);
    glVertex2i(768, 530);
    glEnd();

//3rd
     glBegin(GL_QUADS);
    glVertex2i(1002, 250);
    glVertex2i(1012, 250);
    glVertex2i(1012, 520);
    glVertex2i(1002, 520);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(1002, 520);
    glVertex2i(1112, 520);
    glVertex2i(1112, 530);
    glVertex2i(1002, 530);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3ub(222,250,50);
    glVertex2i(1082, 510);
    glVertex2i(1122, 510);
    glVertex2i(1102, 530);
    glEnd();
//4th
     glBegin(GL_QUADS);
    glVertex2i(1336, 250);
    glVertex2i(1346, 250);
    glVertex2i(1346, 520);
    glVertex2i(1336, 520);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(1336, 520);
    glVertex2i(1446, 520);
    glVertex2i(1446, 530);
    glVertex2i(1336, 530);
    glEnd();
glBegin(GL_TRIANGLES);
     glColor3ub(222,250,50);
    glVertex2i(1416, 510);
    glVertex2i(1456, 510);
    glVertex2i(1436, 530);
    glEnd();
//last
     glBegin(GL_QUADS);
    glVertex2i(1670, 250);
    glVertex2i(1680, 250);
    glVertex2i(1680, 520);
    glVertex2i(1670, 520);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(1670, 520);
    glVertex2i(1780, 520);
    glVertex2i(1780, 530);
    glVertex2i(1670, 530);
    glEnd();
    glBegin(GL_TRIANGLES);
     glColor3ub(222,250,50);
    glVertex2i(1750, 510);
    glVertex2i(1790, 510);
    glVertex2i(1770, 530);
    glEnd();



    //horizontal
    glFlush();
}
//light
void Light()
{
if (lightStatus==1){



      //fst
    glBegin(GL_TRIANGLES);
     glColor3ub(222,250,150);
    glVertex2i(344, 300);
    glVertex2i(514, 300);
    glVertex2i(424, 510);
    glEnd();
//2nd
     glBegin(GL_TRIANGLES);
     glColor3ub(222,250,150);
    glVertex2i(678, 300);
    glVertex2i(858, 300);
    glVertex2i(768, 510);
    glEnd();

//3rd
   glBegin(GL_TRIANGLES);
     glColor3ub(222,250,50);
    glVertex2i(1012, 300);
    glVertex2i(1192, 300);
    glVertex2i(1102, 510);
    glEnd();
//4th

glBegin(GL_TRIANGLES);
     glColor3ub(222,250,150);
    glVertex2i(1346, 300);
    glVertex2i(1526, 300);
    glVertex2i(1436, 510);
    glEnd();
    //last light
    glBegin(GL_TRIANGLES);
     glColor3ub(222,250,150);
    glVertex2i(1680, 300);
    glVertex2i(1860, 300);
    glVertex2i(1770, 510);
    glEnd();





}







}



void myDisplay(void)
{
    sky();

    if (sunY <= -200)
    {
        skynight();


    }

    if (sunY <= -425)
    {
        star();
    }




    moveCloud();

    moveSun();
    moveMoon();
river();
//ship();
 //house();
//moveShip();
mainfield();
field();
hills();
house();
movecar();
moveShip();
lampPost();
tree();

//rainf();
Light();

    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
   // glutSpecialFunc(SpecialKey);
}
void myInit(void)
{
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glColor3f(1.0f, 1.0f, 0.0f);
    glPointSize(0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 2000.0, 0.0, 1500.0);
}
int main(int argc, char** argv)
{


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(2000, 1500);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Day_Night");

    glutDisplayFunc(myDisplay);

glutSpecialFunc(SpecialKey);

    myInit();
//PlaySound(TEXT("sound.wav"),NULL,SND_ASYNC|SND_FILENAME);


    glutMainLoop();

}

