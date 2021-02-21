double calculaVelocidadeMedia(int tA, int tB, double distancia){
    double t = (tB - tA);
    return distancia/(t/3600);
}
int levouMulta(int tA, int tB, double distancia, double velocidadeMaxima){
    if(calculaVelocidadeMedia(tA,tB,distancia) > velocidadeMaxima){
        return 1;
    }else
    {
        return 0;
    }
}
