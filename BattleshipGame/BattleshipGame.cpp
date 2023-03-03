                                    
                            /* BattleShip2 -- Maham Imran SE-F 22I2733 */

#define GL_SILENCE_DEPRECATION
// will silence deprecation warning on macos
#ifndef BATTLESHIP2_CPP_
#define BATTLESHIP2_CPP_
#include "header.hpp"
#include <iostream>
#include<string>
#include<cmath> 
#include <fstream>
#include <unistd.h>
using namespace std;

void DisplayLeaderboard(string, int,string,string [], int[]);
void sort(int [],int,int,string [],string);
void displayarrays(string [], int []);
void updatetextfile(string,int [],string []);
void startgame();
void grid(int gridx,int gridy, int startx, int starty, double c1, double c2, double c3);
void unit(int x, int y, double c1, double c2, double c3);
void PrintableKeys(unsigned char key, int x, int y);
void MouseClick2(int button, int state, int x, int y);
void MouseClicked(int button, int state, int x, int y);




void SetCanvasSize(int width, int height)
{
    // set the screen size to given width and height.
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
}

bool flag1 = false;
bool flag2 = false;
bool flag3 = false;
bool flag4 = false;
bool flag5 = false;
bool flag6 = false;
bool flag7 = false;
bool flag8 = false;
bool flag9 = false;
bool flag10 = false;

void drawbomb(int x, int y)
{
    DrawCircle(x, y, 35, colors[BLACK]);
    DrawRectangle(x, y+20, 5, 30, colors[GOLD]);
    DrawCircle(x+3, y+20, 3, colors[RED]);
}


void EnemyShip1()
{
        int E1x = 1500, E1y = 1000;
        DrawTriangle(E1x+25,E1y+50, E1x+100, E1y , E1x+100,E1y+100, colors[RED]);
        DrawSquare(E1x+100,E1y,100,colors[RED]);
        DrawSquare(E1x+200,E1y,100,colors[RED]);
        DrawSquare(E1x+300,E1y,100,colors[RED]);
}

void EnemyShip2()
{
    int E2x = 1300, E2y = 1100;
    DrawTriangle(E2x+50,E2y+75, E2x, E2y,E2x+100,E2y, colors[RED]);
    DrawSquare(E2x,E2y-100,100,colors[RED]);
    DrawSquare(E2x,E2y-200,100,colors[RED]);
}

void EnemyShip3()
{
    int E3x = 1800, E3y = 800;
    DrawTriangle(E3x+50,E3y+75, E3x, E3y,E3x+100,E3y, colors[RED]);
    DrawSquare(E3x,E3y-100,100,colors[RED]);
    DrawSquare(E3x,E3y-200,100,colors[RED]);
}

void EnemyShip4()
{
    int E4x = 2000, E4y = 500;
    DrawTriangle(E4x+25,E4y+50, E4x+100, E4y , E4x+100,E4y+100, colors[RED]);
    DrawSquare(E4x+100,E4y,100,colors[RED]);
}

void EnemyShip5()
{
    int E5x = 2000, E5y = 800;
    DrawTriangle(E5x+25,E5y+50, E5x+100, E5y , E5x+100,E5y+100, colors[RED]);
    DrawSquare(E5x+100,E5y,100,colors[RED]);
}

void EnemyShip6()
{
    int E6x = 1600, E6y = 400;
    DrawTriangle(E6x+50,E6y+75, E6x, E6y,E6x+100,E6y, colors[RED]);
    DrawSquare(E6x,E6y-100,100,colors[RED]);
}

void EnemyShip7()
{
    int E7x = 1400, E7y = 300;
    DrawTriangle(E7x+50,E7y+75, E7x, E7y,E7x+100,E7y, colors[RED]);
}

void EnemyShip8()
{
    int E8x = 1400, E8y = 500;
    DrawTriangle(E8x+50,E8y+75, E8x, E8y,E8x+100,E8y, colors[RED]);
}

void EnemyShip9()
{
    int E9x = 1800, E9y = 400;
    DrawTriangle(E9x+25,E9y+50, E9x+100, E9y , E9x+100,E9y+100, colors[RED]);
}

void EnemyShip10()
{
    int E10x = 2100, E10y = 200;
    DrawTriangle(E10x+25,E10y+50, E10x+100, E10y , E10x+100,E10y+100, colors[RED]);
}
int total_score0 = -1;
string colorofship = "";
int B1x = 1600, B1y = 1000; // initial coordinates battleship 1
void drawBattleship1()
{
    // drawing first battleship size 4
    // B1x = 1600, B1y = 1000
    if(colorofship == "blue")
    {
        if(flag1 == false)
        {
            DrawTriangle(B1x+25,B1y+50, B1x+100, B1y , B1x+100,B1y+100, colors[TURQUOISE]);
            DrawSquare(B1x+100,B1y,100,colors[TURQUOISE]);
            DrawSquare(B1x+200,B1y,100,colors[TURQUOISE]);
            DrawSquare(B1x+300,B1y,100,colors[TURQUOISE]);
        }
        else
        {
            DrawTriangle(B1x+50,B1y+75, B1x, B1y,B1x+100,B1y, colors[TURQUOISE]);
            DrawSquare(B1x,B1y-100,100,colors[TURQUOISE]);
            DrawSquare(B1x,B1y-200,100,colors[TURQUOISE]);
            DrawSquare(B1x,B1y-300,100,colors[TURQUOISE]);
        }
    }
    if(colorofship == "gold")
    {
        if(flag1 == false)
        {
            DrawTriangle(B1x+25,B1y+50, B1x+100, B1y , B1x+100,B1y+100, colors[GOLD]);
            DrawSquare(B1x+100,B1y,100,colors[GOLD]);
            DrawSquare(B1x+200,B1y,100,colors[GOLD]);
            DrawSquare(B1x+300,B1y,100,colors[GOLD]);
        }
        else
        {
            DrawTriangle(B1x+50,B1y+75, B1x, B1y,B1x+100,B1y, colors[GOLD]);
            DrawSquare(B1x,B1y-100,100,colors[GOLD]);
            DrawSquare(B1x,B1y-200,100,colors[GOLD]);
            DrawSquare(B1x,B1y-300,100,colors[GOLD]);
        }
    }
    if(colorofship == "violet")
    {
        if(flag1 == false)
        {
            DrawTriangle(B1x+25,B1y+50, B1x+100, B1y , B1x+100,B1y+100, colors[MEDIUM_PURPLE]);
            DrawSquare(B1x+100,B1y,100,colors[MEDIUM_PURPLE]);
            DrawSquare(B1x+200,B1y,100,colors[MEDIUM_PURPLE]);
            DrawSquare(B1x+300,B1y,100,colors[MEDIUM_PURPLE]);
        }
        else
        {
            DrawTriangle(B1x+50,B1y+75, B1x, B1y,B1x+100,B1y, colors[MEDIUM_PURPLE]);
            DrawSquare(B1x,B1y-100,100,colors[MEDIUM_PURPLE]);
            DrawSquare(B1x,B1y-200,100,colors[MEDIUM_PURPLE]);
            DrawSquare(B1x,B1y-300,100,colors[MEDIUM_PURPLE]);
        }
    }
    if(colorofship == "grey")
    {
        if(flag1 == false)
        {
            DrawTriangle(B1x+25,B1y+50, B1x+100, B1y , B1x+100,B1y+100, colors[DARK_GRAY]);
            DrawSquare(B1x+100,B1y,100,colors[DARK_GRAY]);
            DrawSquare(B1x+200,B1y,100,colors[DARK_GRAY]);
            DrawSquare(B1x+300,B1y,100,colors[DARK_GRAY]);
        }
        else
        {
            DrawTriangle(B1x+50,B1y+75, B1x, B1y,B1x+100,B1y, colors[DARK_GRAY]);
            DrawSquare(B1x,B1y-100,100,colors[DARK_GRAY]);
            DrawSquare(B1x,B1y-200,100,colors[DARK_GRAY]);
            DrawSquare(B1x,B1y-300,100,colors[DARK_GRAY]);
        }
    }
    
        glutPostRedisplay();
}
int B2x = 1500, B2y = 800; // initial coordinates battleship 2
void drawBattleship2()
{
    // drawing second battleship size 3
    // B2x = 1500, B2y = 800
    if(colorofship == "blue")
    {
        if(flag2 == false)
        {
            DrawTriangle(B2x+25,B2y+50, B2x+100, B2y , B2x+100,B2y+100, colors[TURQUOISE]);
            DrawSquare(B2x+100,B2y,100,colors[TURQUOISE]);
            DrawSquare(B2x+200,B2y,100,colors[TURQUOISE]);
        }
        else
        {
            DrawTriangle(B2x+50,B2y+75, B2x, B2y,B2x+100,B2y, colors[TURQUOISE]);
            DrawSquare(B2x,B2y-100,100,colors[TURQUOISE]);
            DrawSquare(B2x,B2y-200,100,colors[TURQUOISE]);
        }
    }
    if(colorofship == "gold")
    {
        if(flag2 == false)
        {
            DrawTriangle(B2x+25,B2y+50, B2x+100, B2y , B2x+100,B2y+100, colors[GOLD]);
            DrawSquare(B2x+100,B2y,100,colors[GOLD]);
            DrawSquare(B2x+200,B2y,100,colors[GOLD]);
        }
        else
        {
            DrawTriangle(B2x+50,B2y+75, B2x, B2y,B2x+100,B2y, colors[GOLD]);
            DrawSquare(B2x,B2y-100,100,colors[GOLD]);
            DrawSquare(B2x,B2y-200,100,colors[GOLD]);
        }
    }
    if(colorofship == "violet")
    {
        if(flag2 == false)
        {
            DrawTriangle(B2x+25,B2y+50, B2x+100, B2y , B2x+100,B2y+100, colors[MEDIUM_PURPLE]);
            DrawSquare(B2x+100,B2y,100,colors[MEDIUM_PURPLE]);
            DrawSquare(B2x+200,B2y,100,colors[MEDIUM_PURPLE]);
        }
        else
        {
            DrawTriangle(B2x+50,B2y+75, B2x, B2y,B2x+100,B2y, colors[MEDIUM_PURPLE]);
            DrawSquare(B2x,B2y-100,100,colors[MEDIUM_PURPLE]);
            DrawSquare(B2x,B2y-200,100,colors[MEDIUM_PURPLE]);
        }
    }
    if(colorofship == "grey")
    {
        if(flag2 == false)
        {
            DrawTriangle(B2x+25,B2y+50, B2x+100, B2y , B2x+100,B2y+100, colors[DARK_GRAY]);
            DrawSquare(B2x+100,B2y,100,colors[DARK_GRAY]);
            DrawSquare(B2x+200,B2y,100,colors[DARK_GRAY]);
        }
        else
        {
            DrawTriangle(B2x+50,B2y+75, B2x, B2y,B2x+100,B2y, colors[DARK_GRAY]);
            DrawSquare(B2x,B2y-100,100,colors[DARK_GRAY]);
            DrawSquare(B2x,B2y-200,100,colors[DARK_GRAY]);
        }
    }
    glutPostRedisplay();
}

