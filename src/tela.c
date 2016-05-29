
#include "tela.h"
#include "include.h"
#include "mapa.h"

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