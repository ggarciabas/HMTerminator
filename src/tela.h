
#ifndef TELA_H_
#define TELA_H_

	#define ALTURA_TELA			25
	#define LARGURA_TELA		80
	#define INICIO_TELA			1

	#define ALTURA_MAPA_TELA	5
	#define LARGURA_MAPA_TELA	13
	#define INICIO_MAPA_TELA	1

	#define BORDA_VERTICAL 		'|'
	#define BORDA_HORIZONTAL 	'-' 
	#define BORDA_DIAGONAL 		'+'

	#define BORDA_MAPA_2PONTOS	':'
	#define BORDA_MAPA_PONTO	'.'
	#define BORDA_SELECAO		'='

	#define COMANDO_LIMPAR_TELA "reset"

	void borda_principal 		();
	void ponto_tela 			(int, int);
	void limpar_tela 			();
	void imprimir_mapa 			();

	void mover_acima			();
	void mover_abaixo			();
	void mover_direita			();
	void mover_esquerda			();

	void atualizar_posicao		(int, int);

	void celula_normal			(int, int);
	void celula_selecionada		(int, int);		

#endif // TELA_H_