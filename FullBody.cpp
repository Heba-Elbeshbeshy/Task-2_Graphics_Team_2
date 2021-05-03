#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14

static int shoulder = 0, elbow = 0 , body =0; 
static int fingerBase1 = 0, fingerUp1 = 0; 
static int fingerBase2 = 0, fingerUp2 = 0; 
static int fingerBase3 = 0, fingerUp3 = 0; 
static int fingerBase4 = 0, fingerUp4 = 0; 
static int fingerBase5 = 0, fingerUp5 = 0; 
static int LeftLeg = 0, LeftKnee =0, LeftFoot=0;


static int shoulder2 = 0, elbow2 = 0 ; 
static int fingerBase21 = 0, fingerUp21 = 0; 
static int fingerBase22 = 0, fingerUp22 = 0; 
static int fingerBase23 = 0, fingerUp23 = 0; 
static int fingerBase24 = 0, fingerUp24 = 0; 
static int fingerBase25 = 0, fingerUp25 = 0; 
static int RightLeg = 0, RightKnee =0 , RightFoot=0;


int moving, startx, starty;

GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */

//camera
double eye[] = { 0, 0, 2 };
double center[] = { 0, 0, 1 };
double up[] = {0.0, 1.0, 0.0};


void crossProduct(double a[], double b[], double c[])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

void normalize(double a[])
{
	double norm;
	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void rotatePoint(double a[], double theta, double p[])
{

	double temp[3];
	temp[0] = p[0];
	temp[1] = p[1];
	temp[2] = p[2];

	temp[0] = -a[2] * p[1] + a[1] * p[2];
	temp[1] = a[2] * p[0] - a[0] * p[2];
	temp[2] = -a[1] * p[0] + a[0] * p[1];

	temp[0] *= sin(theta);
	temp[1] *= sin(theta);
	temp[2] *= sin(theta);

	temp[0] += (1 - cos(theta)) * (a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
	temp[1] += (1 - cos(theta)) * (a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
	temp[2] += (1 - cos(theta)) * (a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

	temp[0] += cos(theta) * p[0];
	temp[1] += cos(theta) * p[1];
	temp[2] += cos(theta) * p[2];

	p[0] = temp[0];
	p[1] = temp[1];
	p[2] = temp[2];
}

void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);

   glMatrixMode(GL_PROJECTION);
	gluPerspective(60.0, 1.0, 1.0, 20.0);
	//glMatrixMode(GL_MODELVIEW);
}

void reset()
{
	double e[] = {0.0, 0.0, 2};
	double c[] = {0.0, 0.0, 1.0};
	double u[] = {0.0, 1.0, 0.0};
	for (int i = 0; i < 3; i++)
	{
		eye[i] = e[i];
		center[i] = c[i];
		up[i] = u[i];
	}
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);

   //glPushMatrix();
   gluLookAt(eye[0], eye[1], eye[2],
			  center[0], center[1], center[2],
			  up[0], up[1], up[2]);
    //glPopMatrix();

   glPushMatrix();
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);
   glTranslatef (0.0, 0.0, 0.0);
   glRotatef ((GLfloat) body, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (1.5, 4.0, 0.5);
   glutWireCube (1.0);
    
   glPopMatrix();

//   Head
   glPushMatrix();
   glTranslatef (0.0, 2.6 , 0.0);
   glutWireSphere(0.42 , 10 , 10);
   glPopMatrix();

   glPopMatrix();

//    Right Arm
   glPushMatrix();
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);
   glTranslatef (-0.9, 1.85, 0.0);
   glRotatef ((GLfloat) shoulder2, 0.0, 0.0, 1.0);
   glTranslatef (0.0, -0.55, 0.0);
   glPushMatrix();
   glScalef (0.3, 1.25, 0.3);
   glutWireCube (1.0);

   glPopMatrix();

   glTranslatef (0.0, -0.6, 0.0);
   glRotatef ((GLfloat) elbow2, 0.0, 0.0, 1.0);
   glTranslatef (0.0, -0.65, 0.0);
   glPushMatrix();
   glScalef (0.3, 1.25, 0.3);
   glutWireCube (1.0);
   glPopMatrix();

   glPopMatrix();

//   Left Arm
   glPushMatrix();
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);
   glTranslatef (0.9, 1.85, 0.0);
   glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
   glTranslatef (0.0, -0.55 , 0.0);
   glPushMatrix();
   glScalef (0.3, 1.25, 0.3);
   glutWireCube (1.0);

   glPopMatrix();

   glTranslatef (0.0, -0.6, 0.0);
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
   glTranslatef (0.0, -0.65, 0.0);
   glPushMatrix();
   glScalef (0.3, 1.25, 0.3);
   glutWireCube (1.0);
   glPopMatrix();

   glPopMatrix();


