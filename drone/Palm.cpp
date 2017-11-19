// Janik und Patrick Tinz

#include "Palm.h"
#include "Pyramid.h"
#include <GL/freeglut.h>

void palm()
{
	glPushMatrix();
	glRotatef(90, 0., 0., 1.);
	glRotatef(90, 0., 1., 0.);
	glColor4f(0.5f, 0.5f, 0.3f, 1.0f);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	gluCylinder(quadratic, 0.1f, 0.1f, 3.0f, 32, 32);	/* (quadrics object, radius of the cylinder at z = 0,
														radius of the cylinder at z = height,  height of the cylinder,
														number of subdivisions around the z axis, number of subdivisions along the z axis)*/
	glPopMatrix();

	glTranslatef(0.0, 3.0, 0.0);
	glScalef(0.3, 0.3, 0.3);
	// leaf above
	glPushMatrix();
	Pyramid();
	glPopMatrix();

	// leaf right
	glPushMatrix();
	glRotatef(90., 0., 0., -1.);
	Pyramid();
	glPopMatrix();
	
	// leaf left
	glPushMatrix();
	glRotatef(90., 0., 0., 1.);
	Pyramid();
	glPopMatrix();

	// leaf front
	glPushMatrix();
	glRotatef(90., 1., 0., 0.);
	Pyramid();
	glPopMatrix();
	
	// leaf back
	glPushMatrix();
	glRotatef(90., -1., 0., 0.);
	Pyramid();
	glPopMatrix();
}