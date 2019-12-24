///////////////////////////////////
// square.cpp
//
// OpenGL program to draw a square.
// 
// Sumanta Guha.
///////////////////////////////////

#include <GL/glew.h>
#include <GL/freeglut.h> 

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 0.0);

	glPointSize(5.0);
	glLineWidth(3.0);

	// Draw a polygon with specified vertices.
	glLineWidth(5.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(10.0, 80.0, 0.0);
	glVertex3f(10.0, 95.0, 0.0);
	glVertex3f(25.0, 80.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(40.0, 95.0, 0.0);
	glVertex3f(25.0, 10.0, 0.0);
	glVertex3f(40.0, 25.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(60.0, 10.0, 0.0);
	glVertex3f(45.0, 25.0, 0.0);
	glVertex3f(60.0, 80.0, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(45.0, 95.0, 0.0);
	glVertex3f(75.0, 80.0, 0.0);
	glVertex3f(75.0, 95.0, 0.0);
	glEnd();

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, 1.0, -1.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(1900 * 0.25, 1080 * 0.25);
	
	glutCreateWindow("square.cpp");
	
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}