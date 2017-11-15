#include "Wing.h"
#include "Cube.h"
#include <GL/freeglut.h>

float fRotation1 = 315.0;
void Wing()
{
	fRotation1 = fRotation1 - 1.0; // Rotationswinkel aendern 
	if (fRotation1 <= 0.0)
	{
		fRotation1 = fRotation1 + 360.0;
	}

	glPushMatrix();   // wing
	glScalef(3.0, 0.5, 0.5);
	Cube(1.0, 0.5f, 0.5f, 0.5f);
	glPopMatrix();

	glTranslatef(1.0, 0.5, 0.0);
	glPushMatrix();   // foot
	glScalef(0.3, 0.5, 0.3);
	Cube(1.0, 0.3f, 0.3f, 0.3f);
	glPopMatrix();

	glPushMatrix();   // propeller
	glTranslatef(0.0, 0.3, 0.);
	glRotatef(fRotation1, 0., -1., 0.);
	glScalef(4.0, 0.1, 0.3);
	Cube(1.0, 0.3f, 0.3f, 0.3f);
	glPopMatrix();
}