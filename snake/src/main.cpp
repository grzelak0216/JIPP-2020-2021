#include <funk.h>

int GAME_OVER = -2;
int SCORE = 0;

int foodx, foody;
int food = 1;

int length = 5;

int posSnake[300][2] = {{11, 14}, {11, 13}, {11, 12}, {11, 11}, {11, 10}, {11, 9}};
int xr = 0, yr = 0;

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
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set top - left display window position.
    glutInitWindowPosition(150, 150);
    // Set display window width and height
    glutInitWindowSize(600, 600);
    // Create display window with the given title
    glutCreateWindow("SNAKE-0.7");
    // Execute initialization procedure

    // Send graphics to display window
    glutDisplayFunc(bildSnake);

    //	if(GAME_OVER == 0 || GAME_OVER == -1)
    //	{
    //		glutSpecialFunc(specialkey1);
    //	}
    //	else
    //	{
    //		glutSpecialFunc(specialkey2);
    //	}

    glutSpecialFunc(specialkey);

    glutTimerFunc(1, timer_callback, 2);
    init();
    // Display everything and wait.
    glutMainLoop();
}