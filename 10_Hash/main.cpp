#include <iostream>
#include <map>//arvore TreeMap
#include <unordered_map> //arvore HashMap
#include <set> //arvore TreeSet
#include <unordered_set>//hash HashSet
#include <vector>
#include <list>
#include <algorithm>

using namespace std;



struct Elem {
    int key;
    int value;
   /// Marcador marcador;

    Elem(int key = 0, int value = 0){
        this->key = key;
        this->value = value;
    }

    bool operator ==(Elem other){
        return key == other.key;
    }
    friend ostream& operator << (ostream& os, Elem e){
        os << e.key;
        return os;
    }
};

struct HashLista{
    Elem * vet;
    int capacity;
    int size;

    HashLista(int capacity){
        vet = new Elem [capacity];
        this->capacity = capacity;

    }

    bool insert(Elem elem){
        int base = elem.key % capacity;
        if(vet[base].value == 0){
            vet[base].value =  elem.value;
            return true;
        }
        while(vet[base].value != 0){
            vet[base + 1 % capacity];
        }
        vet[base].value =  elem.value;
    }

    Elem busca(Elem bus){
        int base = bus.key % capacity;
        while(vet[base].value != 0){
            if(vet[base].value == bus.value)
                return vet[base];
            vet[base + 1 % capacity];
        }
        return NULL;
    }

    bool remove(Elem elem){
        elem = busca(elem);
        int base = elem.key % capacity;
        base += 1;
        while(vet[base].value != 0 ){
            vet[base] = vet[base += 1];
        }

    }

    /*

*/
};
int main(){
    HashLista hl(10);
    Elem elem (2);
    hl.insert(elem);
    Elem e = hl.busca(elem);
    cout << e.value;

    return 0;
}
