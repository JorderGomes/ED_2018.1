#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void mostrar( list<int> vet){
    for(auto elemento : vet){
        cout << elemento << " ";
    }
    cout << endl;
}

int main(){
    int qtd = 0 , esp = 0 ;
    cin >> qtd >> esp;
    list<int> vet;

    for(int i = 0; i < qtd; i++  ){
        vet.push_back( i + 1 );
    }
    for(auto num : vet){
        cout << num << ", ";
    }


    while(vet.front() != esp){
        vet.push_back(vet.front());
        vet.pop_front();
    }

    while(vet.size() != 1){
        mostrar(vet);

        vet.push_back(vet.front());
        vet.pop_front();

        vet.pop_front();
        mostrar(vet);
    }



    return 0;
}
