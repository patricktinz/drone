// Janik und Patrick Tinz

#include "Island.h"
#include "Palm.h"
#include <GL/freeglut.h>

void cylinder()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	gluCylinder(quadratic, 0.1f, 0.2f, 3.0f, 32, 32);	/* (quadrics object, radius of the cylinder at z = 0,
														radius of the cylinder at z = height,  height of the cylinder,
														number of subdivisions around the z axis, number of subdivisions along the z axis)*/
}

void island(float rValue, float gValue, float bValue)
{
	glColor4f(rValue, gValue, bValue, 1.0f);	// color

	glBegin(GL_POLYGON);   // island bottom
	glVertex3f(4., -0.5, 0.);
	glVertex3f(3., -0.5, 3.);
	glVertex3f(0., -0.5, 4.);
	glVertex3f(-3., -0.5, 3.);
	glVertex3f(-4., -0.5, 0.);
	glVertex3f(-3., -0.5, -3.);
	glVertex3f(0., -0.5, -4.);
	glVertex3f(3., -0.5, -3.);
	glEnd();

	glBegin(GL_POLYGON);   // island top
	glColor4f(rValue, gValue, bValue, 1.0f);	// color
	glVertex3f(4., 0.5, 0.);
	glVertex3f(3., 0.5, 3.);
	glVertex3f(0., 0.5, 4.);
	glVertex3f(-3., 0.5, 3.);
	glVertex3f(-4., 0.5, 0.);
	glVertex3f(-3., 0.5, -3.);
	glVertex3f(0., 0.5, -4.);
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

void island_palm(float rValue, float gValue, float bValue)
{
	island(rValue, gValue, bValue);

	// Palm
	glPushMatrix();
	glTranslatef(0., 0.5, 0.);
	glScalef(2., 2., 2.);
	palm();
	glPopMatrix();
}

void tower()
{
	glPushMatrix();
	glScalef(2., 3., 2.);
	glRotatef(90, 0., 0., 1.);
	glRotatef(90, 0., 1., 0.);
	glColor4f(0.5, 0.5, 0.5, 1.0f);
	cylinder();
	glPopMatrix();
}

void island_main(float rValue, float gValue, float bValue)
{
	island(rValue, gValue, bValue);

	glPushMatrix();
	glTranslatef(-3.5, 0.5, 0.);
	tower();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, 0.5, 0.);
	tower();
	glPopMatrix();
}

