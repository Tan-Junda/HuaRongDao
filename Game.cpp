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
    double margin=1;

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
}

void Game::draw_board() {
    Quad board = Quad({0.2,0.2,0.1},{center_x,center_y},unit*4,unit*5);
    board.draw();

}
