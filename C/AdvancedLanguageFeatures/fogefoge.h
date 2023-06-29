#ifndef _FOGEFOGE_H_
#define _FOGEFOGE_H_

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou();
void move(char direcao);
void explodepilula();
void explodepilula2(int x, int y, int somax, int somay, int qtd);
int ehdirecao(char direcao);
void fantasmas();

#endif
