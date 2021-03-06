//
// Created by zuozu on 2019/5/20.
//
#include "graphic.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

GLdouble width, height;
int wd;
Game game;
int times=0;
bool click=false;
int last_x;
int last_y;
int index1;
int changes = 0;
bool ending_move = false;
bool new_game = false;
int index2=0;
int t = 0;
enum screen {
    Start,
    Play,
    End
};
bool sound = true;

void play_sound1();
void play_sound2();
void play_sound3();

screen window;
void init() {
    window = Start;
    click = false;
    width = 1265;
    height = 700;
}

void display_game(){

    if (window == Start) {
        if(times == 0 || new_game) {
            game = Game(width, height);
            times++;
        }
        game.draw_board();
        game.intro_background();
    }

    if (window == End ) {
        game.draw_end_screen();
        game.gameover_background();
    }

    if (window == Play ) {
        game.draw_board();
        game.draw_buttons();
    }

}
// Initialize OpenGL Graphics
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
}

/* Handler for window-repaint event. Call back when the windwo first appears and whenever
 * the window needs to be re-painted.*/
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

    display_game();

    glFlush(); // Render now
}

void kbd(unsigned char key, int x, int y) {
    if  (key == 27){
        glutDestroyWindow(wd);
        exit(0);
    }
    if (key == 'r') {
        window = Start;
        new_game = true;
        ending_move = false;
    }
    if (key == 'e') {
        window = End;
    }
    if (key == 32) {
        window = Play;
        if (sound)
            play_sound2();
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
    click = true;
    last_x = x;
    last_y = y;
    glutPostRedisplay();
    index1 = 0;
    for (Button &piece : game.get_blocks()) {
        if (state == 0) {
            if (piece.isOverlapping(x, y)) {
                game.pressDown(index1);
                if (sound)
                    play_sound1();
            }
        }
        if (state == 1){
            game.release(index1);
        }
        index1++;
    }
}

void timer(int dummy) {
    if (ending_move) {
        game.move_buttons_down(1, 5);
        if (game.get_blocks()[1].getQuad().getCenterY() == game.get_over_position().y + 155 ) {
            ending_move = false;
            if (sound)
                play_sound3();
            window = End;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, timer, dummy);
}

void play_sound1(){
#ifdef  _WIN32
    Beep(440, 125);
#endif

#ifdef __APPLE__
    //system("afplay /System/Library/Sounds/Pop.aiff");
#endif

#ifdef __linux__
//    system("mpg123 /home/youyou/game.mp3");
#endif
}

void play_sound2(){
#ifdef  _WIN32
    Beep(261.6, 125);
    Beep(293.6, 125);
    Beep(329.6, 125);
    Beep(392.6, 125);
    Beep(523.2, 250);
#endif

#ifdef __APPLE__
    //system("afplay /System/Library/Sounds/glass.aiff");
#endif

#ifdef __linux
    //system("mpg123 /home/youyou/Music/1.m4a");
#endif
}

void play_sound3(){
#ifdef  _WIN32
    Beep(261.6, 250);
    Beep(261.6, 125);
    Beep(293.6, 125);
    Beep(329.6, 250);
    Beep(392.6, 250);
    Beep(523.2, 500);
#endif

#ifdef __APPLE__
    //system("afplay /System/Library/Sounds/glass.aiff");
#endif

#ifdef __linux
    //system("mpg123 /home/youyou/main.mp3");
#endif
}


void move_button(int x, int y) {
    if(click) {
        index2 = 0;
        changes = 0;
        for (Button &piece : game.get_blocks()) {
            if (piece.isOverlapping(last_x, last_y)) {
                double delta_x, delta_y;
                delta_x = x - last_x;
                delta_y = y - last_y;
                if (delta_x < 0)
                    delta_x = -delta_x;

                if (delta_y < 0)
                    delta_y = -delta_y;

                if (delta_x == delta_y) {
                    changes = -1;
                }
                if (delta_y > delta_x && last_y < y) { //down
                    if (game.get_board().getBottomY() - 75 > game.get_blocks()[index2].getQuad().getBottomY()) {
                        bool move = true;
                        for (int i = 0; i < 10; i++) {
                            if (game.get_blocks()[index2].getQuad().getBottomY() ==
                                game.get_blocks()[i].getQuad().getTopY() - 5 &&
                                ((game.get_blocks()[i].getQuad().getLeftX() <
                                  game.get_blocks()[index2].getQuad().getCenterX() &&
                                  game.get_blocks()[index2].getQuad().getCenterX() <
                                  game.get_blocks()[i].getQuad().getRightX()) ||
                                 (game.get_blocks()[index2].getQuad().getLeftX() ==
                                  game.get_blocks()[i].getQuad().getLeftX() &&
                                  game.get_blocks()[index2].getQuad().getRightX() >
                                  game.get_blocks()[i].getQuad().getRightX()) ||
                                 (game.get_blocks()[index2].getQuad().getRightX() ==
                                  game.get_blocks()[i].getQuad().getRightX() &&
                                  game.get_blocks()[index2].getQuad().getLeftX() <
                                  game.get_blocks()[i].getQuad().getLeftX()))) {
                                move = false;
                            }
                        }
                        if (move) {
                            game.move_buttons_down(index2);
                            changes = 1;
                            click = false;
                        }
                    }
                } else if (delta_y > delta_x && last_y > y) { //up
                    if (game.get_board().getTopY() + 75 < game.get_blocks()[index2].getQuad().getTopY()) {
                        bool move = true;
                        for (int i = 0; i < 10; i++) {
                            if (game.get_blocks()[index2].getQuad().getTopY() ==
                                game.get_blocks()[i].getQuad().getBottomY() + 5 &&
                                ((game.get_blocks()[i].getQuad().getLeftX() <
                                  game.get_blocks()[index2].getQuad().getCenterX() &&
                                  game.get_blocks()[index2].getQuad().getCenterX() <
                                  game.get_blocks()[i].getQuad().getRightX()) ||
                                 (game.get_blocks()[index2].getQuad().getLeftX() ==
                                  game.get_blocks()[i].getQuad().getLeftX() &&
                                  game.get_blocks()[index2].getQuad().getRightX() >
                                  game.get_blocks()[i].getQuad().getRightX()) ||
                                 (game.get_blocks()[index2].getQuad().getRightX() ==
                                  game.get_blocks()[i].getQuad().getRightX() &&
                                  game.get_blocks()[index2].getQuad().getLeftX() <
                                  game.get_blocks()[i].getQuad().getLeftX()))) {
                                move = false;
                            }
                        }
                        if (move) {
                            game.move_buttons_up(index2);
                            changes = 2;
                            click = false;
                        }
                    }
                } else if (delta_x > delta_y && last_x < x) { //right
                    if (game.get_board().getRightX() - 75 > game.get_blocks()[index2].getQuad().getRightX()) {
                        bool move = true;
                        for (int i = 0; i < 10; i++) {
                            if (game.get_blocks()[index2].getQuad().getRightX() ==
                                game.get_blocks()[i].getQuad().getLeftX() - 5 &&
                                ((game.get_blocks()[i].getQuad().getTopY() <
                                  game.get_blocks()[index2].getQuad().getCenterY() &&
                                  game.get_blocks()[index2].getQuad().getCenterY() <
                                  game.get_blocks()[i].getQuad().getBottomY()) ||

                                 // same Top
                                 (game.get_blocks()[index2].getQuad().getTopY() ==
                                  game.get_blocks()[i].getQuad().getTopY() &&
                                  game.get_blocks()[index2].getQuad().getBottomY() >
                                  game.get_blocks()[i].getQuad().getBottomY()) ||

                                 // same Bottom
                                 (game.get_blocks()[index2].getQuad().getBottomY() ==
                                  game.get_blocks()[i].getQuad().getBottomY() &&
                                  game.get_blocks()[index2].getQuad().getTopY() <
                                  game.get_blocks()[i].getQuad().getTopY()) ||

                                 // is moved in the Bottom
                                 (game.get_blocks()[index2].getQuad().getBottomY() + 2.5 ==
                                  game.get_blocks()[i].getQuad().getCenterY() &&
                                  game.get_blocks()[index2].getQuad().getBottomY() <
                                  game.get_blocks()[i].getQuad().getBottomY()) ||

                                 // is moved in the Top
                                 (game.get_blocks()[index2].getQuad().getTopY() - 2.5 ==
                                  game.get_blocks()[i].getQuad().getCenterY() &&
                                  game.get_blocks()[index2].getQuad().getTopY() >
                                  game.get_blocks()[i].getQuad().getTopY()))) {
                                move = false;
                            }
                        }
                        if (move) {
                            game.move_buttons_right(index2);
                            changes = 3;
                            click = false;
                        }
                    }
                } else if (delta_x > delta_y && last_x > x) { //left
                    if (game.get_board().getLeftX() + 75 < game.get_blocks()[index2].getQuad().getLeftX()) {
                        bool move = true;

                        for (int i = 0; i < 10; i++) {
                            if (game.get_blocks()[index2].getQuad().getLeftX() ==
                                game.get_blocks()[i].getQuad().getRightX() + 5 &&
                                ((game.get_blocks()[i].getQuad().getTopY() <
                                  game.get_blocks()[index2].getQuad().getCenterY() &&
                                  game.get_blocks()[index2].getQuad().getCenterY() <
                                  game.get_blocks()[i].getQuad().getBottomY()) ||

                                 // same top
                                 (game.get_blocks()[index2].getQuad().getTopY() ==
                                  game.get_blocks()[i].getQuad().getTopY() &&
                                  game.get_blocks()[index2].getQuad().getBottomY() >
                                  game.get_blocks()[i].getQuad().getBottomY()) ||

                                 // same bottom
                                 (game.get_blocks()[index2].getQuad().getBottomY() ==
                                  game.get_blocks()[i].getQuad().getBottomY() &&
                                  game.get_blocks()[index2].getQuad().getTopY() <
                                  game.get_blocks()[i].getQuad().getTopY()) ||

                                 // same middle from top
                                 (game.get_blocks()[index2].getQuad().getTopY() <
                                  game.get_blocks()[i].getQuad().getBottomY() &&
                                  game.get_blocks()[index2].getQuad().getTopY() - 2.5 ==
                                  game.get_blocks()[i].getQuad().getCenterY()) ||

                                 // same middle from bottom
                                 (game.get_blocks()[index2].getQuad().getCenterY() + 2.5 ==
                                  game.get_blocks()[i].getQuad().getTopY() &&
                                  game.get_blocks()[index2].getQuad().getBottomY() >
                                  game.get_blocks()[i].getQuad().getTopY()))) {
                                move = false;
                            }
                        }
                        if (move) {
                            game.move_buttons_left(index2);
                            changes = 4;
                            click = false;
                        }
                    }
                }
//                click = false;
            }
            index2++;
        }
        //test for detecting end of the game.
        if (game.get_over_position().y == game.get_blocks()[1].getQuad().getCenterY()) {
            if (game.get_over_position().x == game.get_blocks()[1].getQuad().getCenterX()) {
                ending_move = true;
            }
        }
    }
}

void motion(int x, int y){
    move_button(x, y);
    glutPostRedisplay();
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

    glutMotionFunc(motion);
    // Enter the event-processing loop
    glutMainLoop();

    return 0;
}


