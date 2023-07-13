#include <GL/glut.h>
#include <stdio.h>
float xmin = 50, ymin = 50, xmax = 100, ymax = 100;
int left = 2, top = 4, right = 8, bottom = 1;
float x1, y1;
float x2, y2;
int compute(float x, float y)
{
    int code = 0;
    if (x < xmin)
        code = code | left;

    if (x > xmax)
        code = code | right;

    if (y < ymin)
        code = code | bottom;

    if (y > ymax)
        code = code | top;

    return code;
}

void lineclipping(float x1, float y1, float x2, float y2)
{
    int code1, code2, codeout;
    int done = 0, accept = 0;

    float x, y;
    code1 = compute(x1, y1);
    code2 = compute(x2, y2);

    do
    {
        
        //completely inside
        if ((code1 | code2) == 0)
        {
            done = 1;
            accept = 1;
        }

        //completely outside
        else if (code1 & code2)
        {
            done = 1;
        }

        //partial
        else
        {
            if (code1 != 0)
                codeout = code1;
            else
                codeout = code2;

            if (codeout & left)
            {
                x = xmin;
                y = y1 + (xmin - x1) * ((y2 - y1) / (x2 - x1));
            }

            else if (codeout & right)
            {
                x = xmax;
                y = y1 + (xmax - x1) * ((y2 - y1) / (x2 - x1));
            }

            else if (codeout & bottom)
            {
                y = ymin;
                x = x1 + (ymin - y1) * ((x2 - x1) / (y2 - y1));
            }

            //top
            else
            {
                y = ymax;
                x = x1 + (ymax - y1) * ((x2 - x1) / (y2 - y1));
            }

            if (codeout == code1)
            {
                x1 = x;
                y1 = y;
                code1 = compute(x1, y1);
            }

            else
            {
                x2 = x;
                y2 = y;
                code2 = compute(x2, y2);
            }
        }

    } while (!done);

    if (accept)
    {
        glTranslatef(100, 100, 0);

        glColor3f(0, 0, 0);

        glBegin(GL_LINE_LOOP);
        glVertex2f(xmin, ymin);
        glVertex2f(xmax, ymin);
        glVertex2f(xmax, ymax);
        glVertex2f(xmin, ymax);
        glEnd();

        glColor3f(1, 0, 0);

        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
}

void display()
{
    
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 0, 0);

    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();

    glColor3f(1, 0, 0);

    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();

    lineclipping(x1, y1, x2, y2);

    glFlush();
}

void init()
{
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    printf("Enter points");
    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Line Clipping 1CR20CS188");
    init();

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
