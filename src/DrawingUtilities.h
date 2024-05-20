#ifndef DrawingUtilities
#define DrawingUtilities

#include <GL/gl.h>
#include <GL/glut.h>
// #include <vector>
#include <array>
#include "globalVariables.h"
using ArrayOfVertices = std::array<std::array<GLfloat, 3>, 8>;

void drawCylinder(float x1, float y1, float z1, float x2, float y2, float z2, float radius, float length,  int slices, int stacks);

void drawLine(float width, float height, float depth);
void drawWindow(GLfloat flag, GLfloat xc, GLfloat yc, GLboolean rotate , GLfloat depth);
void drawBicycle();
void drawCuboid(GLfloat height, GLfloat width, GLfloat depth, GLfloat  xc, GLfloat yc, GLfloat zc);
void drawLand(void);

#endif
