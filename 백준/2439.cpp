#include <stdio.h>

int main(){
    int i, j, k, input;
 
    scanf("%d", &input);
 
    for(i = 1; i < input+1; i++){
        for(j = input-i; j > 0; j--)
            printf(" ");
        
        for(k = 1; k < i+1; k++)
            printf("*");
        
        printf("\n");
    }
    
    return 0;
}
