#include <stdio.h>
int main(){
    int n, m, p, a, b, Xpa,Ypa,Xpb,Ypb, caso = 0,stop =0,pass;

    scanf("%d %d %d", &n, &m, &p);
    Xpb = n;
    Ypb = m;
	Xpa = Ypa = 1;
	for(int i = 0; i < p; i++)
	{
		scanf("%d %d", &a, &b);
		if(stop == 0)
		{
			switch (a)
			{
				case 1:
					Ypa++;
					break;
				case 2:
					Ypa--;
					break;
				case 3:
					Xpa++;
					break;
				case 4:
					Xpa--;
					break;
			}
			switch (b)
			{
				case 1:
					Ypb++;
					break;
				case 2:
					Ypb--;
					break;
				case 3:
					Xpb++;
					break;
				case 4:
					Xpb--;
					break;
			}
			if(Xpa == Xpb && Ypa == Ypb)
			{
				pass = i+1;
				caso = 1;
				stop = 1;
			}

			if (Xpa > n || Xpa < 1 || Ypa > m || Ypa < 1)
			{
				pass = i+1;
				caso = 2;
				stop = 1;
			}

			if ( Xpb> n || Xpb < 1 || Ypb > m || Ypb < 1)
			{
				if(caso == 2){
					caso = 4;
				}else{
					caso = 3;
				}
				pass = i+1;  
				stop = 1;
			}
		}
	}

    switch (caso){
        case 1:
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", Xpa, Ypa, pass);
            break;
        case 2:
            printf("PA saiu na posicao (%d,%d) no passo %d\n", Xpa, Ypa, pass);
            break;
        case 3:
            printf("PB saiu na posicao (%d,%d) no passo %d\n", Xpb, Ypb, pass);
            break;
        case 4: 
            printf("PA saiu na posicao (%d,%d) no passo %d\n", Xpa, Ypa, pass);
            break;
        default:
            printf("Nao se encontraram\n");
    }
    return 0;
}