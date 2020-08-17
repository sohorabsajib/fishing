/*
 * PROJECT NAME: Draw a Fishing Scene using glut, openGL & c++
 * PROGRAMMER: MD. TOUHIDUL ISLAM SHAWAN
 * ID: 171-15-9354
 * PROJECT_START_DATE: 29 JULY 2020 12.00 AM
 * SUBMITTED TO : ESHITA KHATUN
 * GITHUB: https://github.com/touhidulShawan/fishing
 */
#include <iostream>
#include <GL/glut.h>
#include <cmath>
// uncomment these if you are on windows machine
// #include <windows.h>
// #include <MMsystem.h>

using namespace std;

//all declarations of my functions
void greeting();

void setup(int argc, char **argv);

void init();

void reshape(GLsizei width, GLsizei height);

void draw();

void drawGrass(float x1, float heightOfGrass);

void first_bird();

void second_bird();

void drawFirstFish();

void drawSecondFish();

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy);

void specialKeyPressed(int key, int x, int y);

void timer(int value);

//my global variables
char input;
float position = -1.75;
float first_fish_position = 1.75;
float second_fish_positon = -1.75;
float bar_postion = 0.07;
float hand_positon = -0.01;

int main(int argc, char **argv)
{
    greeting();

    // if user correctly enter keyword s then start the main window else exit

    if (input == 's')
    {
        setup(argc, argv);
    }
    else
    {
        cout << "You enter wrong keyword :(" << endl;
        exit(0);
    }
}

//greeting for user before start
void greeting()
{
    cout << "*** Welcome to Fishing ***" << endl;
    cout << "-> Press s to start" << endl;
    cout << "> ";
    cin >> input;
}

//initial setup of glut
void setup(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(1124, 645);
    glutInitWindowPosition(100, 10);
    glutCreateWindow("Fishing");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutIdleFunc(draw);
    glutTimerFunc(0, timer, 0);
    init();
    glutSpecialFunc(specialKeyPressed);
    glutMainLoop();
}

void init()
{
    glClearColor(1, 1, 1, 1); // just change the default bg color of window
}

//reshape the workspace

void reshape(GLsizei width, GLsizei height)
{ // GLsizei for non-negative integer
    // To prevent divide by 0
    if (height == 0)
        height = 1;
    // calculate aspect ratio of the new window
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping area to match the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (width >= height)
    {
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    }
    else
    {
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }
}

