#ifndef InputHandling
#define InputHandling

#include <GL/gl.h>  
#include <GL/glu.h> 
#include <GL/glut.h>

void keyPressed(unsigned char key, int x, int y);
void keyReleased(unsigned char key, int x, int y);
// void updateKeyInput();
void mouseClick(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void specialKeys(int key, int x, int y);


#endif // !InputHandling
