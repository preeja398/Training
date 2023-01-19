#include<iostream>
using namespace std;

int sum(int num1, int num2) {
    return num1 + num2;
}

float sum(float num1, float num2) {
    return num1 + num2;
}

double  sum(double num1, double num2) {
    return num1 + num2;
}

int main () { 
    cout << "sum of int =  " << sum(10, 20) << endl;
    cout << "sum of float = " << sum(30.4f, 40.5f) << endl;
    cout << "sum of double = " << sum(50.34, 60.56) << endl;
}
