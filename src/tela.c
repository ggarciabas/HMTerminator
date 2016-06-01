
#include "tela.h"
#include "include.h"
#include "mapa.h"
#include "jogador.h"

void mover_acima () {
	// Verificar se ultrapassou o limite mapa-tela, pois assim deve-se andar no mapa macro
	if ((j_tela_mapa_y-1/*mover_acima*/) < 0) { 
		// Verificar se pode andar dentro do mapa maior,
		// 		verificar se não ultrapassou o limite do mapa
		if ((mapa_tela_y-1/*mover_acima*/) >= 0) { // verificando se a nova posição do mapa é válida 
			mapa_tela_y--; // subiu
			imprimir_mapa		(); // atualizando mapa
			atualizar_posicao	(mapa_tela_x+j_tela_mapa_x, mapa_tela_y+j_tela_mapa_y); // atualizando posicao
		} else {
			// Log	
		}
	} else {
		// Pode posicionar acima sem problemas
		j_tela_mapa_y--; // subiu
		atualizar_posicao		(mapa_tela_x+j_tela_mapa_x, mapa_tela_y+j_tela_mapa_y); // atualizando posicao
	}
}

void mover_abaixo () {
	// Verificar se ultrapassou o limite mapa-tela, pois assim deve-se andar no mapa macro
	if ((j_tela_mapa_y+1/*mover_abaixo*/) >= ALTURA_MAPA_TELA) { 
		// Verificar se pode andar dentro do mapa maior,
		// 		verificar se não ultrapassou o limite do mapa
		if ((mapa_tela_y+j_tela_mapa_y/*mover_abaixo*/) < ALTURA_MAPA-1) { // verificando se a nova posição do mapa é válida 
			mapa_tela_y++; // desceu
			imprimir_mapa		(); // atualizando mapa
			atualizar_posicao	(mapa_tela_x+j_tela_mapa_x, mapa_tela_y+j_tela_mapa_y); // atualizando posicao
		} else {
			// Log	
		}
	} else {
		// Pode posicionar acima sem problemas
		j_tela_mapa_y++; // desceu
		atualizar_posicao		(mapa_tela_x+j_tela_mapa_x, mapa_tela_y+j_tela_mapa_y); // atualizando posicao
	}
}

void mover_direita () {
	// Verificar se ultrapassou o limite mapa-tela, pois assim deve-se andar no mapa macro
	if ((j_tela_mapa_x+1/*mover_abaixo*/) >= LARGURA_MAPA_TELA) { 
		// Verificar se pode andar dentro do mapa maior,
		// 		verificar se não ultrapassou o limite do mapa
		if ((mapa_tela_x+j_tela_mapa_x/*mover_abaixo*/) < LARGURA_MAPA-1) { // verificando se a nova posição do mapa é válida 
			mapa_tela_x++; // foi para direita
			imprimir_mapa		(); // atualizando mapa
			atualizar_posicao	(mapa_tela_x+j_tela_mapa_x, mapa_tela_y+j_tela_mapa_y); // atualizando posicao
		} else {
			// Log	
		}
	} else {
		// Pode posicionar acima sem problemas
		j_tela_mapa_x++; // foi para direita
		atualizar_posicao		(mapa_tela_x+j_tela_mapa_x, mapa_tela_y+j_tela_mapa_y); // atualizando posicao
	}
}

void mover_esquerda () {
	// Verificar se ultrapassou o limite mapa-tela, pois assim deve-se andar no mapa macro
	if ((j_tela_mapa_x-1/*mover_acima*/) < 0) { 
		// Verificar se pode andar dentro do mapa maior,
		// 		verificar se não ultrapassou o limite do mapa
		if ((mapa_tela_x-1/*mover_acima*/) >= 0) { // verificando se a nova posição do mapa é válida 
			mapa_tela_x--; // foi para esquerda
			imprimir_mapa		(); // atualizando mapa
			atualizar_posicao	(mapa_tela_x+j_tela_mapa_x, mapa_tela_y+j_tela_mapa_y); // atualizando posicao
		} else {
			// Log	
		}
	} else {
		// Pode posicionar acima sem problemas
		j_tela_mapa_x--; // foi para esquerda
		atualizar_posicao		(mapa_tela_x+j_tela_mapa_x, mapa_tela_y+j_tela_mapa_y); // atualizando posicao
	}
}

void atualizar_posicao (int x, int y) {
	pthread_mutex_lock(&m);
	{
		ponto_tela		(LARGURA_TELA-12, INICIO_TELA+3);
		printf 			("POS.:(%02d,%02d)", x+1, y+1);
	}
	pthread_mutex_unlock(&m);
}

void limpar_tela () {
	system(COMANDO_LIMPAR_TELA);
}

