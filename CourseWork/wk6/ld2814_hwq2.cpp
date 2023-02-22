#include <iostream>
using namespace std;

int printShiftedTriangle(int n, int m, char symbol){

    cout<<"rows "<<n<<" spacing "<<m<<" symbols "<<symbol<<endl;

    for (int i = 0; i < n; i++){

        for (int j = 1; j <= n; j++){
            cout<<symbol;

        }

    }

    cout<<endl;

    return 0;

}



int printPineTree(int n, char symbol){

    return 0;
}


int main(){

    int n;
    int m;
    char symbol;

    cout<<"Please enter two integers and a character, separated by spaces"<<endl;
    cin>>n;
    cin>>m;
    cin>>symbol;

   // cout<<n<<" "<<m<<" "<<symbol<<endl;


    cout<<printShiftedTriangle(n, m, symbol)<<endl;

    cout<<printPineTree(n, symbol)<<endl;

    return 0;
}