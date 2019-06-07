#include <GL\glut.h>

int rotsfera = 0;
int rotsfera1 = 0;
int rotsfera2 = 0;
int rotsfera3 = 0;
int rotsfera4 = 0;
int rotsfera5 = 0;
float x, y, m, n, e;

typedef struct f {

	float r, g, b; 
	float a1 = 0.5;
	float b1 = 0.3, b2 = 10;
	float c2 = 0.9, c3 = 20;
	float d1 = 0.2, d2 = 0.6;
} Figura;
Figura fig;
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glPushMatrix();
	glRotatef((GLfloat)rotsfera3, 0.0, 0.0, 1.0); 
	glPushMatrix();
	glRotatef((GLfloat)rotsfera1, 1.0, 0.0, 0.0);
	glRotatef((GLfloat)rotsfera2, 0.0, 1.0, 0.0);

	glColor3f(0.0, 0.0, 0.0);
	glutWireSphere(1.0, 15, 15);

	glPushMatrix();
	glTranslatef(-1.0, 1.2, 0.0);
	glRotatef((GLfloat)rotsfera, 0.0, 1.0, 0.0);
	glColor3f(fig.r, fig.g, fig.b);
	glutWireSphere(fig.a1, fig.c3, fig.c3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, 1.2, 0.0);
	glRotatef((GLfloat)rotsfera, 0.0, 1.0, 0.0);
	glColor3f(fig.r, fig.g, fig.b);
	glutWireSphere(fig.a1, fig.c3, fig.c3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -1.3, 0.0);
	glRotatef((GLfloat)rotsfera, 0.0, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glutWireSphere(fig.b1, fig.b2, fig.b2);


	glPushMatrix();
	glTranslatef(1.1, -0.3, 0.0);
	glColor3f(fig.r, fig.g, fig.b);
	glRotated(270, 1.0, 2.5, 0.0);
	glutWireCone(fig.a1, fig.c2, fig.c3, fig.c3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.1, -0.3, 0.0);
	glColor3f(fig.r, fig.g, fig.b);
	glRotated(90, -1.0, 2.5, 0.0);
	glutWireCone(fig.a1, fig.c2, fig.c3, fig.c3);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)rotsfera4, 0.0, 1.0, 0.0);
	glTranslatef(-2.2, -1.0, 1.0);
	glColor3f(0.19, 0.8, 0.6);
	glutWireTeapot(fig.a1);
	glPopMatrix();

	glPushMatrix();
	glRotatef((GLfloat)rotsfera4, 0.0, 1.0, 0.0);
	glTranslatef(3.0, -0.8, 0.0);
	glColor3f(0.73, 0.56, 0.56);
	glutWireTorus(fig.d1, fig.d2, fig.c3, fig.c3);
	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	/*glViewport(0, 0, (GLsizei)w, (GLsizei)h);*/
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0); 
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 's':
		rotsfera1 = (rotsfera1 + 5) % 360;
		break;
	case 'S':
		rotsfera1 = (rotsfera1 - 5) % 360;
		break;
	case 'a':
		rotsfera2 = (rotsfera2 + 5) % 360;
		break;
	case 'A':
		rotsfera2 = (rotsfera2 - 5) % 360;
		break;
	case 'q':
		rotsfera3 = (rotsfera3 + 3) % 360;
		break;
	case 'Q':
		rotsfera3 = (rotsfera3 - 3) % 360;
		break;
	case 'd':
		rotsfera = (rotsfera + 5) % 360;
		break;
	case 'l':
		rotsfera = (rotsfera - 5) % 360;
		break;
	case 't':
		rotsfera4 = (rotsfera4 + 5) % 360;
		break;
	case 'T':
		rotsfera4 = (rotsfera4 - 5) % 360;
		break;
	default:
		break;
	}

	if (key == 'r') { fig.r = 0.8; fig.g = 0.19, fig.b = 0.6; }
	if (key == 'g') { fig.r = 0.4; fig.g = 1.0, fig.b = 0.0; }
	if (key == 'b') { fig.r = 0.3; fig.g = 0.3, fig.b = 1.00; }
	glutPostRedisplay();
}
void mouse(int button, int state, int mousex, int mousey)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		x = mousex;
		y = mousey;

		m = ((double)rand() / (RAND_MAX));
		n = ((double)rand() / (RAND_MAX));
		e = ((double)rand() / (RAND_MAX));
		glClearColor(m, n, e, 0);
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		x = mousex;
		y = mousey;

		glClearColor(0.0, 0.0, 0.0, 0);
	}
	glutPostRedisplay();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("a");
	glClearColor(0.18, 0.18, 0.3, 0.0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape); 
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0; 
}