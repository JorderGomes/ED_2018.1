#include "libs/ed_base.h"
#include "libs/ed_mat.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <algorithm> //random_shuffle

using namespace std;

int nlinhas = 20;
int ncolunas = 35;

const char PAREDE = 'k';
const char ABERTO = 'w';
const char EMBUSCA = 'y';
const char CAMINHO = 'b';
const char ABATIDO = 'm';

void showMat(matchar& mat, Par inicio, Par fim, Par atual){
    mat_draw(mat);
    mat_focus(inicio, 'g');
    mat_focus(fim, 'r');
    mat_focus(atual, 'y');
    ed_show();

}

void showMat(matchar& mat, vector<Par> pilha){
    mat_draw(mat);
    for(Par par : pilha){
        mat_focus(par, 'c');
    }
    if(pilha.size() > 0){
        mat_focus(pilha.back(), 'm');
    }

}


vector<Par> getNeib(Par par){
    vector<Par> vizinhos;
    vizinhos.push_back(Par(par.l + 1, par.c));
    vizinhos.push_back(Par(par.l - 1, par.c));
    vizinhos.push_back(Par(par.l, par.c + 1));
    vizinhos.push_back(Par(par.l, par.c - 1));

//    vizinhos.push_back(Par(par.l - 1, par.c));
//    vizinhos.push_back(Par(par.l - 1, par.c));
//    vizinhos.push_back(Par(par.l, par.c + 1));
//    vizinhos.push_back(Par(par.l, par.c - 1));
    return vizinhos;
}

int countOpen(matchar &mat, Par par){
    int cont = 0;
    for(auto vizinho : getNeib(par))
        if(!mat.is_inside(vizinho) || mat.get(vizinho) != PAREDE)
            cont++;
    return cont;
}

vector<Par> shuffle(vector<Par> vet){
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}


void furar(matchar &mat, Par par){ // ALTERAR ESTE METODO
    if(!mat.equals(par, PAREDE) || countOpen(mat, par) > 1)
        return;
    mat.get(par) = ABERTO;
    for(Par vizinho : shuffle(getNeib(par)))
        furar(mat, vizinho);
}

bool eh_furavel(matchar &mat, Par p){
    int cont = 0;
    if(!mat.equals(p, PAREDE))
        return false;

    for(auto &viz : getNeib(p)){
        if(mat.equals(viz, PAREDE))
            cont++;
    }

    if(cont >= 3) return true;
    else return false;
}

int sortear(int x){
    return rand() % x;
}

void furarI(matchar &mat, vector<Par> &pilha){
    mat.get(Par(1, 1)) = ABERTO;
    pilha.push_back(Par(1, 1));
    while(!pilha.empty()){
        vector<Par> furaveis;
        for(auto viz : getNeib(pilha.back()))
            if(eh_furavel(mat, viz))
                furaveis.push_back(viz);

        if(furaveis.size() == 0){
            pilha.pop_back();
            showMat(mat, pilha);
            ed_show();
        }else{
            Par sortudo = furaveis[sortear(furaveis.size())];
            mat.get(sortudo) = ABERTO;
            pilha.push_back(sortudo);
            showMat(mat, pilha);
            ed_show();
        }
    }
}


bool findPath(matchar& mat, Par inicio, Par final, Par atual){
    if(atual == final){
        mat.get(atual) = CAMINHO;
        showMat(mat, inicio, final, atual);
        return true;
    }
    if(!mat.is_inside(atual))
        return false;
    if(mat.get(atual) != ABERTO)
        return false;

    mat.get(atual) = EMBUSCA;
    showMat(mat, inicio, final, atual);

    for(Par vizinho : shuffle(getNeib(atual))){
        if(findPath(mat, inicio, final, vizinho)){
            mat.get(atual) = CAMINHO;
            showMat(mat, inicio, final, atual);
            return true;
        }
    }
    mat.get(atual) = ABATIDO;
    showMat(mat, inicio, final, atual);
    return false;
}

#include <cstdlib>
#include <ctime>
int main(){
    srand(time(NULL));
    matchar mat(15, 20, PAREDE);

    vector<Par> pilha;
    furarI(mat, pilha);//chama a função recursiva

    mat_draw(mat);
    ed_show();

    Par inicio = mat_get_click(mat, "digite o local de inicio");
    Par final = mat_get_click(mat, "digite o local de fim");
    mat_draw(mat);
    ed_show();
    findPath(mat, inicio, final, inicio);

    ed_lock();//impede que termine abruptamente
    return 0;
}


