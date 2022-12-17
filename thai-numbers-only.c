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


double width = WIDTH, height = HEIGHT;


double imagemap[WIDTH][HEIGHT];

void display(void)
{
    printf("glFloat colors[] = \n{\n");
    for (x = 0; x < width; x++)
    for (y = 0; y < height; y++) 
    {    
        extra = extra + 0.00001;
        duh = (640.0 + (640.0 * sin(x / 8.0))+ 640.0 + (640.0 * sin(y / 2.0))) / 4000 * sin(extra); 
        der = (128.0 + (64.0 * sin(sqrt((x - width / 8.0) * (x - width / 8.0) + (y - height / 8.0) * (y - height / 8.0)) / 8.0)))/200; // * sin(extra);
        duh = duh + der;
        imagemap[(int)x][(int)y] = duh;

        // ORIGINAL (bad) CODE:
        //glColor3f(imagemap[x][y], imagemap[x][x], imagemap[y][y]);
        //glVertex2f(x,y);

        //Color array, for use instead of the code above::
        printf("%f, %f, %f, 1.0,\n", imagemap[x][y], imagemap[x][x], imagemap[y][y]);

        
        //printf("Vertex: %i, %i\n", x, y);
        if (extra > 3.0) extra = 0.00001;
    }
    printf("}\n");
}

int main(int argc, char* argv[])
{
    extra = 0.00001;
    display();

    return(0);
}