//draw circle
void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for (int i = 0; i <= 100; i++)
    {
        float angle = 2 * M_PI * i / 100;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

//my color palette for drawing
/*
 * Skyblue -> 0.5, 0.82, 0.95
 * LightGreen -> 0.6, 0.75, 0.06
 * DarkGreen -> 0.28, 0.35, 0.0078
 * Ash -> 0.82, 0.84, 0.85
 * Blue -> 0.26, 0.62, 0.85
 * Yellow -> 0.95, 0.89, 0.11
 * DarkBlue -> 0.02, 0.067, 0.95
 * Red -> 0.851, 0.028, 0.09
 * Orange -> 0.95, 0.46, 0.02
 * Brown -> 0.35, 0.17, 0.1
 * Skin -> 0.94, 0.69, 0.6
 */

//all the drawing goes here
void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // draw sky
    glColor3f(0.5, 0.82, 0.95);
    glRectf(-1.75, 0.0, 1.75, 1.0);

    // draw mountain
    glBegin(GL_TRIANGLES);
    glColor3f(0.82, 0.84, 0.85);
    // 1st mountain
    glVertex2f(-1.7, 0.0);
    glVertex2f(-0.5, 0.0);
    glVertex2f(-1.1, 0.75);
    // 2nd mountain
    glVertex2f(-0.4, 0.0);
    glVertex2f(0.8, 0.0);
    glVertex2f(0.2, 0.575);
    // 3rd mountain
    glVertex2f(0.9, 0.0);
    glVertex2f(1.68, 0.0);
    glVertex2f(1.29, 0.7);
    glEnd();
    // draw trees

    // 1st tree
    glColor3f(0.35, 0.17, 0.1);
    glRectf(-1.4, 0.0, -1.3, 0.4);
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.75, 0.06);
    glVertex2f(-1.6, 0.4);
    glVertex2f(-1.1, 0.4);
    glVertex2f(-1.35, 0.6);
    glEnd();
    // 2nd tree
    glColor3f(0.35, 0.17, 0.1);
    glRectf(-0.7, 0.0, -0.6, 0.5);
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.75, 0.06);
    glVertex2f(-0.9, 0.5);
    glVertex2f(-0.4, 0.5);
    glVertex2f(-0.65, 0.8);
    glEnd();
    // 3rd tree
    glColor3f(0.35, 0.17, 0.1);
    glRectf(-0.1, 0.0, 0.0, 0.3);
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.75, 0.06);
    glVertex2f(-0.3, 0.3);
    glVertex2f(0.2, 0.3);
    glVertex2f(-0.05, 0.6);
    glEnd();
    // 4th tree
    glColor3f(0.35, 0.17, 0.1);
    glRectf(0.5, 0.0, 0.8, 0.6);
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.75, 0.06);
    glVertex2f(0.3, 0.6);
    glVertex2f(1, 0.6);
    glVertex2f(0.65, 0.88);
    glEnd();
    // 5th tree
    glColor3f(0.35, 0.17, 0.1);
    glRectf(1.3, 0.0, 1.6, 0.4);
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.75, 0.06);
    glVertex2f(1.1, 0.4);
    glVertex2f(1.8, 0.4);
    glVertex2f(1.45, 0.75);
    glEnd();
    // draw grass
    drawGrass(-1.75, 0.1);
    drawGrass(-1.73, 0.11);
    // draw portion of land
    glColor3f(0.6, 0.75, 0.06);
    glRectf(-1.75, 0.0, 1.75, -0.15);
    // draw  sea
    glColor3f(0.26, 0.62, 0.85);
    glRectf(-1.75, -0.15, 1.75, -1);
    // draw fish
    glPushMatrix();
    glTranslatef(first_fish_position, 0.0, 0.0);
    drawFirstFish();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.38, 0.0);
    glTranslatef(second_fish_positon, 0.0, 0.0);
    drawSecondFish();
    glPopMatrix();

    // draw branch
    glColor3f(0.35, 0.17, 0.1);
    glRectf(-1.75, -0.4, -0.3, -0.58);
    // draw the 2 pillar
    glRectf(-0.9, -0.27, -0.98, -0.9);
    glRectf(-0.85, -0.27, -0.77, -0.9);
    // draw cartoon person
    glColor3f(0.02, 0.067, 0.95);
    // leg
    glRectf(-0.5, -0.3, -0.2, -0.4);
    glRectf(-0.3, -0.4, -0.2, -0.8);
    // foot
    glColor3f(0.35, 0.17, 0.1);
    glRectf(-0.3, -0.8, -0.13, -0.88);
    // body
    glColor3f(0.95, 0.46, 0.02);
    glRectf(-0.5, 0.0, -0.2, -0.3);
    // head
    glColor3f(0.94, 0.69, 0.6);
    circle(0.15, 0.15, -0.35, 0.13);
    // eye
    glColor3f(1, 1, 1);
    circle(0.05, 0.05, -0.32, 0.14);
    glColor3f(0.0078, 0.0196, 0.051);
    circle(0.02, 0.02, -0.32, 0.14);
    // hand
    glColor3f(0.94, 0.69, 0.6);
    glPushMatrix();
    glTranslatef(0.0, hand_positon, 0.0);
    glRectf(-0.2, -0.1, 0.1, -0.18);
    glPopMatrix();

    // fishing bar
    glPushMatrix();
    glTranslated(0, bar_postion, 0.0);
    glColor3f(0.28, 0.35, 0.0078);
    glBegin(GL_POLYGON);
    glVertex2f(-0.15, 0.08);
    glVertex2f(0.3, -0.5);

    glVertex2f(0.3, -0.5);
    glVertex2f(0.35, -0.52);

    glVertex2f(0.35, -0.52);
    glVertex2f(-0.13, 0.1);

    glVertex2f(-0.13, 0.1);
    glVertex2f(-0.15, 0.08);
    glEnd();
    glPopMatrix();

    // draw a sun
    glColor3f(0.851, 0.028, 0.09);
    circle(0.15, 0.15, -1.70, 0.9);

    // draw some birds
    glPushMatrix();
    glTranslatef(position, 0.0, 0.0);
    first_bird();
    second_bird();
    glPopMatrix();

    glutSwapBuffers();
}

