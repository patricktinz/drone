#include "Pyramid.h"
#include <GL/freeglut.h>

void Pyramid(float rValue, float gValue, float bValue)
{
	glColor4f(rValue, gValue, bValue, 1.0f);
	// front triangle
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.5f);
	glRotatef(-15.2f, 1.0f, 0.0f, 0.0f);
	triangle();
	glPopMatrix();
	
	// back triangle
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -0.5f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(-14.48f, 1.0f, 0.0f, 0.0f);
	triangle();
	glPopMatrix();

	// right tiangle
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 0.5f);
	glRotatef(-14.48f, 1.0f, 0.0f, 0.0f);
	triangle();
	glPopMatrix();

	// left triangle
	glPushMatrix();
	glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, 0.5f);
	glRotatef(-14.48f, 1.0f, 0.0f, 0.0f);
	triangle();
	glPopMatrix();
	
	glBegin(GL_POLYGON);   // bottom
	glColor4f(rValue, gValue, bValue, 1.0f);
	glVertex3f(-0.5f, 0.0f, -0.5f);
	glVertex3f(0.5f, 0.0f, -0.5f);
	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(-0.5, 0.0f, 0.5f);
	glEnd();
}

void triangle()
{
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(+0.5f, 0.0f, 0.0f);
	glEnd();
}