//
// Created by zuozu on 2019/5/20.
//

#include "Quad.h"
#include <iostream>
#include "Button.h"
#include "graphic.h"
using namespace std;
/********** Quad *************/

Quad::Quad() {
    fill = {0, 0, 0};
    center = {0, 0};
    width = 50;
    height = 50;
}

Quad::Quad(color fill, point center, double width, double height) {
    this->fill = fill;
    this->center = center;
    this->width = width;
    this->height = height;
}

double Quad::getCenterX() const {
    return center.x;
}

double Quad::getLeftX() const {
    return center.x - (width / 2.0);
}

double Quad::getRightX() const {
    return center.x + (width / 2.0);
}

double Quad::getCenterY() const {
    return center.y;
}

double Quad::getTopY() const {
    return center.y - (height / 2.0);
}

double Quad::getBottomY() const {
    return center.y + (height / 2.0);
}

point Quad::getCenter() const {
    return center;
}

double Quad::getRed() const {
    return fill.red;
}

double Quad::getGreen() const {
    return fill.green;
}

double Quad::getBlue() const {
    return fill.blue;
}

color Quad::getFill() const {
    return fill;
}

unsigned int Quad::getWidth() const {
    return width;
}

unsigned int Quad::getHeight() const {
    return height;
}

void Quad::setColor(double red, double green, double blue) {
    fill = {red, green, blue};
}

void Quad::setColor(color fill) {
    this->fill = fill;
}

void Quad::move(int deltaX, int deltaY) {
    center.x += deltaX;
    center.y += deltaY;
}

void Quad::resize(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
}

void Quad::draw() const {
    // TODO: Implement
    // Don't forget to set the color to the fill field

    glColor3f((float)getRed(), (float)getGreen(), (float)getBlue());
    glBegin(GL_QUADS);
    glVertex2i(getLeftX(),getBottomY());
    glVertex2i(getRightX(),getBottomY());
    glVertex2i(getRightX(),getTopY());
    glVertex2i(getLeftX(),getTopY());

    glEnd();
}