#include <stdio.h>
#include <string.h>

int main(){
    int n, cont, i, j;
    int aux1, aux2, res;
    int tam1, tam2;
    char n1[1000], n2[1000];
   
    scanf("%d", &n);
  
    
    for(cont=0; cont<n; cont++){
        char numFinal[1000] = {0};
        
        scanf("%s", n1);
        scanf("%s", n2);
        
        tam1 = strlen(n1);
        tam2 = strlen(n2);
        
        res = 0;

        for(j=tam2-1; j>=0; j--){
            aux2 = n2[j] - '0';
            for(i = tam1-1; i >= -1; i--){
                aux1 = i >= 0 ? n1[i] - '0' : 0;
                numFinal[j+i+1] += aux2*aux1+res;
                res = numFinal[j+i+1] / 10;
                numFinal[j+i+1] = numFinal[j+i+1] % 10;
            }
        }
        
        numFinal[tam1 + tam2] = '\0';

        for(i=0; i<tam1+tam2; i++)
            numFinal[i] += '0';

        for(i=0; i<tam1+tam2-1 && numFinal[i] == '0'; i++);
            strcpy(numFinal, &numFinal[i]);
        
        printf("%s\n", numFinal);
    }
}