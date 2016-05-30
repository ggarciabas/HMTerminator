
#ifndef MAPA_H_
#define MAPA_H_

	#define LARGURA_MAPA	50
	#define ALTURA_MAPA		50
	#define INICIO_MAPA		0
	
	typedef enum Tipo {
		AREIA,
	} TIPO;

	typedef struct Celula {
		TIPO 		tipo;
		double 		porcentagem; // completa
		double 		taxa_crescimento; // porcentagem por minuto do jogo
		double 		valor_venda;
		char		letra;	
	} CELULA;

	extern CELULA mapa_jogo[LARGURA_MAPA][ALTURA_MAPA];
	extern int mapa_tela_x;
	extern int mapa_tela_y;

	void criar_jogo_teste ();

#endif // MAPA_H_