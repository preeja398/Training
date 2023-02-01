#include<iostream>
using namespace std;

class Space {
    public :
        virtual void calculateArea() = 0;
};

class Triangle : public Space {
    private :
        float base;
        float height;
        float area;
    public :
         Triangle(float base, float height) {
             this->base = base;
             this->height = height;
         }

         void calculateArea() {
            area = (base * height)/2;
            cout << "Area of triangle:" << area << endl;
        }
};

class Rectangle : public Space {
    private :
        float length;
        float breadth;
        float area;
    public :
        Rectangle(float length, float breadth) {
            this->length = length;
            this->breadth = breadth;
        }

        void calculateArea() {
            area = length * breadth;
            cout << "Area of rectangle:" << area << endl;
        }
};

int main() {
    Triangle triangle(10, 20);
    Space *s1 = &triangle;
    s1->calculateArea();
    
    Rectangle rectangle(30, 10);
    Space *s2 = &rectangle;
    s2->calculateArea();
}
