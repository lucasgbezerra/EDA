#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 101

typedef struct Item{
    char str[30];
}Item;

int hash(char *key, int len){
    int r = 0;

    for(int i = 0; i < len; i++){
        r += 19*(key[i]*(i+1));
    }
    return r%M;
}

int main(){
    int n, t, pos, len;
    char string[20], *key, cmd;
    int flag;
    int N;
    Item *ht;
    
    //Hash table init
    ht = malloc(M * sizeof(Item));
    

    scanf("%d", &t);
    while (t--)
    {
        N = 0; 
        for(int i = 0; i < M; i++)
            strcpy(ht[i].str, "");

        scanf("%d", &n);


        for(int i = 0; i < n; ++i){
            scanf("%s", string);
            key = &string[4];
            len = strlen(key);
            cmd = string[0];

            if(cmd == 'A'){
                flag = 1;

                for(int j = 0; j < 20; ++j){
                    pos = (hash(key, len) +j*j+ 23*j)% M;
                    if(ht[pos].str != NULL && strcmp(key, ht[pos].str) == 0){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    for(int j = 0; j < 20; ++j){
                        //inserir
                        pos = (hash(key, len) +j*j+ 23*j)% M;
                        if(ht[pos].str != NULL && strcmp(ht[pos].str, "") == 0){
                            strcpy(ht[pos].str, key);
                            N++;
                            break;
                        }
                    }
                }

            }else if(cmd == 'D'){
                for(int j = 0; j < 20; j++){
                    pos = (hash(key, len) +j*j+ 23*j)% M;
                    if(ht[pos].str != NULL && strcmp(key, ht[pos].str) == 0){
                        strcpy(ht[pos].str, "");
                        N--;
                        break;
                    }
                }
            }
            
        }
        printf("%d\n", N);
        for(int i = 0; i < M; i++){
            if(strcmp(ht[i].str, "") != 0)
                printf("%d:%s\n", i, ht[i].str);
        }
    }
    return 0;
}