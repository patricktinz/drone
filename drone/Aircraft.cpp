// Janik und Patrick Tinz

#include "Aircraft.h"
#include "Cube.h"
#include "Pyramid.h"
#include <GL/freeglut.h>

float fRotation1 = 315.0;

void wing()
{
	fRotation1 = fRotation1 - 1.0; 
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

void drone() 
{
	glPushMatrix();   // main cube 
	glScalef(2.0, 0.5, 1.0);
	Cube(2.0, 0.3f, 0.3f, 0.3f);
	glPopMatrix();

	// wings
	glPushMatrix();
	glTranslatef(1.5, 0., 0.5);
	glRotatef(45., 0., -1., 0.);
	glTranslatef(1.5, 0., 0.);
	glScalef(1.0, 1.0, 1.0);
	wing();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.5, 0., -0.5);
	glRotatef(-45., 0., -1., 0.);
	glTranslatef(1.5, 0., 0.);
	glScalef(1.0, 1.0, 1.0);
	wing();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 0., 0.5);
	glRotatef(135., 0., -1., 0.);
	glTranslatef(1.5, 0., 0.);
	glScalef(1.0, 1.0, 1.0);
	wing();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 0., -0.5);
	glRotatef(-135., 0., -1., 0.);
	glTranslatef(1.5, 0., 0.);
	glScalef(1.0, 1.0, 1.0);
	wing();
	glPopMatrix();

	glPushMatrix();   // cube at the top
	glTranslatef(0.0, 0.75, 0.);
	glScalef(2.0, 0.5, 1.0);
	Cube(1.0, 0.5f, 0.5f, 0.5f);
	glPopMatrix();
}

void tail_rotor()
{
	fRotation1 = fRotation1 - 7.0;
	if (fRotation1 <= 0.0)
	{
		fRotation1 = fRotation1 + 360.0;
	}

	glPushMatrix();   // tail
	glScalef(3.0, 0.5, 0.5);
	Cube(1.0, 0.3f, 0.3f, 0.3f);
	glPopMatrix();
	
	glPushMatrix();   // foot
	glTranslatef(1.0, 0.25, 0.0);
	glScalef(0.3, 0.2, 0.3);
	Pyramid(0., 0., 0.);
	glPopMatrix();

	glPushMatrix();   // propeller
	glTranslatef(1.0, 0.5, 0.);
	glRotatef(fRotation1, 0., -1., 0.);
	glScalef(1.0, 0.1, 0.2);
	Cube(1.0, 0.3f, 0.3f, 0.3f);
	glPopMatrix();
}

void main_rotor()
{
	fRotation1 = fRotation1 - 1.0;
	if (fRotation1 <= 0.0)
	{
		fRotation1 = fRotation1 + 360.0;
	}

	glPushMatrix();   // foot
	glScalef(0.4, 0.2, 0.4);
	Pyramid(0., 0., 0.);
	glPopMatrix();

	glPushMatrix();   // propeller
	glTranslatef(0.0, 0.3, 0.0);
	glRotatef(fRotation1, 0., -1., 0.);
	glScalef(6.0, 0.1, 0.3);
	Cube(1.0, 0.3f, 0.3f, 0.3f);
	glPopMatrix();
}

void helicopter()
{
	glPushMatrix();   // main cube   
	glScalef(1.0, 0.5, 0.5);
	Cube(3.0, 0.7, 0.3, 0.);
	glPopMatrix();

	glPushMatrix();   // tail rotor
	glTranslatef(3.0, 0.5, 0.);
	glRotatef(90., 1., 0., 0.);
	glScalef(1., 1., 1.);
	tail_rotor();
	glPopMatrix();

	glPushMatrix();   // main rotor
	glTranslatef(0., 0.75, 0.);
	glScalef(1., 1., 1.);
	main_rotor();
	glPopMatrix();
}