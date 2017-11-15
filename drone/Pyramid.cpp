#include "Pyramid.h"
#include <GL/freeglut.h>

void Pyramid()
{
	glBegin(GL_TRIANGLES); 
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); 
	glVertex3f(0.0f, 2.0f, 0.0f); 	
	glVertex3f(-0.5f, 0.0f, 0.5f); 
	glVertex3f(+0.5f, 0.0f, 0.5f);  
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.5f);
	glVertex3f(-0.5f, 0.0f, -0.5f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(0.5f, 0.0f, -0.5f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);
	glVertex3f(-0.5f, 0.0f, -0.5f);
	glVertex3f(0.5f, 0.0f, -0.5f);
	glEnd();

	glBegin(GL_POLYGON);   //Boden
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);	//ROT
	glVertex3f(-0.5f, 0.0f, -0.5f);
	glVertex3f(0.5f, 0.0f, -0.5f);
	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(-0.5f, 0.0f, 0.5f);
	glEnd();
}