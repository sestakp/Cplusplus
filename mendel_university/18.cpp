
struct node{
    struct node* lptr;
    struct node* rptr;
    void *data;
};

int calculateNodesWithGreaterValue(struct node* root, void *value){
    if(root == nullptr){
        return 0;
    }

    int retval = calculateNodesWithGreaterValue(root->lptr,value) + calculateNodesWithGreaterValue(root->rptr,value);

    if(value > root->data){
        return retval + 1;
    }

    return retval;
}


int main(){
    return 0;
}