void borda_principal () {
	int i;

	ponto_tela	(INICIO_TELA, INICIO_TELA);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela	(LARGURA_TELA, INICIO_TELA);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela	(INICIO_TELA, ALTURA_TELA);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela	(LARGURA_TELA, ALTURA_TELA);
	printf 		("%c", BORDA_DIAGONAL);

	for (i = INICIO_TELA+1; i < ALTURA_TELA; ++i)
	{
		ponto_tela	(INICIO_TELA, i);
		printf 		("%c", BORDA_VERTICAL);
		ponto_tela 	(LARGURA_TELA, i);
		printf 		("%c", BORDA_VERTICAL);
	}

	for (i = INICIO_TELA+1; i < LARGURA_TELA; ++i)
	{
		ponto_tela 	(i, INICIO_TELA); 
		printf 		("%c", BORDA_HORIZONTAL);
		ponto_tela 	(i, ALTURA_TELA);
		printf 		("%c", BORDA_HORIZONTAL);
	}

	for (i = INICIO_TELA+1; i < ALTURA_TELA-4; ++i) {
		ponto_tela 	(LARGURA_TELA-13, INICIO_TELA+i);
		printf 		("%c", BORDA_VERTICAL);
	}

	ponto_tela 	(LARGURA_TELA-13, INICIO_TELA+1);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA_TELA-13, INICIO_TELA+4);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA_TELA, INICIO_TELA+1);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA_TELA, INICIO_TELA+4);
	printf 		("%c", BORDA_DIAGONAL);

	ponto_tela 	(LARGURA_TELA-13, INICIO_TELA+7);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA_TELA, INICIO_TELA+7);
	printf 		("%c", BORDA_DIAGONAL);

	ponto_tela 	(LARGURA_TELA-13, INICIO_TELA+8);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA_TELA, INICIO_TELA+8);
	printf 		("%c", BORDA_DIAGONAL);

	ponto_tela 	(LARGURA_TELA-13, INICIO_TELA+20);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA_TELA, INICIO_TELA+20);
	printf 		("%c", BORDA_DIAGONAL);

	ponto_tela 	(INICIO_TELA, INICIO_TELA+21);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA_TELA, INICIO_TELA+21);
	printf 		("%c", BORDA_DIAGONAL);

	for (i = INICIO_TELA; i < 13; ++i) {
		ponto_tela 	(LARGURA_TELA-i, INICIO_TELA+1);
		printf 		("%c", BORDA_HORIZONTAL);

		ponto_tela 	(LARGURA_TELA-i, INICIO_TELA+4);
		printf 		("%c", BORDA_HORIZONTAL);

		ponto_tela 	(LARGURA_TELA-i, INICIO_TELA+7);
		printf 		("%c", BORDA_HORIZONTAL);

		ponto_tela 	(LARGURA_TELA-i, INICIO_TELA+8);
		printf 		("%c", BORDA_HORIZONTAL);

		ponto_tela 	(LARGURA_TELA-i, INICIO_TELA+20);
		printf 		("%c", BORDA_HORIZONTAL);
	}

	for (i = INICIO_TELA+1; i < LARGURA_TELA; ++i) {
		ponto_tela 	(i, ALTURA_TELA-3);
		printf 		("%c", BORDA_HORIZONTAL);
	}

	ponto_tela		(LARGURA_TELA-12, INICIO_TELA+2);
	printf 			("HORA: %02d:%02d", 10, 15);
	ponto_tela		(LARGURA_TELA-12, INICIO_TELA+3);
	printf 			("POS.:(%02d,%02d)", 10, 15);
	ponto_tela		(LARGURA_TELA-12, INICIO_TELA+5);
	printf 			("    GRANA");
}

void ponto_tela (int x, int y) // coluna (x) por linha (y)
{
   printf("%c[%d;%df",0x1B,y,x);
   fflush(stdout);
}

void imprimir_mapa () {
	int i, j;

	pthread_mutex_lock(&m);
	{
		for (j = INICIO_MAPA_TELA; j <= ALTURA_MAPA_TELA; ++j) {
			for (i = INICIO_MAPA_TELA; i <= LARGURA_MAPA_TELA; ++i) {
				ponto_tela		(INICIO_TELA+1+((i-1)*5), INICIO_TELA+1+((j-1)*4));
				printf 			("%c%c%c%c%c", BORDA_MAPA_PONTO, BORDA_MAPA_PONTO, BORDA_MAPA_PONTO, BORDA_MAPA_PONTO, BORDA_MAPA_PONTO);

				ponto_tela		(INICIO_TELA+1+((i-1)*5), INICIO_TELA+1+((j-1)*4)+1);
				printf 			("%c %c %c", BORDA_MAPA_2PONTOS, mapa_jogo[i+(mapa_tela_x-1)][j+(mapa_tela_y-1)].letra, BORDA_MAPA_2PONTOS);

				ponto_tela		(INICIO_TELA+1+((i-1)*5), INICIO_TELA+1+((j-1)*4)+2);
				printf 			("%c%03.0lf%c", BORDA_MAPA_2PONTOS, mapa_jogo[i+(mapa_tela_x-1)][j+(mapa_tela_y-1)].porcentagem, BORDA_MAPA_2PONTOS);

				ponto_tela		(INICIO_TELA+1+((i-1)*5), INICIO_TELA+1+((j-1)*4)+3);
				printf 			("%c%c%c%c%c", BORDA_MAPA_2PONTOS, BORDA_MAPA_PONTO, BORDA_MAPA_PONTO, BORDA_MAPA_PONTO, BORDA_MAPA_2PONTOS);
			}
		}
	}
	pthread_mutex_unlock(&m);
}