int B3x = 1800, B3y = 800; // initial coordinates battleship 3
void drawBattleship3()
{
    // drawing third battleship size 3
    // B3x = 1800, B3y = 800
    if(colorofship == "blue")
    {
        if(flag3 == false)
        {
            DrawTriangle(B3x+25,B3y+50, B3x+100, B3y , B3x+100,B3y+100, colors[TURQUOISE]);
            DrawSquare(B3x+100,B3y,100,colors[TURQUOISE]);
            DrawSquare(B3x+200,B3y,100,colors[TURQUOISE]);
        }
        else
        {
            DrawTriangle(B3x+50,B3y+75, B3x, B3y,B3x+100,B3y, colors[TURQUOISE]);
            DrawSquare(B3x,B3y-100,100,colors[TURQUOISE]);
            DrawSquare(B3x,B3y-200,100,colors[TURQUOISE]);
        }
    }
    if(colorofship == "gold")
    {
        if(flag3 == false)
        {
            DrawTriangle(B3x+25,B3y+50, B3x+100, B3y , B3x+100,B3y+100, colors[GOLD]);
            DrawSquare(B3x+100,B3y,100,colors[GOLD]);
            DrawSquare(B3x+200,B3y,100,colors[GOLD]);
        }
        else
        {
            DrawTriangle(B3x+50,B3y+75, B3x, B3y,B3x+100,B3y, colors[GOLD]);
            DrawSquare(B3x,B3y-100,100,colors[GOLD]);
            DrawSquare(B3x,B3y-200,100,colors[GOLD]);
        }
    }
    if(colorofship == "violet")
    {
        if(flag3 == false)
        {
            DrawTriangle(B3x+25,B3y+50, B3x+100, B3y , B3x+100,B3y+100, colors[MEDIUM_PURPLE]);
            DrawSquare(B3x+100,B3y,100,colors[MEDIUM_PURPLE]);
            DrawSquare(B3x+200,B3y,100,colors[MEDIUM_PURPLE]);
        }
        else
        {
            DrawTriangle(B3x+50,B3y+75, B3x, B3y,B3x+100,B3y, colors[MEDIUM_PURPLE]);
            DrawSquare(B3x,B3y-100,100,colors[MEDIUM_PURPLE]);
            DrawSquare(B3x,B3y-200,100,colors[MEDIUM_PURPLE]);
        }
    }
    if(colorofship == "grey")
    {
        if(flag3 == false)
        {
            DrawTriangle(B3x+25,B3y+50, B3x+100, B3y , B3x+100,B3y+100, colors[DARK_GRAY]);
            DrawSquare(B3x+100,B3y,100,colors[DARK_GRAY]);
            DrawSquare(B3x+200,B3y,100,colors[DARK_GRAY]);
        }
        else
        {
            DrawTriangle(B3x+50,B3y+75, B3x, B3y,B3x+100,B3y, colors[DARK_GRAY]);
            DrawSquare(B3x,B3y-100,100,colors[DARK_GRAY]);
            DrawSquare(B3x,B3y-200,100,colors[DARK_GRAY]);
        }
    }
    glutPostRedisplay();
}

int B4x = 1400, B4y = 600; // initial coordinates battleship 4
void drawBattleship4()
{
    // drawing forth battleship size 2
    // B4x = 1400, B4y = 600
    if(colorofship == "blue")
    {
        if(flag4 == false)
        {
            DrawTriangle(B4x+25,B4y+50, B4x+100, B4y , B4x+100,B4y+100, colors[TURQUOISE]);
            DrawSquare(B4x+100,B4y,100,colors[TURQUOISE]);
        }
        else
        {
            DrawTriangle(B4x+50,B4y+75, B4x, B4y,B4x+100,B4y, colors[TURQUOISE]);
            DrawSquare(B4x,B4y-100,100,colors[TURQUOISE]);
        }
    }
    if(colorofship == "gold")
    {
        if(flag4 == false)
        {
            DrawTriangle(B4x+25,B4y+50, B4x+100, B4y , B4x+100,B4y+100, colors[GOLD]);
            DrawSquare(B4x+100,B4y,100,colors[GOLD]);
        }
        else
        {
            DrawTriangle(B4x+50,B4y+75, B4x, B4y,B4x+100,B4y, colors[GOLD]);
            DrawSquare(B4x,B4y-100,100,colors[GOLD]);
        }
    }
    if(colorofship == "violet")
    {
        if(flag4 == false)
        {
            DrawTriangle(B4x+25,B4y+50, B4x+100, B4y , B4x+100,B4y+100, colors[MEDIUM_PURPLE]);
            DrawSquare(B4x+100,B4y,100,colors[MEDIUM_PURPLE]);
        }
        else
        {
            DrawTriangle(B4x+50,B4y+75, B4x, B4y,B4x+100,B4y, colors[MEDIUM_PURPLE]);
            DrawSquare(B4x,B4y-100,100,colors[MEDIUM_PURPLE]);
        }
    }
    if(colorofship == "grey")
    {
        if(flag4 == false)
        {
            DrawTriangle(B4x+25,B4y+50, B4x+100, B4y , B4x+100,B4y+100, colors[DARK_GRAY]);
            DrawSquare(B4x+100,B4y,100,colors[DARK_GRAY]);
        }
        else
        {
            DrawTriangle(B4x+50,B4y+75, B4x, B4y,B4x+100,B4y, colors[DARK_GRAY]);
            DrawSquare(B4x,B4y-100,100,colors[DARK_GRAY]);
        }
    }
    
    glutPostRedisplay();
}
int B5x = 1700, B5y = 600; // initial coordinates battleship 5
void drawBattleship5()
{
    // drawing fifth battleship size 2
    // B5x = 1700, B5y = 600
    if(colorofship == "blue")
    {
        if(flag5 == false)
        {
            DrawTriangle(B5x+25,B5y+50, B5x+100, B5y , B5x+100,B5y+100, colors[TURQUOISE]);
            DrawSquare(B5x+100,B5y,100,colors[TURQUOISE]);
        }
        else
        {
            DrawTriangle(B5x+50,B5y+75, B5x, B5y,B5x+100,B5y, colors[TURQUOISE]);
            DrawSquare(B5x,B5y-100,100,colors[TURQUOISE]);
        }
    }
    if(colorofship == "gold")
    {
        if(flag5 == false)
        {
            DrawTriangle(B5x+25,B5y+50, B5x+100, B5y , B5x+100,B5y+100, colors[GOLD]);
            DrawSquare(B5x+100,B5y,100,colors[GOLD]);
        }
        else
        {
            DrawTriangle(B5x+50,B5y+75, B5x, B5y,B5x+100,B5y, colors[GOLD]);
            DrawSquare(B5x,B5y-100,100,colors[GOLD]);
        }
    }
    if(colorofship == "violet")
    {
        if(flag5 == false)
        {
            DrawTriangle(B5x+25,B5y+50, B5x+100, B5y , B5x+100,B5y+100, colors[MEDIUM_PURPLE]);
            DrawSquare(B5x+100,B5y,100,colors[MEDIUM_PURPLE]);
        }
        else
        {
            DrawTriangle(B5x+50,B5y+75, B5x, B5y,B5x+100,B5y, colors[MEDIUM_PURPLE]);
            DrawSquare(B5x,B5y-100,100,colors[MEDIUM_PURPLE]);
        }
    }
    if(colorofship == "grey")
    {
        if(flag5 == false)
        {
            DrawTriangle(B5x+25,B5y+50, B5x+100, B5y , B5x+100,B5y+100, colors[DARK_GRAY]);
            DrawSquare(B5x+100,B5y,100,colors[DARK_GRAY]);
        }
        else
        {
            DrawTriangle(B5x+50,B5y+75, B5x, B5y,B5x+100,B5y, colors[DARK_GRAY]);
            DrawSquare(B5x,B5y-100,100,colors[DARK_GRAY]);
        }
    }
    glutPostRedisplay();
}
int B6x = 2000, B6y = 600; // initial coordinates battleship 6
void drawBattleship6()
{
    // drawing sixth battleship size 2
    // B6x = 2000, B6y = 600
    if(colorofship == "blue")
    {
        if(flag6 == false)
        {
            DrawTriangle(B6x+25,B6y+50, B6x+100,B6y,B6x+100,B6y+100,colors[TURQUOISE]);
            DrawSquare(B6x+100,B6y,100,colors[TURQUOISE]);
        }
        else
        {
            DrawTriangle(B6x+50,B6y+75, B6x, B6y,B6x+100,B6y, colors[TURQUOISE]);
            DrawSquare(B6x,B6y-100,100,colors[TURQUOISE]);
        }
    }
    if(colorofship == "gold")
    {
        if(flag6 == false)
        {
            DrawTriangle(B6x+25,B6y+50, B6x+100,B6y,B6x+100,B6y+100,colors[GOLD]);
            DrawSquare(B6x+100,B6y,100,colors[GOLD]);
        }
        else
        {
            DrawTriangle(B6x+50,B6y+75, B6x, B6y,B6x+100,B6y, colors[GOLD]);
            DrawSquare(B6x,B6y-100,100,colors[GOLD]);
        }
    }
    if(colorofship == "violet")
    {
        if(flag6 == false)
        {
            DrawTriangle(B6x+25,B6y+50, B6x+100,B6y,B6x+100,B6y+100,colors[MEDIUM_PURPLE]);
            DrawSquare(B6x+100,B6y,100,colors[MEDIUM_PURPLE]);
        }
        else
        {
            DrawTriangle(B6x+50,B6y+75, B6x, B6y,B6x+100,B6y, colors[MEDIUM_PURPLE]);
            DrawSquare(B6x,B6y-100,100,colors[MEDIUM_PURPLE]);
        }
    }
    if(colorofship == "grey")
    {
        if(flag6 == false)
        {
            DrawTriangle(B6x+25,B6y+50, B6x+100,B6y,B6x+100,B6y+100,colors[DARK_GRAY]);
            DrawSquare(B6x+100,B6y,100,colors[DARK_GRAY]);
        }
        else
        {
            DrawTriangle(B6x+50,B6y+75, B6x, B6y,B6x+100,B6y, colors[DARK_GRAY]);
            DrawSquare(B6x,B6y-100,100,colors[DARK_GRAY]);
        }
    }
    glutPostRedisplay();
}

