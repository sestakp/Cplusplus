/*
    Write a program which will find all such numbers which are divisible by 7 but are not a multiple of 5, between 2000 and 3200

    Challenge by Sololearn Forum

    Owner - Pavel Šesták

    Github.com/alepir
*/
#include <iostream>

using namespace std;

int main(){

    cout << "program which will find all such numbers which are divisible by 7 but are not a multiple of 5, between 2000 and 3200"<<endl;
    cout << "Numbers: ";

    for (int i=2000; i<=3200; i++) if ((i % 7 == 0)&&(i % 5 != 0)) cout << i<<", ";
    
    cin.get();
    return 0;
}