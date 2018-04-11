//prime numbers
#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {
	
	cout <<"--- program in C++ ---"<<endl;
	cout <<"Program will print prime numbers in interval <1;n)"<<endl;
  cout <<"Insert please integer n: ";
   
   int n;
   cin >> n;
   bool check = NULL;
   
   for (int i=2; i <= n;i++)
   {
       check = true;
       for (int j=2; j<i;j++) if (i % j == 0) check = false;    
       if (check == true) cout <<i<<endl;     
   }	
	cout << "program end!";
	return 0;
}