int B7x = 1300, B7y = 400; // initial coordinates battleship 7
void drawBattleship7()
{
    // drawing seventh battleship size 1
    // B7x = 1300, B7y = 400
    if(colorofship == "blue")
    {
        if(flag7 == false)
        {
            DrawTriangle(B7x+10,B7y+50, B7x+100,B7y,B7x+100,B7y+100,colors[TURQUOISE]);
        }
        else
        {
            DrawTriangle(B7x+50,B7y+75, B7x, B7y,B7x+100,B7y, colors[TURQUOISE]);
        }
    }
    if(colorofship == "gold")
    {
        if(flag7 == false)
        {
            DrawTriangle(B7x+10,B7y+50, B7x+100,B7y,B7x+100,B7y+100,colors[GOLD]);
        }
        else
        {
            DrawTriangle(B7x+50,B7y+75, B7x, B7y,B7x+100,B7y, colors[GOLD]);
        }
    }
    if(colorofship == "violet")
    {
        if(flag7 == false)
        {
            DrawTriangle(B7x+10,B7y+50, B7x+100,B7y,B7x+100,B7y+100,colors[MEDIUM_PURPLE]);
        }
        else
        {
            DrawTriangle(B7x+50,B7y+75, B7x, B7y,B7x+100,B7y, colors[MEDIUM_PURPLE]);
        }
    }
    if(colorofship == "grey")
    {
        if(flag7 == false)
        {
            DrawTriangle(B7x+10,B7y+50, B7x+100,B7y,B7x+100,B7y+100,colors[DARK_GRAY]);
        }
        else
        {
            DrawTriangle(B7x+50,B7y+75, B7x, B7y,B7x+100,B7y, colors[DARK_GRAY]);
        }
    }
    glutPostRedisplay();
}

int B8x = 1600, B8y = 400; // initial coordinates battleship 8
void drawBattleship8()
{
    // drawing eighth battleship size 1
    // B8x = 1600, B8y = 400
    if(colorofship == "blue")
    {
        if(flag8 == false)
        {
            DrawTriangle(B8x+10,B8y+50, B8x+100,B8y,B8x+100,B8y+100,colors[TURQUOISE]);
        }
        else
        {
            DrawTriangle(B8x+50,B8y+75, B8x, B8y,B8x+100,B8y, colors[TURQUOISE]);
        }
    }
    if(colorofship == "gold")
    {
        if(flag8 == false)
        {
            DrawTriangle(B8x+10,B8y+50, B8x+100,B8y,B8x+100,B8y+100,colors[GOLD]);
        }
        else
        {
            DrawTriangle(B8x+50,B8y+75, B8x, B8y,B8x+100,B8y, colors[GOLD]);
        }
    }
    if(colorofship == "violet")
    {
        if(flag8 == false)
        {
            DrawTriangle(B8x+10,B8y+50, B8x+100,B8y,B8x+100,B8y+100,colors[MEDIUM_PURPLE]);
        }
        else
        {
            DrawTriangle(B8x+50,B8y+75, B8x, B8y,B8x+100,B8y, colors[MEDIUM_PURPLE]);
        }
    }
    if(colorofship == "grey")
    {
        if(flag8 == false)
        {
            DrawTriangle(B8x+10,B8y+50, B8x+100,B8y,B8x+100,B8y+100,colors[DARK_GRAY]);
        }
        else
        {
            DrawTriangle(B8x+50,B8y+75, B8x, B8y,B8x+100,B8y, colors[DARK_GRAY]);
        }
    }
    glutPostRedisplay();
}
int B9x = 1900, B9y = 400; // initial coordinates battleship 9
void drawBattleship9()
{
    // drawing ninth battleship size 1
    // B9x = 1900, B9y = 400
    if(colorofship == "blue")
    {
        if(flag9 == false)
        {
            DrawTriangle(B9x+10,B9y+50, B9x+100,B9y,B9x+100,B9y+100,colors[TURQUOISE]);
        }
        else
        {
            DrawTriangle(B9x+50,B9y+75, B9x, B9y,B9x+100,B9y, colors[TURQUOISE]);
        }
    }
    if(colorofship == "gold")
    {
        if(flag9 == false)
        {
            DrawTriangle(B9x+10,B9y+50, B9x+100,B9y,B9x+100,B9y+100,colors[GOLD]);
        }
        else
        {
            DrawTriangle(B9x+50,B9y+75, B9x, B9y,B9x+100,B9y, colors[GOLD]);
        }
    }
    if(colorofship == "violet")
    {
        if(flag9 == false)
        {
            DrawTriangle(B9x+10,B9y+50, B9x+100,B9y,B9x+100,B9y+100,colors[MEDIUM_PURPLE]);
        }
        else
        {
            DrawTriangle(B9x+50,B9y+75, B9x, B9y,B9x+100,B9y, colors[MEDIUM_PURPLE]);
        }
    }
    if(colorofship == "grey")
    {
        if(flag9 == false)
        {
            DrawTriangle(B9x+10,B9y+50, B9x+100,B9y,B9x+100,B9y+100,colors[DARK_GRAY]);
        }
        else
        {
            DrawTriangle(B9x+50,B9y+75, B9x, B9y,B9x+100,B9y, colors[DARK_GRAY]);
        }
    }
    glutPostRedisplay();
}
int B10x = 2200, B10y = 400; // initial coordinates battleship 10
void drawBattleship10()
{
    // drawing tenth battleship size 1
    // B10x = 2200, B10y = 400
    if(colorofship == "blue")
    {
        if(flag10 == false)
        {
            DrawTriangle(B10x+10,B10y+50, B10x+100,B10y,B10x+100,B10y+100,colors[TURQUOISE]);
        }
        else
        {
            DrawTriangle(B10x+50,B10y+75, B10x, B10y,B10x+100,B10y, colors[TURQUOISE]);
        }
    }
    if(colorofship == "gold")
    {
        if(flag10 == false)
        {
            DrawTriangle(B10x+10,B10y+50, B10x+100,B10y,B10x+100,B10y+100,colors[GOLD]);
        }
        else
        {
            DrawTriangle(B10x+50,B10y+75, B10x, B10y,B10x+100,B10y, colors[GOLD]);
        }
    }
    if(colorofship == "violet")
    {
        if(flag10 == false)
        {
            DrawTriangle(B10x+10,B10y+50, B10x+100,B10y,B10x+100,B10y+100,colors[MEDIUM_PURPLE]);
        }
        else
        {
            DrawTriangle(B10x+50,B10y+75, B10x, B10y,B10x+100,B10y, colors[MEDIUM_PURPLE]);
        }
    }
    if(colorofship == "grey")
    {
        if(flag10 == false)
        {
            DrawTriangle(B10x+10,B10y+50,B10x+100,B10y,B10x+100,B10y+100,colors[DARK_GRAY]);
        }
        else
        {
            DrawTriangle(B10x+50,B10y+75,B10x,B10y,B10x+100,B10y, colors[DARK_GRAY]);
        }
    }
    glutPostRedisplay();
}
void MainMenu()
{
    // first screen to come up when program is run
    glClearColor(0.2,0.2,0.25,0);
    glClear (GL_COLOR_BUFFER_BIT);
   // DrawSquare(600,100, 1200, colors[GHOST_WHITE]);
    DrawString(1050, 900, "BATTLESHIP 2", colors[WHITE]);
    DrawString(900, 800, "Maham Imran SE-F 22I-2733", colors[WHITE]);
    DrawString(1050, 600, "Click 'S' to Start!", colors[WHITE]);
    DrawString(920, 500, "Click 'L' to check Leaderboard", colors[WHITE]);
    glutSwapBuffers();
}
string buffer;
static void key(unsigned char key, int x, int y)
{
    // function to enter name
    if(key == 8 || key == '=')
        // backspace condition is also satisfied by '=' because my backspace key won't work ahaha :(
    buffer.pop_back();
    
    else
    buffer.push_back((char) key);
    cout<<key;
    cout<<buffer;
    glutPostRedisplay();
    
}
void EnterNameDisplay()
{
    // this display will promt the user to enter their name
    glClearColor(0,0.25,0.25,0);
    glClear (GL_COLOR_BUFFER_BIT);
    glutMouseFunc(MouseClicked);
    glutKeyboardFunc(key);
    DrawString(975,800, "Enter your Name", colors[WHITE]);
    DrawRectangle(975, 675, 500, 75, colors[WHITE]);
    DrawString(1000,695, buffer, colors[BLACK]);
    
    // skip button
    DrawSquare(1700,200,100, colors[WHITE]);
    DrawSquare(1800,200,100, colors[WHITE]);
    DrawSquare(1750,200,100, colors[WHITE]);
    DrawTriangle(1899,300,1899,200,1930,250,colors[WHITE]);
    DrawString(1730,233, "NEXT", colors[BLACK]);
    glutSwapBuffers();
}
void ChooseColorDisplay()
{
    // when mouse is clicked this will promt the user to choose the color of ship
    glClearColor(0.8,0.8,0.8,0);
    glClear (GL_COLOR_BUFFER_BIT);
    glutKeyboardFunc(PrintableKeys);
    DrawString(925,1000,"Choose a color for your battleships", colors[BLACK]);
    DrawString(1050,800,"Click 'B' for Blue", colors[BLUE]);
    DrawString(1050,700,"Click 'G' for Gold", colors[GOLD]);
    DrawString(1050,600,"Click 'V' for Violet", colors[MEDIUM_PURPLE]);
    DrawString(1020,150, "Press 'M' to go back", colors[BLACK]);
    glutSwapBuffers();
}

