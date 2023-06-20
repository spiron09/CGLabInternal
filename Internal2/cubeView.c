#include<GL/glut.h>
float v[8][3] = {{-1,1,1},{-1,-1,1},{1,-1,1},{1,1,1},{-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1}};

int view[] = {0,0,5};
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
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(view[0], view[1], view[2], 0,0,0, 0,1,0);
cube();
glutSwapBuffers();
glFlush();

}


void init()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-2,2,-2,2,2,20);
glMatrixMode(GL_MODELVIEW);
}


void keys (unsigned char ch, int x, int y)
{
if(ch=='x') view[0] -= 1;
if(ch=='X') view[0] += 1;

if(ch=='y') view[1] -= 1;
if(ch=='Y') view[1] += 1;

if(ch=='z') view[2] -= 1;
if(ch=='Z') view[2] += 1;

glutPostRedisplay();

}

int main(int argc, char **argv) {

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE |GLUT_DEPTH);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("Cube 1CR20CS201");
init();
glutDisplayFunc(display);

glutKeyboardFunc(keys);
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}
