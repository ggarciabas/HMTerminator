
#include "mapa.h"
#include "include.h"

void criar_jogo_teste () {
	int i, j;
	for (i = INICIO_MAPA; i < LARGURA_MAPA; ++i) {
		for (j = INICIO_MAPA; j < ALTURA_MAPA; ++j) {
			CELULA novo;
			novo.tipo = AREIA;
			novo.porcentagem = 0;
			novo.taxa_crescimento = 0;
			novo.valor_venda = 0;
			novo.letra = 'A';
			mapa_jogo[i][j] = novo;
		}
	}
}