void RulesDisplay()
{
    static int gamecounter = 10;
    // before game starts this will be displayed
    glClearColor(0.25,0.25,0.25,0);
    glClear (GL_COLOR_BUFFER_BIT);
    glutKeyboardFunc(PrintableKeys);
    glutMouseFunc(MouseClick2);
    DrawString(925,1100,"RULES FOR THE GAME: ", colors[WHITE]);
    DrawString(650,900,"1. Do not place ships within 100 square feet of each other", colors[WHITE]);
    DrawString(650,800,"2. Press arrow keys to move ships", colors[WHITE]);
    DrawString(650,700,"3. Press number keys (0-9) to choose the ship you want to move", colors[WHITE]);
    DrawString(650,600, "4. Press 'F' to flip ship orientation", colors[WHITE]);
    DrawString(650,500, "5. Press 'H' to hide your ships after placing them", colors[WHITE]);
    DrawString(800,230, "Starting in " + Num2Str(gamecounter) + "...", colors[WHITE]);
    // skip botton
    DrawSquare(1700,200,100, colors[WHITE]);
    DrawSquare(1800,200,100, colors[WHITE]);
    DrawSquare(1750,200,100, colors[WHITE]);
    DrawTriangle(1899,300,1899,200,1930,250,colors[WHITE]);
    DrawString(1755,233, "SKIP", colors[BLACK]);

    gamecounter--;
    sleep(1);
    if(gamecounter == 0) {glutDisplayFunc(ChooseColorDisplay);}
    glutSwapBuffers();
}

int score[10];
string name[10];
void StartDisplay()
{
    // second menu, when s is clicked on the first menu
    glClearColor(0,0.25,0.25,0);
    glClear (GL_COLOR_BUFFER_BIT);
    glutKeyboardFunc(PrintableKeys);
    name[0] = buffer;
    score[0] = 0;
    DrawString(1050,1000, "START GAME", colors[WHITE]);
    DrawString(950,850, "Press 'P' place battleships", colors[WHITE]);
    DrawString(950,750, "Press 'O' to view options", colors[WHITE]);
    DrawString(950,650, "Press 'X' view balance", colors[WHITE]);
    DrawString(950,550, "Press 'M' to go back", colors[WHITE]);
    glutSwapBuffers();

}
void PlaceShipsDisplay()
{
    // main game screen
    glClearColor(1,1,1,0); // white
    glClear (GL_COLOR_BUFFER_BIT); // Update the colors (don't question)
    glutMouseFunc(MouseClick2);
    // background grid
    grid(2400,1400, 0, 0,  0.75, 0.75, 0.75);
    // endx, endy, startx, starty, three components of colors
    
    // battleship grid
    grid(1100,1200, 100, 200, 0, 0, 0);
    // LABELLING THE AXIS
    int positionx = 140;
    for(int i=1;i<=10;i++)
    {
        string str = Num2Str(i);
        if(i!=10) // BETTER ALLIGHNMENT FOR 10
            DrawString(positionx,1225, str, colors[BLACK]);
        else
            DrawString(positionx-15,1225, str, colors[BLACK]);
        positionx += 100;
    }
    int positiony = 1130;
    char yaxis = 'A';
    for(int i=0;i<=9;i++)
    {
        string s(1, yaxis);
        DrawString(40,positiony, s, colors[BLACK]);
        yaxis++;
        positiony -= 100;
    }
    
    // calling the drawing battleship function from this screen
    drawBattleship1();
    drawBattleship2();
    drawBattleship3();
    drawBattleship4();
    drawBattleship5();
    drawBattleship6();
    drawBattleship7();
    drawBattleship8();
    drawBattleship9();
    drawBattleship10();
    //scoring functionality
    DrawString(1600,1225, "YOUR BATTLESHIPS", colors[BLACK]);
    
    // auto button
    DrawSquare(1300, 200, 100, colors[BLACK]);
    DrawSquare(1400, 200, 100, colors[BLACK]);
    DrawSquare(1350, 200, 100, colors[BLACK]);
    DrawString(1325,230, "AUTO", colors[WHITE]);
    
    // reset buttom
    DrawSquare(2100, 200, 100, colors[BLACK]);
    DrawSquare(2200, 200, 100, colors[BLACK]);
    DrawSquare(2150, 200, 100, colors[BLACK]);
    DrawString(2125, 230, "RESET", colors[WHITE]);
    
    DrawString(725,35,"Press 'H' to Hide Ships", colors[BLACK]);
    DrawString(1325,35,"Press 'O' to see Options", colors[BLACK]);
    
    
    glutSwapBuffers(); // do not question this line
}
void LeaderBoardDisplay()
{
    // called when user presses "L", displays leaderboard from a file called leaderboard.txt
    glClearColor(0,0.25,0.25,0);
    // pretty green
    glClear (GL_COLOR_BUFFER_BIT);
    string player1 = name[0] + "            " + Num2Str(score[0]);
    string player2 = name[1] + "            " + Num2Str(score[1]);
    string player3 = name[2] + "            " + Num2Str(score[2]);
    string player4 = name[3] + "            " + Num2Str(score[3]);
    string player5 = name[4] + "            " + Num2Str(score[4]);
    string player6 = name[5] + "            " + Num2Str(score[5]);
    string player7 = name[6] + "            " + Num2Str(score[6]);
    string player8 = name[7] + "            " + Num2Str(score[7]);
    string player9 = name[8] + "            " + Num2Str(score[8]);
    string player10 = name[9] + "            " + Num2Str(score[9]);
    // reads values from array and puts them in strings to display on window
    DrawString(1000,1100, "LEADERBOARD" , colors[WHITE]);
    // an unused element has -1 as score, it won't display empty arrays
    int xpos = 1000;
    if(score[0]!=-1)
    DrawString(xpos,1000, player1 , colors[WHITE]);
    else
        DrawString(775,300, "No one has played yet, press S to start playing" , colors[WHITE]);
    if(score[1]!=-1)
    DrawString(xpos,900, player2, colors[WHITE]);
    if(score[2]!=-1)
    DrawString(xpos,800, player3, colors[WHITE]);
    if(score[3]!=-1)
    DrawString(xpos,700, player4, colors[WHITE]);
    if(score[4]!=-1)
    DrawString(xpos,600, player5, colors[WHITE]);
    if(score[5]!=-1)
    DrawString(xpos,500, player6, colors[WHITE]);
    if(score[6]!=-1)
    DrawString(xpos,400, player7, colors[WHITE]);
    if(score[7]!=-1)
    DrawString(xpos,300, player8, colors[WHITE]);
    if(score[8]!=-1)
    DrawString(xpos,200, player9, colors[WHITE]);
    if(score[9]!=-1)
    DrawString(xpos,100, player10, colors[WHITE]);
    
    DrawString(980,200, "Press 'M' to go back" , colors[WHITE]);
    glutSwapBuffers();  // again don't question the last line
}
void OptionsDisplay()
{
    // shows the weapons you own, mines submarines and bombs
    glClearColor(0.9,0.9,0.9,1);
    glClear (GL_COLOR_BUFFER_BIT);
    DrawRectangle(1075, 1175, 225, 100, colors[WHITE]);
    DrawString(1100, 1200, "ASSETS", colors[BLACK]);
    drawbomb(650,600);
    drawbomb(750,600);
    drawbomb(850,600);
    DrawString(650, 400, "BOMBS", colors[BLACK]);
    colorofship = "blue";
    drawBattleship1();
    drawBattleship2();
    drawBattleship3();
    drawBattleship4();
    drawBattleship5();
    drawBattleship6();
    drawBattleship7();
    drawBattleship8();
    drawBattleship9();
    drawBattleship10();
    //scoring functionality
    DrawString(1650,200, "BATTLESHIPS", colors[BLACK]);
    glutSwapBuffers();

}
void ViewBalanceDisplay()
{
    // this display will show your current balance earned in the game
    glClearColor(0.9,0.9,0.9,1);
    glClear (GL_COLOR_BUFFER_BIT);
    static int bal = 0;
    string balance = Num2Str(bal);
    DrawString(1050, 1000, "BALANCE", colors[BLACK]);
    DrawString(900, 900, "Your current balance is: " + balance, colors[BLACK]);
    
    
    glutSwapBuffers();
}
static int counter = 0;
void HideShipsDisplay()
{
    // DISPLAY AFTER SHIPS ARE HIDDEN
    glClearColor(1,1,1,0);
    glClear (GL_COLOR_BUFFER_BIT);
    glutMouseFunc(MouseClick2);
    // background grid
    grid(2400,1400, 0, 0,  0.75, 0.75, 0.75);
    // endx, endy, startx, starty, three components of colors
    
    // battleship grid
    grid(1100,1200, 100, 200, 0, 0, 0);
    
    // LABELLING THE AXIS
    int positionx = 140;
    for(int i=1;i<=10;i++)
    {
        string str = Num2Str(i);
        if(i!=10) // BETTER ALLIGHNMENT FOR 10
            DrawString(positionx,1225, str, colors[BLACK]);
        else
            DrawString(positionx-15,1225, str, colors[BLACK]);
        positionx += 100;
    }
    int positiony = 1130;
    char yaxis = 'A';
    for(int i=0;i<=9;i++)
    {
        string s(1, yaxis);
        DrawString(40,positiony, s, colors[BLACK]);
        yaxis++;
        positiony -= 100;
    }
    
    
    // GRID # 2
    grid(2300,1200,1300,200, 0, 0, 0);
    int positionx2 = 1330;
    for(int i=1;i<=10;i++)
    {
        string str = Num2Str(i);
        if(i!=10) // BETTER ALLIGHNMENT FOR 10
            DrawString(positionx2,1225, str, colors[BLACK]);
        else
            DrawString(positionx2-15,1225, str, colors[BLACK]);
        positionx2 += 100;
    }
    int positiony2 = 1130;
    char yaxis2 = 'A';
    for(int i=0;i<=9;i++)
    {
        string s(1, yaxis2);
        DrawString(1240,positiony2,s, colors[BLACK]);
        yaxis2++;
        positiony2 -= 100;
    }
    // your placed ships will be in the same spot, just colored grey
    drawBattleship1();
    drawBattleship2();
    drawBattleship3();
    drawBattleship4();
    drawBattleship5();
    drawBattleship6();
    drawBattleship7();
    drawBattleship8();
    drawBattleship9();
    drawBattleship10();
    // for time
    int total_score = 0;
    string str = to_string(total_score);
    DrawString(2050,1325,"SCORE =",colors[BLACK]);
    DrawString(1075,1325,"TIMER = " + Num2Str(counter),colors[BLACK]);
    DrawString(2250,1325,str,colors[BLACK]);
    DrawString(400,130, buffer + "'s Ships",colors[BLACK]);
    DrawString(1600,130,"Baymax's Ships",colors[BLACK]);
    DrawString(800,30,"CLICK 'E' TO EXPOSE ENEMY SHIPS",colors[BLACK]);
    sleep(1);
    counter++;
    glutSwapBuffers();
   
}
void ExposeEnemyShipsDisplay()
{
    // DISPLAY AFTER SHIPS ARE HIDDEN
    glClearColor(1,1,1,0);
    glClear (GL_COLOR_BUFFER_BIT);
    glutMouseFunc(MouseClick2);
    // background grid
    grid(2400,1400, 0, 0,  0.75, 0.75, 0.75);
    // endx, endy, startx, starty, three components of colors
    
    // battleship grid
    grid(1100,1200, 100, 200, 0, 0, 0);
    
    // LABELLING THE AXIS
    int positionx = 140;
    for(int i=1;i<=10;i++)
    {
        string str = Num2Str(i);
        if(i!=10) // BETTER ALLIGHNMENT FOR 10
            DrawString(positionx,1225, str, colors[BLACK]);
        else
            DrawString(positionx-15,1225, str, colors[BLACK]);
        positionx += 100;
    }
    int positiony = 1130;
    char yaxis = 'A';
    for(int i=0;i<=9;i++)
    {
        string s(1, yaxis);
        DrawString(40,positiony, s, colors[BLACK]);
        yaxis++;
        positiony -= 100;
    }
    
    
    // GRID # 2
    grid(2300,1200,1300,200, 0, 0, 0);
    int positionx2 = 1330;
    for(int i=1;i<=10;i++)
    {
        string str = Num2Str(i);
        if(i!=10) // BETTER ALLIGHNMENT FOR 10
            DrawString(positionx2,1225, str, colors[BLACK]);
        else
            DrawString(positionx2-15,1225, str, colors[BLACK]);
        positionx2 += 100;
    }
    int positiony2 = 1130;
    char yaxis2 = 'A';
    for(int i=0;i<=9;i++)
    {
        string s(1, yaxis2);
        DrawString(1240,positiony2,s, colors[BLACK]);
        yaxis2++;
        positiony2 -= 100;
    }
    // your placed ships will be in the same spot, just colored grey
    drawBattleship1();
    drawBattleship2();
    drawBattleship3();
    drawBattleship4();
    drawBattleship5();
    drawBattleship6();
    drawBattleship7();
    drawBattleship8();
    drawBattleship9();
    drawBattleship10();
    
    // exosing enemy shps
    EnemyShip1();
    EnemyShip2();
    EnemyShip3();
    EnemyShip4();
    EnemyShip5();
    EnemyShip6();
    EnemyShip7();
    EnemyShip8();
    EnemyShip9();
    EnemyShip10();
    
    // for time
    int total_score = 0;
    string str = to_string(total_score);
    DrawString(2050,1325,"SCORE =",colors[BLACK]);
    DrawString(1075,1325,"TIMER = " + Num2Str(counter),colors[BLACK]);
    DrawString(2250,1325,str,colors[BLACK]);
    DrawString(400,130, buffer + "'s Ships",colors[BLACK]);
    DrawString(1600,130,"Baymax's Ships",colors[BLACK]);
    DrawString(800,30,"CLICK 'E' TO EXPOSE ENEMY SHIPS",colors[BLACK]);
    sleep(1);
    counter++;
    glutSwapBuffers();
   
}
void GameOverDisplay()
{
    glClearColor(0.9,0.2,0.2,0);
    glClear (GL_COLOR_BUFFER_BIT);
    DrawString(1050,1000, "GAME OVER", colors[WHITE]);
    DrawString(900,800,"Better luck next time " + buffer + "...",colors[WHITE]);
    // storing name score and balance, re-initialising
    static int playernumberindex = 0;
    name[playernumberindex] = buffer;
    int playernumberscore = 90;
    score[playernumberindex] = playernumberscore;
    glutSwapBuffers();
}



