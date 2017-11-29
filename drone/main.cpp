// Janik und Patrick Tinz

#include <iostream> 
#include <windows.h>
#include <GL/freeglut.h>   // load all for OpenGL
#include <GL/SOIL.h>
#include <math.h>
#include "Aircraft.h"
#include "Palm.h"
#include "Island.h"
#include <ctime>
#include <vector>

const int world_size = 200;

bool check = true;
std::vector<int> islandVector;

float fRotation = 315.0f;
float fTranslation = 1.0f;

// keyboard func
GLfloat x_winkel = 0.0f, y_winkel = 0.0f;
GLfloat yTranslation = 0.0f;
GLfloat xTranslation = 0.0f;
GLfloat zTranslation = 0.0f;

// texture palm id
GLuint tex_2d;

// menu - camera view
bool right = false;
bool left = false;
bool front = false;
bool back = false;
bool drone_view = true;

void mainMenu(int item)
{
	switch (item)
	{
	case 1:
		std::cout << "Exit" << std::endl;
		exit(0);
	}
}

void cameraView(int item)
{
	switch (item)
	{
		case 0:   // drone
		{
			drone_view = true;
			front = false;
			back = false;
			right = false;
			left = false;
			break;
		}
		case 1:   // front
		{
			drone_view = false;
			front = true;
			back = false;
			right = false;
			left = false;
			break;
		}
		case 2:   // back
		{
			drone_view = false;
			front = false;
			back = true;
			right = false;
			left = false;
			break;
		}
		case 3:   // right
		{
			drone_view = false;
			front = false;
			back = false;
			right = true;
			left = false;
			break;
		}
		case 4:   // left
		{
			drone_view = false;
			front = false;
			back = false;
			right = false;
			left = true;
			break;
		}
	}
}

void Init()
{
	// all actions for program start
	// light
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);   // calculate the light 
	GLfloat light_position[] = { 10.0, 70.0, 0.0, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);   // light at the top right, GL_POSITION = light is directed
	glEnable(GL_COLOR_MATERIAL);   // use material parameter for actual color setting
	
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glEnable(GL_NORMALIZE);

	// read texture
	tex_2d = SOIL_load_OGL_texture("PALM.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
	glBindTexture(GL_TEXTURE_2D, tex_2d);
	glEnable(GL_BLEND);   // transparency (z.B. Billboards)
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// submenu
	int submenu;
	submenu = glutCreateMenu(cameraView);
	glutAddMenuEntry("Drone", 0);
	glutAddMenuEntry("At the front", 1);
	glutAddMenuEntry("At the back", 2);
	glutAddMenuEntry("On the right", 3);
	glutAddMenuEntry("On the left", 4);

	// main menu
	glutCreateMenu(mainMenu);
	glutAddSubMenu("Camera", submenu);
	glutAddMenuEntry("Exit", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);   // open menu with right click
}

void helicopterRotate()
{
	// helicopter
	glPushMatrix();
	glRotatef(fRotation, 0.0f, -1.0f, 0.0f);
	glTranslatef(15.0f, 25.0f, 0.0f);
	glRotatef(10.0f, 1.0f, 0.0f, 1.0f);
	helicopter();
	glPopMatrix();
}

void islandsWithPalm()
{
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
}

void islandsRandom()
{
	// island random
	glPushMatrix();
	glTranslatef(20.0f, 0.0f, 20.0f);
	islands(islandVector[0], 0.7f, 1.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(20.0f, 0.0f, -20.0f);
	islands(islandVector[1], 0.7f, 1.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20.0f, 0.0f, 20.0f);
	islands(islandVector[2], 0.7f, 1.0f, 0.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-20.0f, 0.0f, -20.0f);
	islands(islandVector[3], 0.7f, 1.0f, 0.0f);
	glPopMatrix();
}

void miniDrone()
{
	// drone mini right
	glPushMatrix();
	glTranslatef(12.0, fTranslation, 0.0);
	glRotated(fRotation, 0., 1., 0.);
	glScalef(0.3, 0.3, 0.3);
	drone();
	glPopMatrix();

	// drone mini left
	glPushMatrix();
	glTranslatef(-12.0, fTranslation, 0.0);
	glRotated(fRotation, 0., 1., 0.);
	glScalef(0.3, 0.3, 0.3);
	drone();
	glPopMatrix();
}

void mainDrone()
{
	// main drone
	glTranslatef(0.0, yTranslation + 1, 0.0);
	glTranslatef(0.0, 0.0, zTranslation);
	glTranslatef(xTranslation, 0.0, 0.0);
	glRotatef(90., 0.0f, 1.0f, 0.0f);
	glScalef(0.5, 0.5, 0.5);
	drone();
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

	// choose camera view
	if (drone_view == true)
		gluLookAt(xTranslation, yTranslation+2, zTranslation+10, xTranslation, yTranslation, zTranslation, 0., 1., 0.); // eye camera position, up where is above on the camera
	if (front == true)
		gluLookAt(0.0f, 30.0f, 50.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	if (back == true)
		gluLookAt(0.0f, 30.0f, -50.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	if (right == true)
		gluLookAt(50.0f, 40.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	if (left == true)
		gluLookAt(-50.0f, 40.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	//systemOfCoordinates();
	
	helicopterRotate();
	
	// main island
	island_main(0.5, 0.3, 0.2);
	
	islandsWithPalm();
	islandsRandom();
	miniDrone();
	mainDrone();
	
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

	//gluPerspective(vertical. aperture, aspect ratio, zNear, zFar); 
	gluPerspective(60., 1., 0.1, 100.0);   // perspective projection
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
	// rotate mini drones and helicopter
	fRotation = fRotation - 0.5; 
	if (fRotation <= 0.0)
	{
		fRotation = fRotation + 360.0;
	}

	// translation mini drones
	if(fTranslation >= 20.0 || check == false)
	{
		fTranslation = fTranslation - 0.05;
		check = false;
		if (fTranslation <= 3)
		{
			check = true;
		}
	}
	if(check == true)
	{
		fTranslation = fTranslation + 0.05;
	}

	// call RenderScene
	glutPostRedisplay();

	int wait_msec = 10;
	glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char **argv)
{
	std::cout << "----------------------------------" << std::endl;
	std::cout << "       Control Instructions       " << std::endl;
	std::cout << "1. Click into the graphics window" << std::endl;
	std::cout << "2. Control the drone with arrow keys, forward (f) and back (b)" << std::endl;
	std::cout << "3. Open a menu with a right click on the graphics window" << std::endl << std::endl;
	std::cout << "Exit -> Close graphics window!" << std::endl << std::endl;
	std::cout << "----------------------------------" << std::endl;

	srand((unsigned)time(0));
	for (int i = 0; i < 5; i++)
	{
		islandVector.push_back(rand()%5);
	}

	glutInit(&argc, argv);                // GLUT init
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);         // window configuration
	glutCreateWindow("Janik Tinz; Patrick Tinz");   // create window
	glutDisplayFunc(RenderScene);         // announce draw function 
	glutReshapeFunc(Reshape);
	glutSpecialFunc(SpecialFunc);
	glutKeyboardFunc(KeyboardFunc);
	// register TimerCallback; call after 10 msec with parameter 0  
	glutTimerFunc(10, Animate, 0);
	Init();
	glutMainLoop();
	return 0;
}