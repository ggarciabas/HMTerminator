/*
	Giovanna Garcia Basilio : ggarciabas@gmail.com
	Gian Maurício Fritsche : gian.fritsche@gmail.com
*/

#include "include.h"
#include "tela.h"
#include "mapa.h"

// primeira e única declaração - EXTERN
CELULA mapa_jogo[50][50]; 
int mapa_tela_x=0; // primeira posição em relação ao mapa_jogo
int mapa_tela_y=0; // para tela (0, 0) qual posição (x, y) do mapa_jogo está sendo impressa

int main () {

	limpar_tela			();
	borda_principal		();
	criar_jogo_teste 	();
	imprimir_mapa		();

	ponto_tela(1,26); // para finalizar

	return 0;
}