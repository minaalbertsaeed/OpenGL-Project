#include "InputHandling.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include "globalVariables.h"

void keyPressed(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            cameraZ -= 0.7f; // Zoom in
            break;
        case 's':
            cameraZ += 0.7f; // Zoom out
            break;
       case 'o': // Open the door
            doorAngle += 5.0f;
            if (doorAngle > 90.0f) doorAngle = 90.0f;
            break;
        case 'c': // Close the door
            doorAngle -= 5.0f;
            if (doorAngle < 0.0f) doorAngle = 0.0f;
            break;   
       case 'O': // Open the door
            windowAngle += 5.0f;
            if (windowAngle > 90.0f) windowAngle = 90.0f;
            break;
        case 'C': // Close the door
            windowAngle -= 5.0f;
            if (windowAngle < 0.0f) windowAngle = 0.0f;
            break;   
        default:
        break;
    }

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

