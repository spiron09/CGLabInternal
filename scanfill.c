#include <GL/glut.h>
#include <stdio.h>

float mx;
int i, flag;
float le[500], re[500];
float x1 = 200, y1 = 200, x2 = 100, y2 = 300, x3 = 300, y3 = 300, x4 = 200, y4 = 400;

void edgedetect(float x1, float y1, float x2, float y2)
{
    int x;
    if ((y2 - y1) != 0)
        mx = (x2 - x1) / (y2 - y1);
    x = x1;
    for (i = y1; i <= y2; i++)
    {
        if (x < le[i])
            le[i] = (int)x;
        if (x > re[i])
            re[i] = (int)x;
        x = x + mx;
    }
}

void scanline()
{
    int y;
    for (i = 0; i < 500; i++)
    {
        le[i] = 500;
        re[i] = 0;
    }
    edgedetect(x1, y1, x2, y2);
    edgedetect(x1, y1, x3, y3);
    edgedetect(x2, y2, x4, y4);
    edgedetect(x3, y3, x4, y4);
    for (y = 0; y < 500; y++)
    {
        for (i = le[y]; i <= re[y]; i++)
        {
            glColor3f(1, 0, 0);
            glBegin(GL_POINTS);
            glVertex2i(i, y);
            glEnd();
        }
    }
}
void display()
{

    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    if (flag == 0)
    {
        glColor3f(0, 0, 0);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x4, y4);
        glVertex2f(x3, y3);

        glEnd();
    }
    if (flag == 1)
        scanline();
    glutPostRedisplay();
    glFlush();
}

void mymenu(int id)
{
    if (id == 1)
        flag = 1;
    if (id == 2)
        exit(0);
}
void init()
{
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv)
{
    int ch;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Polygon_187");
    init();
    glutDisplayFunc(display);
    glutCreateMenu(mymenu);
    glutAddMenuEntry("Fill", 1);
    glutAddMenuEntry("Exit", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}