//   Right Leg
   glPushMatrix();
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);
   glTranslatef (-0.55, -2.0, 0.0);
   glRotatef ((GLfloat) RightLeg, 0.0, 0.0, 1.0);
   glTranslatef (0.05, -0.9, 0.0);
   glPushMatrix();
   glScalef (0.5, 1.7, 0.5);
   glutWireCube (1.0);

   glPopMatrix();

   glTranslatef (0.0, -0.8, 0.0);
   glRotatef ((GLfloat) RightKnee, 0.0, 0.0, 1.0);
   glTranslatef (0.0, -0.9, 0.0);
   glPushMatrix();
   glScalef (0.5, 1.7, 0.5);
   glutWireCube (1.0);

   glPopMatrix();

   glTranslatef (0.0, -1.0, 0.0);
   glRotatef ((GLfloat) RightFoot, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (0.55, 0.5, 1.0);
   glutSolidCube (1.0);
   glPopMatrix();

   glPopMatrix();

//  Left Leg
   glPushMatrix();
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);
   glTranslatef (0.55, -2.0, 0.0);
   glRotatef ((GLfloat) LeftLeg, 0.0, 0.0, 1.0);
   glTranslatef (-0.05, -0.9, 0.0);
   glPushMatrix();
   glScalef (0.5, 1.7, 0.5);
   glutWireCube (1.0);

   glPopMatrix();

   glTranslatef (0.0, -0.8, 0.0);
   glRotatef ((GLfloat) LeftKnee, 0.0, 0.0, 1.0);
   glTranslatef (0.0, -0.9, 0.0);
   glPushMatrix();
   glScalef (0.5, 1.7, 0.5);
   glutWireCube (1.0);

   glPopMatrix();

   glTranslatef (0.0, 0.0, 0.0);
   glRotatef ((GLfloat) LeftFoot, 0.0, 0.0, 1.0);
   glTranslatef (0.0, -1.0, 0.0);
   glPushMatrix();
   glScalef (0.55, 0.5, 1.0);
   glutSolidCube (1.0);

   glPopMatrix();
   
   glPopMatrix();
   glutSwapBuffers();



}

// Rotation about vertical direction
void lookRight()
{
	rotatePoint(up, PI / 20, eye);
}

void lookLeft()
{
	rotatePoint(up, -PI / 20, eye);
}

// Rotation about horizontal direction

void lookUp()
{
	double horizontal[3];
	double look[] = {center[0] - eye[0], center[1] - eye[1], center[2] - eye[2]};
	crossProduct(up, look, horizontal);
	normalize(horizontal);
	rotatePoint(horizontal, PI / 20, eye);
	rotatePoint(horizontal, PI / 20, up);
}

void lookDown()
{
	double horizontal[3];
	double look[] = {center[0] - eye[0], center[1] - eye[1], center[2] - eye[2]};
	crossProduct(up, look, horizontal);
	normalize(horizontal);
	rotatePoint(horizontal, -PI / 20, eye);
	rotatePoint(horizontal, -PI / 20, up);
}

