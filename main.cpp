#include <GL/glut.h>
#include <vector>

std::vector<std::pair<int, int>> points;
bool isDrawing = false;
void drawPoint(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    for (const auto& point : points) {
        drawPoint(point.first, point.second);
    }

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            points.emplace_back(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
            isDrawing = true;
        } else if (state == GLUT_UP) {
            isDrawing = false;
            glutPostRedisplay();
        }
    }
}

void motion(int x, int y) {
    if (isDrawing) {
        points.emplace_back(x, glutGet(GLUT_WINDOW_HEIGHT) - y);
        glutPostRedisplay();
    }
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Oyu iin mouse aar zurah");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    init();
    glutMainLoop();
    return 0;
}
