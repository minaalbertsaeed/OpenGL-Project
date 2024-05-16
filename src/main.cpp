#ifdef WIN32
    #include "winbase.h"
    #include "windef.h"
#endif
#include <iostream>  
#include <GL/gl.h>  
// #include <GL/glew.h>
#include <GL/glu.h> 
#include <GL/glut.h>
// #include <GL/freeglut.h>  

/* Global variables */
GLfloat anglePyramid = 0.0f;  // Rotational angle for pyramid [NEW]
GLfloat angleCube = 0.0f;     // Rotational angle for cube [NEW]
int refreshMills = 15;        // refresh interval in milliseconds [NEW]

/* Global variable to track key states */
bool keys[256];

/* Global variable to track left mouse button state */
bool leftMouseButtonPressed = false;
 
/* Called back when timer expired [NEW] */
void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}/* Global variable to track key states */

/* Function to handle keyboard input */
void keyPressed(unsigned char key, int x, int y) {
    keys[key] = true;
}

void keyReleased(unsigned char key, int x, int y) {
    keys[key] = false;
}

/* Function to handle mouse clicks */
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        anglePyramid += 1.0f;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        anglePyramid -= 1000.0f;
		// leftMouseButtonPressed = true;
    }
}

/* Function to handle mouse motion */
void mouseMotion(int x, int y) {
    // Handle mouse motion
}

/* Update function to handle key presses */
void updateKeyInput() {
    // Example: Rotate cube when 'r' key is pressed
    if (keys['r']) {
        angleCube += 1.0f;
    }
    if (keys['R']) {
        angleCube -= 1.0f;
    }

    // Add your update logic here

    glutPostRedisplay(); // Request redraw
}

/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1, 1, -1, 1, 2, 10);
    glMatrixMode(GL_MODELVIEW);
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void drawCube(GLfloat  x, GLfloat y, GLfloat  z){

   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(x, y, z);  // Move right and into the screen
   glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]
   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f,  1.0f);
 
      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
 
      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
 
      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
 
      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
 
      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();  // End of drawing color-cube


}
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

    // gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); // Camera position

    glRotatef(0.0, 0, 1, 0); // Rotate around Y-axis
    glRotatef(0.0, 1, 0, 0); // Rotate around X-axis

    drawCube(-5.0, 0.0, -10.0); 
    drawCube(5.0, 0.0, -10.0); 
    drawCube(0.0, -2.5, -10.0); 
    drawCube(0.0, 2.5, -10.0); 
    // glFlush(); 
    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

    // Update the rotational angle after each refresh [NEW]
    anglePyramid += 0.2f;
    angleCube -= 0.15f;
}



/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT

    // Request double buffered true color window with Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    // glutInitDisplayMode( GLUT_DOUBLE |GLUT_DEPTH);

    glutInitWindowSize(1920, 1080);     // Set the window's initial width & height
    glutCreateWindow("test");          // Create window with the given title

    // Callback Functions
    initGL();                         // Our own OpenGL initialization
    glutReshapeFunc(reshape);               // Register callback handler for window re-size event
    glutKeyboardFunc(keyPressed);           // Register callback handler for keyboard input
    glutKeyboardUpFunc(keyReleased);        // Register callback handler for keyboard release
    glutMouseFunc(mouseClick);              // Register callback handler for mouse clicks
    glutMotionFunc(mouseMotion);            // Register callback handler for mouse motion
    glutIdleFunc(updateKeyInput);           // Register callback handler for update


    glutDisplayFunc(display);             // Register callback handler for window re-paint event
    glutTimerFunc(0, timer, 0);       // First timer call immediately [NEW]
    glutMainLoop();                   // Enter the infinite event-processing loop
    return 0;
}
