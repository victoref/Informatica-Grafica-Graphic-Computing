﻿/*Made by:
* Victor Emiliano Fernandez Rubio*/

//Teacher: Antonio Gavilanes Franco

/*Practice of the subject Graphic Computing of the UCM*/
/*
In the scene you can see a hypotrocoid, it conteins a car inside, you can move the car inside of the hypotrocoid.
Working:
Key 'o': Change the hypotrocoid between full and line mode
Key 'f': The car goes forward
Key 'v': The car goes backward
Key 'q': Roll move of the camera
Key '1': Spin around the x axis
Key 'h': Turn up the lights of the scene
Key 'n': Turn off the lights of the scene
Key 'g': Turn up the lights of the car
Key 'b': Turn off the lights of the car

Keys z,a,x,s,c,d for rotate the scene

*/


#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Hipotrocoide.h"
#include "Coche.h"
#include "Camara.h"
#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <iostream>
using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;
// Viewing frustum parameters
GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

// Scene variables
GLfloat angX, angY, angZ; 


GLfloat gradosC = 0;

GLfloat gradosRoll = 0;

GLdouble rotacionRuedas = 0;

PuntoVector3D* eye = new PuntoVector3D(eyeX, eyeY, eyeZ, 1);
PuntoVector3D* look = new PuntoVector3D(lookX, lookY, lookZ, 0);
PuntoVector3D* up = new PuntoVector3D(upX, upY, upZ, 0);

bool transp = false;

//OBJETOS

float alfa;
Hipotrocoide* h;
Coche* c;
Camara* camara;


void buildSceneObjects() {	 
    angX=0.0f;
    angY=0.0f;
    angZ=0.0f;	

	h = new Hipotrocoide(20, 100, 14, 8, 4);
	c = new Coche();
	camara = new Camara(eye, look, up);
}

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);
      
	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.9f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH); // Shading by default

	buildSceneObjects();

	// Light0
	glEnable(GL_LIGHTING); 
    glEnable(GL_LIGHT0);

    /*GLfloat d[]={0.7f,0.5f,0.5f,1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat s[]={1.0f,1.0f,1.0f,1.0f};
    glLightfv(GL_LIGHT0, GL_SPECULAR, s);
	GLfloat p[]={25.0f, 25.0f, 25.0f, 1.0f};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);*/

	////original ▲

	GLfloat d[] = { 0, 1, 0, 1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
	GLfloat a[] = { 0, 0, 0, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat s[]={1.0f,1.0f,1.0f,1.0f};
	glLightfv(GL_LIGHT0, GL_SPECULAR, s);
	GLfloat p[] = { 0, 10, 10, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, p);
	GLfloat lmb[] = { 0, 0, 0, 1 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmb);
	
	////nueva ▲


	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);  	
 }


//======================================================================

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

	glMatrixMode(GL_MODELVIEW);
	GLfloat p[] = { 0, 10, 10, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, p);
	
	glPushMatrix();
	
		// Rotating the scene
		glRotatef(angX, 1.0f, 0.0f, 0.0f);
        glRotatef(angY, 0.0f, 1.0f, 0.0f);
        glRotatef(angZ, 0.0f, 0.0f, 1.0f);
		
		glLineWidth(1.5f);
		// Drawing axes
		glBegin( GL_LINES );			
			glColor3f(1.0,0.0,0.0); 
			glVertex3f(0, 0, 0);
			glVertex3f(20, 0, 0);	     
	 
			glColor3f(0.0,1.0,0.0); 
			glVertex3f(0, 0, 0);
			glVertex3f(0, 20, 0);	 
	 
			glColor3f(0.0,0.0,1.0); 
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, 20);	     
		glEnd();
		 		
		// Drawing the scene	 		 
		//glColor3f(1.0, 1.0, 1.0);
		//glutSolidSphere(6, 50, 60); //Sphere: radius=6, meridians=50, parallels=60

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


		//movemos el coche, hacer un metodo
		glPushMatrix();

		alfa = atan2(h->C’(gradosC)->getX(), h->C’(gradosC)->getZ());
		alfa = (alfa* 360) / (2 * 3.1415926);
		glTranslated(h->C(gradosC)->getX(), h->C(gradosC)->getY(), h->C(gradosC)->getZ());
		glRotated(-90, 0, 1, 0);
		glRotated(alfa, 0, 1, 0);
		c->dibuja(0.1, rotacionRuedas);
		glPopMatrix();


		if (transp)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		else if (!transp)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		
			h->dibuja();



	glPopMatrix();
 
	glFlush();
	glutSwapBuffers();
}


void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop (); 
			break;		 
		case 'a': angX=angX+5; break;
		case 'z': angX=angX-5; break; 
		case 's': angY=angY+5; break;
		case 'x': angY=angY-5; break;
		case 'd': angZ=angZ+5; break;
		case 'c': angZ=angZ-5; break;  

		case 'o': 
			if (!transp)
				transp = true;
			else 
				transp = false;
			break;

		case 'f':
			gradosC += 0.1;
			rotacionRuedas -= 10;
			break;
		case 'v':
			gradosC -= 0.1;
			rotacionRuedas += 10;
			break;
		case 'q':
			camara->movRoll();
			break;
		case '1':
			camara->giraX();
			break;
		case 'h':
			glEnable(GL_LIGHT0);
			break;
		case 'n':
			glDisable(GL_LIGHT0);
			break;
		case 'g':
			glEnable(GL_LIGHT1);
			glEnable(GL_LIGHT2);
			break;

		case 'b':
			glDisable(GL_LIGHT1);
			glDisable(GL_LIGHT2);
			break;
			

		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (0, 0);
	//glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
	

	
	// We would never reach this point using classic glut
	system("PAUSE"); 
   
	return 0;
}

