#include "funk.h"

void init()
{
    // For displaying the window color
    glClearColor(0, 0, 0, 1);
    // Choosing the type of projection
    glMatrixMode(GL_PROJECTION);
    // for setting the transformation which here is 2D
    gluOrtho2D(0, 600, 0, 600);
}

void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(120, timer_callback, 0);
}

int main(int agrc, char **argv)
{
    srand(time(NULL));
    // Initialize GLUT
    glutInit(&agrc, argv);
    cout << 1 << "\n";
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    cout << 2 << "\n";
    // Set top - left display window position.
    glutInitWindowPosition(150, 150);
    cout << 3 << "\n";
    // Set display window width and height
    glutInitWindowSize(600, 600);
    cout << 4 << "\n";
    // Create display window with the given title
    glutCreateWindow("SNAKE");
    cout << 5 << "\n";
    // Execute initialization procedure

    // Send graphics to display window
    glutDisplayFunc(SNAKE::buildSnake);

    //glutDisplayFunc(mapBUILD[GAME_OVER]);

    glutSpecialFunc(SNAKE::specialkey);

    glutTimerFunc(1, timer_callback, 2);
    init();
    // Display everything and wait.
    glutMainLoop();
}