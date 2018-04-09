#include <lib/pen.h>

void quadrado(Pen &p, int lado){
    auto ang = p.getHeading();
    p.down();
    p.setHeading(0);
    for(int i = 0; i < 4; i++){
        p.walk(lado);
        p.right(90);
    }
    p.setHeading(ang);
    p.up();
}
void ebua(Pen &p, int lado){
    float ang2 = 45;
    float dec = 0.89;
    if(lado < 10){
        return;
    }
    p.walk(lado);
    p.right(ang2);
    quadrado(p, lado * 0.3);
    ebua(p, lado * dec);
}
void fractal3(){   
    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(300, 100);
    //faz o pincel apontar pra direita
    p.setHeading(0);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(50);
    p.up();
    ebua(p, 250);
    //espera clicar no botao de fechar
    p.wait();
}
// quadrado
int main(){
    fractal3();
    return 0;
}
