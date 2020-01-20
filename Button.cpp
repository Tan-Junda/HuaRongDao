//
// Created by zuozu on 2019/5/20.
//

#include "Button.h"


#include <string>
Button::Button() {

}
Button::Button(Quad box, std::string label) {
    isSelected = false;
    this->box = box;
    this->label = label;
    originalFill = box.getFill();
    hoverFill = {box.getRed()+0.2, box.getGreen()+0.6, box.getBlue()+0.2};
    pressFill = {box.getRed()-0.3, box.getGreen()-0.1, box.getBlue()-0.1};
}

void Button::draw() {
    box.draw();
    glColor3f(0, 0, 0);
    glRasterPos2i(box.getCenterX()-(4*label.length()), box.getCenterY()+7);
    for (char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
}

/* Returns true if the coordinate is inside the box */
bool Button::isOverlapping(int x, int y) const {
    // TODO: Implement
    if (box.getLeftX() <= x && x<= box.getRightX()) {
        if(box.getTopY()<= y && y<= box.getBottomY()) {
            return true;
        }
    }
    return false; // Placeholder for compilation
}

/* Change color of the box when the user is hovering over it */
void Button::hover() {
    box.setColor(hoverFill);
}

/* Change color of the box when the user is clicking on it */
void Button::pressDown() {
    box.setColor(pressFill);
}

/* Change the color back when the user is not clicking/hovering */
void Button::release() {
    box.setColor(originalFill);
}
/* Move the position of button when press arrows*/
void Button::moves(std::string direction) {
    if(direction == "up")
        box.move(0,-75);
    if(direction == "down")
        box.move(0,75);
    if(direction == "left")
        box.move(-75,0);
    if(direction == "right")
        box.move(75,0);
}
/* Execute whatever the Button is supposed to do */
void Button::click(function<void()> callback) {
    callback();
}


void Button::set_selected(bool selected) {
    isSelected =  selected;
}

bool Button::get_selected() {
    return isSelected;
}

Quad Button::getQuad() {
    return box;
}

void Button::moves(std::string direction, int distance) {
    if(direction == "up")
        box.move(0,-distance);
    if(direction == "down")
        box.move(0,distance);
    if(direction == "left")
        box.move(-distance,0);
    if(direction == "right")
        box.move(distance,0);
}

