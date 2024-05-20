#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include "globalVariables.h"
#include "DrawingUtilities.h"

void drawCuboid(GLfloat height, GLfloat width, GLfloat depth, GLfloat xc, GLfloat yc, GLfloat zc){
     ArrayOfVertices vertices = {{
            {(xc - 0.5f * width), (yc + 0.5f * height), zc}, // Top-Left (0)
            {(xc + 0.5f * width), (yc + 0.5f * height), zc}, // Top-Right (1
            {(xc + 0.5f * width), (yc - 0.5f * height), zc}, // Bottom-Right (2 
            {(xc - 0.5f * width), (yc - 0.5f * height), zc}, // Bottom-Left 3 

            {(xc - 0.5f * width), (yc + 0.5f * height), zc - depth}, // Top-Left 4 
            {(xc + 0.5f * width), (yc + 0.5f * height), zc - depth}, // Top-Right 5 
            {(xc + 0.5f * width), (yc - 0.5f * height), zc - depth}, // Bottom-Right 6 
            {(xc - 0.5f * width), (yc - 0.5f * height), zc - depth}, // Bottom-Left 7 

    }};


    glBegin(GL_QUADS);
        // glColor3f(1.0f, 0.0f, 0.0f);     // Green
        glVertex3f(vertices[0][0], vertices[0][1], vertices[0][2]);
        glVertex3f(vertices[1][0], vertices[1][1], vertices[1][2]);
        glVertex3f(vertices[2][0], vertices[2][1], vertices[2][2]);
        glVertex3f(vertices[3][0], vertices[3][1], vertices[3][2]);

        // glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3f(vertices[0][0], vertices[0][1], vertices[0][2]);
        glVertex3f(vertices[4][0], vertices[4][1], vertices[4][2]);
        glVertex3f(vertices[5][0], vertices[5][1], vertices[5][2]);
        glVertex3f(vertices[1][0], vertices[1][1], vertices[1][2]);

        // glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3f(vertices[1][0], vertices[1][1], vertices[1][2]);
        glVertex3f(vertices[5][0], vertices[5][1], vertices[5][2]);
        glVertex3f(vertices[6][0], vertices[6][1], vertices[6][2]);
        glVertex3f(vertices[2][0], vertices[2][1], vertices[2][2]);
        //
        // glColor3f(1.0f, 0.0f, 1.0f);     // Green
        glVertex3f(vertices[2][0], vertices[2][1], vertices[2][2]);
        glVertex3f(vertices[3][0], vertices[3][1], vertices[3][2]);
        glVertex3f(vertices[7][0], vertices[7][1], vertices[7][2]);
        glVertex3f(vertices[6][0], vertices[6][1], vertices[6][2]);
        //
        // glColor3f(1.0f, 1.0f, 0.0f);     // Green
        glVertex3f(vertices[0][0], vertices[0][1], vertices[0][2]);
        glVertex3f(vertices[4][0], vertices[4][1], vertices[4][2]);
        glVertex3f(vertices[7][0], vertices[7][1], vertices[7][2]);
        glVertex3f(vertices[3][0], vertices[3][1], vertices[3][2]);
        //
        // glColor3f(1.0f, 1.0f, 1.0f);     // Green
        glVertex3f(vertices[4][0], vertices[4][1], vertices[4][2]);
        glVertex3f(vertices[5][0], vertices[5][1], vertices[5][2]);
        glVertex3f(vertices[6][0], vertices[6][1], vertices[6][2]);
        glVertex3f(vertices[7][0], vertices[7][1], vertices[7][2]);
    glEnd();
}


void drawLand(void) {
    glColor3f(1.0f,1.0f,1.0f);
    glBegin(GL_LINES);
    for(GLfloat i =- 100.0f; i < 100.0f; i += 1.0f) {
        glVertex3f(-100.0f,-1.0f,i);
        glVertex3f( 100.0f,-1.0f,i);
        glVertex3f(i,-1.0f,-100.0f);
        glVertex3f(i,-1.0f,100.0f);
    }
    glEnd();
}
// flag --> 1 (left)
// flag --> 0 (right)
void drawWindow(GLfloat flag, GLfloat xc, GLfloat yc){
    if (flag == 1.0) flag = -1.3f;
    else flag = 2.5f;
    glPushMatrix(); 
        glTranslatef(flag * windowWidth, 0.0f, 0.0f); 
        glRotatef(windowAngle, 0.0f, 1.0f, 0.0f);     
        glTranslatef(-0.5f * windowWidth, 0.0f, 0.0f); 
        glColor3f(0.5f, 0.5f, 0.5f); 
        drawCuboid(0.2f, 0.2f, windowDepth, xc, yc, windowDepth);
    glPopMatrix();
}