void drawGrass(float x1, float heightOfGrass)
{
    float x2 = x1 + 0.05;
    float middlePoint = (x1 + x2) / 2;
    float y1 = 0.0;
    glColor3f(0.28, 0.35, 0.0078);
    glBegin(GL_TRIANGLES);
    while (x1 < 1.75)
    {
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(middlePoint, heightOfGrass);

        // update next point to draw continuously
        x1 += 0.05;
        x2 = x1 + 0.05;
        middlePoint = (x1 + x2) / 2;
    }
    glEnd();
}

void first_bird()
{
    //    yellow body bird
    // body
    glColor3f(0.95, 0.89, 0.11);
    circle(0.09, 0.038, -0.5, 0.9);
    //head
    glColor3f(0.95, 0.46, 0.02);
    circle(0.034, 0.034, -0.4, 0.9);
    // eye
    glColor3f(1, 1, 1);
    circle(0.013, 0.013, -0.39, 0.9);

    //beak
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.35, 0.17, 0.1);
    glVertex2f(-0.39, 0.9);
    glVertex2f(-0.32, 0.83);
    glEnd();

    //    tail
    glBegin(GL_TRIANGLES);
    glColor3f(0.851, 0.028, 0.09);
    glVertex2f(-0.68, 0.9);
    glColor3f(0.95, 0.46, 0.02);
    glVertex2f(-0.54, 0.9);
    glColor3f(0.6, 0.75, 0.06);
    glVertex2f(-0.68, 0.98);
    glEnd();
    // wing
    glBegin(GL_TRIANGLES);
    glColor3f(0.6, 0.75, 0.06);
    glVertex2f(-0.55, 0.83);
    glColor3f(0.95, 0.46, 0.02);
    glVertex2f(-0.45, 0.83);
    glColor3f(0.851, 0.028, 0.09);
    glVertex2f(-0.5, 0.9);
    glEnd();
}

void second_bird()
{
    // orange body bird
    // body
    glColor3f(0.95, 0.46, 0.02);
    circle(0.09, 0.038, 0.1, 0.9);
    //head
    glColor3f(0.02, 0.067, 0.95);
    circle(0.034, 0.034, 0.19, 0.9);
    // eye
    glColor3f(1, 1, 1);
    circle(0.013, 0.013, 0.2, 0.9);

    //beak
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3f(0.35, 0.17, 0.1);
    glVertex2f(0.2, 0.9);
    glVertex2f(0.27, 0.83);
    glEnd();

    //    tail
    glBegin(GL_TRIANGLES);
    glColor3f(0.851, 0.028, 0.09);
    glVertex2f(-0.1, 0.9);
    glColor3f(0.35, 0.17, 0.1);
    glVertex2f(0.05, 0.9);
    glColor3f(0.95, 0.89, 0.11);
    glVertex2f(-0.1, 0.98);
    glEnd();
    // wing
    glBegin(GL_TRIANGLES);
    glColor3f(0.95, 0.89, 0.11);
    glVertex2f(0.05, 0.83);
    glColor3f(0.35, 0.17, 0.1);
    glVertex2f(0.14, 0.83);
    glColor3f(0.851, 0.028, 0.09);
    glVertex2f(0.095, 0.9);
    glEnd();
}

