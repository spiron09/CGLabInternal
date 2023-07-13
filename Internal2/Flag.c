#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float cp[4][2] = {{100, 400}, {150, 450}, {200, 350}, {250, 400}};
float theta = 0;
int flag = 0;

int fact(int n)
{
    int i, num = 1;
    for (i = n; i > 1; i--)
    {
        num *= i;
    }
    return num;
}

float combination(float i, float n)
{
    float c;
    c = fact(n) / (fact(i) * fact(n - i));
    return c;
}

void curve()
{
    int i;
    float t, x, y;
    int n = 3;
    glPointSize(15.0);
    glBegin(GL_LINE_STRIP);
    for (t = 0; t <= 1; t += 0.1)
    {
        x = 0, y = 0;
        for (i = 0; i < 4; i++)
        {
            x += cp[i][0] * combination(i, n) * pow(t, i) * pow(1 - t, n - i);
            y += cp[i][1] * combination(i, n) * pow(t, i) * pow(1 - t, n - i);
        }
        glVertex2f(x, y);
        printf("%f %f\n", x, y);
    }
    glEnd();
}

void display()
{
    int i;
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    // theta = (theta * 3.14) / 180;
    cp[1][0] += sin(theta);
    cp[1][1] += sin(theta);

    cp[2][0] += sin(theta);
    cp[2][1] += sin(theta);

    cp[3][0] += sin(theta);
    cp[3][1] += sin(theta);

    glPushMatrix();

    for (i = 0; i < 20; i++)
    {
        glColor3f(1, 0.5, 0);
        glTranslatef(0, -1, 0);
        curve();
    }
    for (i = 0; i < 20; i++)
    {
        glColor3f(1, 1, 1);
        glTranslatef(0, -1, 0);
        curve();
    }

    for (i = 0; i < 20; i++)
    {
        glColor3f(0, 1, 0);
        glTranslatef(0, -1, 0);
        curve();
    }

    glPopMatrix();
    glLineWidth(5.0);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(100, 400);
    glVertex2f(100, 200);
    glEnd();

    glFlush();
}

void idle()
{
    theta += 0.20;
    if (theta > 360)
        theta = 0;
    display();
}

void init()
{
    gluOrtho2D(0, 500, 0, 500);
}

void menu(int id)
{
    if (id == 1)
        glutIdleFunc(idle);

    if (id == 2)
        glutIdleFunc(NULL);

    if (id == 3)
        exit(0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("CURVE_177");
    init();

    glutCreateMenu(menu);
    glutAddMenuEntry("Start", 1);
    glutAddMenuEntry("Stop", 2);
    glutAddMenuEntry("Exit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    

    
    glutMainLoop();
    return 0;
}