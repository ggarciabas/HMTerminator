
#include "mapa.h"
#include "include.h"

void criar_jogo_teste () {
	int i, j;
	for (i = INICIO_MAPA; i < LARGURA_MAPA; ++i) {
		for (j = INICIO_MAPA; j < ALTURA_MAPA; ++j) {
			CELULA novo;
			novo.porcentagem = 0;
			novo.taxa_crescimento = 0;
			novo.valor_venda = 0;
			
			if (i==INICIO_MAPA || j==INICIO_MAPA || i==LARGURA_MAPA-1 || j==ALTURA_MAPA-1) {
				novo.tipo = PEDRA;
				novo.letra = 'P';
			} else {
				novo.tipo = AREIA;
				novo.letra = 'A';
			}
			mapa_jogo[i][j] = novo;
		}
	}
}