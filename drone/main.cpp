// Janik und Patrick Tinz

#include <iostream> 
#include <GL/freeglut.h>   // load all for OpenGL
#include "Cube.h"
#include "Pyramid.h"
#include "Wing.h"
#include "Drone.h"

float fRotation = 315.0;
float zTranslation = -0.2;
void Init()
{
	// all actions for program start
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
}

void RenderScene()
{
	// Here is the code that must be executed in each frame
	glLoadIdentity();   // Reset current model / view transformation matrix
	glClearColor(0.0, 0.5, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // Delete background
	gluLookAt(0., 5., 7., 0., 0., 0., 0., 1., 0.); // eye camera position, up where is above on the camera

	//glutWireCube(0.2);

	/*glLineWidth(5.0); 
	glBegin(GL_LINES); 
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); 
	glVertex3f(-1.0f, 0.0f, 0.0f); 
	glVertex3f(1.0f, 0.0f, 0.0f); 
	glVertex3f(+0.0f, -1.0f, 0.0f); 
	glVertex3f(+0.0f, 1.0f, 0.0f); 
	glVertex3f(+0.0f, 0.0f, -1.0f);
	glVertex3f(+0.0f, 0.0f, 1.0f);
	glEnd();*/

	//Pyramid();
	


	glPushMatrix();
	glTranslatef(4.0, 3.0, 0.0);
	glScalef(0.3, 0.3, 0.3);
	Drone();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.0, 3.0, 0.0);
	glScalef(0.3, 0.3, 0.3);
	Drone();
	glPopMatrix();


	//glTranslatef(0.0, 0.0, zTranslation);
	glRotatef(fRotation, 0., -1., 0.);
	Drone();
	/*glTranslatef(0.1, 0.1, 0.);
	glRotatef(fRotation, 0., 0., -1.);

	glPushMatrix();
	glTranslatef(0.1, 0., 0.);
	glScalef(0.5, 0.3, 0.3);
	Cube(0.4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 0., 0.);
	glScalef(0.5, 0.15, 0.15);
	Cube(0.4);
	glPopMatrix();*/

	glutSwapBuffers();
}

void Reshape(int width, int height)
{
	// Hier finden die Reaktionen auf eine Veraenderung der Groeße des 
	// Graphikfensters statt
	// Matrix fuer Transformation: Frustum->viewport 
	glMatrixMode(GL_PROJECTION);
	// Aktuelle Transformations-Matrix zuruecksetzen 
	glLoadIdentity();
	// Viewport definieren
	glViewport(0, 0, width, height);

	// Frustum definieren (siehe unten) 
	//glOrtho( -1., 1., -1., 1., 0.0, 2.0);   // Parallel Projektion (orthographische Projektion)
	// gluPerspective(senkr. Oeffnungsw., Seitenverh., zNear, zFar); 
	gluPerspective(90., 1., 0.1, 30.0);   // Perspektivische Projektion

										  // Matrix fuer Modellierung/Viewing 
	glMatrixMode(GL_MODELVIEW);
}

void Animate(int value)
{
	// Hier werden Berechnungen durchgefuehrt, die zu einer Animation der Szene  
	// erforderlich sind. Dieser Prozess l‰uft im Hintergrund und wird alle 
	// 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
	// inkrementiert und dem Callback wieder uebergeben. 
	std::cout << "value=" << value << std::endl;
	zTranslation = zTranslation - 0.2;
	if (zTranslation < -30.0)
	{
		zTranslation = +30.0;
	}

	fRotation = fRotation - 1.0; // Rotationswinkel aendern 
	if (fRotation <= 0.0)
	{
		fRotation = fRotation + 360.0;
	}
	// RenderScene aufrufen
	glutPostRedisplay();
	// Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
	int wait_msec = 10;
	glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);                // GLUT initialisieren
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);         // Fenster-Konfiguration
	glutCreateWindow("Janik Tinz; Patrick Tinz");   // Fenster-Erzeugung
	glutDisplayFunc(RenderScene);         // Zeichenfunktion bekannt machen
	glutReshapeFunc(Reshape);
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	glutTimerFunc(10, Animate, 0);
	Init();
	glutMainLoop();
	return 0;
}