// Forward and Backward
void moveForward()
{
	double direction[3];
	direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
	double speed = 0.1;
	eye[0] += direction[0] * speed;
	eye[1] += direction[1] * speed;
	eye[2] += direction[2] * speed;

	center[0] += direction[0] * speed;
	center[1] += direction[1] * speed;
	center[2] += direction[2] * speed;
}

void moveBackword()
{
	double direction[3];
	direction[0] = center[0] - eye[0];
	direction[1] = center[1] - eye[1];
	direction[2] = center[2] - eye[2];
	double speed = 0.1;
	eye[0] -= direction[0] * speed;
	eye[1] -= direction[1] * speed;
	eye[2] -= direction[2] * speed;

	center[0] -= direction[0] * speed;
	center[1] -= direction[1] * speed;
	center[2] -= direction[2] * speed;

}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -5.0);
}

void specialKeys(int key, int x, int y)
{
	switch (key)
	{  
	case GLUT_KEY_LEFT:
		lookLeft();
		break;
	case GLUT_KEY_RIGHT:
		lookRight();
		break;
	case GLUT_KEY_UP:
		lookUp();
		break;
	case GLUT_KEY_DOWN:
		lookDown();
		break;
	}
	glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   { 
        //camera's keys
        case 'f':
            moveForward();
            glutPostRedisplay();
            break;
        case 'b':
            moveBackword();
            glutPostRedisplay();
            break;
        case 'r':
            reset();
            glutPostRedisplay();
            break; 
        //   Left Arm
        // Shoulder
        case 's':
            shoulder = (shoulder + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':
            shoulder = (shoulder - 5) % 360;
            glutPostRedisplay();
            break;
        // Elbow
        case 'e':
            elbow = (elbow + 5) % 180;
            glutPostRedisplay();
            break;
        case 'E':
            elbow = (elbow - 5) % 180;
            glutPostRedisplay();
            break;

        // Right Arm
        // Shoulder
        case 'a':
            shoulder2 = (shoulder2 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'A':
            shoulder2 = (shoulder2 - 5) % 360;
            glutPostRedisplay();
            break;
        // Elbow
        case 'c':
            elbow2 = (elbow2 + 5) % 180;
            glutPostRedisplay();
            break;
        case 'C':
            elbow2 = (elbow2 - 5) % 180;
            glutPostRedisplay();
            break;

        // Right Leg
        case 'i':
            RightLeg = (RightLeg + 5) % 360;
            glutPostRedisplay();
            break;
        case 'I':
            RightLeg = (RightLeg - 5) % 360;
            glutPostRedisplay();
            break;
    
        case 'j':
            RightKnee = (RightKnee + 5) % 180;
            glutPostRedisplay();
            break;
        case 'J':
            RightKnee = (RightKnee - 5) % 180;
            glutPostRedisplay();
            break;

        // Left Leg
        case 'k':
            LeftLeg = (LeftLeg + 5) % 360;
            glutPostRedisplay();
            break;
        case 'K':
            LeftLeg = (LeftLeg - 5) % 360;
            glutPostRedisplay();
            break;
    
        case 'l':
            LeftKnee = (LeftKnee + 5) % 180;
            glutPostRedisplay();
            break;
        case 'L':
            LeftKnee = (LeftKnee - 5) % 180;
            glutPostRedisplay();
            break;
   case 27:
      exit(0);
      break;
   default:
      break;
   }
}

static void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      moving = 1;
      startx = x;
      starty = y;
    }
    if (state == GLUT_UP) {
      moving = 0;
    }
  }
}


static void motion(int x, int y)
{
  if (moving) {
    angle = angle + (x - startx);
    angle2 = angle2 + (y - starty);
    startx = x;
    starty = y;
    glutPostRedisplay();
  }
}



int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(750, 750);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutMouseFunc(mouse);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialKeys);
   glutMotionFunc(motion);  
   glutMainLoop();
   return 0;
}