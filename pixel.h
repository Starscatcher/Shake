#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
public:
    Pixel(int x, int y);
    int get_x();
    int get_y();
    void set_x(int x);
    void set_y(int y);
    ~Pixel();

private:
    int _x;
    int _y;
};

#endif
