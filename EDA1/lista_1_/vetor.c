#include <stdio.h>

int main(){
    int len, num, cont =0;

    scanf("%d", &len);
    int vec[len];
    for(int c =0; c < len; c++){
        scanf("%d", &vec[c]);
    }
    scanf("%d", &num);

    for(int c =0; c < len; c++){
       if(num != vec[c]){
           cont++;
       }
    }
    if (cont == len)
    {
        printf("nao pertence\n");
    }else
    {
        printf("pertence\n");
    }
    
    
    return 0;
}