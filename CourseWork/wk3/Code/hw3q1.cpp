#include <iostream>
using namespace std;

const int ONE_HUNDRED = 100;
const int HALF = 2;

int main(){

    float price_one, price_two;
    float taxRate;
    char clubCardStatus;

    cout<<"Enter price of first item: ";
    cin>>price_one;
    cout<<"Enter the price of second item: ";
    cin>>price_two;
    cout<<"Does customer have a club card? (Y/N): ";
    cin>>clubCardStatus;
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>taxRate;
    
    taxRate = (ONE_HUNDRED + taxRate) / ONE_HUNDRED;

    float basePrice = price_one + price_two;

    cout<<"Base price: "<<basePrice<<endl;

    if (price_one > price_two){
        price_two /= HALF;
    } else {
        price_one /= HALF;
    }

    float discountedPrice = price_one + price_two;

    if (clubCardStatus == 'Y' || clubCardStatus == 'y') {
        discountedPrice *= .9;
    }

    cout<<"Price after discounts: "<<discountedPrice<<endl;

    float priceWithTax = taxRate * discountedPrice;

    cout<<"Total price: "<<priceWithTax<<endl;
    
    return 0;
}