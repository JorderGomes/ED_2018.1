#include <lib/pen.h>

void trigo(Pen &p, int lado){
    float ang = 40;
    float dec = 0.35;
    if(lado < 1){
        return;
    }
    p.setColor ( sf :: Color :: Yellow);

    for(int i = 0; i < 4; i++){
        p.walk(lado);
        p.right(ang);
        trigo(p, lado * dec);
        p.left(ang * 2);
        trigo(p, lado * dec);
        p.right(ang);
    }
    p.walk(-lado * 4);
}
void fractal2(){
    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 595);
    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(50);
    trigo(p, 100);
    //espera clicar no botao de fechar
    p.wait();
}
// Trigo
int main(){
    fractal2();
    return 0;
}
