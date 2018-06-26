#include <iostream>

using namespace std;


struct Vetor{
    int * _data;//bloco de dados
    int _capacidade;//tamanho maximo do vetor
    int _size; //quantos elementos estao inseridos

    Vetor(int capacidade){
        this->_capacidade = capacidade;
        this->_size = 0;
        this->_data = new int[capacidade];//retorno zerado
    }

    void push_back(int value){ // CORRETO
        if(this->_size == this->_capacidade)
            return;

        this->_data[this->_size] = value;
        this->_size += 1;
    }

    void pop_back(){ // CORRETO
        if(this->_size == 0)
            return;

        this->_data[_size] = 0;
        this->_size -= 1;
    }


    int& at(int indice){ // CORRETO
        return this->_data[indice];
    }

    int& front(){ // CORRETO
        return this->_data[0];
    }

    int& back(){ // CORRETO
        return this->_data[this->_size - 1];
    }

    int * begin(){ // CORRETO
        return &this->_data[0];
    }

    int * end(){ // CORRETO

        return &this->_data[this->_size];
    }

    int size(){ // CORRETO
    return this->_size;
    }

    int capacity(){ // INCORRETO
        return this->_capacidade;
    }

    void reserve(int capacity){ // ANALISAR
        //salva o bloco antigo em algum lugar
        int * _data2;//bloco de dados
        for(int i = 0; i < this->_size; i++){
          _data2[i] =  this->_data[i];
        }

        //pede uma novo bloco de dados
        if(capacity < this->_capacidade)
            return;

        this->_capacidade = capacity;

    }


};

#include <vector>
int main()
{
    // TESTES VECTOR CRIADOS PELO DAVID SENA



    Vetor pivet(5);
    pivet.push_back(4);
    pivet.push_back(2);
    pivet.push_back(7);
    cout << pivet.at(2);
    pivet.at(2) = 9;

    return 0;
}
