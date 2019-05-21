//
// Created by zuozu on 2019/5/20.
//

#include "graphic.h"
#include "Game.h"
#include <iostream>
#include <vector>
using namespace std;

GLdouble width, height;
int wd;
void init() {
    width = 1265;
    height = 700;
    glClearColor(0.5f,0.5f,0.5f,0.0f);
    glColor3f(0.9,0.5,0.4);
    glBegin(GL_QUADS);
    glVertex2i(20,20);
    glVertex2i(20,50);
    glVertex2i(100,50);
    glVertex2i(100,20);
    glEnd();
    glFlush();
}

// Initialize OpenGL Graphics
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
}

/* Handler for window-repaint event. Call back when the windwo first appears and whenever
 * the windwo needs to be re-painted.*/
void display(){
    // tell OpenGl to use the whole window for drawing
    glViewport(0,0,width,height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.1f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     *  Draw here
     */
    Game game = Game(width,height);
    game.draw_board();
    game.draw_buttons();
    glFlush(); // Render now
}

void kbd(unsigned char key, int x, int y) {
    if  (key == 27){
        glutDestroyWindow(wd);
        exit(0);
    }
    glutPostRedisplay();
}
void kbdS(int key, int x, int y){
    switch(key){
        case GLUT_KEY_DOWN:
            break;
        case GLUT_KEY_LEFT:
            break;
        case GLUT_KEY_RIGHT:
            break;
        case GLUT_KEY_UP:
            break;
    }
}

void cursor(int x, int y){
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if(state == 0) {

    }
    if(state ==1){

    }
    glutPostRedisplay();
}

void timer(int dummy) {
    glutPostRedisplay();
    glutTimerFunc(50, timer, dummy);
}

/* Main function: GLUT runs as a consolr application starting at main() */
int main(int argc, char** argv){
    init();
    glutInit(&argc, argv);
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(0,0); //upper-left corner

    /* create window and store the handle to it*/
    wd = glutCreateWindow("HuaRongDao");  /* title */

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    // Our own OPenGL initialization
    initGL();

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}



