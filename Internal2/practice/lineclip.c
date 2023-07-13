#include<GL/glut.h>

void display(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}
void init(){
    gluOrtho2D(0,500,0,500);
}
int main(int argc, char **argv){
    glutInit(argc, &argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize();
    glutInitWindowPosition();
    glutCreateWindow("Something");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}