struct Element{
    int x;
    int y;
    char* data;
    struct Element *lptr;
    struct Element *rptr;
};


char* FindValue(int x, int y, struct Element *root){

    while(root != nullptr){
        if(root->x == x){
            if(root->y == y){
                return root->data;
            }
            else if(root->y < y){
                root = root->rptr;
            }
            else{
                root = root->lptr;
            }
        }
        else if(root->x < x){
            root = root->rptr;
        }
        else{
            root = root ->lptr;
        }
    }
    
    return (char *)"";
}

int main(){
    return 0;
}