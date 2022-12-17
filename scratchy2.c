#include<stdio.h>
#include<math.h>

#include<GLUT/glut.h>
#include<stdlib.h>

#include <time.h>
#include <unistd.h>


int x, y;
double a, duh, der, myx, myy, extra;


GLdouble width = 640, height = 480;


// double imagemap[][] = new double [width][height];

double imagemap[640][480];

void display(void)
{
    // clear all pixels? */
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a point
    glBegin(GL_POINTS);
    //glVertex2f(width / 2, height / 2);
    for (x = 0; x < width; x++)
    for (y = 0; y < height; y++) 
    {    
        extra = extra + 0.00001;
        duh = (64.0 + (640.0 * sin(x / 8.0))+ 640.0 + (640.0 * sin(y / 3.0))) / 4000 * sin(extra * 0.978); 
        der = (128.0 + (64.0 * sin(sqrt((x - width / 8.0) * (x - width / 8.0) + (y - height / 8.0) * (y - height / 8.0)) / 8.0)))/200 * sin(extra*2);
        duh = duh + der;
        imagemap[(int)x][(int)y] = duh;
        // Everything above here ^ should be pre-rendered.  Maybe we should start with a sin table and let the rest be realtime?
        glColor3f(imagemap[x][y], imagemap[x][x], imagemap[y][y]);
        glVertex2f(x,y); 
 
        if (extra > 3.0) extra = 0.00001;
    }
    glEnd();

    //SwapBuffers();    // this doesn't seem to work outside of windows? :(
    // ^ Very old comment left in for lul'z sake
    glutSwapBuffers();
    //glFlush();
}

void init (void)
{
    extra = 0.00001;
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

