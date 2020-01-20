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
    double
    cao_length = unit*2-5;
    double four_general_height = unit*2-5;
    double four_general_width = unit-5;
    double guan_height = unit-5;
    double guan_width = unit*2-5;
    double solider_length = unit-5;
    double escape_width = unit*2-5;
    double escape_height = unit / 15.0;
    double margin_x =0;
    double margin_y =0;
    point over_position;
    vector<point> position;
    Button cao_cao =Button(), guan_yu =Button(), zhang_fei=Button(), zhao_yun=Button(), huang_zhong=Button(), ma_chao=Button(), bing1=Button(), bing2=Button(), bing3=Button(), bing4=Button();
    Quad empty1 = Quad();
    vector<Button> blocks;
    Quad board;

public:
    Game();
    Game(GLdouble width, GLdouble height);
    void draw_buttons();
    void draw_board();
    vector<Button> get_blocks();
    void move_buttons_right(int index);
    void move_buttons_left(int index);
    void move_buttons_down(int index);
    void move_buttons_down(int index, int distance);
    void move_buttons_up(int index);
    void pressDown(int index);
    void release(int index);
    void set_selected(int index);
    void draw_end_screen();
    Quad get_board();
    point get_over_position();

    // global prototype for background of the game
    void intro_background();
    void gameover_background();
};


#endif //HUARONGDAO_GAME_H
