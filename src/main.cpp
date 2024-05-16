#ifdef WIN32
    #include "winbase.h"
    #include "windef.h"
#endif

// #include <iostream>  
#include <GL/gl.h>  
#include <GL/glu.h> 
#include <GL/glut.h>
#include "InputHandling.h"
#include "globalVariables.h"
#include "DrawingUtilities.h"

// #include ""  
GLfloat angleCube;
GLfloat anglePyramid;

/* Global variables */
int refreshMills = 15;        

void timer(int value) {
   glutPostRedisplay();      
   glutTimerFunc(refreshMills, timer, 0); 
}

void reshape(GLsizei width, GLsizei height) {  

   if (height == 0) height = 1;                
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   glViewport(0, 0, width, height);
 

   glMatrixMode(GL_PROJECTION);  
   glLoadIdentity();

   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}




void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        anglePyramid += 1.0f;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        anglePyramid -= 1000.0f;
    }
}


void mouseMotion(int x, int y) {

}

/* Initialize OpenGL Settings */
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   // Set background color to black and opaque
    glClearDepth(1.0f);                     // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);                // Enable depth testing for z-culling
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 2, 10);
    glMatrixMode(GL_MODELVIEW);
    glDepthFunc(GL_LEQUAL);                 // Set the type of depth-test
    glShadeModel(GL_SMOOTH);                // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW);     

    // gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); // Camera position

    glRotatef(0.0, 0, 1, 0); 
    glRotatef(0.0, 1, 0, 0); 

    drawCube(-5.0, 0.0, -10.0); 
    drawCube(5.0, 0.0, -10.0); 
    drawCube(0.0, -2.5, -10.0); 
    drawCube(0.0, 2.5, -10.0); 
    // glFlush(); 
    glutSwapBuffers();  


    anglePyramid += 0.2f;
    angleCube -= 0.15f;
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);            
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(1920, 1080);
    glutCreateWindow("test");

    // Callback Functions
    initGL();                               // My own OpenGL initialization
    glutReshapeFunc(reshape);               // Register callback handler for window re-size event
    glutKeyboardFunc(keyPressed);           // Register callback handler for keyboard input
    glutKeyboardUpFunc(keyReleased);        // Register callback handler for keyboard release
    glutMouseFunc(mouseClick);              // Register callback handler for mouse clicks
    glutMotionFunc(mouseMotion);            // Register callback handler for mouse motion
    glutIdleFunc(updateKeyInput);           // Register callback handler for update

    glutDisplayFunc(display);               // Register callback handler for window re-paint event
    glutTimerFunc(0, timer, 0);             // First timer call immediately [NEW]
    glutMainLoop();                         // Enter the infinite event-processing loop
    return 0;
}
