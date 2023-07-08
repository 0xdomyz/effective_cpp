// g++ rect_square.cpp -o rect_square && ./rect_square
#include <cassert>

class Rectangle
{
public:
    virtual void setHeight(int newHeight) { height_ = newHeight; };
    virtual void setWidth(int newWidth) { width_ = newWidth; };
    virtual int height() const
    {
        return height_;

    }; // return current values
    virtual int width() const
    {
        return width_;
    };

private:
    int height_;
    int width_;
};

void makeBigger(Rectangle &r) // function to increase r’s area
{
    int oldHeight = r.height();
    r.setWidth(r.width() + 10);      // add 10 to r’s width
    assert(r.height() == oldHeight); // assert that r’s
}

class Square : public Rectangle
{
};

int main()
{
    Square s;
    assert(s.width() == s.height()); // this must be true for all squares
    makeBigger(s);                   // by inheritance, s is-a Rectangle,
    // so we can increase its area
    assert(s.width() == s.height()); // this must still be true
    // for all squares
}