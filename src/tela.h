
#ifndef TELA_H_
#define TELA_H_

	#define ALTURA_TELA			25
	#define LARGURA_TELA		80
	#define INICIO_TELA			1

	#define BORDA_VERTICAL 		'|'
	#define BORDA_HORIZONTAL 	'-' 
	#define BORDA_DIAGONAL 		'+'

	#define COMANDO_LIMPAR_TELA "reset"

	void borda_principal ();
	void ponto_tela (int, int);
	void limpar_tela ();

#endif // TELA_H_