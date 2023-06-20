#include <GL/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;

void plot_pixel(int x, int y)
{

    glColor3d(0, 0, 0);

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void bhams(int x1, int y1, int x2, int y2)
{

    int dx;
    int dy;
    int x, y;
    x = x1;
    y = y1;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    int incx, incy;
    incx = 1;
    incy = 1;
    if (x2 < x1)
        incx = -1;
    if (y2 < y1)
        incy = -1;
    plot_pixel(x, y);

    if (dx >= dy)
    {
        int p;
        p = (2 * dy) - dx;

        for (int i = 0; i < dx; i++)
        {
            x = x + incx;
            
            if (p < 0)
            {
                y = y;
                p = p + 2 * dy;
            }

            else
            {
                y = y + incy;
                p = p + (2 * dy) - (2 * dx);
            }

            plot_pixel(x, y);
        }
    }

    else if (dy > dx)
    {
        int p;
        p = (2 * dx) - dy;

        for (int i = 0; i < dy; i++)
        {

            y = y + incy;
            if (p < 0)
            {
                x = x;
                p = p + 2 * dx;
            }

            else
            {
                x = x + incx;
                p = p + (2 * dx) - (2 * dy);
            }

            plot_pixel(x, y);
        }
    }
}

void display()
{

    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    bhams(x1, y1, x2, y2);
    glFlush();
}

void init()
{
    gluOrtho2D(0, 600, 0, 400);
}

int main(int argc, char **argv)
{
    printf("Enter initial points");
    scanf("%d %d", &x1, &y1);
    printf("Enter final points");
    scanf("%d %d", &x2, &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("LINE DRAWING ALGORITHM 1CR20CS198");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
