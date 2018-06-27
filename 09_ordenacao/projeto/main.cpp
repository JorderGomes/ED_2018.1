#include <iostream>
#include <ctime>
#include <cstdlib>
#include "libs/ed_sort.h"

using namespace std;


void quick(vector<int>& vet, int inicio, int fim){
    if( inicio >= fim)
        return;
        int pontoDePartida = vet[inicio];
        int i = inicio;
        int j = fim;
        faixa(inicio,fim);
            while(i <= j){
            while(vet[i] < pontoDePartida && (i < fim)){
                i++;
                show(vet, {inicio, fim, i, j}, "rgby" );
            }
            while(vet[j] > pontoDePartida && (j > inicio)){
                j--;
                show(vet, {inicio, fim, i, j}, "rgby" );
            }
            if(vet[i] >= vet[j]){
                std::swap(vet[i], vet[j]);
                show(vet, {inicio, fim, i, j}, "rgby" );
                i++;
                j++;
            }
            }

        quick(vet, inicio, j);
        quick(vet, i, fim);
}

void    merge(vector<int> & vet, int a, int b, int c){ //// nao apaga
    int i = a;
    int j = b;
    vector<int> vaux;
    vaux.reserve(c - a);
   while(i < b && j < c){
        if(vet[i] < vet[j])
            vaux.push_back(vet[i++]);
        else{
            vaux.push_back(vet[j++]);
            view_show(vet, {a,b,c,i,j}, "rgbyc");
        }
    }
   while(i < b){
       vaux.push_back(vet[i++]);
       view_show(vet, {a,b,c,i,j}, "rgbyc");
   }
   while(j < c){
        vaux.push_back(vet[i++]);
        view_show(vet, {a,b,c,i,j}, "rgbyc");
   }
   for(int i = 0; i < (int) vaux.size(); i++){
       vet[a + i] = vaux[i];
       view_show(vet, {a,b,c,i,j}, "rgbyc");
    }
}
int main(){
    srand(time(NULL));
    const int qtd = 70;
    vector<int> vet(qtd, 0);

    int min = 10;
    int max = 400;

    for(int i = 0; i < qtd; i++)
        vet[i] = (rand() % (max - min + 1) + min);

    view_set_bar();
    view_set_faixa(0, qtd - 1);
    merge(vet,35,10,60);



    view_lock();
    return 0;
}
/
