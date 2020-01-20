//
// Created by zuozu on 2019/5/20.
//

#ifndef HUARONGDAO_BUTTON_H
#define HUARONGDAO_BUTTON_H

#include "Quad.h"
#include "graphic.h"
#include <string>
#include <functional>

using namespace std;

class Button {
private:
    /* Assume Quad includes color, center, width, height */
    Quad box;
    std::string label;
    color originalFill, hoverFill, pressFill;
    bool isSelected;

public:
    Button();
    Button(Quad box, std::string label);

    /* Uses OpenGL to draw the box with the label on top */
    virtual void draw();


    /* Returns true if the coordinate is inside the box */
    bool isOverlapping(int x, int y) const;

    /* Change color of the box when the user is hovering over it */
    void hover();

    /* Change color of the box when the user is clicking on it */
    void pressDown();

    /* Change the color back when the user is not clicking/hovering */
    void release();

    /* Moving button with press arrows*/
    void moves(std::string direction);

    void moves(std::string direction, int distance);

    /* void every button is not overlapping*/
    //void isButtonOverlapping(int x, int y) const;

    /* Execute whatever the Button is supposed to do */
    virtual void click(std::function<void()> callback);

    void set_selected(bool selected);
    bool get_selected();

    Quad getQuad();
};



#endif //HUARONGDAO_BUTTON_H
