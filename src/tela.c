
#include "tela.h"
#include "include.h"
#include "mapa.h"

void limpar_tela () {
	system(COMANDO_LIMPAR_TELA);
}

void borda_principal () {
	int i;

	ponto_tela	(INICIO, INICIO);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela	(LARGURA, INICIO);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela	(INICIO, ALTURA);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela	(LARGURA, ALTURA);
	printf 		("%c", BORDA_DIAGONAL);

	for (i = INICIO+1; i < ALTURA; ++i)
	{
		ponto_tela	(INICIO, i);
		printf 		("%c", BORDA_VERTICAL);
		ponto_tela 	(LARGURA, i);
		printf 		("%c", BORDA_VERTICAL);
	}

	for (i = INICIO+1; i < LARGURA; ++i)
	{
		ponto_tela 	(i, INICIO); 
		printf 		("%c", BORDA_HORIZONTAL);
		ponto_tela 	(i, ALTURA);
		printf 		("%c", BORDA_HORIZONTAL);
	}

	for (i = INICIO+1; i < ALTURA-4; ++i) {
		ponto_tela 	(LARGURA-13, INICIO+i);
		printf 		("%c", BORDA_VERTICAL);
	}

	ponto_tela 	(LARGURA-13, INICIO+1);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA-13, INICIO+4);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA, INICIO+1);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA, INICIO+4);
	printf 		("%c", BORDA_DIAGONAL);

	ponto_tela 	(LARGURA-13, INICIO+7);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA, INICIO+7);
	printf 		("%c", BORDA_DIAGONAL);

	ponto_tela 	(LARGURA-13, INICIO+8);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA, INICIO+8);
	printf 		("%c", BORDA_DIAGONAL);

	ponto_tela 	(LARGURA-13, INICIO+20);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA, INICIO+20);
	printf 		("%c", BORDA_DIAGONAL);

	ponto_tela 	(INICIO, INICIO+21);
	printf 		("%c", BORDA_DIAGONAL);
	ponto_tela 	(LARGURA, INICIO+21);
	printf 		("%c", BORDA_DIAGONAL);

	for (i = INICIO; i < 13; ++i) {
		ponto_tela 	(LARGURA-i, INICIO+1);
		printf 		("%c", BORDA_HORIZONTAL);

		ponto_tela 	(LARGURA-i, INICIO+4);
		printf 		("%c", BORDA_HORIZONTAL);

		ponto_tela 	(LARGURA-i, INICIO+7);
		printf 		("%c", BORDA_HORIZONTAL);

		ponto_tela 	(LARGURA-i, INICIO+8);
		printf 		("%c", BORDA_HORIZONTAL);

		ponto_tela 	(LARGURA-i, INICIO+20);
		printf 		("%c", BORDA_HORIZONTAL);
	}

	for (i = INICIO+1; i < LARGURA; ++i) {
		ponto_tela 	(i, ALTURA-3);
		printf 		("%c", BORDA_HORIZONTAL);
	}

	ponto_tela		(LARGURA-12, INICIO+2);
	printf 			("HORA: %02d:%02d", 10, 15);
	ponto_tela		(LARGURA-12, INICIO+3);
	printf 			("POS.:(%02d,%02d)", 10, 15);
	ponto_tela		(LARGURA-12, INICIO+5);
	printf 			("    GRANA");
}

void ponto_tela (int x, int y) // coluna (x) por linha (y)
{
   printf("%c[%d;%df",0x1B,y,x);
   fflush(stdout);
}