void drawFirstFish()
{
    // draw 1st fish

    //    wing bottom
    glBegin(GL_TRIANGLES);
    glColor3f(0.82, 0.84, 0.85);
    glVertex2f(0.9, -0.54);
    glVertex2f(1.1, -0.54);
    glVertex2f(1, -0.45);
    glEnd();

    //    wing top
    glBegin(GL_TRIANGLES);
    glColor3f(0.82, 0.84, 0.85);
    glVertex2f(0.9, -0.24);
    glVertex2f(1.1, -0.24);
    glVertex2f(1, -0.35);
    glEnd();

    //    tail
    glBegin(GL_TRIANGLES);
    glColor3f(0.82, 0.84, 0.85);
    glVertex2f(1.25, -0.44);
    glVertex2f(1.25, -0.34);
    glVertex2f(1.15, -0.39);
    glEnd();

    //    body
    glColor3f(0.95, 0.46, 0.02);
    circle(0.2, 0.099, 1, -0.4);
    glColor3f(0.94, 0.69, 0.6);
    circle(0.009, 0.078, .93, -0.4);
    //    eye
    glColor3f(1, 1, 1);
    circle(0.02, 0.02, 0.85, -0.4);
    //    eyeball
    glColor3f(0, 0, 0);
    circle(0.01, 0.01, 0.85, -0.4);
}

void drawSecondFish()
{
    // draw 2nd fish

    //    wing bottom
    glBegin(GL_TRIANGLES);
    glColor3f(0.82, 0.84, 0.85);
    glVertex2f(-0.9, -0.54);
    glVertex2f(-1.1, -0.54);
    glVertex2f(-1, -0.45);
    glEnd();

    //    wing top
    glBegin(GL_TRIANGLES);
    glColor3f(0.82, 0.84, 0.85);
    glVertex2f(-0.9, -0.24);
    glVertex2f(-1.1, -0.24);
    glVertex2f(-1, -0.35);
    glEnd();

    //    tail
    glBegin(GL_TRIANGLES);
    glColor3f(0.82, 0.84, 0.85);
    glVertex2f(-1.25, -0.44);
    glVertex2f(-1.25, -0.34);
    glVertex2f(-1.15, -0.39);
    glEnd();

    //    body
    glColor3f(0.95, 0.46, 0.02);
    circle(0.2, 0.099, -1, -0.4);
    glColor3f(0.94, 0.69, 0.6);
    circle(0.009, 0.078, -0.93, -0.4);
    //    eye
    glColor3f(1, 1, 1);
    circle(0.02, 0.02, -0.85, -0.4);
    //    eyeball
    glColor3f(0, 0, 0);
    circle(0.01, 0.01, -0.85, -0.4);
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 600, timer, value);

    // reassign the x axis value of bird

    if (position < 2.85)
        position += 0.007;
    else
        position = -1.75;

    // re-assign the x value of first fish

    if (first_fish_position > -2.85)
        first_fish_position -= 0.007;
    else
        first_fish_position = 1.75;

    // re-assign the x value of second fish

    if (second_fish_positon < 2.85)
        second_fish_positon += 0.007;
    else
        second_fish_positon = -1.75;

    // re-assign the y value of fishing bar
    if (bar_postion < 0.08)
        bar_postion += 0.001;
    else
        bar_postion = 0.07;

    // re-assing the y value for hand moving
    if (hand_positon < 0)
        hand_positon += 0.001;
    else
        hand_positon = -0.01;
}

// play sound when up arrow key pressed from keyboard and stop playing sound when down arrow key pressed

void specialKeyPressed(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        // uncomment below line if you are on windows
        //  PlaySound("fishing_music.wav", NULL, SND_ASYNC | SND_FILENAME);
        glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:
        // uncomment below line if you are on windows
        // PlaySound(NULL, NULL, 0);
        glutPostRedisplay();
        break;
    default:
        break;
    }
}