// number of ship to move
int moveship = 0;

// fixed 2D array for player ship grid
bool playershipgrid[10][10];
void InitialiseShipArray()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            playershipgrid[i][j] = false;
        }
    }
}
int sizeofship1 = 4;
int sizeofship2 = 3;
int sizeofship3 = 3;
int sizeofship4 = 2;
int sizeofship5 = 2;
int sizeofship6 = 2;
int sizeofship7 = 1;
int sizeofship8 = 1;
int sizeofship9 = 1;
int sizeofship10 = 1;

void UpdateShipArray()
{
    // horizontal ship 1
    for(int startingxB1=100;startingxB1<=700;startingxB1+=100)
    {
        int index = 0;
        int startshipx = 0;
        // formula according to my coordinates, can't explain it just makes sense
        startshipx = (startingxB1 - 100) / 100;
        for(int startingyB1=1100;startingyB1>=200;startingyB1-=100)
        {
            if(B1x == startingxB1 && B1y == startingyB1 && flag1 == false)
            {
                for(int i=startshipx;i<startshipx+sizeofship1;i++)
                {
                    playershipgrid[index][i] = true;
                   
                }
            }
            index++;
        }
    }
    
    // vertical ship 1
    
    for(int startingxB1=100;startingxB1<=1000;startingxB1+=100)
    {
        static int index = 0;
        int startshipy = 0;
        // formula according to my coordinates, can't explain it just makes sense
        for(int startingyB1=1100;startingyB1>=500;startingyB1-=100)
        {
            // vertical ship
            // again another formula according to my coordinates, can't explain but it works
            startshipy = 10 - ((startingyB1-100)/100);
            if(B1x == startingxB1 && B1y == startingyB1 && flag1 == true)
            {
                for(int i=startshipy;i<startshipy+sizeofship1;i++)
                {
                    playershipgrid[i][index] = true;
                   
                }
            }
        }
        index++;
    }

    
    
    // horizontal ship 2
    for(int startingxB2=100;startingxB2<=800;startingxB2+=100)
    {
        int index = 0;
        int startshipx = 0;
        // formula according to my coordinates, can't explain it just makes sense
        startshipx = (startingxB2 - 100) / 100;
        for(int startingyB2=1100;startingyB2>=200;startingyB2-=100)
        {
            if(B2x == startingxB2 && B2y == startingyB2 && flag2 == false)
            {
                for(int i=startshipx;i<startshipx+sizeofship2;i++)
                {
                    playershipgrid[index][i] = true;
                }
            }
            index++;
        }
    }
    
    // vertical ship 2
    
    for(int startingxB2=100;startingxB2<=1000;startingxB2+=100)
    {
        static int index = 0;
        int startshipy = 0;
        // formula according to my coordinates, can't explain it just makes sense
        for(int startingyB2=1100;startingyB2>=400;startingyB2-=100)
        {
            // vertical ship
            // again another formula according to my coordinates, can't explain but it works
            startshipy = 10 - ((startingyB2-100)/100);
            if(B2x == startingxB2 && B2y == startingyB2 && flag2 == true)
            {
                for(int i=startshipy;i<startshipy+sizeofship2;i++)
                {
                    playershipgrid[i][index] = true;
                }
            }
        }
        index++;
    }
    
    // horizontal ship 3
    
    for(int startingxB3=100;startingxB3<=800;startingxB3+=100)
    {
        int index = 0;
        int startshipx = 0;
        // formula according to my coordinates, can't explain it just makes sense
        startshipx = (startingxB3 - 100) / 100;
        for(int startingyB3=1100;startingyB3>=200;startingyB3-=100)
        {
            if(B3x == startingxB3 && B3y == startingyB3 && flag3 == false)
            {
                for(int i=startshipx;i<startshipx+sizeofship3;i++)
                {
                    playershipgrid[index][i] = true;
                }
            }
            index++;
        }
    }
    
    // vertical ship 3
    
    for(int startingxB3=100;startingxB3<=1000;startingxB3+=100)
    {
        static int index = 0;
        int startshipy = 0;
        // formula according to my coordinates, can't explain it just makes sense
        for(int startingyB3=1100;startingyB3>=400;startingyB3-=100)
        {
            // vertical ship
            // again another formula according to my coordinates, can't explain but it works
            startshipy = 10 - ((startingyB3-100)/100);
            if(B3x == startingxB3 && B3y == startingyB3 && flag3 == true)
            {
                for(int i=startshipy;i<startshipy+sizeofship3;i++)
                {
                    playershipgrid[i][index] = true;
                }
            }
        }
        index++;
    }
    
    // horizontal ship 4
    
    for(int startingxB4=100;startingxB4<=900;startingxB4+=100)
    {
        int index = 0;
        int startshipx = 0;
        // formula according to my coordinates, can't explain it just makes sense
        startshipx = (startingxB4 - 100) / 100;
        for(int startingyB4=1100;startingyB4>=200;startingyB4-=100)
        {
            if(B4x == startingxB4 && B4y == startingyB4 && flag4 == false)
            {
                for(int i=startshipx;i<startshipx+sizeofship4;i++)
                {
                    playershipgrid[index][i] = true;
                }
            }
            index++;
        }
    }
    
    // vertical ship 4
    
    for(int startingxB4=100;startingxB4<=1000;startingxB4+=100)
    {
        static int index = 0;
        int startshipy = 0;
        // formula according to my coordinates, can't explain it just makes sense
        for(int startingyB4=1100;startingyB4>=300;startingyB4-=100)
        {
            // vertical ship
            // again another formula according to my coordinates, can't explain but it works
            startshipy = 10 - ((startingyB4-100)/100);
            if(B4x == startingxB4 && B4y == startingyB4 && flag4 == true)
            {
                for(int i=startshipy;i<startshipy+sizeofship4;i++)
                {
                    playershipgrid[i][index] = true;
                }
            }
        }
        index++;
    }
    
    // horizontal ship 5
    
    for(int startingxB5=100;startingxB5<=900;startingxB5+=100)
    {
        int index = 0;
        int startshipx = 0;
        // formula according to my coordinates, can't explain it just makes sense
        startshipx = (startingxB5 - 100) / 100;
        for(int startingyB5=1100;startingyB5>=200;startingyB5-=100)
        {
            if(B5x == startingxB5 && B5y == startingyB5 && flag5 == false)
            {
                for(int i=startshipx;i<startshipx+sizeofship5;i++)
                {
                    playershipgrid[index][i] = true;
                }
            }
            index++;
        }
    }
    
    // vertical ship 5
    
    for(int startingxB5=100;startingxB5<=1000;startingxB5+=100)
    {
        static int index = 0;
        int startshipy = 0;
        // formula according to my coordinates, can't explain it just makes sense
        for(int startingyB5=1100;startingyB5>=300;startingyB5-=100)
        {
            // vertical ship
            // again another formula according to my coordinates, can't explain but it works
            startshipy = 10 - ((startingyB5-100)/100);
            if(B5x == startingxB5 && B5y == startingyB5 && flag5 == true)
            {
                for(int i=startshipy;i<startshipy+sizeofship5;i++)
                {
                    playershipgrid[i][index] = true;
                }
            }
        }
        index++;
    }
    
    
    // horizontal ship 6
    
    for(int startingxB6=100;startingxB6<=900;startingxB6+=100)
    {
        int index = 0;
        int startshipx = 0;
        // formula according to my coordinates, can't explain it just makes sense
        startshipx = (startingxB6 - 100) / 100;
        for(int startingyB6=1100;startingyB6>=200;startingyB6-=100)
        {
            if(B6x == startingxB6 && B6y == startingyB6 && flag6 == false)
            {
                for(int i=startshipx;i<startshipx+sizeofship6;i++)
                {
                    playershipgrid[index][i] = true;
                }
            }
            index++;
        }
    }
    
    // vertical ship 6
    
    for(int startingxB6=100;startingxB6<=1000;startingxB6+=100)
    {
        static int index = 0;
        int startshipy = 0;
        // formula according to my coordinates, can't explain it just makes sense
        for(int startingyB6=1100;startingyB6>=300;startingyB6-=100)
        {
            // vertical ship
            // again another formula according to my coordinates, can't explain but it works
            startshipy = 10 - ((startingyB6-100)/100);
            if(B6x == startingxB6 && B6y == startingyB6 && flag6 == true)
            {
                for(int i=startshipy;i<startshipy+sizeofship6;i++)
                {
                    playershipgrid[i][index] = true;
                }
            }
        }
        index++;
    }
    
    // horizontal ship 7
    
    for(int startingxB7=100;startingxB7<=1000;startingxB7+=100)
    {
        int index = 0;
        int startshipx = 0;
        // formula according to my coordinates, can't explain it just makes sense
        startshipx = (startingxB7 - 100) / 100;
        for(int startingyB7=1100;startingyB7>=200;startingyB7-=100)
        {
            if(B7x == startingxB7 && B7y == startingyB7 && flag7 == false)
            {
                for(int i=startshipx;i<startshipx+sizeofship7;i++)
                {
                    playershipgrid[index][i] = true;
                }
            }
            index++;
        }
    }
    
    // vertical ship 7
    
    for(int startingxB7=100;startingxB7<=1000;startingxB7+=100)
    {
        static int index = 0;
        int startshipy = 0;
        // formula according to my coordinates, can't explain it just makes sense
        for(int startingyB7=1100;startingyB7>=200;startingyB7-=100)
        {
            // vertical ship
            // again another formula according to my coordinates, can't explain but it works
            startshipy = 10 - ((startingyB7-100)/100);
            if(B7x == startingxB7 && B7y == startingyB7 && flag7 == true)
            {
                for(int i=startshipy;i<startshipy+sizeofship7;i++)
                {
                    playershipgrid[i][index] = true;
                }
            }
        }
        index++;
    }
    
    // horizontal ship 8
    
    for(int startingxB8=100;startingxB8<=1000;startingxB8+=100)
    {
        int index = 0;
        int startshipx = 0;
        // formula according to my coordinates, can't explain it just makes sense
        startshipx = (startingxB8 - 100) / 100;
        for(int startingyB8=1100;startingyB8>=200;startingyB8-=100)
        {
            if(B8x == startingxB8 && B8y == startingyB8 && flag8 == false)
            {
                for(int i=startshipx;i<startshipx+sizeofship8;i++)
                {
                    playershipgrid[index][i] = true;
                }
            }
            index++;
        }
    }
    
    // vertical ship 8
    
    for(int startingxB8=100;startingxB8<=1000;startingxB8+=100)
    {
        static int index = 0;
        int startshipy = 0;
        // formula according to my coordinates, can't explain it just makes sense
        for(int startingyB8=1100;startingyB8>=200;startingyB8-=100)
        {
            // vertical ship
            // again another formula according to my coordinates, can't explain but it works
            startshipy = 10 - ((startingyB8-100)/100);
            if(B8x == startingxB8 && B8y == startingyB8 && flag8 == true)
            {
                for(int i=startshipy;i<startshipy+sizeofship8;i++)
                {
                    playershipgrid[i][index] = true;
                }
            }
        }
        index++;
    }
    
    // horizontal ship 9
    
    for(int startingxB9=100;startingxB9<=1000;startingxB9+=100)
    {
        int index = 0;
        int startshipx = 0;
        // formula according to my coordinates, can't explain it just makes sense
        startshipx = (startingxB9 - 100) / 100;
        for(int startingyB9=1100;startingyB9>=200;startingyB9-=100)
        {
            if(B9x == startingxB9 && B9y == startingyB9 && flag9 == false)
            {
                for(int i=startshipx;i<startshipx+sizeofship9;i++)
                {
                    playershipgrid[index][i] = true;
                }
            }
            index++;
        }
    }
    
    // vertical ship 9
    
    for(int startingxB9=100;startingxB9<=1000;startingxB9+=100)
    {
        static int index = 0;
        int startshipy = 0;
        // formula according to my coordinates, can't explain it just makes sense
        for(int startingyB9=1100;startingyB9>=200;startingyB9-=100)
        {
            // vertical ship
            // again another formula according to my coordinates, can't explain but it works
            startshipy = 10 - ((startingyB9-100)/100);
            if(B9x == startingxB9 && B9y == startingyB9 && flag9 == true)
            {
                for(int i=startshipy;i<startshipy+sizeofship9;i++)
                {
                    playershipgrid[i][index] = true;
                }
            }
        }
        index++;
    }
    
    // horizontal ship 10
    
    for(int startingxB10=100;startingxB10<=1000;startingxB10+=100)
    {
        int index = 0;
        int startshipx = 0;
        // formula according to my coordinates, can't explain it just makes sense
        startshipx = (startingxB10 - 100) / 100;
        for(int startingyB10=1100;startingyB10>=200;startingyB10-=100)
        {
            if(B10x == startingxB10 && B10y == startingyB10 && flag10 == false)
            {
                for(int i=startshipx;i<startshipx+sizeofship10;i++)
                {
                    playershipgrid[index][i] = true;
                }
            }
            index++;
        }
    }
    
    // vertical ship 10
    
    for(int startingxB10=100;startingxB10<=1000;startingxB10+=100)
    {
        static int index = 0;
        int startshipy = 0;
        // formula according to my coordinates, can't explain it just makes sense
        for(int startingyB10=1100;startingyB10>=200;startingyB10-=100)
        {
            // vertical ship
            // again another formula according to my coordinates, can't explain but it works
            startshipy = 10 - ((startingyB10-100)/100);
            if(B10x == startingxB10 && B10y == startingyB10 && flag10 == true)
            {
                for(int i=startshipy;i<startshipy+sizeofship10;i++)
                {
                    playershipgrid[i][index] = true;
                }
            }
        }
        index++;
    }
    
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<playershipgrid[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;cout<<endl;
 
}

void NonPrintableKeys(int key, int x, int y)
{
    // horizontal limits to keep ship in grid
    int rightextremehorizontalship = 700;
    int bottomextremehorizontalship = 200;
    
    // vertical limits to keep ship in grid
    int rightextremeverticalship = 1000;
    int bottomextremeverticalship = 500;
    
    // limits that are the same for horizontal and vertical ship
    int topextreme = 1100;
    int leftextreme = 100;
   
    // arrow keys functionality
    if (key == GLUT_KEY_LEFT)
    {
        // left arrow key for each ship x cordinate
        if(moveship == 0)
        {
            if(B1x>leftextreme)
                B1x -= 100;
        }
        if(moveship == 1)
        {
            if(B2x>leftextreme)
                B2x -= 100;
        }
        if(moveship == 2)
        {
            if(B3x>leftextreme)
                B3x -= 100;
        }
        if(moveship == 3)
        {
            if(B4x>leftextreme)
                B4x -= 100;
        }
        if(moveship == 4)
        {
            if(B5x>leftextreme)
                B5x -= 100;
        }
        if(moveship == 5)
        {
            if(B6x>leftextreme)
                B6x -= 100;
        }
        if(moveship == 6)
        {
            if(B7x>leftextreme)
                B7x -= 100;
        }
        if(moveship == 7)
        {
            if(B8x>leftextreme)
                B8x -= 100;
        }
        if(moveship == 8)
        {
            if(B9x>leftextreme)
                B9x -= 100;
        }
        if(moveship == 9)
        {
            if(B10x>leftextreme)
                B10x -= 100;
        }
    }
    if (key == GLUT_KEY_RIGHT)
    {
        // right arrow key for each ship x cordinate
        if(moveship == 0)
        {
            if(B1x<rightextremehorizontalship && flag1 == false)
                B1x += 100;
            if(B1x<1000 && flag1 == true)
                B1x += 100;
        }
        if(moveship == 1)
        {
            if(B2x<rightextremehorizontalship+100 && flag2 == false)
                B2x += 100;
            if(B2x<rightextremeverticalship && flag2 == true)
                B2x += 100;
        }
        if(moveship == 2)
        {
            if(B3x<rightextremehorizontalship+100 && flag3 == false)
                B3x += 100;
            if(B3x<rightextremeverticalship && flag3 == true)
                B3x += 100;
        }
        if(moveship == 3)
        {
            if(B4x<rightextremehorizontalship+200 && flag4 == false)
                B4x += 100;
            if(B4x<rightextremeverticalship && flag4 == true)
                B4x += 100;
        }
        if(moveship == 4)
        {
            if(B5x<rightextremehorizontalship+200 && flag5 == false)
                B5x += 100;
            if(B5x<rightextremeverticalship && flag5 == true)
                B5x += 100;
        }
        if(moveship == 5)
        {
            if(B6x<rightextremehorizontalship+200 && flag6 == false)
                B6x += 100;
            if(B6x<rightextremeverticalship && flag6 == true)
                B6x += 100;
        }
        if(moveship == 6)
        {
            if(B7x<rightextremehorizontalship+300 && flag7 == false)
                B7x += 100;
            if(B7x<rightextremeverticalship && flag7 == true)
                B7x += 100;
        }
        if(moveship == 7)
        {
            if(B8x<rightextremehorizontalship+300 && flag8 == false)
                B8x += 100;
            if(B8x<rightextremeverticalship && flag8 == true)
                B8x += 100;
        }
        if(moveship == 8)
        {
            if(B9x<rightextremehorizontalship+300 && flag9 == false)
                B9x += 100;
            if(B9x<rightextremeverticalship && flag9 == true)
                B9x += 100;
            
        }
        if(moveship == 9)
        {
            if(B10x<rightextremehorizontalship+300 && flag10 == false)
                B10x += 100;
            if(B10x<rightextremeverticalship && flag10 == true)
                B10x += 100;
        }
    }
    
    if (key == GLUT_KEY_UP)
    {
            // up arrow key for each ship y cordinate
            if(moveship == 0)
            {
                if(B1y<topextreme)
                    B1y += 100;
            }
            if(moveship == 1)
            {
                if(B2y<topextreme)
                    B2y += 100;
            }
            if(moveship == 2)
            {
                if(B3y<topextreme)
                    B3y += 100;
            }
            if(moveship == 3)
            {
                if(B4y<topextreme)
                    B4y += 100;
            }
            if(moveship == 4)
            {
                if(B5y<topextreme)
                    B5y += 100;
            }
            if(moveship == 5)
            {
                if(B6y<topextreme)
                    B6y += 100;
            }
            if(moveship == 6)
            {
                if(B7y<topextreme)
                    B7y += 100;
            }
            if(moveship == 7)
            {
                if(B8y<topextreme)
                    B8y += 100;
            }
            if(moveship == 8)
            {
                if(B9y<topextreme)
                    B9y += 100;
            }
            if(moveship == 9)
            {
                if(B10y<topextreme)
                    B10y += 100;
            }
    }
    
    if (key == GLUT_KEY_DOWN)
    {
      
            // down arrow key for each ship y cordinate
            if(moveship == 0)
            {
                if(B1y>bottomextremehorizontalship && flag1 == false)
                    B1y -= 100;
                if(B1y>bottomextremeverticalship && flag1 == true)
                    B1y -= 100;
            }
            if(moveship == 1)
            {
                if(B2y>bottomextremehorizontalship && flag2 == false)
                    B2y -= 100;
                if(B2y>bottomextremeverticalship-100 && flag2 == true)
                    B2y -= 100;
            }
            if(moveship == 2)
            {
                if(B3y>bottomextremehorizontalship && flag3 == false)
                    B3y -= 100;
                if(B3y>bottomextremeverticalship-100 && flag3 == true)
                    B3y -= 100;
            }
            if(moveship == 3)
            {
                if(B4y>bottomextremehorizontalship && flag4 == false)
                    B4y -= 100;
                if(B4y>bottomextremeverticalship-200 && flag4 == true)
                    B4y -= 100;
            }
            if(moveship == 4)
            {
                if(B5y>bottomextremehorizontalship && flag5 == false)
                    B5y -= 100;
                if(B5y>bottomextremeverticalship-200 && flag5 == true)
                    B5y -= 100;
            }
            if(moveship == 5)
            {
                if(B6y>bottomextremehorizontalship && flag6 == false)
                    B6y -= 100;
                if(B6y>bottomextremeverticalship-200 && flag6 == true)
                    B6y -= 100;
            }
            if(moveship == 6)
            {
                if(B7y>bottomextremehorizontalship && flag7 == false)
                    B7y -= 100;
                if(B7y>bottomextremeverticalship-200 && flag7 == true)
                    B7y -= 100;
            }
            if(moveship == 7)
            {
                if(B8y>bottomextremehorizontalship && flag8 == false)
                    B8y -= 100;
                if(B8y>bottomextremeverticalship-300 && flag8 == true)
                B8y -= 100;
            }
            if(moveship == 8)
            {
                if(B9y>bottomextremehorizontalship && flag9 == false)
                    B9y -= 100;
                if(B9y>bottomextremeverticalship-300 && flag9 == true)
                B9y -= 100;
            }
            if(moveship == 9)
            {
                if(B10y>bottomextremehorizontalship && flag10 == false)
                    B10y -= 100;
                if(B10y>bottomextremeverticalship-300 && flag10 == true)
                B10y -= 100;
            }
    }
        glutPostRedisplay();
    
}

void PrintableKeys(unsigned char key, int x, int y)
{
    // letter keys functionality
    if (key == 27)
        exit(1);
    if (key == '0')
        moveship = 0;
    if (key == '1')
        moveship = 1;
    if (key == '2')
        moveship = 2;
    if (key == '3')
        moveship = 3;
    if (key == '4')
        moveship = 4;
    if (key == '5')
        moveship = 5;
    if (key == '6')
        moveship = 6;
    if (key == '7')
        moveship = 7;
    if (key == '8')
        moveship = 8;
    if (key == '9')
        moveship = 9;
    
    // letters for menus
    if (key == 's' || key == 'S')
        // starting
        glutDisplayFunc(EnterNameDisplay);
    if (key == 'l' || key == 'L')
        // leaderboard
        glutDisplayFunc(LeaderBoardDisplay);
    if (key == 'p' || key == 'P')
    {
        // place ships
        glutDisplayFunc(RulesDisplay);
    }
    if (key == 'o' || key == 'O')
        // options
        glutDisplayFunc(OptionsDisplay);
    if (key == 'x' || key == 'X')
        // view balance
        glutDisplayFunc(ViewBalanceDisplay);
    if (key == 'm' || key == 'M')
        // back to main menu
        glutDisplayFunc(MainMenu);
    if (key == 'h' || key == 'H')
    {
        // to hide placed ships
        UpdateShipArray();
        glutDisplayFunc(HideShipsDisplay);
        colorofship = "grey";
        // updates the ship array when all ships are hidden
        UpdateShipArray();
    }
    if (key == 'e' || key == 'E')
        // exposing enemt ships
        glutDisplayFunc(ExposeEnemyShipsDisplay);
    
    
    // for color of ship
    if (key == 'b' || key == 'B')
    {
        colorofship = "blue";
        glutDisplayFunc(PlaceShipsDisplay);
    }
    if (key == 'g' || key == 'G')
    {
        colorofship = "gold";
        glutDisplayFunc(PlaceShipsDisplay);
        
    }
    if (key == 'v' || key == 'V')
    {
        colorofship = "violet";
        glutDisplayFunc(PlaceShipsDisplay);
    }
    cout<<colorofship<<endl;
        
    // to flip ships
    if (key == 'f' || key == 'F')
    {
        // true becomes false, vice versa
        // Flip ship 1
        if(moveship==0)
        {
            if(flag1 == false) flag1 = true;
            else flag1 = false;
        }
        // Flip ship 2
        if(moveship==1)
        {
            if(flag2 == false) flag2 = true;
            else flag2 = false;
        }
        // Flip ship 3
        if(moveship==2)
        {
            if(flag3 == false) flag3 = true;
            else flag3 = false;
        }
        // Flip ship 4
        if(moveship==3)
        {
            if(flag4 == false) flag4 = true;
            else flag4 = false;
        }
        // Flip ship 5
        if(moveship==4)
        {
            if(flag5 == false) flag5 = true;
            else flag5 = false;
        }
        // Flip ship 6
        if(moveship==5)
        {
            if(flag6 == false) flag6 = true;
            else flag6 = false;
        }
        // Flip ship 7
        if(moveship==6)
        {
            if(flag7 == false) flag7 = true;
            else flag7 = false;
        }
        // Flip ship 8
        if(moveship==7)
        {
            if(flag8 == false) flag8 = true;
            else flag8 = false;
        }
        // Flip ship 9
        if(moveship==8)
        {
            if(flag9 == false) flag9 = true;
            else flag9 = false;
        }
        // Flip ship 10
        if(moveship==9)
        {
            if(flag10 == false) flag10 = true;
            else flag10 = false;
        }
    
    }
    
    
    // when game is over
    if (key == 'q' || key == 'Q')
        glutDisplayFunc(GameOverDisplay);
    glutPostRedisplay(); // don't question this line (3)
}

void MousePressedAndMoved(int x, int y)
{
    // mouse press and move functionality
   // cout << x << " " << y << endl;
    glutPostRedisplay();
}
void MouseMoved(int x, int y)
{
    // mouse move functionality
    // cout << x << " " << y << endl;
    glutPostRedisplay();
}
// when battleship clicked change a global variable to move specific ship

void MouseClicked(int button, int state, int x, int y)
{
    // mouse click
    if (button == GLUT_LEFT_BUTTON)
    {
        if(x>=850 && x<=950 && y>=550 && y<=600)
        {
            cout<<"next button pressed"<<endl;
            glutDisplayFunc(StartDisplay);
        }
    }
    
    else if (button == GLUT_RIGHT_BUTTON)
            cout<<"Right Button Pressed"<<endl;
    glutPostRedisplay();
}
void autoshipplacement()
{
    // initialising array each time auto button is clicked
    InitialiseShipArray();
    
    // ship 1
    flag1 = GetRandInRange(0,2); // either 0 or 1
    if(flag1 == 0)
    {
        B1x = (GetRandInRange(100, 700)/100) * 100;
        B1y = (GetRandInRange(200, 1200)/100) * 100;
    }
    else
    {
        B1x = (GetRandInRange(100, 1000)/100) * 100;
        B1y = (GetRandInRange(600, 1200)/100) * 100;
    }
    
    // ship 2
    flag2 = GetRandInRange(0,2); // either 0 or 1
    if(flag2 == 0)
    {
        B2x = (GetRandInRange(100, 800)/100) * 100;
        B2y = (GetRandInRange(200, 1200)/100) * 100;
    }
    else
    {
        B2x = (GetRandInRange(100, 1000)/100) * 100;
        B2y = (GetRandInRange(500, 1200)/100) * 100;
    }
    
    // ship 3
    flag3 = GetRandInRange(0,2); // either 0 or 1
    if(flag3 == 0)
    {
        B3x = (GetRandInRange(100, 800)/100) * 100;
        B3y = (GetRandInRange(200, 1200)/100) * 100;
    }
    else
    {
        B3x = (GetRandInRange(100, 1000)/100) * 100;
        B3y = (GetRandInRange(500, 1200)/100) * 100;
    }
    
    // ship 4
    flag4 = GetRandInRange(0,2); // either 0 or 1
    if(flag4 == 0)
    {
        B4x = (GetRandInRange(100, 900)/100) * 100;
        B4y = (GetRandInRange(200, 1200)/100) * 100;
    }
    else
    {
        B4x = (GetRandInRange(100, 1000)/100) * 100;
        B4y = (GetRandInRange(400, 1200)/100) * 100;
    }
    
    // ship 5
    flag5 = GetRandInRange(0,2); // either 0 or 1
    if(flag5 == 0)
    {
        B5x = (GetRandInRange(100, 900)/100) * 100;
        B5y = (GetRandInRange(200, 1200)/100) * 100;
    }
    else
    {
        B5x = (GetRandInRange(100, 1000)/100) * 100;
        B5y = (GetRandInRange(400, 1200)/100) * 100;
    }
    
    // ship 6
    flag6 = GetRandInRange(0,2); // either 0 or 1
    if(flag6 == 0)
    {
        B6x = (GetRandInRange(100, 900)/100) * 100;
        B6y = (GetRandInRange(200, 1200)/100) * 100;
    }
    else
    {
        B6x = (GetRandInRange(100, 1000)/100) * 100;
        B6y = (GetRandInRange(400, 1200)/100) * 100;
    }
    
    // ship 7
    // horizontal and vertical take up same amount of space
    flag7 = GetRandInRange(0,2); // either 0 or 1
    B7x = (GetRandInRange(100, 1000)/100) * 100;
    B7y = (GetRandInRange(200, 1200)/100) * 100;
    
    // ship 8
    // horizontal and vertical take up same amount of space
    flag8 = GetRandInRange(0,2); // either 0 or 1
    B8x = (GetRandInRange(100, 1000)/100) * 100;
    B8y = (GetRandInRange(200, 1200)/100) * 100;
    
    // ship 9
    // horizontal and vertical take up same amount of space
    flag9 = GetRandInRange(0,2); // either 0 or 1
    B9x = (GetRandInRange(100, 1000)/100) * 100;
    B9y = (GetRandInRange(200, 1200)/100) * 100;
   
    // ship 10
    // horizontal and vertical take up same amount of space
    flag10 = GetRandInRange(0,2); // either 0 or 1
    B10x = (GetRandInRange(100, 1000)/100) * 100;
    B10y = (GetRandInRange(200, 1200)/100) * 100;
    
    UpdateShipArray();
    
}
void MouseClick2(int button, int state, int x, int y)
{
    // looking for opponents ships, first clicking function already used
    if (button == GLUT_LEFT_BUTTON)
    {
        if(x>=650 && x<=750 && y>=550 && y<=600)
        {
            cout<<"auto button pressed"<<endl;
            autoshipplacement();
        }
        if(x>=850 && x<=950 && y>=550 && y<=600)
        {
            cout<<"next button pressed"<<endl;
            glutDisplayFunc(ChooseColorDisplay);
        }
        if(x>=1050 && x<=1150 && y>=550 && y<=600)
        {
            cout<<"reset button pressed"<<endl;
            B1x = 1600; B1y = 1000;
            B2x = 1500; B2y = 800;
            B3x = 1800; B3y = 800;
            B4x = 1400; B4y = 600;
            B5x = 1700; B5y = 600;
            B6x = 2000; B6y = 600;
            B7x = 1300; B7y = 400;
            B8x = 1600; B8y = 400;
            B9x = 1900; B9y = 400;
            B10x = 2200; B10y = 400;
            flag1 = false;
            flag2 = false;
            flag3 = false;
            flag4 = false;
            flag5 = false;
            flag6 = false;
            flag7 = false;
            flag8 = false;
            flag9 = false;
            flag10 = false;
            InitialiseShipArray();
        }
       // cout<<x<<"  "<<y<<endl;
    }
    
    else if (button == GLUT_RIGHT_BUTTON)
    {
        cout<<"Right Button Pressed"<<endl;
        
    }
    glutPostRedisplay();
}

int main(int argc, char*argv[])
{
    // main function, initialisation of most things
    int width = 2400, height = 1400;
    
    // dynamic allocation of board array
    int** board = new int*[height];
    for(int i=0;i<height;i++){board[i] = new int[width];}

    // glut functions to initialise and specify
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width/2, height/2);
    glutCreateWindow("Battleship2");
    SetCanvasSize(width,height);
   
    // links my functions with glut stuff i think
    glutDisplayFunc(MainMenu);
    glutSpecialFunc(NonPrintableKeys);
    glutKeyboardFunc(PrintableKeys);
    glutMouseFunc(MouseClicked);
    glutPassiveMotionFunc(MouseMoved);
    glutMotionFunc(MousePressedAndMoved);
    
    
    // this function deals with file handlinng (given below)
    startgame();
    
    // Timer to end the game in 3 min
   // glutTimerFunc(1000, endGameTimer, 0);
    
    glutMainLoop();
    return 1;
}


