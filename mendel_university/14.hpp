

struct Element{
    void *data;
    struct Element *next;
};

struct List{
    struct Element *head;
};

void Init(struct List *l);
void Add(struct List *l, void *data, int position);
typedef char* (*TransformDataToString)(void* data);
void Save(struct List *l, char* filename);