#include<iostream>
using namespace std;

class Shape {
    protected :
        float width;
        float height;
    public :
        void setValue() {
            cout << "Enter width and height :";
            cin >> width >> height;
        }
};

class Triangle : virtual public Shape {
    public :
        void areaOfTriangle() {
            cout << "Area of Triangle:" << (width * height) << endl;
        }
};

class Rectangle : virtual public Shape {
    public :
        void areaOfRectangle() {
            cout << "Area of Rectangle:" << ((width * height)/2) << endl;
        }
};

class Square : public Triangle, public Rectangle {
    public :
        void areaOfSquare() {
            cout << "Area of Square:" << (width * width) << endl;
        }
};

int main () {
    Square square;
    square.setValue();
    square.areaOfTriangle();
    square.areaOfRectangle();
    square.areaOfSquare();
}
