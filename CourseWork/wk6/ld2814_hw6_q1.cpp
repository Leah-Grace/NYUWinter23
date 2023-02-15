/*

The	Fibonacci	numbers sequence, Fn,	is defined	as	follows:
F1 is	1,	F2 is	1,	and	Fn = Fn-1 + Fn-2 for	n =	3,	4,	5,	...	
In	other	words,	each	number	is	the	sum	of	the	previous	two	numbers.	The	first	10	numbers	
in	Fibonacci	sequence	are: 1,	1,	2,	3,	5,	8,	13,	21,	34,	55
Note: Background of Fibonacci sequence: https://en.wikipedia.org/wiki/Fibonacci_number
1. Write a function int fib(int n) that returns the n-th element of the Fibonacci
sequence.
2. Write a program that prompts the user to enter a positive integer num, and then
prints the num’s elements in the Fibonacci sequence.
Your	program	should	interact	with	the	user	exactly as	it	shows	in	the	following	
example:
Please	enter	a	positive	integer: 7
13

*/

#include <iostream>
using namespace std;

int fib(int n){

    int counter = 1;
    int fromOne = 1;
    int fromZero = 0;
    int fib = 1;

        if (n == 0){
            return 0;
        }
        
        while ( counter <= n - 1){

            if (counter % 2 == 1){
                fromZero += fromOne;
                fib = fromZero;
            } else {
                fromOne += fromZero;
                fib = fromOne;
            }
            
            counter++;

        }

        return fib;
}

int main(){

    int nthSequence = 0;

    cout<<"Please enter a positive integer : "<<endl;
    cin>>nthSequence;

    cout<<fib(nthSequence)<<endl;

    return 0;
}