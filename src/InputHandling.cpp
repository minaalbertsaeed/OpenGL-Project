#include "InputHandling.h"
#include <GL/freeglut_std.h>
#include <GL/glut.h>
#include "globalVariables.h"

// bool keys[256];
// void keyPressed(unsigned char key, int x, int y) {
//     keys[key] = true;
// }
//
// void keyReleased(unsigned char key, int x, int y) {
//     keys[key] = false;
// }

// void updateKeyInput() {
//
//     if (keys['r']) {
//         cameraZ -= 1.0f;
//     }
//
//     glutPostRedisplay();
// }
void keyPressed(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            cameraZ -= 0.7f; // Zoom in
            break;
        case 's':
            cameraZ += 0.7f; // Zoom out
            break;
    }
    // if (cameraZ < 1.0f) cameraZ = 1.0f; 
    // if (cameraZ > 10.0f) cameraZ = 5.0f; 

    glutPostRedisplay();
}


void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            angleX -= 5.1f; // Move up
            break;
        case GLUT_KEY_DOWN:
            angleX += 10.1f; // Move down
            break;
        case GLUT_KEY_LEFT:
            angleY -= 10.1f; // Move left
            break;
        case GLUT_KEY_RIGHT:
            angleY += 10.1f; // Move right
            break;
    }
}

void mouseClick(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_LEFT_BUTTON :
            switch (state) { // DOWN or UP
                case GLUT_DOWN:
                    lastX = x;
                    lastY = y;
                    rotation = true;
                    break;

                case GLUT_UP:
                    rotation = false;

                default:
                    break;
            }
    }
    
        glutPostRedisplay();
}


void mouseMotion(int x, int y) {

    if (rotation) {
        angleX += (x - lastX ) * 0.1f;
        angleY += (y - lastY ) * 0.1f;

        lastX = x;
        lastY = y;

    }
        glutPostRedisplay();
}