// file handling for leaderboard
void startgame()
{
   
    //funtion will take parameter of score (current game)
    string leaderboard = "/Users/mahamimran/leaderboard.txt";
    ifstream fin;
    ofstream fout;
    
    //INITIALISING ARRAYS
     for(int i=0;i<10;i++){score[i]=-1;}
     for(int i=0;i<10;i++){name[i]="empty";}
    
    //CREATES FILE IF IT DOES NOT ALREADY EXIST, INITIALISING IT
    fout.open(leaderboard,ios::app);
    {
        updatetextfile(leaderboard,score,name);
    }
    fout.close();
    string playername = "" ;
    int newplayerscore = 0 ;
    while(newplayerscore != -1)
    {
        //  cout<<"Enter your name: ";
        // cin>>playername;
        playername = buffer;
        name[0] = playername;
        //  cout<<"Enter score: ";
        newplayerscore = total_score0;
        //newplayerscore = 90;
        DisplayLeaderboard(playername, newplayerscore,leaderboard,name,score);
    }
    
}
void updatetextfile(string leaderboard,int score[],string name[])
{
    ofstream fout;
    fout.open(leaderboard,ios::out);
    if(!fout.eof())
    {
        for(int i=0;i<10;i++)
        {
            string tempscore = to_string(score[i]);
            string line = tempscore + name[i];
            fout<<line<<endl;
        }
    fout.close();
    }
}
void DisplayLeaderboard(string playername, int newplayerscore,string leaderboard,string name[], int score[])
{
    ifstream fin;
    ofstream fout;
    
        //PUTTING CONTENTS OF FILE INTO ARRAY
        fin.open(leaderboard);
        if(fin.is_open())
        {
            string line = "";
            int index = 0;
            while(!(fin.eof()) && index<10)
            {
                    getline(fin,line);
                    string temp = line.substr(0,2);
                    score[index]=stoi(temp);
                    temp = line.substr(2,30);
                    //NAME SHOULD NOT EXCEED 30 LETTERS
                    name[index]=temp;
                    index++;
            }
        }
        //SORTING ARRAY ACCORDING TO SCORE
        for(int index2=0; index2<10;index2++)
        {sort(score,index2,newplayerscore,name,playername);}
        fin.close();
    
    
        //DISPLAYING ARRAYS
        //  displayarrays(name,score);
        
        //UPDATING THE .TXT FILE SORTED
        updatetextfile(leaderboard,score,name);
   
    
}
void sort(int score[],int index2,int newplayerscore,string name[],string playername)
{
     //ARRAY UPDATED IN MIDDLE
    if(newplayerscore>=score[index2] && newplayerscore<score[index2-1] && index2!=0)
         {
             for(int i=9;i>index2;i--)
             {
                 score[i]=score[i-1];
                 name[i]=name[i-1];
             }
             score[index2]=newplayerscore;
             name[index2]=playername;
             index2++;
         }
    //HIGH SCORE
    else if(index2 == 0 && newplayerscore>score[0])
    {
        for(int i=9;i>0;i--)
        {
            score[i]=score[i-1];
            name[i]=name[i-1];
        }
        score[0]=newplayerscore;
        name[0]=playername;
        index2++;
    }
     
}
void displayarrays(string name[], int score[])
{
    for(int i=0;i<10;i++)
    {
        cout<<score[i]<<"  "<<name[i]<<endl;
    }
}

void unit(int x, int y, double c1, double c2, double c3)
{
    glColor3f(c1,c2,c3);
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP); //loop = closed shape
    glVertex2f(x,y);
    glVertex2f(x+100,y);
    glVertex2f(x+100,y+100);
    glVertex2f(x,y+100);
    glEnd();
}
void grid(int gridx,int gridy, int startx, int starty, double c1, double c2, double c3)
{
    for(int i=startx;i<gridx;i+=100)
    {
        for (int j=starty; j<gridy; j+=100)
        {
            unit(i,j,c1,c2,c3);
        }
    }
}
#endif
