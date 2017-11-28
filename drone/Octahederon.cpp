// Janik und Patrick Tinz

#include "Octahederon.h"
#include <GL/freeglut.h>

void Octahederon(float rValue, float gValue, float bValue)
{
	glColor4f(rValue, gValue, bValue, 1.0f);	// color

	glBegin(GL_POLYGON);   // island bottom
	glVertex3f(4.0f, -0.5f, 0.0f);
	glVertex3f(3.0f, -0.5f, 3.0f);
	glVertex3f(0., -0.5, 4.);
	glVertex3f(-3., -0.5, 3.);
	glVertex3f(-4., -0.5, 0.);
	glVertex3f(-3., -0.5, -3.);
	glVertex3f(0., -0.5, -4.);
	glVertex3f(3., -0.5, -3.);
	glEnd();

	glBegin(GL_POLYGON);   // island top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glColor4f(rValue, gValue, bValue, 1.0f);	// color
	glVertex3f(4., 0.5, 0.);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(3., 0.5, 3.);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0., 0.5, 4.);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-3., 0.5, 3.);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-4., 0.5, 0.);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-3., 0.5, -3.);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0., 0.5, -4.);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(3., 0.5, -3.);
	glEnd();

	//////////////////////////////////////////////////   front

	glBegin(GL_POLYGON);   // quad on the side front right on x 
	glVertex3f(4., -0.5, 0.);
	glVertex3f(3., -0.5, 3.);
	glVertex3f(3., 0.5, 3.);
	glVertex3f(4., 0.5, 0.);
	glEnd();

	glBegin(GL_POLYGON);   // quad on the side front right on z 
	glVertex3f(3., -0.5, 3.);
	glVertex3f(0., -0.5, 4.);
	glVertex3f(0., 0.5, 4.);
	glVertex3f(3., 0.5, 3.);
	glEnd();

	glBegin(GL_POLYGON);   // quad on the side front left on z 
	glVertex3f(0., -0.5, 4.);
	glVertex3f(-3., -0.5, 3.);
	glVertex3f(-3., 0.5, 3.);
	glVertex3f(0., 0.5, 4.);
	glEnd();

	glBegin(GL_POLYGON);   // quad on the side front left on x 
	glVertex3f(-3., -0.5, 3.);
	glVertex3f(-4., -0.5, 0.);
	glVertex3f(-4., 0.5, 0.);
	glVertex3f(-3., 0.5, 3.);
	glEnd();

	//////////////////////////////////////////////////   back

	glBegin(GL_POLYGON);   // quad on the side back left on x 
	glVertex3f(-4., -0.5, 0.);
	glVertex3f(-3., -0.5, -3.);
	glVertex3f(-3., 0.5, -3.);
	glVertex3f(-4., 0.5, 0.);
	glEnd();

	glBegin(GL_POLYGON);   // quad on the side back left on z
	glVertex3f(-3., -0.5, -3.);
	glVertex3f(0., -0.5, -4.);
	glVertex3f(0., 0.5, -4.);
	glVertex3f(-3., 0.5, -3.);
	glEnd();

	glBegin(GL_POLYGON);   // quad on the side back right on z 
	glVertex3f(0., -0.5, -4.);
	glVertex3f(3., -0.5, -3.);
	glVertex3f(3., 0.5, -3.);
	glVertex3f(0., 0.5, -4.);
	glEnd();

	glBegin(GL_POLYGON);   // quad on the side back right on x
	glVertex3f(3., -0.5, -3.);
	glVertex3f(4., -0.5, 0.);
	glVertex3f(4., 0.5, 0.);
	glVertex3f(3., 0.5, -3.);
	glEnd();
}