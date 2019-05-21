//
// Created by zuozu on 2019/5/20.
//

#ifndef HUARONGDAO_QUAD_H
#define HUARONGDAO_QUAD_H


struct color {
    double red;
    double green;
    double blue;
};

struct point {
    double x;
    double y;
};

class Quad {
private:
    color fill;
    point center;
    point rightBottom;
    double width;
    double height;

public:
    Quad();
    Quad(color fill, point center,  double width,  double height);

    double getCenterX() const;
    double getLeftX() const;
    double getRightX() const;
    double getCenterY() const;
    double getTopY() const;
    double getBottomY() const;
    point getCenter() const;

    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    color getFill() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void setColor(double red, double green, double blue);
    void setColor(color fill);
    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);

    void draw() const;
};



#endif //HUARONGDAO_RECT_H
