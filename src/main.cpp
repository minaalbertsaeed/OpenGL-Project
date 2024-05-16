#ifdef WIN32
    #include "winbase.h"
    #include "windef.h"
#endif

#include <iostream>  
#include <GL/gl.h>  
#include <GL/glu.h> 
#include <GL/glut.h>
#include <vector>
#include "InputHandling.h"
#include "globalVariables.h"
#include "DrawingUtilities.h"

using Vector = std::vector<std::vector<GLfloat>>;
// #include ""  
GLfloat angleCube;
GLfloat anglePyramid;

GLfloat angleX = 0.0f;
// GLfloat angleZ = 0.0f;
GLfloat angleY = 0.0f;
GLint lastX;
GLfloat cameraZ = 5.0f;
GLint lastY;
bool rotation = false;

/* Global variables */
int refreshMills = 15;        

void timer(int value) {
   glutPostRedisplay();      
   glutTimerFunc(refreshMills, timer, 0); 
}

void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (double)w / h, 1, 100);
    glMatrixMode(GL_MODELVIEW);
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
int i = 0;

void drawLand(void)
{
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_LINES);
    for(GLfloat i =- 100.0f; i < 100.0f; i += 1.0f) {
        glVertex3f(-100.0f,-9.0f,i);
        glVertex3f( 100.0f,-9.0f,i);
        glVertex3f(i,-9.0f,-100.0f);
        glVertex3f(i,-9.0f,100.0f);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    // Draw land Grid 
    drawLand();
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 10 + cameraZ,   // Eye position
             0.0, 0.0, 0.0,             // Center position (look at)
             0.0, 1.0, 0.0);            // Up vector

    glRotatef(angleY , 0, 1, 0); // Rotate around Y-axis
    glRotatef(angleX , 1, 0, 0); // Rotate around X-axis

    glTranslatef(-1.5, 0,0 ); // Rotate around Z-axis
    glColor3f(1.0f,1.0f,1.0f);
    glutSolidSphere(5, 100, 32);

    glTranslatef(-7.0, 0,0 ); // Rotate around Z-axis
    glColor3f(1.0f,1.0f,1.0f);
    glutSolidSphere(5, 100, 64);

    drawCube(2.0, 2.5, 1.0 , 0.0, 0.0, 0.0); 
    // glFlush(); 
    glutSwapBuffers();  
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);            
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(1920, 1080);
    glutCreateWindow("test");

    // Callback Functions
    initGL();                               // My own OpenGL initialization
    glEnable(GL_DEPTH_TEST);                // Enable depth testing for z-culling
    glutDisplayFunc(display);               // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);               // Register callback handler for window re-size event
    glutKeyboardFunc(keyPressed);           // Register callback handler for keyboard input
    glutMouseFunc(mouseClick);              // Register callback handler for mouse clicks
    glutMotionFunc(mouseMotion);            // Register callback handler for mouse motion
    glutSpecialFunc(specialKeys);           // Register callback handler for special keys
    glutTimerFunc(0, timer, 0);             // First timer call immediately [NEW]
    glutMainLoop();                         // Enter the infinite event-processing loop
    return 0;
}
