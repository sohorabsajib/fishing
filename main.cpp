/*
 * PROJECT NAME: Draw a Fishing Scene using glut, openGL & c++
 * PROGRAMMER: MD. TOUHIDUL ISLAM SHAWAN
 * ID: 171-15-9354
 * PROJECT_START_DATE: 29 JULY 2020 12.00 AM
 * SUBMITTED TO : ESHITA KHATUN
 * GITHUB: https://github.com/touhidulShawan/fishing
 */
#include <iostream>
//#include <windows.h> // uncomment this if you are on windows machine
#include <GL/glut.h>

using namespace std;

//all declarations of my functions
void greeting();

void setup(int argc, char **argv);

void init();

void reshape(GLsizei width, GLsizei height);

void draw();

//my global variables
char input;

int main(int argc, char **argv)
{
    greeting();
    //    if user correctly enter keyword s then start the main window else exit
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
    init();
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
    glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
    glLoadIdentity();            // Reset the projection matrix
    if (width >= height)
    {
        // aspect >= 1, set the height from -1 to 1, with larger width
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    }
    else
    {
        // aspect < 1, set the width to -1 to 1, with larger height
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }
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
 */

//all the drawing goes here
void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //    draw sky
    glColor3f(0.5, 0.82, 0.95);
    glRectf(-1.75, 0.0, 1.75, 1.0);

    //    draw mountain
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
    glutSwapBuffers();
}
