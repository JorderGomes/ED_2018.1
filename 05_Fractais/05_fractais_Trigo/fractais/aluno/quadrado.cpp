#include <lib/pen.h>

void quadrado(Pen &p, int lado){

    for(int i = 0; i < 4;i++){
        p.walk(lado);
        p.right(90);
    }

}

void quadrados(Pen &p, int lado){
    float ang = 90;
    float ang2 = 45;
    float dec = 6;

    if(lado < 15){
        return;
    }
    p.up();

    p.walk(lado);

    p.down();

    quadrado(p,lado);

    p.walk(lado - dec);

    p.right(ang2);



    quadrados(p, lado - dec);

    //p.left(2 * ang);
    //quadrados(p, lado - dec);

    //p.right(ang);
    //p.walk(- lado);
    //}
}

void fractal3(){

    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 100);
    //faz o pincel apontar pra direita
    p.setHeading(0);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(30);

    quadrados(p, 120);
    //espera clicar no botao de fechar
    p.wait();
}

// quadrado
int main(){
    fractal3();
    return 0;
}
