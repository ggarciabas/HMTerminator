/*
	Giovanna Garcia Basilio : ggarciabas@gmail.com
	Gian Maurício Fritsche : gian.fritsche@gmail.com
*/

#include "include.h"
#include "tela.h"
#include "mapa.h"
#include "input.h"
#include "jogador.h"

// primeira e única declaração - EXTERN
CELULA mapa_jogo[LARGURA_MAPA][ALTURA_MAPA]; 
int mapa_tela_x=0; // primeira posição em relação ao mapa_jogo
int mapa_tela_y=15; // para tela (0, 0) qual posição (x, y) do mapa_jogo está sendo impressa
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
struct termios old, new;
int j_tela_mapa_x;
int j_tela_mapa_y;

int main () {

	pthread_t t_ler_comando;

	j_tela_mapa_x = j_tela_mapa_y = 0; // primeira pos 

	limpar_tela			();
	borda_principal		();
	criar_jogo_teste 	();
	imprimir_mapa		();
	atualizar_posicao	(mapa_tela_x+j_tela_mapa_x, mapa_tela_y+j_tela_mapa_y); // atualizando posicao

	pthread_create 		(&t_ler_comando, NULL, ler_comando, NULL);

	pthread_join 		(t_ler_comando, 0);

	ponto_tela			(1, 26); // para finalizar

	// for (int i = 0; i < LARGURA_MAPA; ++i)
	// {
	// 	for (int j = 0; j < ALTURA_MAPA; ++j)
	// 	{
	// 		printf("[%d]", mapa_jogo[i][j].letra);
	// 	}
	// 	printf("\n");
	// }

	pthread_exit 		(NULL);

	return 0;
}