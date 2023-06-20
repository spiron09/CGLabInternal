#include<GL/glut.h>
float v[8][3] = {{-1,1,1},{-1,-1,1},{1,-1,1},{1,1,1},{-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1}};

int view[] = {0,0,5};
float theta[3] = { 0,0,0 };
int axis = 0;
void square(int a, int b, int c, int d)
{

glBegin(GL_POLYGON);
glVertex3fv(v[a]);
glVertex3fv(v[b]);
glVertex3fv(v[c]);
glVertex3fv(v[d]);
glEnd();

}

void cube()
{

glColor3f(1,0,0);
square(0,1,2,3);

glColor3f(0,1,0);
square(4,5,6,7);

glColor3f(0,0,1);
square(1,4,7,0);

glColor3f(1,1,0);
square(2,5,6,3);

glColor3f(0,1,1);
square(0,7,6,3);

glColor3f(1,0,1);
square(1,2,5,4);

}
void display()
{


glClearColor(1,1,1,1);
glLoadIdentity();
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glRotatef(theta[0],1,0,0);
glRotatef(theta[1],0,1,0);
glRotatef(theta[2],0,0,1);
cube();
glutSwapBuffers();
glutPostRedisplay();
glFlush();

}


void init()
{
glMatrixMode(GL_PROJECTION);
glOrtho(-2,2,-2,2,-2,2);
glMatrixMode(GL_MODELVIEW);
}

void mousefunc(int button, int status, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && status == GLUT_DOWN)
		axis = 0;
	if (button == GLUT_RIGHT_BUTTON && status == GLUT_DOWN)
		axis = 1;
	else
		axis = 2;

}


void spinning_axis(){
    theta[axis]+=0.5;
    if (theta[axis]>=360) theta[axis] = 0;
    glutPostRedisplay();
}
int main(int argc, char **argv) {

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE |GLUT_DEPTH);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("CubeSpin 1CR20CS181");
init();
glutDisplayFunc(display);
glutMouseFunc(mousefunc);
glutIdleFunc(spinning_axis);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}
