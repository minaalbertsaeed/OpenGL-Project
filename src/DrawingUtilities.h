#ifndef DrawingUtilities
#define DrawingUtilities

#include <GL/gl.h>
#include <GL/glut.h>
// #include <vector>
#include <array>
#include "globalVariables.h"
using ArrayOfVertices = std::array<std::array<GLfloat, 3>, 8>;


void drawWindow(GLfloat flag, GLfloat xc, GLfloat yc);
void drawCuboid(GLfloat height, GLfloat width, GLfloat depth, GLfloat  xc, GLfloat yc, GLfloat zc);
void drawLand(void);

#endif
