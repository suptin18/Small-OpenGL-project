#include <windows.h>
#include <GL/glut.h>

// Function to draw a cube with sharp edges
void drawRect(float x1, float y1, float z1, float x2, float y2, float z2, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);

    // Front Face
    glVertex3f(x1, y1, z1); glVertex3f(x2, y1, z1);
    glVertex3f(x2, y2, z1); glVertex3f(x1, y2, z1);

    // Back Face
    glVertex3f(x1, y1, z2); glVertex3f(x2, y1, z2);
    glVertex3f(x2, y2, z2); glVertex3f(x1, y2, z2);

    // Left Face
    glVertex3f(x1, y1, z1); glVertex3f(x1, y1, z2);
    glVertex3f(x1, y2, z2); glVertex3f(x1, y2, z1);

    // Right Face
    glVertex3f(x2, y1, z1); glVertex3f(x2, y1, z2);
    glVertex3f(x2, y2, z2); glVertex3f(x2, y2, z1);

    // Top Face
    glVertex3f(x1, y2, z1); glVertex3f(x2, y2, z1);
    glVertex3f(x2, y2, z2); glVertex3f(x1, y2, z2);

    // Bottom Face
    glVertex3f(x1, y1, z1); glVertex3f(x2, y1, z1);
    glVertex3f(x2, y1, z2); glVertex3f(x1, y1, z2);

    glEnd();

    // Edge outlines for precision
    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x1, y1, z1); glVertex3f(x2, y1, z1);
    glVertex3f(x2, y2, z1); glVertex3f(x1, y2, z1);
    glEnd();
}

// Function to draw the chair
void drawChair() {
    // Seat
    drawRect(-0.3, 0.1, -0.3, 0.3, 0.15, 0.3, 0.7, 0.4, 0.2);

    // Legs
    drawRect(-0.25, -0.3, -0.25, -0.2, 0.1, -0.2, 0.6, 0.3, 0.0);
    drawRect(0.2, -0.3, -0.25, 0.25, 0.1, -0.2, 0.6, 0.3, 0.0);
    drawRect(-0.25, -0.3, 0.2, -0.2, 0.1, 0.25, 0.6, 0.3, 0.0);
    drawRect(0.2, -0.3, 0.2, 0.25, 0.1, 0.25, 0.6, 0.3, 0.0);

    // Backrest vertical supports
    drawRect(-0.25, 0.15, 0.25, -0.2, 0.7, 0.3, 0.7, 0.4, 0.2);
    drawRect(0.2, 0.15, 0.25, 0.25, 0.7, 0.3, 0.7, 0.4, 0.2);

    // Backrest slats
    drawRect(-0.25, 0.6, 0.2, 0.25, 0.65, 0.25, 0.7, 0.4, 0.2);
    drawRect(-0.25, 0.5, 0.2, 0.25, 0.55, 0.25, 0.7, 0.4, 0.2);
    drawRect(-0.25, 0.4, 0.2, 0.25, 0.45, 0.25, 0.7, 0.4, 0.2);
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.5, 0.5, 1.5, 0, 0.2, 0, 0, 1, 0);
    drawChair();
    glFlush();
}

// Initialization
void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(45, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0, 0, 0, 1); // Black background
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Chair");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
