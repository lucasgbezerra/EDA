// separa a partir de um pivo, maneira comum
int separa(int *v, int l, int r){
    int j =l, pv = v[r];

    for(int k = 0; k < r; k++){
        if(less(v[k], v[r])){
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);

    return j;

}

// Separa Chadwik
int separaChadwick(int *v, int l, int r){
    int i = l -1, j = r;
    int pv = v[r];

    for(;;){
        while(less(v[++i], pv));
        while(less(pv, v[--j]))
            if(j == l)
                break;
        if(i >= j)
            break;
        exch(v[i], v[j]);
    }

    exch(v[i], v[r]);

    return i;
}
//Simples implementação de quickSort()
//Essa forma de implementar sofre com vetores ordenados de maneira reversa, e quase ordenados
void quickSort( int *v, int l, int r){
	int j;

    if(r <= l)
        return;
    j = separa(v, l, r);
    quickSort(v, l, j-1);
    quickSort(v, j+1, r);

}
