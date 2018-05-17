#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "libs/sftext.h"
#include <stack>
using namespace std;

struct Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();
    }

    Ambiente(const Ambiente& other):
        texto(other.texto)
    {
        this->cursor = this->texto.begin();
        for(auto it = other.texto.begin(); it != other.cursor; it++)
            this->cursor++;
    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == cursor)
                ss << "|";
            ss << (*it); ///
        }
        if(cursor == texto.end())
            ss << "|";
        return ss.str();
    }
};


struct eco{
    list<Ambiente> ec;
    list<Ambiente>::iterator atual;
};


int main(){

    eco e;
    e.ec.push_back(Ambiente ());
    e.atual = e.ec.begin();

    e.ec.push_back(*e.atual);
    e.atual = e.ec.end();
    e.atual--;
    e.atual->texto.push_back('a');

    e.ec.push_back(*e.atual);
    e.atual = e.ec.end();
    e.atual--;
    e.atual->texto.push_back('m');

    e.ec.push_back(*e.atual);
    e.atual = e.ec.end();
    e.atual--;
    e.atual->texto.push_back('o');

    e.ec.push_back(*e.atual);
    e.atual = e.ec.end();
    e.atual--;
    e.atual->texto.push_back('r');

    e.ec.push_back(*e.atual);
    e.atual = e.ec.end();
    e.atual--;
    e.atual->cursor = e.atual->texto.end();


    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.control && (event.key.code == sf::Keyboard::Z)){
                    if(e.atual-- != e.ec.begin()) e.atual--;
                    cout << "control z" << endl;
                }
                else if(event.key.control && (event.key.code == sf::Keyboard::R)){
                    if(e.atual++ != e.ec.end()) e.atual++;
                    cout << "control r" << endl;
                }
                else if((event.key.code >= sf::Keyboard::A) && (event.key.code <= sf::Keyboard::Z)){
                    char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                    e.ec.push_back(*e.atual);
                    e.atual = e.ec.end();
                    e.atual--;
                    e.atual->texto.insert(e.atual->cursor, tecla);
                    cout << tecla << endl;
                }
                else if((event.key.code == sf::Keyboard::Return)){
                    cout << "enter" << endl;
                }
                else if((event.key.code == sf::Keyboard::Space)){
                    e.ec.push_back(*e.atual);
                    e.atual = e.ec.end();
                    e.atual--;
                    e.atual->texto.insert(e.atual->cursor, ' ') ;
                    cout << "espaco" << endl;
                }
                else if(event.key.code == sf::Keyboard::BackSpace){
                    e.ec.push_back(*e.atual);
                    e.atual = e.ec.end();
                    e.atual--;
                    e.atual->texto.erase(e.atual->cursor++ , e.atual->cursor--);
                    cout << "backspace" << endl;
                }
                else if(event.key.code == sf::Keyboard::Delete){

                    e.ec.push_back(*e.atual);
                    e.atual = e.ec.end();
                    e.atual--;
                    e.atual->cursor++;
                    e.atual->texto.erase(e.atual->cursor++ , e.atual->cursor--);
                    cout << "delete" << endl;
                }
                else if(event.key.code == sf::Keyboard::Left){
                    e.atual->cursor--;
                }
                else if(event.key.code == sf::Keyboard::Right){
                    e.atual->cursor++;
                }
            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, e.atual->toString(), sf::Color::White, 30));
        janela.display();
    }
    return 0;
}




