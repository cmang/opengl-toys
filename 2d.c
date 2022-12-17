/* 2D Template for OpenGL
   Sam Foster 
*/


#include<stdio.h>
#include<math.h>

#include<GL/glut.h>
#include<stdlib.h>

int a;
double y, x;

GLdouble width = 640, height = 480;

void display(void)
{
    // clear all pixels? */
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a point
    glBegin(GL_POINTS);
    glVertex2f(width / 2, height / 2);
    glEnd();

    glFlush();
}

void init (void)
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glDisable(GL_DEPTH_TEST);
}

int main(int argc, char* argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (width, height);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();



    for (a=1; a<25; a++)
    {
        x = sin(random());
        y = sin(random());
        printf("%f, %f\n", x, y);
    }
    return(0);
}

