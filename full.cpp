#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

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

//*********1
double eye[] = { 0, 0, 2 };
double center[] = { 0, 0, 1 };
double up[] = { 0, 1, 0 };
double speed = 0.2;
int pressed = 0;
int limitForwardBackward = 0;
int limitUpDown = 0;
int limitRightLeft = 0;

int moving, startx, starty;

GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */

void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   //**********2
   glMatrixMode(GL_PROJECTION);
    gluPerspective(65.0, (GLfloat)1024 / (GLfloat)869, 1.0, 60.0);
}


void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
    
   glPushMatrix();
   gluLookAt(eye[0], eye[1], eye[2],
              center[0], center[1], center[2],
              up[0], up[1], up[2]);
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);
// Body
   glPushMatrix();
   glTranslatef (0.0, 0.0, 0.0);
   glRotatef ((GLfloat) body, 0.0, 0.0, 1.0);
   glTranslatef (0.0, 0.0, 0.0);   
   glScalef (1.5, 4.0, 0.5);
   glutWireCube (1.0);    
   glPopMatrix();
//   Head
   glPushMatrix();
   glTranslatef (0.0, 3.0, 0.0);
   glutWireSphere(0.5 , 10 , 10);
   glPopMatrix();

   //glPopMatrix();

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
   glPopMatrix();
   glutSwapBuffers();
}

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

    temp[0] += (1 - cos(theta))*(a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
    temp[1] += (1 - cos(theta))*(a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
    temp[2] += (1 - cos(theta))*(a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

    temp[0] += cos(theta)*p[0];
    temp[1] += cos(theta)*p[1];
    temp[2] += cos(theta)*p[2];

    p[0] = temp[0];
    p[1] = temp[1];
    p[2] = temp[2];

}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -8.0);
}


void Left()
{


    // implement camera rotation arround vertical window screen axis to the left
    // used by mouse and left arrow
    rotatePoint(up, (float)22/7/20, eye);

    limitRightLeft += 1;

}

void Right()
{

    // implement camera rotation arround vertical window screen axis to the right
    // used by mouse and right arrow
    rotatePoint(up, -(float)22/7/20, eye);
    limitRightLeft -= 1;
}

void Up()
{
    // implement camera rotation arround horizontal window screen axis +ve
    // used by up arrow
    double horizontal[] = {0, 0, 0};

    crossProduct(eye, up, horizontal);
    normalize(horizontal);
    rotatePoint(horizontal, 3.14/20, eye);
    rotatePoint(horizontal, 3.14/20, up);
    limitUpDown += 1;

}

void Down()
{
    // implement camera rotation arround horizontal window screen axis
    // used by down arrow
    double horizontal[] = {0, 0, 0};
    crossProduct(eye, up, horizontal);
    normalize(horizontal);
    rotatePoint(horizontal, -3.14/20, eye);
    rotatePoint(horizontal, -3.14/20, up);
    limitUpDown -= 1;

}

void moveForward()
{
    double direction[] = {0, 0, 0};
    direction[0] = center[0] - eye[0];
    direction[1] = center[1] - eye[1];
    direction[2] = center[2] - eye[2];

    eye[0] -= direction[0] * speed;
    eye[1] -= direction[1] * speed;
    eye[2] -= direction[2] * speed;
    center[0] -= direction[0] * speed;
    center[1] -= direction[1] * speed;
    center[2] -= direction[2] * speed;

    limitForwardBackward += 1;
}

void moveBack()
{

    double direction[] = {0, 0, 0};
    direction[0] = center[0] - eye[0];
    direction[1] = center[1] - eye[1];
    direction[2] = center[2] - eye[2];

    eye[0] += direction[0] * speed;
    eye[1] += direction[1] * speed;
    eye[2] += direction[2] * speed;
    center[0] += direction[0] * speed;
    center[1] += direction[1] * speed;
    center[2] += direction[2] * speed;

    limitForwardBackward -= 1;
}


void specialKeys(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            if(pressed==0) {
                if (limitForwardBackward < 10) {
                    moveForward();
                }
            }
            else {
                if (limitRightLeft < 10) {
                    Left();
                }
            }
            break;
        case GLUT_KEY_RIGHT:
            if(pressed==0) {
                if (limitForwardBackward > -10){
                    moveBack();
                }
            }
            else {
                if (limitRightLeft > -10) {
                    Right();
                }
            }
            break;
        case GLUT_KEY_UP:
            if(limitUpDown<8)
            {
                Up();
            }
            break;
        case GLUT_KEY_DOWN:
            if(limitUpDown>-8){
                Down();}
            break;
    }

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {   
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
        case 'w':
            elbow2 = (elbow2 + 5) % 180;
            glutPostRedisplay();
            break;
        case 'W':
            elbow2 = (elbow2 - 5) % 180;
            glutPostRedisplay();
            break;

        // Right Leg
        case 'd':
            RightLeg = (RightLeg + 5) % 360;
            glutPostRedisplay();
            break;
        case 'D':
            RightLeg = (RightLeg - 5) % 360;
            glutPostRedisplay();
            break;
    
        case 'r':
            RightKnee = (RightKnee + 5) % 180;
            glutPostRedisplay();
            break;
        case 'R':
            RightKnee = (RightKnee - 5) % 180;
            glutPostRedisplay();
            break;

        // Left Leg
        case 'f':
            LeftLeg = (LeftLeg + 5) % 360;
            glutPostRedisplay();
            break;
        case 'F':
            LeftLeg = (LeftLeg - 5) % 360;
            glutPostRedisplay();
            break;
    
        case 't':
            LeftKnee = (LeftKnee + 5) % 180;
            glutPostRedisplay();
            break;
        case 'T':
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
   glutInitWindowSize(500, 600);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(specialKeys);
   glutMainLoop();
   return 0;
}