#include <GL/glut.h>
#include <stdlib.h>

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

void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}


void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);

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
   glutInitWindowSize(500, 600);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}