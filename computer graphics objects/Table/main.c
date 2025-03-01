#include <windows.h>
#include <GL/glut.h>

void rectangle(float x1, float y1, float z1, float x2, float y2, float z2,
               float x3, float y3, float z3, float x4, float y4, float z4,
               float r, float g, float b) {
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glVertex3f(x4, y4, z4);
    glEnd();
}

void drawTable() {
    // Table Top
    rectangle(-20, 10, -10, 20, 10, -10, 20, 10, 10, -20, 10, 10, 0.7, 0.5, 0.3);

    // Table Legs
    rectangle(-18, -10, -8, -16, -10, -8, -16, 10, -8, -18, 10, -8, 0.6, 0.4, 0.2);
    rectangle(16, -10, -8, 18, -10, -8, 18, 10, -8, 16, 10, -8, 0.6, 0.4, 0.2);
    rectangle(-18, -10, 8, -16, -10, 8, -16, 10, 8, -18, 10, 8, 0.6, 0.4, 0.2);
    rectangle(16, -10, 8, 18, -10, 8, 18, 10, 8, 16, 10, 8, 0.6, 0.4, 0.2);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -50); // Adjust position for perspective
    drawTable();
    glutSwapBuffers();
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Wooden Table");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
