#include <GL/glut.h>
#include <stdio.h>
int flag = 0;
int i;
float le[500], re[500];
float x1 = 200, y1 = 200, x2 = 100, y2 = 300, x3 = 300, y3 = 300, x4 = 200, y4 = 400;
float mx;
void edgedetect(float x1, float y1, float x2, float y2)
{

    int x;
    if ((y2 - y1) != 0)
    {
        mx = (x2 - x1) / (y2 - y1);
    }
    x = x1;

    for (int i = y1; i <= y2; i++)
    {
        if (x < le[i])
            le[i] = (int)x;
        if (x > re[i])
            re[i] = (int)x;

        x = x+mx;
    }

}

void scanfill()
{
    int y,j;
    for (int i = 0; i < 500; i++)
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
        for (j = le[i]; j <= re[i]; j++)
        {

            glColor3f(0, 1, 0);
            glBegin(GL_LINES);
            glVertex2i(y, j);
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

    if(flag == 1){
        scanfill();
    }

    glutPostRedisplay();
    glFlush();


}

void init()
{

    gluOrtho2D(0, 500, 0, 500);
}

void mymenu(int id)
{
    if (id == 1)
        flag = 1;
    else
        exit(0);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("scanfill");
    init();
    glutDisplayFunc(display);
    glutCreateMenu(mymenu);
    glutAddMenuEntry("fill", 1);
    glutAddMenuEntry("exit", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}