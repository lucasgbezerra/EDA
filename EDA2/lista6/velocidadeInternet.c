#include <stdio.h>
#include <stdlib.h>


#define Key(A) (internet[A]) 
#define lessDown(A, B) (Key(A).down < Key(B).down)
#define eq(A, B) (Key(A).down == Key(B).down)
#define lessUp(A, B) (Key(A).up < Key(B).up)
#define lesseq(A, B) (Key(A) <= Key(B))
#define exch2(A, B){int t = A; A = B; B = t;}
#define cmpexch(A, B){if(lessDown(B, A)) exch2(A, B)}

int cnt = 0;
int teste = 1;
typedef struct testes
{
    int down;
    int up;
}testes; testes *internet;

typedef struct pq_ist
{
    int N;
    int *pq;
    int *qp;
}pq_ist;

void exch(pq_ist *PQ, int i, int j){
    int t;
    t = PQ->qp[i];
    PQ->qp[i] = PQ->qp[j];
    PQ->qp[j] = t;
    PQ->pq[PQ->qp[i]] = i;
    PQ->pq[PQ->qp[j]] = j;
   
}
void PQinit(int maxN, pq_ist *PQ){
    PQ->pq = malloc(sizeof(int) * (maxN+1));
    PQ->qp = malloc(sizeof(int) * (maxN+1));
    PQ->N = 0;
}

int PQempty(pq_ist *PQ){
    return(PQ->N == 0);
}

void fixUp(pq_ist *PQ, int k){
    while (k > 1 && lessDown(PQ->pq[k/2],PQ->pq[k]))
    {
        exch(PQ,PQ->pq[k], PQ->pq[k/2]);
        k = k/2;
    }
    
}

void fixDown(pq_ist *PQ, int k, int N){
    int j;

    while (2*k <= N)
    {
        j = 2*k;
        if(j < N && lessDown(PQ->pq[j],PQ->pq[j+1]))
            j++;
        if(!lessDown(PQ->pq[k],PQ->pq[j]))
            break;
        exch(PQ,PQ->pq[k], PQ->pq[j]);
        k = j;
    }
    
}

void PQinsert(pq_ist *PQ, int k){
    PQ->qp[k]= ++PQ->N;
    PQ->pq[PQ->N]= k;
    fixUp(PQ, PQ->N);
}

int PQDelMax(pq_ist *PQ){
    exch(PQ,PQ->pq[1], PQ->pq[PQ->N]);
    fixDown(PQ, 1, PQ->N - 1);
    return PQ->pq[PQ->N--];
}

void PQchange(pq_ist *PQ, int k){
    fixUp(PQ, PQ->qp[k]);
    fixDown(PQ, PQ->qp[k], PQ->N);

}

int partition(int *v, int l, int r){
	int pv = v[r];
	int j = l;
	int aux;

	for(int k = l; k < r; k++){
        if(eq(v[k], pv)){
            if(lessUp(v[k], pv)){
                exch2(v[k], v[j]);
			    j++;
            }
        }
		else if(lessDown(v[k], pv)){
			exch2(v[k], v[j]);
			j++;
		}
	}

	exch2(v[r], v[j]);	
	return j;
}


void quickSortM3(int *v, int l, int r){
	int j;
	int m = (r+l)/2;
	if(r <= l)
		return;
	cmpexch(v[m], v[r]);
	cmpexch(v[l], v[m]);
	cmpexch(v[r], v[m]);

	j = partition(v, l, r);
	quickSortM3(v, l, j-1);
	quickSortM3(v, j+1, r);
}
void imprimeHeap(int *pq, int n,int t){
    int *p = malloc(sizeof(int) *n+2);
    for (int i = 1; i <= n; i++)
        p[i] = pq[i];
    
    quickSortM3(p, 1, n);
    for (int i = 1; i <= t; i++){
        printf("%d/%d\n", internet[p[i]].down, internet[p[i]].up);
    }
    free(p);
}
void imprime(int *pq, int n,int t){
    int *p = malloc(sizeof(int) *n+2);
    FILE *fp;
    for (int i = 1; i <= n; i++)
        p[i] = pq[i];
    
    quickSortM3(p, 1, n);
    fp = fopen("Output.txt", "w");// "w" means that we are going to write on this file
    for (int i = 1; i <= t; i++){
        printf("%d/%d\n", internet[p[i]].down, internet[p[i]].up);
        fprintf(fp, "%d/%d\n", internet[p[i]].down, internet[p[i]].up);

    }
    fclose(fp);
    free(p);
}

int main(){
    int download, upload, t;
    int d, u;
    int limite_d, limite_u;
    char str;
    double l;
    pq_ist *PQ = malloc(sizeof(pq_ist));

    scanf("%d %d %lf %d", &download, &upload, &l, &t);
    
    l = (100 - l)/100;
    limite_d = download*l;
    limite_u = upload*l;
    internet = malloc(sizeof(testes) * t);
    PQinit(t+2, PQ);
    for (int i = 0; i < t; i++){
        scanf("%d %c %d", &d ,&str, &u);
        if(d < limite_d || u < limite_u){
            internet[cnt].down = d;
            internet[cnt].up = u;
            PQinsert(PQ, cnt);
            cnt++;
        }
    }

    imprimeHeap(PQ->pq, PQ->N, cnt);
    return 0;
}