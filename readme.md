Just some old OpenGL/GLUT demos I made a long time ago.

When building in Linux, the -l options should be placed after the source to properly link dependencies:

gcc -Wall -o name name.c -lGL -lglut -lm


