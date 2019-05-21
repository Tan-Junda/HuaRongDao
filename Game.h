//
// Created by zuozu on 2019/5/20.
//

#ifndef HUARONGDAO_GAME_H
#define HUARONGDAO_GAME_H
#include <vector>
#include "Button.h"
class Game {
    double center_x = 0;
    double center_y = 0;
    double unit = 75;
    double cao_length = unit*2-5;
    double four_general_height = unit*2-5;
    double four_general_width = unit-5;
    double guan_height = unit-5;
    double guan_width = unit*2-5;
    double solider_length = unit-5;

    double margin_x =0;
    double margin_y =0;
    vector<point> position;
    Button cao_cao =Button(), guan_yu =Button(), zhang_fei=Button(), zhao_yun=Button(), huang_zhong=Button(), ma_chao=Button(), bing1=Button(), bing2=Button(), bing3=Button(), bing4=Button();
    vector<Button> blocks;

//    Button cao_cao = Button(Quad({0.5, 0.5, 0.2},{position[1][0],position[1][1]},cao_length,cao_length),"Cao, Cao");
//    Button guan_yu = Button(Quad({0.5, 0.5, 0.2},{position[4][0],position[4][1]},guan_width,guan_height),"Guan, Yu");
//    Button zhang_fei = Button(Quad({0.5, 0.5, 0.2},{position[0][0],position[0][1]},four_general_width,four_general_height),"Zhang, Fei");
//    Button zhao_yun = Button(Quad({0.5, 0.5, 0.2},{position[2][0],position[2][1]},four_general_width,four_general_height),"Zhao, Yun");
//    Button huang_zhong = Button(Quad({0.5, 0.5, 0.2},{position[5][0],position[5][1]},four_general_width,four_general_height),"Huang, Zhong");
//    Button ma_chao = Button(Quad({0.5, 0.5, 0.2},{position[3][0],position[3][1]},four_general_width,four_general_height),"Ma, Chao");
//    Button bing1 = Button(Quad({0.5, 0.5, 0.2},{position[6][0],position[6][1]},solider_length,solider_length),"Bing1");
//    Button bing2 = Button(Quad({0.5, 0.5, 0.2},{position[7][0],position[7][1]},solider_length,solider_length),"Bing2");
//    Button bing3 = Button(Quad({0.5, 0.5, 0.2},{position[8][0],position[8][1]},solider_length,solider_length),"Bing3");
//    Button bing4 = Button(Quad({0.5, 0.5, 0.2},{position[9][0],position[9][1]},solider_length,solider_length),"Bing4");


public:
    Game();
    Game(GLdouble width, GLdouble height);
    void draw_buttons();
    void draw_board();


};


#endif //HUARONGDAO_GAME_H
