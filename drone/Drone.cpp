#include "Drone.h"
#include "Wing.h"
#include "Cube.h"
#include <GL/freeglut.h>

void Drone() 
{
	glPushMatrix();   
	glScalef(2.0, 0.5, 1.0);
	Cube(2.0, 0.3f, 0.3f, 0.3f);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1.5, 0., 0.5);
	glRotatef(45., 0., -1., 0.);
	glTranslatef(1.5, 0., 0.);
	glScalef(1.0, 1.0, 1.0);
	Wing();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1.5, 0., -0.5);
	glRotatef(-45., 0., -1., 0.);
	glTranslatef(1.5, 0., 0.);
	glScalef(1.0, 1.0, 1.0);
	Wing();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-1.5, 0., 0.5);
	glRotatef(135., 0., -1., 0.);
	glTranslatef(1.5, 0., 0.);
	glScalef(1.0, 1.0, 1.0);
	Wing();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-1.5, 0., -0.5);
	glRotatef(-135., 0., -1., 0.);
	glTranslatef(1.5, 0., 0.);
	glScalef(1.0, 1.0, 1.0);
	Wing();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0.0, 0.75, 0.);
	glScalef(2.0, 0.5, 1.0);
	Cube(1.0, 0.5f, 0.5f, 0.5f);
	glPopMatrix();
}
