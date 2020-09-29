#include <stdio.h>

int main(){
    int n, m, p, a, b,Xpa,Ypa,Xpb,Ypb;
	int pass,parar = 0,caso=0;
	scanf("%d %d %d", &n, &m, &p);
	Xpa = Ypa = 1;
	Xpb = n;
	Ypb = m;

	for(int i=0; i<p ; i++)
	{
		scanf("%d %d",&a,&b);
		if(parar == 0)
		{
			switch(a)
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
			switch(b)
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
			if(Xpa == Xpb && Ypb == Ypa)
			{
				pass = i+1;
				parar = 1;
				caso = 1;
			}
			if(Xpa > n || Ypa > m || Xpa < 1 || Ypa < 1)
			{
				pass = i+1;
				parar = 1;
				caso = 2;
			}
			if(Xpb > n || Ypb > m || Xpb < 1 || Ypb < 1)
			{
				if (caso == 2){
					caso = 4;
				}else{
					caso = 3;
				}
				pass = i+1;
				parar = 1;
			}

		}

	}

    switch (caso)
	{
        case 1:
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", Xpa, Ypa, pass);
            break;
        case 2:
            printf("PA saiu na posicao (%d,%d) no passo %d\n", Xpa, Ypa, pass);
            break;
        case 3:
            printf("PB saiu na posicao (%d,%d) no passo %d\n", Ypb, Ypb, pass);
            break;
        case 4: 
            printf("PA saiu na posicao (%d,%d) no passo %d\n", Xpa, Ypa, pass);
            break;
        default:
            printf("Nao se encontraram\n");
    }
    return 0;
}
