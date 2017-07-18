#include <GLUT/GLUT.h>
#include <iostream>
#include <cmath>



int i;
int Sub_Menu;
float x,y,z,w;
float angle,angle1,theta=0 ;
void speed(){
    theta +=10.0;
    glutPostRedisplay();
}

void spiral()
{
    z = 0.0;
    w = 0.0;
    for(i = 0 ;i < 3600; i++)
    {
        x=w*(cos(z * 3.14 / 180.0));
        y=w*(sin(z * 3.14 / 180.0));
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
        z = z + 1.0;
        w = 0.1 * z / 360;
        
    }
    glRotatef(theta, 0, 0, 1);
    
}
void Wiresphere()
{
    glLoadIdentity();
    glColor3f (0,0.90,0);
    glutWireSphere(0.8,50,50);
}
void WireCube()
{
    glLoadIdentity();
    glColor3f (0,0,1);
    glRotatef(theta,0, 1, 0);
    glutWireCube (1);
}
void WireTeapot()
{
    glLoadIdentity();
    glColor3f (0,1,1);
    glRotatef(theta,0, 1, 0);
    glutWireTeapot (0.5);
    
}


void display()
{
    
}

void init()
{
    glClearColor(0,0,0,0.0);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0,1.0,-1.0,1.0);
    
    
    
}

void Top_Menu( int value)
{
    if (value == 1)
    {
        exit(0);
    }
}
void Down_Menu (int value)
{
    
    if (value == 2)
    {
        
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f (1,1,1);
        
        spiral();
        glutPostRedisplay ();
        glutSwapBuffers();
        glFlush();
        glutPostRedisplay ();
        
        
    }
    if (value == 3)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        Wiresphere();
        glutSwapBuffers();
        glFlush();
        glutPostRedisplay ();
    }
    
    if (value == 4)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        WireCube ();
        glutSwapBuffers();
        glFlush();
        glutPostRedisplay ();
    }
    if (value == 5)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        WireTeapot ();
        glutSwapBuffers();
        glFlush();
        glutPostRedisplay ();
    }
    
}


int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize (400,400);
    glutInitWindowPosition (0.0,0.0);
    glutCreateWindow ("Shapes");
    init();
    glutDisplayFunc (display);
    Sub_Menu=glutCreateMenu(Down_Menu);
    glutAddMenuEntry("Spiral",2);
    glutAddMenuEntry("Sphere",3);
    glutAddMenuEntry("Simple Cube",4);
    glutAddMenuEntry("Tea Pot",5);
    glutCreateMenu (Top_Menu);
    glutAddSubMenu ("Shapes", Sub_Menu );
    glutAddMenuEntry("Exit",1);
    glutAttachMenu (GLUT_RIGHT_BUTTON );
    
    glutIdleFunc(speed);
    glutMainLoop();
}