// Janik und Patrick Tinz

#include <iostream> 
#include <windows.h>
#include <GL/freeglut.h>   // load all for OpenGL
#include <math.h>
#include "Cube.h"
#include "Pyramid.h"
#include "Aircraft.h"
#include "Palm.h"
#include "Island.h"
#include "World.h"

float fRotation = 315.0;

GLfloat x_winkel = 0.0, y_winkel = 0.0;
GLfloat yTranslation = 0.0;
GLfloat xTranslation = 0.0;
GLfloat zTranslation = 0.0;

int world_size = 200;

void Init()
{
	// all actions for program start
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
}

void systemOfCoordinates() 
{
	// system of coordinates
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-50.0f, 0.0f, 0.0f);
	glVertex3f(50.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(+0.0f, -50.0f, 0.0f);
	glVertex3f(+0.0f, 50.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(+0.0f, 0.0f, -50.0f);
	glVertex3f(+0.0f, 0.0f, 50.0f);
	glEnd();
}

void RenderScene()
{
	// Here is the code that must be executed in each frame
	glLoadIdentity();   // Reset current model / view transformation matrix
	glClearColor(0.0, 0.5, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Delete background
	gluLookAt(xTranslation, yTranslation+2, zTranslation+10, xTranslation, yTranslation, zTranslation, 0., 1., 0.); // eye camera position, up where is above on the camera
	
	//systemOfCoordinates();

	// world
	glPushMatrix();
	glTranslatef(0., world_size/2, 0.);
	world(world_size);
	glPopMatrix();

	// main island
	island_main(0.5, 0.3, 0.2);

	// island with palm left front
	glPushMatrix();
	glTranslatef(-9., 0., 10.);
	island_palm(1., 1., 0.);
	glPopMatrix();

	// island with palm right front
	glPushMatrix();
	glTranslatef(9., 0., 10.);
	island_palm(1., 1., 0.);
	glPopMatrix();

	// island with palm left back
	glPushMatrix();
	glTranslatef(-9., 0., -10.);
	island_palm(1., 1., 0.);
	glPopMatrix();

	// island with palm right back
	glPushMatrix();
	glTranslatef(9., 0., -10.);
	island_palm(1., 1., 0.);
	glPopMatrix();
	
	// drone mini right
	glPushMatrix();
	glTranslatef(8.0, 3.0, 0.0);
	glScalef(0.3, 0.3, 0.3);
	drone();
	glPopMatrix();

	// drone mini left
	glPushMatrix();
	glTranslatef(-8.0, 3.0, 0.0);
	glScalef(0.3, 0.3, 0.3);
	drone();
	glPopMatrix();

	// main drone
	glTranslatef(0.0, yTranslation+1, 0.0);
	glTranslatef(0.0, 0.0, zTranslation);
	glTranslatef(xTranslation, 0.0, 0.0);
	glRotatef(90., 0.0f, 1.0f, 0.0f);
	glScalef(0.5, 0.5, 0.5);
	drone();

	glutSwapBuffers();
}

void Reshape(int width, int height)
{
	// Responses to a change in the size of the graphics window
	// Matrix for Transformation: Frustum->viewport 
	glMatrixMode(GL_PROJECTION);
	// Current Transformations-Matrix reset
	glLoadIdentity();
	// define Viewport
	glViewport(0, 0, width, height);

	// define Frustum
	//glOrtho( -1., 1., -1., 1., 0.0, 2.0);   // parallel projection (orthographic projection)
	// gluPerspective(vertical. aperture, aspect ratio, zNear, zFar); 
	gluPerspective(60., 1., 0.1, 200.0);   // perspective projection

										  // Matrix for modeling/Viewing 
	glMatrixMode(GL_MODELVIEW);
}

void SpecialFunc(int key, int x, int y)
// query function and arrow keys
{
	GLfloat xMousePos = float(x);
	GLfloat yMousePos = float(y);
	if (key <= 12)
		std::cout << "GLUT_KEY_F" << key << "  " << xMousePos << ", " << yMousePos << std::endl;
	else
		switch (key) {
		case GLUT_KEY_LEFT:
			std::cout << "GLUT_KEY_LEFT " << xMousePos << ", " << yMousePos << std::endl;
			/*y_winkel = y_winkel + 5.0f;
			if (y_winkel > 360.0)
				y_winkel = 0.0f;*/
			if (xTranslation <= -(world_size/2))
				break;
			xTranslation = xTranslation - 1.;
			break;
		case GLUT_KEY_UP:
			std::cout << "GLUT_KEY_UP " << xMousePos << ", " << yMousePos << std::endl;
			/*x_winkel = x_winkel - 5.0f;
			if (x_winkel<0.0)
				x_winkel = 360.0f;*/
			if (yTranslation >= world_size)
				break;
			yTranslation = yTranslation + 0.5;
			break;
		case GLUT_KEY_RIGHT:
			std::cout << "GLUT_KEY_RIGHT " << xMousePos << ", " << yMousePos << std::endl;
			/*y_winkel = y_winkel - 5.0f;
			if (y_winkel < 0.0)
				y_winkel = 360.0f;*/
			if (xTranslation >= world_size / 2)
				break;
			xTranslation = xTranslation + 1.;
			break;
		case GLUT_KEY_DOWN:
			std::cout << "GLUT_KEY_DOWN " << xMousePos << ", " << yMousePos << std::endl;
			/*x_winkel = x_winkel + 5.0f;
			if (x_winkel>360.0)
				x_winkel = 0.0f;*/
			if (yTranslation < 0.5)
				break;
			yTranslation = yTranslation - 0.5;
			break;
		}
	// call RenderScene
	glutPostRedisplay();
}

void KeyboardFunc(unsigned char key, int x, int y)
{
	GLfloat xMousePos = float(x);
	GLfloat yMousePos = float(y);
	std::cout << "key = " << key << "  " << xMousePos << ", " << yMousePos << std::endl;
	if(key == 'f') 
	{
		zTranslation -= 1;
	}

	if (key == 'b')
	{
		zTranslation += 1;
	}
	// call RenderScene
	glutPostRedisplay();
}

void Animate(int value)
{
	// Hier werden Berechnungen durchgefuehrt, die zu einer Animation der Szene  
	// erforderlich sind. Dieser Prozess l‰uft im Hintergrund und wird alle 
	// 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
	// inkrementiert und dem Callback wieder uebergeben. 
	//std::cout << "value=" << value << std::endl;

	fRotation = fRotation - 1.0; // Rotationswinkel aendern 
	if (fRotation <= 0.0)
	{
		fRotation = fRotation + 360.0;
	}
	// call RenderScene
	glutPostRedisplay();
	// Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
	int wait_msec = 10;
	glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char **argv)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "       Control Instructions       " << std::endl;
	std::cout << "1. Click into the graphics window" << std::endl;
	std::cout << "2. " << std::endl;
	std::cout << "3. " << std::endl << std::endl;
	std::cout << "Exit -> Close graphics window!" << std::endl << std::endl;
	std::cout << "----------------------------------" << std::endl;


	glutInit(&argc, argv);                // GLUT initialisieren
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);         // window configuration
	glutCreateWindow("Janik Tinz; Patrick Tinz");   // Fenster-Erzeugung
	glutDisplayFunc(RenderScene);         // Zeichenfunktion bekannt machen
	glutReshapeFunc(Reshape);
	glutSpecialFunc(SpecialFunc);
	glutKeyboardFunc(KeyboardFunc);
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc(10, Animate, 0);
	Init();
	glutMainLoop();
	return 0;
}