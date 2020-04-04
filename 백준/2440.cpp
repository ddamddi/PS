#include <stdio.h>

int main(){
    int i, j, input;
    
    scanf("%d", &input);
    for(i = input; i > 0; i--){
        for(j = i; j > 0; j--)
            printf("*");
        printf("\n");
    }
    
    return 0;
}
