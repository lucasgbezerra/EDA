#include <stdio.h>


int main(){
    int n, m, p, a, b, pa[] = {1,1}, pb[2], caso = 0, enc[2], pass,stop = 0;

    scanf("%d %d %d", &n, &m, &p);
    pb[0] = m;
    pb[1] = n;

            for(int i = 1; i <= p; i++){
                
                scanf("%d %d", &a, &b);
                
                if (stop == 0){


                        switch (a){
                            case 1:
                                pa[1]++;
                                break;
                            case 2:
                                pa[1]--;
                                break;
                            case 3:
                                pa[0]++;
                                break;
                            case 4:
                                pa[0]--;
                                break;
                        }

                    

                        switch (b){
                            case 1:
                                pb[1]++;
                                break;
                            case 2:
                                pb[1]--;
                                break;
                            case 3:
                                pb[0]++;
                                break;
                            case 4:
                                pb[0]--;
                                break;
                        }

                    
                    if(pa[0] == pb[0] && pa[1] == pb[1]){
                        caso = 1;
                        enc[0] = pa[0];
                        enc[1] = pa[1];
                        pass = i;
                        stop = 1;
                    }

                    if (pa[0] > n || pa[0] <= 0 || pa[1] > m || pa[1] <= 0){
                        caso = 2;
                        pass = i;
                        stop = 1;
                    }

                    if (pb[0] > n || pb[0] <= 0 || pb[1] > m || pb[1] <= 0){
                        caso = 3;        
                        pass = i;
                        stop = 1;
                    }

                    if((pa[0] > n || pa[0] <= 0 || pa[1] > m || pa[1] <= 0) && 
                            (pb[0] > n || pb[0] <= 0 || pb[1] > m || pb[1] <= 0)){
                        caso = 4;
                        pass = i;
                        stop = 1;
                    }
                }
            }


    switch (caso){
        case 1:
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", enc[0], enc[1], pass);
            break;
        case 2:
            printf("PA saiu na posicao (%d,%d) no passo %d\n", pa[0], pa[1], pass);
            break;
        case 3:
            printf("PB saiu na posicao (%d,%d) no passo %d\n", pb[0], pb[1], pass);
            break;
        case 4: 
            printf("PA saiu na posicao (%d,%d) no passo %d\n", pa[0], pa[1], pass);
            break;
        default:
            printf("Nao se encontraram\n");
    }

    return 0;
}
