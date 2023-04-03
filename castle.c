// gcc castle.c -lglut -lGL -lGLU -lm -o castle && ./castle

#include <GL/glut.h>
#include <math.h>

// Rotation
static GLfloat yRot = 0.0f;
static GLfloat xRot = 0.0f;

void torres(GLUquadric *);
void muros(GLUquadric *);

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
    gluPerspective(90.0f, fAspect, 1.0, 40.0);

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

void MakeSquare(float width, float height, float depth) {
    glBegin(GL_QUADS);
    glVertex3f(-width / 2.0f, -height / 2.0f, depth / 2.0f);
    glVertex3f(width / 2.0f, -height / 2.0f, depth / 2.0f);
    glVertex3f(width / 2.0f, height / 2.0f, depth / 2.0f);
    glVertex3f(-width / 2.0f, height / 2.0f, depth / 2.0f);
    glEnd();

    // Draw the back face
    glBegin(GL_QUADS);
    glVertex3f(width / 2.0f, -height / 2.0f, -depth / 2.0f);
    glVertex3f(-width / 2.0f, -height / 2.0f, -depth / 2.0f);
    glVertex3f(-width / 2.0f, height / 2.0f, -depth / 2.0f);
    glVertex3f(width / 2.0f, height / 2.0f, -depth / 2.0f);
    glEnd();

    // Draw the left face
    glBegin(GL_QUADS);
    glVertex3f(-width / 2.0f, -height / 2.0f, -depth / 2.0f);
    glVertex3f(-width / 2.0f, -height / 2.0f, depth / 2.0f);
    glVertex3f(-width / 2.0f, height / 2.0f, depth / 2.0f);
    glVertex3f(-width / 2.0f, height / 2.0f, -depth / 2.0f);
    glEnd();

    // Draw the right face
    glBegin(GL_QUADS);
    glVertex3f(width / 2.0f, -height / 2.0f, depth / 2.0f);
    glVertex3f(width / 2.0f, -height / 2.0f, -depth / 2.0f);
    glVertex3f(width / 2.0f, height / 2.0f, -depth / 2.0f);
    glVertex3f(width / 2.0f, height / 2.0f, depth / 2.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-width / 2.0f, height / 2.0f, -depth / 2.0f);
    glVertex3f(width / 2.0f, height / 2.0f, -depth / 2.0f);
    glVertex3f(width / 2.0f, height / 2.0f, depth / 2.0f);
    glVertex3f(-width / 2.0f, height / 2.0f, depth / 2.0f);
    glEnd();    
    glutSolidCube(1.0f);
}

void MakeTriangle(float width, float height, float depth) {
    glBegin(GL_TRIANGLES);
    glVertex3f(-width / 2.0f, height / 2.0f, -depth / 2.0f);
    glVertex3f(0.0f, height, 0.0f);
    glVertex3f(width / 2.0f, height / 2.0f, -depth / 2.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(width / 2.0f, height / 2.0f, -depth / 2.0f);
    glVertex3f(0.0f, height, 0.0f);
    glVertex3f(width / 2.0f, height / 2.0f, depth / 2.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(width / 2.0f, height / 2.0f, depth / 2.0f);
    glVertex3f(0.0f, height, 0.0f);
    glVertex3f(-width / 2.0f, height / 2.0f, depth / 2.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(-width / 2.0f, height / 2.0f, depth / 2.0f);
    glVertex3f(0.0f, height, 0.0f);
    glVertex3f(-width / 2.0f, height / 2.0f, -depth / 2.0f);
    glEnd();

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

    glTranslatef(0.0f, 0.5f, 0.0f);

    // Draw something
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    // white
    glColor3f(1.0f, 1.0f, 1.0f);


    torres(pObj);
    muros(pObj);
    base(pObj);
    


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


void torres(GLUquadric *pObj) {
    float posX = 2.0f;
    float posY = 0.5f;
    float posZ = 2.0f;
    float raio = 0.5f;
    float altura = 1.5f;
    float raioCone = 0.6f;

    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
        glTranslatef(-posX, posY, -posZ);
        glRotatef(90, 1, 0, 0);
        gluCylinder(pObj, raio, raio, altura, 26, 13);
        glRotatef(180, 1, 0, 0);
        glutSolidCone(raioCone, 1.0f, 26, 13);
    glPopMatrix();

    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
        glTranslatef(posX, posY, -posZ);
        glRotatef(90, 1, 0, 0);
        gluCylinder(pObj, raio, raio, altura, 26, 13);
        glRotatef(180, 1, 0, 0);
        glutSolidCone(raioCone, 1.0f, 26, 13);
    glPopMatrix();

    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
        glTranslatef(posX, posY, posZ);
        glRotatef(90, 1, 0, 0);
        gluCylinder(pObj, raio, raio, altura, 26, 13);
        glRotatef(180, 1, 0, 0);
        glutSolidCone(raioCone, 1.0f, 26, 13);
    glPopMatrix();

    glColor3f(1.0, 0.0, 0.0);
    glPushMatrix();
        glTranslatef(-posX, posY, posZ);
        glRotatef(90, 1, 0, 0);
        gluCylinder(pObj, raio, raio, altura, 26, 13);
        glRotatef(180, 1, 0, 0);
        glutSolidCone(raioCone, 1.0f, 26, 13);
    glPopMatrix();
}

void muros(GLUquadric *pObj) {
    glPushMatrix();
        glColor3f(0.6f, 0.6f, 0.6f);
        glTranslatef(2.0f, -0.5f, 0.0f);
        glScalef(0.3f, 1.0f, 3.0f);
        glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.6f, 0.6f, 0.6f);
        glTranslatef(-2.0f, -0.5f, 0.0f);
        glScalef(0.3f, 1.0f, 3.0f);
        glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.6f, 0.6f, 0.6f);
        glTranslatef(0.0f, -0.5f, 2.0f);
        glScalef(3.0f, 1.0f, 0.3f);
        glutSolidCube(1.0f);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.6f, 0.6f, 0.6f);
        glTranslatef(0.0f, -0.5f, -2.0f);
        glScalef(3.0f, 1.0f, 0.3f);
        glutSolidCube(1.0f);
    glPopMatrix();
} 