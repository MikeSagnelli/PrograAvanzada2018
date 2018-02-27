typedef struct e{
    void *key;
    void *value;
} Element;

typedef struct v{
    unsigned count;
    unsigned size;
    Element *elements;
} Vector;

typedef struct h{
    unsigned size;
    Vector * data;
    unsigned (* hash) (void *, unsigned);
} Hash;

void initHash(Hash *, unsigned, unsigned (* hash ) (void *, unsigned));
void insertHash(Hash *, void *, void *, void * (*caster)(void *));
void * getHash(Hash *,void *,void *(*caster)(void *),int (*cmpKeys)(void *, void *));