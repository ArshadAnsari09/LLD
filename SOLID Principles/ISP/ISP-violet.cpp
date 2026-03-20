#include<iostream>
#include<stdexcept>
using namespace std;

class Shape {
    public : 
     virtual double area() = 0;
     virtual double volume() = 0;
};

class Square : public Shape{
    private :
    double side;

    public :
    Square(double s) : side(s){}
    double area() override{
        cout << "Area of square" << side * side << endl;
    }
    double volume() override{
        throw overflow_error("Volume not applicable for square");
    }
};

class Rectangle : public Shape{
    public : 
    double area() override{
        cout << "Area of Rectangle" << endl;
    }
    double volume() override{
        throw overflow_error("Volume not applicable for Rectangle");
    }
};

class Cube : public Shape{
    public : 
    double area() override{
        cout << "Area of Cube" << endl;
    }
    double volume() override{
        cout << "Volume of Cube" << endl;
    }
};

int main() {

    return 0;
}