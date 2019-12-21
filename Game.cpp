//
// Created by zuozu on 2019/5/20.
//

#include <iostream>
#include "Game.h"

Game::Game(){

}

void Game::draw_buttons() {
    for(Button piece : blocks){
        piece.draw();
    }
}

Game::Game(GLdouble x, GLdouble y) {
    center_x = x/2;
    center_y = y/2;
    margin_y = unit*2+12;
    margin_x = center_x-2*unit;

//    position ={{center_x-unit*1.5 - margin, unit + board_margin},{center_x, 75 + board_margin},{center_x + 1.5 * unit, 75 + board_margin}, //row1
//              {center_x - 1.5 * unit - margin, unit * 3 + board_margin + margin}, {center_x, 2.5 * unit + board_margin + margin}, {center_x + 1.5 * unit, unit*3 + board_margin + margin}, //row2
//              {center_x - 1.5 * unit - margin, unit * 4.5 + board_margin + 2 * margin},{center_x - 0.5 * unit, 3.5*unit + board_margin + margin},{center_x + 0.5 * unit, unit * 3.5 + board_margin + margin},{center_x + 1.5 * unit, unit * 4.5 + board_margin + 2 * margin}}; //row3

    cao_cao = Button(Quad({0.5, 0.5, 0.2},{2*unit+margin_x, unit+margin_y},cao_length,cao_length),"1");
    guan_yu = Button(Quad({0.5, 0.5, 0.2},{2*unit+margin_x, 2.5*unit+margin_y},guan_width,guan_height),"4");
    zhang_fei = Button(Quad({0.5, 0.5, 0.2},{unit*0.5+margin_x, unit+margin_y},four_general_width,four_general_height),"0");
    zhao_yun = Button(Quad({0.5, 0.5, 0.2},{unit*3.5+margin_x, unit+margin_y},four_general_width,four_general_height),"2");
    huang_zhong = Button(Quad({0.5, 0.5, 0.2},{unit*3.5+margin_x, 3*unit+margin_y},four_general_width,four_general_height),"5");
    ma_chao = Button(Quad({0.5, 0.5, 0.2},{unit*0.5+margin_x, 3*unit+margin_y},four_general_width,four_general_height),"3");
    bing1 = Button(Quad({0.5, 0.5, 0.2},{unit*0.5+margin_x, 4.5*unit+margin_y},solider_length,solider_length),"6");
    bing2 = Button(Quad({0.5, 0.5, 0.2},{1.5*unit+margin_x, 3.5*unit+margin_y},solider_length,solider_length),"7");
    bing3 = Button(Quad({0.5, 0.5, 0.2},{2.5*unit+margin_x, 3.5*unit+margin_y},solider_length,solider_length),"8");
    bing4 = Button(Quad({0.5, 0.5, 0.2},{unit*3.5+margin_x, 4.5*unit+margin_y},solider_length,solider_length),"9");
    blocks={zhang_fei,cao_cao, zhao_yun,ma_chao,guan_yu,huang_zhong,bing1,bing2,bing3,bing4};
    empty1 = Quad({0.8,0.7,0.4}, {2*unit+margin_x, 5*unit+margin_y}, escape_width, escape_height);
    over_position.x = 2*unit+margin_x - solider_length - 2.5;
    over_position.y = 4*unit+margin_y;
    cout << over_position.x << " " <<over_position.y<<endl;
}

void Game::draw_board() {
    board = Quad({0.2,0.2,0.1},{center_x,center_y},unit*4+5,unit*5+5);
    board.draw();
    empty1.draw();

}

vector<Button> Game::get_blocks() {
    return blocks;
}


void Game::pressDown(int index) {
    blocks[index].pressDown();
}

void Game::release(int index) {
    blocks[index].release();
}

void Game::set_selected(int index) {
    switch (blocks[index].get_selected()) {
        case true:
            blocks[index].set_selected(false);
            break;
        case false:
            blocks[index].set_selected(true);
            break;
    }
}

void Game::move_buttons_right(int index) {
    blocks[index].moves("right");
}

void Game::move_buttons_left(int index) {
    blocks[index].moves("left");
}

void Game::move_buttons_down(int index) {
    blocks[index].moves("down");
}

void Game::move_buttons_up(int index) {
    blocks[index].moves("up");
}

Quad Game::get_board() {
    return board;
}

point Game::get_over_position() {
    return over_position;
}

void Game::draw_end_screen() {
    Quad a = Quad({0.5,0,0.5},{center_x,center_y},400,500);
    a.draw();
}

void Game::intro_background() {
}

void Game::gameover_background() {
    glClearColor((double)17/255, (double)17/255, (double)91/255, 1.0f);
    glBegin(GL_QUADS);
    glColor3f((double)17/255, (double)17/255, (double)91/255);
    glVertex2i(0, 0);
    glVertex2i(500, 0);
    glEnd();
}