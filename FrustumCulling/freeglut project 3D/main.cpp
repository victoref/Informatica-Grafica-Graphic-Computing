/*Made by:
* Victor Emiliano Fernandez Rubio
* Gonzalo Guzman del Rio*/

//Teacher: Antonio Gavilanes Franco

/*Practice of the subject Graphic Computing of the UCM*/
/*
In the scene you can see a hypotrocoid, it conteins a car inside, you can move the car inside of the hypotrocoid.
If you crash with a tree, this disappears.
Working:
Key 'q': The car goes backward and right
Key 'w': The car goes forward and right
Key 'e': The car goes forward and left
Key 'r': The car goes backward and left
Key 'f': activate/deactivate rustum culling


Keys z,a,x,s,c,d for rotate the scene

*/
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/freeglut.h>
#include "Escena.h"
//#include <GL/glut.h>

#include <iostream>
using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;

// Viewing frustum parameters
GLdouble xRight=20, xLeft=-xRight, yTop=20, yBot=-yTop, N=60, F=500;

// Camera parameters
//GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0; original
GLdouble eyeX = 0.0, eyeY = 100.0, eyeZ = 0.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
//GLdouble upX=0, upY=1, upZ=0; original
GLdouble upX = 0, upY = 0, upZ = -1;


// Scene variables
GLfloat angX, angY, angZ;

Escena* escena;
Cubo* c;

//Variables movimiento
double mov = 5;
double radio = 10; 
void followingCam();

void buildSceneObjects() {	 
    angX=0.0f;
    angY=0.0f;
    angZ=0.0f;
	escena = new Escena(-53,53);
	
}

void followingCam() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	PuntoVector3D* posicion = new PuntoVector3D(escena->getHijo()[0]->getmT()->getM()[12], escena->getHijo()[0]->getmT()->getM()[13], escena->getHijo()[0]->getmT()->getM()[14], 1);
	gluLookAt(posicion->getX(), eyeY, posicion->getZ(), posicion->getX(), lookY, posicion->getZ(), upX, upY, upZ);
}

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);
      
	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.9f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	buildSceneObjects();

	// Light0
	glEnable(GL_LIGHTING);  
    glEnable(GL_LIGHT0);
    GLfloat d[]={0.7f,0.5f,0.5f,1.0f};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0f};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat s[]={1.0f,1.0f,1.0f,1.0f};
    glLightfv(GL_LIGHT0, GL_SPECULAR, s);
	GLfloat p[]={25.0f, 25.0f, 25.0f, 1.0f};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);

	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  
	glFrustum(xLeft, xRight, yBot, yTop, N, F);
	//glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);  	
 }


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	 
	glMatrixMode(GL_MODELVIEW);	 
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
		escena->dibuja(xLeft + escena->getHijo()[0]->getmT()->getM()[12],
			escena->getHijo()[0]->getmT()->getM()[14] - yTop,
			escena->getHijo()[0]->getmT()->getM()[12] + xRight,
			escena->getHijo()[0]->getmT()->getM()[14] - yTop,
			xRight + escena->getHijo()[0]->getmT()->getM()[12],
			escena->getHijo()[0]->getmT()->getM()[14] + yTop,
			xLeft + escena->getHijo()[0]->getmT()->getM()[12],
			escena->getHijo()[0]->getmT()->getM()[14] + yTop);
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
	//glOrtho(xLeft, xRight, yBot, yTop, N, F);
	glFrustum(xLeft, xRight, yBot, yTop, N, F);

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
		case 'f':
			escena->frustum = !escena->frustum;
			break;
		case 'w':
				escena->colision();
				if (!escena->canMove()){
					// rotación izquierda y alante
					escena->getHijo()[0]->getmT()->traslada(0, 0, -radio);
					escena->getHijo()[0]->getmT()->rota(mov, 0, 1, 0);
					escena->getHijo()[0]->getmT()->traslada(0, 0, radio);
					followingCam();
				}
			break;
		case 'q':
				escena->colision();
				if (!escena->canMove()){
					//rotacion izquierda y atras
					escena->getHijo()[0]->getmT()->traslada(0, 0, -radio);
					escena->getHijo()[0]->getmT()->rota(-mov, 0, 1, 0);
					escena->getHijo()[0]->getmT()->traslada(0, 0, radio);
					followingCam();
				}
			break;

		case 'r':
				escena->colision();
				if (!escena->canMove()){
					//rotacion derecha y atras
					escena->getHijo()[0]->getmT()->traslada(0, 0, radio);
					escena->getHijo()[0]->getmT()->rota(mov, 0, 1, 0);
					escena->getHijo()[0]->getmT()->traslada(0, 0, -radio);
					followingCam();
				}
		break;
			

		case 'e':
				escena->colision();
				if (!escena->canMove()){
					//rotacion derecha y alante
					escena->getHijo()[0]->getmT()->traslada(0, 0, radio);
					escena->getHijo()[0]->getmT()->rota(-mov, 0, 1, 0);
					escena->getHijo()[0]->getmT()->traslada(0, 0, -radio);
					followingCam();
				}
			break;

		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay) {
		glutPostRedisplay();
	}
		
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

   
	return 0;
}
