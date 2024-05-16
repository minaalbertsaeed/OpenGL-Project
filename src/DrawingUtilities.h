#ifndef DrawingUtilities
#define DrawingUtilities

#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include "globalVariables.h"
using VectorOfVertices = std::vector<std::vector<GLfloat>>;

void drawCube(GLfloat height, GLfloat width, GLfloat depth, GLfloat  xc, GLfloat yc, GLfloat  zc);

#endif
