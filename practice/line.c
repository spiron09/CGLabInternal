#include<GL/glut.h>

int x1 = 100,x2 = 100,y1=100,y2=300;
void plotpix(int x, int y){

    glColor3f(0,0,0);
    glBegin(GL_POINTS);
        glVertex2f(x,y);
    glEnd();
}
void bhams(int x1, int y1, int x2, int y2){
    int dx,dy,x,y,incx, incy;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    incx = 1;
    incy = 1;
    if(x2<x1)
        incx = -1;
    if(y2<y1)
        incy = -1;

    x=x1;
    y=y1;
    plotpix(x,y);

    if(dx>=dy){
        int p;
        p = 2*dy - dx;

        for(int i =0; i<dx; i++){
            x=x+incx;
        if(p<0){
            y=y;
            p=p+2*dy;
            
        }

        else {
            y = y + incy;
            p = 2*dy-2*dx;
            
        }

        plotpix(x,y);

        }
    }

    else {

        int p;
        p = 2*dx - dy;

        for(int i =0; i<dy; i++){
        
        y=y+incy;
        if(p<0){
            x=x;
            p=p+2*dx;
            
        }

        else {
            x = x + incx;
            p = 2*dx-2*dy;
            
        }

        plotpix(y,y);

        }
    }
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);
	

	
	bhams(x1,y1,x2,y2);
	glFlush();
}

void init() {

	gluOrtho2D(0, 500, 0, 500);

}

int main(int argc, char **argv) {


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	
	glutCreateWindow("Hello!");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
