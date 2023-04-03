// gcc robot.c -lglut -lGL -lGLU -lm -o robot && ./robot

#include <GL/glut.h>
#include <math.h>

// Rotation
static GLfloat yRot = 0.0f;
static GLfloat xRot = 0.0f;

void cabeca(GLUquadric *);
void bracoEsquerdo(GLUquadric *);
void bracoDireito(GLUquadric *);
void pernas(GLUquadric *);
void olhos(GLUquadric *);
void rodinhas(GLUquadric *);
void corpo(GLUquadric *);

// Change viewing volume and viewport.  Called when window is resized
void ChangeSize(int w, int h)
    {
    GLfloat fAspect;

    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w/(GLfloat)h;

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Produce the perspective projection
    gluPerspective(35.0f, fAspect, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    }


// This function does any needed initialization on the rendering context.  Here it sets up and initializes the lighting for the scene.
void SetupRC(){

    // Light values and coordinates
    GLfloat  whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
    GLfloat  lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };

    glEnable(GL_DEPTH_TEST);    // Hidden surface removal
    glFrontFace(GL_CCW);        // Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE);     // Do not calculate inside

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Black blue background
    glClearColor(0.25f, 0.25f, 0.50f, 1.0f);

}

// Respond to arrow keys (rotate snowman)
void SpecialKeys(int key, int x, int y){

    if(key == GLUT_KEY_LEFT)
        yRot -= 5.0f;

    if(key == GLUT_KEY_RIGHT)
        yRot += 5.0f;

    if(key == GLUT_KEY_UP)
        xRot -= 5.0f;

    if(key == GLUT_KEY_DOWN)
        xRot += 5.0f;

    yRot = (GLfloat)((const int)yRot % 360);
    xRot = (GLfloat)((const int)xRot % 360);

    // Refresh the Window
    glutPostRedisplay();
}

// Called to draw scene
void RenderScene(void){



    GLUquadricObj *pObj;    // Quadric Object

    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Save the matrix state and do the rotations
    glPushMatrix();

    // Move object back and do in place rotation
    glTranslatef(0.0f, -1.0f, -5.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);

    glTranslatef(0.0f, 1.3f, 0.0f);

    // Draw something
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    // white
    glColor3f(0.0f, 0.0f, 0.0f);

    // Main Body

    glColor3f(0.0f, 0.0f, 0.0f);

    cabeca(pObj);
    olhos(pObj);
    corpo(pObj);
    pernas(pObj);
    rodinhas(pObj);
    bracoDireito(pObj);
    bracoEsquerdo(pObj);

    // Restore the matrix state
    glPopMatrix();

    // Buffer swap
    glutSwapBuffers();

}

int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Modeling with Quadrics");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    SetupRC();
    glutMainLoop();

    return 0;
}

void cabeca(GLUquadric *pObj) {
    glColor3f(0.196f, 0.804f, 0.196f);//Blue-Green
    glPushMatrix(); // save transform matrix state
        glTranslatef(0.0f, 1.0f, 0.0f);
        gluSphere(pObj, 0.12f, 26, 13);
    glPopMatrix();
}

void olhos(GLUquadric *pObj) {
    glPushMatrix(); // save transform matrix state
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(0.05f, 1.05f, 0.05f);
        gluSphere(pObj, 0.04f, 26, 13);
    glPopMatrix(); // restore transform matrix stat

    glPushMatrix(); // save transform matrix state
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(-0.05f, 1.05f, 0.05f);
        gluSphere(pObj, 0.04f, 26, 13);
    glPopMatrix(); // restore transform matrix stat
}

