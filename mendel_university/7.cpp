#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;
int main(int argc, char *argv[]){

    if(argc <= 1){
        cerr << "missing argument";
        return 1;
    }
    char* filename = argv[1];


    fstream my_file;
	my_file.open(filename, ios::in);
	if (!my_file) {
		cerr << "No such file";
        return 1;
	}
	else {
        int x;
        int y;
        char size;
        my_file >> x;
        my_file >> y;
        my_file >> size;
        size /= 8;
        

        printf("%d\n",x);
        printf("%d\n",y);

        int acc = 0;

        int refPixel = 0;

        char *data = (char*)malloc(size);

        if(data == nullptr){
            std::cerr << "intern error";
            return 1;
        }

        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                
                my_file.read(data,size);
                
                int value = atoi(data);

                if(i == j == 0){
                    refPixel = value;
                }
                else{
                    if(refPixel == value){
                        acc++;
                    }
                }

            }
        }
        //Answer is in accumulator
        free(data);
	}
	my_file.close();
    return 0;
}