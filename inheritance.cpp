#include<iostream>
using namespace std;

class Shape {
    private :
        string name;
    public :
        Shape(string name) {
	    this-> name = name;
	}
        
        void display() {
	    cout << "Shape:" << name << endl;
	}
	    	
};

class Rectangle : public Shape {
    private :
        float length;
        float breadth;
        float area;
    public :
        Rectangle(string name, float length, float breadth):Shape(name) {
	    this->length = length;
            this->breadth = breadth;
	}

	void areaOfRectangle() {
	    area = length * breadth;
	}

	void getArea() {
            cout << "Area:" << area << endl;
	}
};

class Triangle :public Shape {
    private :
        float base;
        float height;
        float area;
    public :
        Triangle(string name, float base, float height):Shape(name) { 	
            this->base = base;
	    this->height = height;

	}

	void areaOfTriangle() {
	    area = (base * height)/2;
        }

        void getArea() {
            cout << "Area:" << area << endl;
        }

};

int main() {
    Rectangle rectangle("Rectangle", 15, 5);
    rectangle.display();
    rectangle.areaOfRectangle(); 
    rectangle.getArea();
 
    Triangle triangle("Triangle", 10, 20);
    triangle.display();
    triangle.areaOfTriangle();
    triangle.getArea();
}