void corpo(GLUquadric *pObj) {
        glColor3f(0.196f, 0.804f, 0.196f);//Blue-Green
        glPushMatrix();
        glTranslatef(0.0f, 0.7f, 0.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        gluSphere(pObj, 0.30f, 26, 13);
        //gluCylinder(pObj, 0.30f, 0.25f, 0.8f, 4, 13);
    glPopMatrix();

    //barriga
    glPushMatrix();
        glTranslatef(0.0f, 0.53f, 0.0f);
        glRotatef(90, 1.0f, 0.0f, 0.0f);
        gluCylinder(pObj, 0.25f, 0.0f,0.8f, 30, 13);
    glPopMatrix();
}

void pernas(GLUquadric *pObj) {
    glColor3f(0.196f, 0.804f, 0.196f);//Dark grey
    glPushMatrix(); // save transform matrix state
        glTranslatef(0.0f, -0.1f, 0.0f);
        gluSphere(pObj, 0.20f, 26, 13);
    glPopMatrix();

    glColor3f(0.663f, 0.663f, 0.663f);
    glPushMatrix(); // save transform matrix state
        glTranslatef(0.4f, -0.1f, 0.0f);
        gluSphere(pObj, 0.1f, 26, 13);
        glTranslatef(0.0f, 0.05f, 0.0f);
        glRotatef(90, 1, 0, 0);
        gluCylinder(pObj, 0.05f, 0.05f,0.6f, 30, 13);
        glTranslatef(0.0f, 0.0f, 0.6f);
        gluSphere(pObj, 0.12f, 26, 13);
        gluCylinder(pObj, 0.06f, 0.06f,0.7f, 30, 13);
    glPopMatrix();


    glPushMatrix(); // save transform matrix state
        glTranslatef(-0.4f, -0.1f, 0.0f);
        gluSphere(pObj, 0.1f, 26, 13);
        glTranslatef(0.0f, 0.05f, 0.0f);
        glRotatef(90, 1, 0, 0);
        gluCylinder(pObj, 0.05f, 0.05f,0.6f, 30, 13);
        glTranslatef(0.0f, 0.0f, 0.6f);
        gluSphere(pObj, 0.12f, 26, 13);
        gluCylinder(pObj, 0.06f, 0.06f,0.7f, 30, 13);
    glPopMatrix();

    glPushMatrix(); // save transform matrix state
        glTranslatef(0.0f, -0.1f, -0.0f);
        glRotatef(90, 0, 1, 0);
        gluCylinder(pObj, 0.05f, 0.05f, 0.4f, 30, 13);
    glPopMatrix();

    glPushMatrix(); // save transform matrix state
        glTranslatef(0.0f, -0.1f, -0.0f);
        glRotatef(90, 0, -1, 0);
        gluCylinder(pObj, 0.05f, 0.05f, 0.4f, 30, 13);
    glPopMatrix();
}

void rodinhas(GLUquadric *pObj) {
    glColor3f(0.196f, 0.804f, 0.196f);//Dark grey
    glPushMatrix();
        glTranslatef(-0.55f, -1.5f, 0.0f);
        glRotatef(90, 0, 1, 0);
        gluCylinder(pObj, 0.2f, 0.2f, 0.3f, 50, 13);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.55, -1.5, 0);
        glRotatef(90, 0.0, 1.0, 0.0);
        gluDisk(pObj, 0.0, 0.21, 20, 20); 
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.55, -1.5, 0);
        glRotatef(90, 0.0, -1.0, 0.0);
        gluDisk(pObj, 0.0, 0.21, 20, 20); 
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.25, -1.5, 0);
        glRotatef(90, 0.0, 1.0, 0.0);
        gluDisk(pObj, 0.0, 0.21, 20, 20); 
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.25, -1.5, 0);
        glRotatef(90, 0.0, -1.0, 0.0);
        gluDisk(pObj, 0.0, 0.21, 20, 20); 
    glPopMatrix();

    glPushMatrix();
         glTranslatef(0.25f, -1.5f, 0.0f);
         glRotatef(90, 0, 1, 0);
         gluCylinder(pObj, 0.2f, 0.2f, 0.3f, 50, 13);
     glPopMatrix();
}

void bracoEsquerdo(GLUquadric *pObj) {
    glColor3f(0.663f, 0.663f, 0.663f);
    glPushMatrix(); // save transform matrix state
        glTranslatef(0.3f, 0.65f, 0.0f);
        gluSphere(pObj, 0.07f, 26, 13);
        glRotatef(90, 1, 0, 1);
       gluCylinder(pObj, 0.04f, 0.04f, 0.3f, 26, 13);
       gluSphere(pObj, 0.07f, 26, 13);
       glTranslatef(0.0f, 0.0f, 0.3f);
       gluCylinder(pObj, 0.04f, 0.04f, 0.3f, 26, 13);
       gluSphere(pObj, 0.07f, 26, 13);
       glTranslatef(0.0f, 0.0f, 0.55f);
       gluSphere(pObj, 0.3f, 26, 13);
       glTranslatef(0.0f, 0.0f, 0.30f);
       gluCylinder(pObj, 0.04f, 0.0f, 0.3f, 26, 13);
    //    glTranslatef(0.1f, -0.25f, -0.3f);
    //    glRotatef(100, 1, 0, 0);
    //    gluCylinder(pObj, 0.04f, 0.0f, 0.3f, 26, 13);
    //    glTranslatef(0.1f, -0.25f, -0.3f);
    //    glRotatef(90, 0, 0, 1);
    //    gluCylinder(pObj, 0.04f, 0.0f, 0.3f, 26, 13);  
    //    glTranslatef(0.1f, -0.05f, -0.4f);
    //    glRotatef(120, 1, 1, 0);
    //    gluCylinder(pObj, 0.04f, 0.0f, 0.3f, 26, 13);
    //    glTranslatef(-0.0f, 0.15f, -0.2f);
    //    glRotatef(250, 1, 1, 1);
    //    gluCylinder(pObj, 0.04f, 0.0f, 0.3f, 26, 13);
    //    gluCylinder(pObj, 0.04f, 0.0f, 0.3f, 26, 13);
    //    glTranslatef(-0.1f, -0.1f, -0.4f);
    //    glRotatef(180, 1, 0, 0);
    //    gluCylinder(pObj, 0.04f, 0.0f, 0.3f, 26, 13);

    glPopMatrix();

}

void bracoDireito(GLUquadric *pObj) {
    glColor3f(0.663f, 0.663f, 0.663f);
    glPushMatrix(); // save transform matrix state
        glTranslatef(-0.3f, 0.65f, 0.0f);
        gluSphere(pObj, 0.07f, 26, 13);
        glRotatef(90, 1, 0, -1);
        gluCylinder(pObj, 0.04f, 0.04f, 0.3f, 26, 13);
       gluSphere(pObj, 0.07f, 26, 13);
       glTranslatef(0.0f, 0.0f, 0.3f);
       gluCylinder(pObj, 0.04f, 0.04f, 0.3f, 26, 13);
       gluSphere(pObj, 0.07f, 26, 13);
       glTranslatef(0.0f, 0.0f, 0.3f);
       gluCylinder(pObj, 0.08f, 0.08f, 0.2f, 26, 13);
       glTranslatef(0.0f, 0.0f, 0.2f);
       gluCylinder(pObj, 0.02f, 0.02f, 0.3f, 26, 13);
    glPopMatrix(); // restore transform matrix state
}