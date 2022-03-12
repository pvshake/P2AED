#include <stdio.h>
#include <stdlib.h>

#define SUCESSO        1
#define FALHA         -1
#define CHAVE_INVALIDA 0
//
// Declaração de tipos globais
//
typedef
   struct Celula*    ApontadorCelula;
typedef
   struct Descritor* ApontadorDescritor;

struct Descritor {
     ApontadorCelula prim;
     int             tam;
     ApontadorCelula ult;
} Descritor;

struct Celula {
     ApontadorCelula ant;
     int             chave; 
     int             dado;
     ApontadorCelula prox;
} Celula;

int CriarListaVazia (ApontadorDescritor* d) {
    (*d) = (ApontadorDescritor) malloc( sizeof(struct Descritor) );
    if ((*d) == NULL) {
       return (FALHA);
    }
    else {
       (*d)->prim = (ApontadorCelula) NULL;
       (*d)->tam  = 0;
       (*d)->ult  = (ApontadorCelula) NULL;
       return (SUCESSO);
    }
}

int InsInicio (ApontadorDescritor* d, struct Celula celula) {
    ApontadorCelula q;

    q = (ApontadorCelula) malloc( sizeof(struct Celula) );
    if (q == NULL) {
        return(FALHA);
    }
    else {
        q->chave = celula.chave;
        q->dado  = celula.dado;
        q->ant   = (ApontadorCelula) NULL;
        q->prox  = (*d)->prim;

        if ((*d)->tam == 0) {
           (*d)->prim = q;
           (*d)->ult  = q;
        }
        else {
           ((*d)->prim)->ant = q;
           (*d)->prim        = q;
        }
        (*d)->tam++;
        return(SUCESSO);
    }
}

int InsFinal (ApontadorDescritor* d, struct Celula celula) {
    ApontadorCelula q;

    if ((*d)->tam == 0) {
       return (InsInicio (d, celula)); 
    }
    else {
       q = (ApontadorCelula) malloc( sizeof(struct Celula) );
       if (q == NULL) {
          return (FALHA);
       }
       else {
          q->chave = celula.chave;
          q->dado  = celula.dado;
          q->prox  = (ApontadorCelula) NULL;
          q->ant   = (*d)->ult;

          ((*d)->ult)->prox  = q;
          (*d)->ult          = q;
          (*d)->tam++;

          return (SUCESSO);
       }
    }
}

int InsOrdem (ApontadorDescritor* d, struct Celula celula) {
    ApontadorCelula q, r;

    if ((*d)->tam == 0) {
        return ( InsInicio(d, celula) );
    }
    else {
        if ( celula.dado < ((*d)->prim)->dado ) {
           return ( InsInicio(d, celula) );
        }
        else { 
           if ( celula.dado >= ((*d)->ult)->dado ) {
               return ( InsFinal(d, celula) );
           }
           else {
               q = (ApontadorCelula) malloc( sizeof(struct Celula));
               
               q->dado  = celula.dado;
               r = (*d)->prim;
               while (r->dado <= celula.dado) { 
                      r = r->prox;
               }
               q->prox = r;
               q->ant  = r->ant;

               r->ant         = q;
               (q->ant)->prox = q;

               (*d)->tam++;

               return(SUCESSO);
           }
        }      
    }
}

int Soma(ApontadorDescritor* d){
    struct Celula *r, *index;
    int soma = 0;
     r = (*d)->prim;
      for(r = (*d)->prim ; r != NULL; r = r->prox) {  
             
            for(index = r->prox; index != NULL; index = index->prox) { 
               
                if(r->dado == index->dado){
                    
                    r = r->prox;
                     
                } 
          }
          soma += r->dado;
          
      }
          return soma;
}

int main (void) {

    ApontadorDescritor d;
    int                intChave, intValor, tamanho, i, soma; 
    struct Celula      celulaAuxiliar;
   
    CriarListaVazia(&d);
    scanf("%d", &tamanho);
    
    for(i=0; i < tamanho; i++){
        
        scanf("%d",&intValor);
        celulaAuxiliar.dado  = intValor;
        InsOrdem(&d, celulaAuxiliar);   
    }

    soma = Soma(&d);
    printf("%d ", soma);
    
}