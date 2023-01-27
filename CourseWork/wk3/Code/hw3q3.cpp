#include <iostream>
#include <cmath>
using namespace std;

const int ZERO = 0;
const int TWO = 2;
const int FOUR = 4;
const int NEGATIVE_ONE = -1;


void quadraticFormula(int a, int b, int c){
    float discriminant = (( b * b ) - FOUR * a * c);
    if (a == ZERO && b == ZERO && c == ZERO){
        cout<<"This equation has an infinite number of solutions"<<endl;
        return;
    }
    if (discriminant > ZERO){
        cout<<"This equation has two real solutions"<<endl;
        float solution_one = ((b * ( NEGATIVE_ONE )) + sqrt(b * b - FOUR * a * c));
        float solution_two = ((b * ( NEGATIVE_ONE )) - sqrt(b * b - FOUR * a * c));
        cout<<"Solution one: x="<<solution_one<<endl;
        cout<<"Solution two: x="<<solution_two<<endl;
        return;
    }
    else if (discriminant == ZERO){
        cout<<"This equation has one real solution"<<endl;
        float solution = ((b * ( NEGATIVE_ONE )) / ( TWO * a ));
        cout<<"Solution: x="<<solution<<endl;
        return;
    }
    else{
        cout<<"This equation has no real solution"<<endl;
        return;
    }
}

int main(){
    int a,b,c;
    cout<<"Please enter the value of a: ";
    cin>>a;
    cout<<"Please enter the value of b: ";
    cin>>b;
    cout<<"Please enter the value of c: ";
    cin>>c;
    quadraticFormula(a, b, c);
    return 0;
}