#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
float tri[3][3] = {{100, 200, 300}, {100, 300, 100}, {1, 1, 1}};
float rotate[3][3] = {{0}, {0}, {0}};
float result[3][3] = {{0}, {0}, {0}};
float theta;

void multiply()
{
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            result[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                result[i][j] += rotate[i][k] * tri[k][j];
            }
        }
    }
}

void trotate(int h, int k)
{
    rotate[0][0] = cos(theta);
    rotate[0][1] = -sin(theta);
    rotate[0][2] = h * (1 - cos(theta)) + k * sin(theta);
    rotate[1][0] = sin(theta);
    rotate[1][1] = cos(theta);
    rotate[1][2] = k * (1 - cos(theta)) - h * sin(theta);
    rotate[2][0] = 0;
    rotate[2][1] = 0;
    rotate[2][2] = 1;

    multiply();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);

    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(tri[0][0], tri[1][0]);
    glVertex2f(tri[0][1], tri[1][1]);
    glVertex2f(tri[0][2], tri[1][2]);
    glEnd();

    trotate(0, 0);
    glColor3f(0, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(result[0][0], result[1][0]);
    glVertex2f(result[0][1], result[1][1]);
    glVertex2f(result[0][2], result[1][2]);
    glEnd();

    trotate(200, 300);
    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(result[0][0], result[1][0]);
    glVertex2f(result[0][1], result[1][1]);
    glVertex2f(result[0][2], result[1][2]);
    glEnd();

    glPointSize(3.0);
    glColor3f(0, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(0, 0);
    glEnd();
    glFlush();
}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    printf("Enter the angle of rotation: ");
    scanf("%f", &theta);
    theta = theta * (3.14 / 180);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);

    
    glutCreateWindow("1CR20CS188_Triangle Rotation");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}