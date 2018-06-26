#include <lib/pen.h>
void embuarvore(Pen& p, int lado){
    float ang = 35;
    float dec = 0.7;
    lado -= (p.rand() % 7 - 3);
    if(lado < 10){
        p.setColor(sf::Color::Red);
        for(int i = 0; i < rand() % 15; i++){
        p.circle(i);
        }
        return;
    }

    p.walk(lado);
    p.right(ang);
    embuarvore(p, lado * dec);
    p.left(ang);
    embuarvore(p, lado * dec);
    p.left(ang);
    embuarvore(p, lado * dec);
    p.right(ang);
    p.setColor(sf::Color::Green);
    p.walk(-lado);
}
void fractal(){
    Pen p(800, 600);
    p.setThickness(2);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 500);
    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(0);
    embuarvore(p, 70);
    //triangulo(p, 400);
    //espera clicar no botao de fechar
    p.wait();
}
int main(){
    fractal();
    return 0;
}
