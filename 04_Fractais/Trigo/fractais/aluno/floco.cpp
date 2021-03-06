#include <lib/pen.h>
void floco(Pen &p, int lado){

    float ang = 72;
    float dec = 0.35;


    if(lado <= 5){
        return;
    }
    p.walk(lado);

    for(int i = 0; i < 5; i++){
        p.right(ang);
        floco(p, lado * dec);
    }
    p.walk(- lado);
}
void fractall(){
    Pen p(800, 800);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 400);
    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(0);
    for(int i = 0; i < 5; i++){
        floco(p, 170);
        p.right(72);
    }
    //espera clicar no botao de fechar
    p.wait();
}
int main_floco(){
    fractall();
    return 0;
}
