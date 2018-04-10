/*
OWNER - Pavel Šesták

github - www.github.com/alepir

This is "game" in C++. You insert maximum generated integer and numbers of tries
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    cout << "----Welcome in tip game----"<<endl;
    cout << "My number will be bigger than 0, declare a maximum of my number"<<endl;
    cout << "Plese dont use a float number "<<endl;
    cout << "How much tries do you want: ";
    int health;
    cin >> health;
    cout <<"Insert how many numbers do you want to generate: ";
    int max;
    cin >> max;
    srand(time(0));
    int x;
    x = 0 + (rand() % max);
    cout << "Random number is generated, good luck: "<<endl;

    int tip;    
        while (x != tip)
        {
            if (health > 0)
            {
             health--; 
            cout << "Insert your tip: ";
            cin >> tip;
            cout << endl<<"Your lives: "<<health<<endl;
            if (x > tip) cout << "Your tip is too small, try it again"<<endl;
            else if (x < tip) cout << "Your tip is too big, try it again"<<endl;
           
            }
            else 
            {
            cout << "----GAME OVER----"<<endl;
            cout << "Thanx for your game :) "<<endl;
            cout << "My number was: "<<x<<endl;
            break;
            }
        }
        
        
        
        if (health > 0){
        cout << "Great job, you Win!"<<endl;
        cout << "Thanx for your game :) "<<endl;
        }
        

        cin.get();



    return 0;
}
