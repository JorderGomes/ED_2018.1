#include "libs/ed_base.h"
#include "libs/ed_mat.h"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <algorithm>

using namespace std;

const char PAREDE = 'k';
const char ABERTO = 'w';
const char EMBUSCA = 'y';
const char CAMINHO = 'b';
const char ABATIDO = 'm';

void showMat(matchar& mat, Par inicio ,vector<Par> pilha,  Par fim){
    mat_draw(mat);
    for(Par par : pilha){
        mat_focus(par, 'c');
    }
    if(pilha.size() > 0){
        mat_focus(pilha.back(), 'k');
    }
    mat_focus(inicio, 'g');
    mat_focus(fim, 'r');
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
    return vizinhos;
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


int countOpen(matchar &mat, Par par){
    int cont = 0;
    for(auto vizinho : getNeib(par))
        if(mat.equals(vizinho, PAREDE))
            cont++;

    return cont;
}

vector<Par> shuffle(vector<Par> vet){
    std::random_shuffle(vet.begin(), vet.end());
    return vet;
}

void furar(matchar &mat, Par par){ // RECURSIO FURAR
    if(!mat.equals(par, PAREDE) || countOpen(mat, par) > 1)
        return;
    mat.get(par) = ABERTO;
    for(Par vizinho : shuffle(getNeib(par)))
        furar(mat, vizinho);
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



bool findPath(matchar& mat, Par inicio, Par final){ // INTERATIVO ACHAR CAMINHO
    vector<Par> pilha;
    pilha.push_back(inicio);
    mat.get(inicio) = EMBUSCA;
    while(pilha.size() != 0){
        Par topo = pilha.back();
        if(topo == final)
            return true;

        vector<Par> viz_abertos;
        for(Par par : getNeib(topo)){
            if(mat.get(par) == ABERTO ){
                viz_abertos.push_back(par);
                showMat(mat, inicio, pilha, final);
                ed_show();
            }
        }
        if(viz_abertos.size() == 0 ){
            pilha.pop_back();
            showMat(mat, inicio, pilha, final);
            ed_show();
        }

        Par escolhido = viz_abertos[rand() % viz_abertos.size()];
        mat.get(escolhido) = EMBUSCA;
        pilha.push_back(escolhido);

    }
    return false;
}

#include <cstdlib>
#include <ctime>
int main(){
    srand(time(NULL));
    matchar mat(15, 20, PAREDE);
    vector<Par> pilha;
    //furar(mat, Par(1, 1));//chama a função recursiva
    furarI(mat, pilha);//chama a
    //furarff(mat);


    mat_draw(mat);
    ed_show();

    Par inicio = mat_get_click(mat, "digite o local de inicio");
    Par final = mat_get_click(mat, "digite o local de fim");

    mat_draw(mat);
    ed_show();

    findPath(mat, inicio, final);

    ed_lock();//impede que termine abruptamente
    return 0;
}


