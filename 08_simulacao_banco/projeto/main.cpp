#include <random>
#include "Libs/pintor.h"

#include <vector>
#include "Libs/pintor.h"
#include <algorithm>
#include <time.h>
#include <stdlib.h> //funcao srand

using namespace std;

//Cada dia possui 6 horas de trabalho
//60 minutos x 6 horas = 360 minutos
//cada minuto eh um turno.
const int TURNOS_DIA = 360;

//A quantidade máxima de caixas não pode ser alterada.
const int MAX_CAIXAS = 10;

//Esse valor determina o quanto o banco gasta  por caixa por dia de trabalho
const int CUSTO_CAIXA_DIA = 100;

//numero de simulacoes de teste para cada caixa
const int N_EXEC_TESTE = 100;

//gera um numero entre min e max, [min, max]
int rand_mm(int min, int max){
    static int init = 1;
    if(init){
        init = 0;
        srand(time(NULL));
    }
    return rand() % (max - min + 1) + min;
}

struct Param {
    int min_pac;
    int max_pac;
    int min_doc;
    int max_doc;
    int min_cli;
    int max_cli;
    int ncaixas;
};

int minha_simulacao(Param p){
    int lucro = 0;
    //Pintor pintor;
    int min_pac = p.min_pac, max_pac = p.max_pac;
    int min_doc = p.min_doc, max_doc = p.max_doc;
    int min_cli = p.min_cli, max_cli = p.max_cli;
    // Tempo da simulação
    const unsigned int tempo = TURNOS_DIA;
    const unsigned int numCaixas = p.ncaixas;

    // Estruturas para representar os clientes no caixa e na fila
    std::vector<Cliente*> caixa(numCaixas);
    std::list<Cliente*> fila;
    std::list<Cliente*> fila_saida;

    for (unsigned int i = 0; i < tempo; i++){ ///  NESTE FOR OCORRE TODO O ALGORITIMO
      //  pintor.desenhar(caixa, fila, 10);

        int qtd = rand_mm(min_cli, max_cli);  /// Gerar aleatoriamente n clientes
        if(fila.size() <= 180) /// Se ainda estiver espaço no banco:
            for(int i = 0; i < qtd; i++) /// insira os clientes na fila de atndimento
                fila.push_back(new Cliente(rand_mm(min_pac, max_pac), rand_mm(min_doc, max_doc)));


        for(auto it = fila.begin() ; it != fila.end();){ /// Para cada cliente na FILA de atendimento faça:
            if((*it)->paciencia == 0){ /// Se cliente está sem paciência então:
                fila_saida.push_back(*it);
                it = fila.erase(it); /// Remover cliente da FILA e colocálo na fila de saída
            }
            else{
                (*it)->paciencia--; /// Decrementar a paciencia do cliente
                it++;
            }
        }


        for(int i = 0; i < (int) numCaixas; i++){
            if(caixa[i] != nullptr){
                if( caixa[i]->documentos > 0 ){
                    caixa[i]->documentos--;
                    lucro++;
                }else{
                    fila_saida.push_back(caixa[i]);
                    caixa[i] = nullptr;
                }
            }
            else{
                if(fila.size() != 0){
                    caixa[i] = fila.front();
                    fila.pop_front();
                }
            }
        }

        while(!fila_saida.empty()){
            delete fila_saida.back();
            fila_saida.pop_back();
        }
    }

    return lucro - p.ncaixas * 100;
}



int main (){

    vector<int> lucro_medio(10);

    for(int i = 0;i <= 9 ;i++){
       lucro_medio[i] = 0;
       for(int j = 0; j < 100; j++)
            lucro_medio[i] += minha_simulacao(Param{1, 60, 1, 10, 0,  1, i});
       lucro_medio[i] = lucro_medio[i]/100;
    }
    for(auto elem : lucro_medio)
        cout << elem << " ";
    cout << endl;

    int imaior = 0;
    for(int i = 0; i <= 9; i++)
        if(lucro_medio[i] > lucro_medio[imaior])
            imaior = i;

    cout << imaior << endl;

    return 0;
}
