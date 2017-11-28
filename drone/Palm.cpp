// Janik und Patrick Tinz

#include "Palm.h"
#include "Pyramid.h"
#include "Octahederon.h"
#include <GL/freeglut.h>

void palm()
{
	glPushMatrix();
	glTranslatef(0., 1.5, 0.);
	glScalef(0.03f, 3.0f, 0.03);
	Octahederon(0.5f, 0.5f, 0.3f);
	glPopMatrix();

	glTranslatef(0.0, 3.0, 0.0);
	leaf();
}

void leaf()
{
	glScalef(0.3, 0.3, 0.3);
	// leaf above
	glPushMatrix();
	Pyramid(0., 1., 0.);
	glPopMatrix();

	// leaf right
	glPushMatrix();
	glRotatef(90., 0., 0., -1.);
	Pyramid(0., 1., 0.);
	glPopMatrix();

	// leaf left
	glPushMatrix();
	glRotatef(90., 0., 0., 1.);
	Pyramid(0., 1., 0.);
	glPopMatrix();

	// leaf front
	glPushMatrix();
	glRotatef(90., 1., 0., 0.);
	Pyramid(0., 1., 0.);
	glPopMatrix();

	// leaf back
	glPushMatrix();
	glRotatef(90., -1., 0., 0.);
	Pyramid(0., 1., 0.);
	glPopMatrix();
}