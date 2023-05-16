#include<GL/glut.h>
#include<stdio.h>
float v[4][3] = {{-1,-1,0},{0,1,0},{1,-1,0},{0,0,1}};

int m;

void triangle(float a[3], float b[3], float c[3]){

    glBegin(GL_TRIANGLES);
        glVertex3fv(a);
        glVertex3fv(b);
        glVertex3fv(c);
    glEnd();
}

void div_triangle(float a[3], float b[3], float c[3], int m){
    float v1[3], v2[3], v3[3];

    if(m>0){
        for(int i = 0; i<3; i++){
            v1[i] = (a[i]+b[i]) /2;
            v2[i] = (a[i]+c[i]) /2;
            v3[i] = (c[i]+b[i]) /2;
        }

        div_triangle(b,v1,v3,m-1);
        div_triangle(c,v2,v3,m-1);
        div_triangle(a,v1,v2,m-1);
    }

    else{
        triangle(a,b,c);
    }
}

void tetraheadtron(int m){

    glColor3f(0,0,0);
        div_triangle(v[0], v[1], v[2], m);

    glColor3f(1,0,0);
        div_triangle(v[0], v[1], v[3], m);

    glColor3f(0,1,0);
        div_triangle(v[1], v[2], v[3], m);

    glColor3f(0,0,1);
        div_triangle(v[0], v[2], v[3], m);
        
}

void display(){

    tetraheadtron(m);
    glFlush();
}

void init(){

    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glOrtho(-2.0, 2.0,-2.0, 2.0,-2.0, 2.0);
}

int main(int argc, char **argv){

    printf("Enter the size of m");
    scanf("%d", &m);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("gasket");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}