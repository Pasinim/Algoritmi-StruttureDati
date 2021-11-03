/* il reparto (e) e il (b) sono da escludere dato che c'è un reparto che riceve i prodotti da due reparti differenti
(d) è da escludere dato che il Primo reparto manda i prodotti in 3 diversi reparti, e non solamente in due
(c) è da escludere perche l'albero a sx è equivalente a quello in (a), mentre in (c) si produrrebe solamente una sola tipologia di prodotto
*/

//posso descrivere i processi descritti come dei nodi, ogni nodo rappresenta un reparto
struct node {
    int n; //numero del reparto
    int *l, *r; //reparti successivi in cui potrà essere inviato il prodotto
    int lavoratori; //numero dei lavoratori per il reparto
    //int isCollaudo; //indica se il reparto è di collaudo oppure no
};
typedef struct node *Node;
#define TRUE 1 
#define FALSE 0
//il reparto primo collaudo è il primo nodo dell'albero (quindi il nodo root).
//Differisce dagli altri in quando non potrà avere dei puntatori che puntano ad esso (quindi non potrà mai essere un figlio di un altro nodo)
//il raparto di collaudo, al contrario, è un nodo in cui le foglie dx e sx saranno sempre NULL. SI tratta quindi del nodo terminale

//a questa funzione deve essere chiamata con (PrimoReparto, 0)
int lavoratoriTotali (Node root, int lavoratori){
    int sum=lavoratori;
    if (root==NULL){ 

    }
}