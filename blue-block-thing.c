#include<stdio.h>
#include<math.h>

#include<GLUT/glut.h>
#include<stdlib.h>

#include <time.h>
#include <unistd.h>


double a, y, x, duh, der, myx, myy, extra;


GLdouble width = 640, height = 480;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);
    for (x = 0; x < width; x++)
    for (y = 0; y < height; y++) 
    {    
        double xloc = sin(x*y + extra * 0.66667);
        glColor3f(0.2, 0, xloc);
        glVertex2f(x, y);
        extra++;
    }
    glEnd();
    glutSwapBuffers();
}

void init (void)
{
    extra = 100;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glDisable(GL_DEPTH_TEST);
}

int main(int argc, char* argv[])
{

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (width, height);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    glutIdleFunc(display);
    init ();
    glutDisplayFunc(display);
    glutMainLoop();

    return(0);
}

