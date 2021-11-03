struct bi_node{
    int info;
    struct bi_node *prev;
    struct bi_node *next;
};
typedef struct bi_node *Bi_node;

struct bi_list{
    Bi_node first;
    Bi_node last;
};
typedef struct bi_list *Bi_list;

void insert (Bi_list b, int n);
Bi_node new_node(int v);
void stampa(Bi_list b);