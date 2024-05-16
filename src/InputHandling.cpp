#include <GL/glut.h>
#include "globalVariables.h"

bool keys[256];
void keyPressed(unsigned char key, int x, int y) {
    keys[key] = true;
}

void keyReleased(unsigned char key, int x, int y) {
    keys[key] = false;
}

void updateKeyInput() {

    if (keys['r']) {
        angleCube += 1.0f;
    }

    glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_LEFT_BUTTON :
            switch (state) { // DOWN or UP
                case GLUT_DOWN:
                    angleCube += 10.0f;
                    break;

                default:
                    break;
            }
    }
    
}


void mouseMotion(int x, int y) {

}

