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
        //unsigned int c = myx ^ myy; 
        //duh = duh + 0.003 * 4.0*atan(1.0);
        //duh = duh + 0.01;
        //duh = sin(myy*a);
        //der = sin(myx*a);
        //double xloc = sin(x*y + extra * 0.66667);                 // original
//        double xloc = cos(x + (extra * 0.1) * y * 0.66667);       // this one is cool.
        //double xloc = cos(sin(x + extra * y * 0.66667));
        //glColor3f(xloc, xloc / 2, 0.7);
        //glVertex2f(x, y);
        extra = extra + 0.00001;
    
        duh = (64.0 + (64.0 * sin(x / 2.0))+ 640.0 + (640.0 * sin(y / 8.0))) / 2000 * sin(extra);
        //der = (128.0 + (128.0 * sin(sqrt((x - width / 2.0) * (x - width / 2.0) + (y - height / 2.0) * (y - height / 2.0)) / 8.0)))/20;
        //der = 0.0;
        //duh = duh + der;
        //if (colorz > 255) colorz = colorz * 0.5;  // turn white into black
        imagemap[(int)x][(int)y] = duh;
        glColor3f(imagemap[x][y], imagemap[x][x], imagemap[y][y]);
        glVertex2f(x,y);
 
        //double c2 = (double) c / 1000;
 //       glColor3f(c2, sin(duh), der);
        //printf("%f\n", duh);
//        glVertex2f(myx, myy);
        //glColor3f(der, duh/7, duh);
        //glVertex2f(der * width, duh * height);
        //if (duh > 1.0) duh = 0.001;
        if (extra > 1.0) extra = 0.00001;
    }
    //a = a + 0.2;
    glEnd();
    //duh = duh +1;
    //printf("%f\n", duh);
    
    //if (duh > 1) duh = 0.001;

    //SwapBuffers();    // this doesn't seem to work outside of windows? 
    glutSwapBuffers();
    //glFlush();
}

void init (void)
{
    //duh = 0.001;
    //a = 1;
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

