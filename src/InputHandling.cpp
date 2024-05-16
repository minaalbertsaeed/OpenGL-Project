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

