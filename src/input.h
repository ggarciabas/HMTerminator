
#ifndef INPUT_H_
#define INPUT_H_

	#define MOVER_ACIMA			'i'
	#define MOVER_ABAIXO		'k'
	#define MOVER_DIREITA		'l'
	#define MOVER_ESQUERDA		'j'

	#define TELA_LER_X			0
	#define TELA_LER_Y			26

	void *ler_comando 		();

	void initTermios		(int echo);
	void resetTermios		(void);
	char getch_				(int echo);
	char getch 				(void);

#endif // INPUT_H_