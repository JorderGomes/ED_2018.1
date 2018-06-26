#include <iostream>
///

using namespace std;

struct  Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }


};

struct SList{

    Node* head;

    SList(){
        this->head = nullptr;
    }

    void push_front(int value){ /// FUNCIONA,  CÓDIGO DAVID
        //this->head = new Node(value, this->head);
        Node * node = new Node(value);
        node->next = head;
        this->head = node;
    }

    void pop_front(){ /// FUNCIONA,  CÓDIGO DAVID
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }

    void push_back(int value){ ///  FUNCIONA,  CÓDIGO DAVID
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = head;
        while(node->next != nullptr)
            node = node->next;

        node->next = new Node(value);
    }

    Node * rpush_back(Node * node ,int value){ /// PUSH_BACK RECURSIVO /  FUNCIONA
        if(node->next == nullptr){
            node->next = new Node (value);
            return node->next;
        }
        return rpush_back(node->next, value);
   }

    void Rpush_back(int value){ /// COMPLEMENTAR rpush_back() FUNCIONA
        rpush_back(head, value);
    }

    void pop_back(){ /// FUNCIONA, CÓDIGO DAVID
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

    void show(){ /// FUNCIONA, CÓDIGO DAVID
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }

    void _rshow(Node * node){
        if(node == nullptr)
            return;
        _rshow(node->next);
        cout << node->value << " ";
    }

    void rshow(){ /// FUNCIONA, CÓDIGO DAVID
        _rshow(head);
        cout << endl;
    }

    Node * _rpop_back(Node * node){/// FUNCIONA , CÓDIGO DAVID
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
    }

    void _Rpop_back(){ /// COMPLEMENTAR _rpop_back() FUNCIONA
        _rpop_back(head);
    }


    Node * _remove(Node * node, int value){ /// CÓDIGO DAVID
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _remove(node->next, value);
    }

    void _Remove(int value){ /// COMPLEMENTAR _remove /
        _remove(head , value);
    }

    void iremove(int value){ /// NOSSO REMOVE INTERATIVO / FUNCIONA
        auto node = head;
        if(node == nullptr)
            return ;
        //se ele for o primeiro da lista
        if(head->value == value){
            auto aux = head;
            head = head->next;
            delete aux;
            //return head;
        }
        while(node->next != nullptr){
            if(node->next->value == value){
                auto aux = node->next;
                node->next = node->next->next;
                delete aux;
                //return node->next;
            }
            node = node->next;
        }
        //return node;
    }

    void Remove(int value){ /// COMPLEMENTAR IREMOVE
        iremove(value);
    }

    void inserir_ordenado(int value){/// CÓDIGO DO DAVID / SEM RECURSÃO / FUNCIONA
        auto node = head;
        if(head == nullptr || head->value > value){
            this->head = new Node(value, head);
            return;
        }
        while ( node->next != nullptr && node->next->value < value){
            node = node->next;
        }
        node->next = new Node(value, node->next);
    }

    int somar(Node * node){ /// SOMAR DO DAVID
        if(node == nullptr){
            return 0;
        }
        return node->value += somar(node->next);
    }

    int Somar(){ /// COMPLEMENTAR DO SOMAR
        return somar(head);
    }

    int rmin(Node * node){/// MINIMO DO DAVID
        if(node->next == nullptr)
            return node->value;

        return std::min(node->value, rmin(node->next));
    }

    int Rmin(){/// COMPLEMENTAR DO RMIN DO DAVID
        return rmin(head);
    }

    Node * Inserir_ordenado(int value, Node * node){/// CÓDIGO DO DAVID / SEM RECURSÃO / FUNCIONA
        node = head;

        if(head->next != nullptr && node->next->value < value){
            Inserir_ordenado(value, node->next);

        }
        if(head == nullptr || head->value > value){
            this->head = new Node(value, head);
            return nullptr;
        }
    }

    void _Inserir_ordenado(int value){
        Inserir_ordenado(value, head);
    }

    int _somar(Node * node){ /// NOSSO SOMAR FUNCIONA
        int value = 0;
        while (node != nullptr) {
            value  += node->value;
            node = node->next;
        }
        return value;
    }

    int _Somar(){ /// COMPLEMENTAR DO SOMAR FUNCIONA
        return _somar(head);
    }

    int min(Node * node){ /// NOSSO MINIMO FUNCIONA
        int min = node->value;
        while (node != nullptr) {
            if(node->value < min)
                min = node->value;
            node = node->next;
        }
        return min;
    }
    int Min(){ /// COMPLEMENTAR DO MIN FUNCIONA
        return min(head);
    }

    ///INSERE ELEMNETO NA LISTA ORDENADA INTERATIVO NOSSO
    void insert_iterativo(int value){
        if(head == nullptr || (head->value > value)){
            head = new Node(value, head);
            return;
        }

        auto node = head;
        while(true){
            if(node->next == nullptr || (node->next->value > value)){
                node->next = new Node(value, node->next);
                break;
            }
            node = node->next;
        }


    }


    Node * deletar_tudo(Node * node){ /// DELETAR TUDO NOSSO
        if(node == nullptr)
            return nullptr;
        deletar_tudo(node->next);
        delete node;
        return nullptr;
    }

    void rdeletar_tudo(){
        head = deletar_tudo(head);
    }

    Node * arrancarabo(Node * node , int value){
        if(node == nullptr)
            return nullptr;
        node->next = arrancarabo(node->next, value);
        if(node->next == nullptr){
            if(node->value != value){
                delete node;
                return nullptr;
            }
            else{
                return node;
            }
        }
        return node;
    }

    void Arrancarabo(int alue){
        arrancarabo(head, alue);
    }


    Node * arrancaventa(Node * node , int value){
        return nullptr;
    }


};


int main(){
    SList lista;

    lista.insert_iterativo(3);
    lista.insert_iterativo(180);
    lista.insert_iterativo(6);
    lista.insert_iterativo(1);
    cout << "Mostrando a lista " << endl;
    lista.show();

    /// MINÍMO NOSSO
    cout << "Minimo da lista " << endl;
    cout << lista.Min() << endl;

    /// SOMAR NOSSO
    cout << "Soma dos valores " << endl;
    cout << lista._Somar() << endl;

    /// REMOVER NOSSO
    cout << "Vamos remover o 3 " << endl;
    lista.Remove(3);
    lista.show();


    /// ARRANCA RABO
    cout << "Vamos remover todos depois do 6" << endl;
    lista.Arrancarabo(6);
    lista.show();

    /// Push_back
    cout << "Vamos adicionar ao final os numeros 5 2 6 8 " << endl;
    lista.Rpush_back(5);
    lista.Rpush_back(2);
    lista.Rpush_back(6);
    lista.Rpush_back(8);
    lista.show();

    cout << "Vamos adicionar os numeros 180 3 56 em ordem cresente" << endl;
    lista.insert_iterativo(180);
    lista.insert_iterativo(3);
    lista.insert_iterativo(56);
    lista.show();



    /// deletar tudo nosso
    cout << "Apagar a lista inteira" << endl;
    lista.rdeletar_tudo();
    lista.show();


    /// MOSTRAR LISTA DO DAVID
   // lista.show();
    return 0;
}
