**Cose da ricordare:**
- Quando inizializzo un grafo (sia matrice di incidenza che lista di adiacenza) devo sempre allocare lo spazio **sia** i vertici **sia** per i loro archi:  
*Matrice di incidenza* 
```c 
Graph new_graph (int n){
    Graph g = malloc(sizeof(struct graph));
    g -> V = n;
    g -> E = 0; 
    g -> mat = calloc(n, sizeof(int*)); //alloco vertici
    for (int i = 0; i < g -> V; i++)
        g -> mat[i] = calloc(n, sizeof(int)); //alloco lo spazio per gli archi 
    return g;
}

```
*Lista di Adiacenza* 
```c
Graph new_graph(int n){
    Graph g = malloc(sizeof(struct graph));
    g -> A = calloc(n + 1, sizeof(struct node*)); //alloco lo spazio per le liste di adiacenza
    g -> V = n; 
    g -> E = 0; 
    return g;
}

```
- Nelle funzioni ricorsive la prima funzione ad essere invocata è l'ultima a finire, perchè devo ragionare con la **pila**.

-  Quando cancello il primo elemento devo mettere il puntatore 
```c
if (prev == NULL)
    {
      *curr = *curr->next;
    }
```