// Janik und Patrick Tinz

#include "Island.h"
#include "Palm.h"
#include "Pyramid.h"
#include "Octahederon.h"
#include <GL/freeglut.h>

void island_palm(float rValue, float gValue, float bValue)
{
	Octahederon(rValue, gValue, bValue);

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
	glTranslatef(0., 5., 0.);
	glScalef(0.1f, 10.0f, 0.1);
	Octahederon(0.7f, 0.7f, 0.7f);
	glPopMatrix();
}

void island_main(float rValue, float gValue, float bValue)
{
	Octahederon(rValue, gValue, bValue);

	glPushMatrix();   // tower 1
	glTranslatef(-3.5, 0.5, 0.);
	tower();
	glPopMatrix();

	glPushMatrix();   // tower 2
	glTranslatef(3.5, 0.5, 0.);
	tower();
	glPopMatrix();
}

void islands(int choice, float rValue, float gValue, float bValue)
{
	Octahederon(rValue, gValue, bValue);

	switch (choice)
	{
		case 0:
			glPushMatrix();   // island with two palms and one bush
			glTranslatef(-3.5, 0.5, 0.);
			palm();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(3.5, 0.5, 0.);
			palm();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0., 0.5, 0.);
			leaf();
			glPopMatrix();
			break;
		case 1:
			glPushMatrix();   // island with two palms and one pyramid
			glTranslatef(-3.0, 0.5, 0.);
			palm();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(3.0, 0.5, 0.);
			palm();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0., 0.5, 0.);
			Pyramid(0.3f, 0.3f, 0.3f);
			glPopMatrix();
			break;
		case 2:
			palmTexture();
			glPushMatrix();   // island with one pyramid and one bush
			glTranslatef(-2.0, 0.5, 0.);
			Pyramid(0.7f, 0.7f, 0.7f);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(2.0, 0.5, 0.);
			leaf();
			glPopMatrix();
			break;
		case 3:
			palmTexture();
			glPushMatrix();   // island two bush
			glTranslatef(2.0, 0.5, 0.);
			leaf();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(-2.0, 0.5, 0.);
			leaf();
			glPopMatrix();
			break;
		case 4:
			glPushMatrix();   // island with three palms
			glTranslatef(-3.0, 0.5, 0.);
			palm();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(3.0, 0.5, 0.);
			palm();
			glPopMatrix();
			glPushMatrix();
			glTranslatef(0.0, 0.5, 0.);
			palm();
			glPopMatrix();
			break;
		default:
			break;
	}
}
