//
// Created by zuozu on 2019/5/20.
//

#include "Button.h"


#include <string>
Button::Button(Quad box, std::string label) {
    this->box = box;
    this->label = label;
    originalFill = box.getFill();
    hoverFill = {box.getRed()+0.5, box.getGreen()+0.5, box.getBlue()+0.5};
    pressFill = {box.getRed()-0.5, box.getGreen()-0.5, box.getBlue()-0.5};
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
        box.move(0,-10);
    if(direction == "down")
        box.move(0,10);
    if(direction == "left")
        box.move(-10,0);
    if(direction == "right")
        box.move(10,0);
}
/* Execute whatever the Button is supposed to do */
void Button::click(function<void()> callback) {
    callback();
}

Button::Button() {

}

point Button::getCenter() {
    return box.getCenter();
}
