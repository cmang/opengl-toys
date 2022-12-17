/* Mac OS X use:
 * gcc -framework OpenGL -framework GLUT
 * Linux use:
 * gcc -lglut 
 * -cmang
 */


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>


#ifdef __APPLE__
    #include<GLUT/glut.h>
#else
    #include<GL/glut.h>
#endif



#define WIDTH 640
#define HEIGHT 480

int x, y;
double duh, der, extra;


GLdouble width = WIDTH, height = HEIGHT;


double imagemap[WIDTH][HEIGHT];

void display(void)
{
    // clear all pixels? */
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw by points
    glBegin(GL_POINTS);
    for (x = 0; x < width; x++)
    for (y = 0; y < height; y++) 
    {    
        extra = extra + 0.00001;
        duh = (640.0 + (640.0 * sin(x / 8.0))+ 640.0 + (640.0 * sin(y / 2.0))) / 4000 * sin(extra); 
        der = (128.0 + (64.0 * sin(sqrt((x - width / 8.0) * (x - width / 8.0) + (y - height / 8.0) * (y - height / 8.0)) / 8.0)))/200; // * sin(extra);
        duh = duh + der;
        imagemap[(int)x][(int)y] = duh;
        glColor3f(imagemap[x][y], imagemap[x][x], imagemap[y][y]);
        glVertex2f(x,y);
        if (extra > 3.0) extra = 0.00001;
    }
    glEnd();
    glutSwapBuffers();
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

