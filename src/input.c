
#include "input.h"
#include "include.h"
#include "tela.h"
#include "jogador.h"

void *ler_comando () {
	char tecla;
	do {
		ponto_tela 		(TELA_LER_X, TELA_LER_Y);
		tecla = getch();

		switch (tecla) {
			case MOVER_ACIMA: 
					mover_acima 		();
				break;
			case MOVER_ABAIXO:
					mover_abaixo 		();
				break;
			case MOVER_DIREITA:
					mover_direita 		();
				break;
			case MOVER_ESQUERDA:
					mover_esquerda 		();
				break;
		}

		// lock: pthread_mutex_lock(&m);

		// unlock: pthread_mutex_unlock(&m);
	} while (tecla != 'q');
	pthread_exit(NULL);
}

//http://stackoverflow.com/questions/7469139/what-is-equivalent-to-getch-getche-in-linux
/* Initialize new terminal i/o settings */
	void initTermios(int echo) 
	{
	  tcgetattr(0, &old); /* grab old terminal i/o settings */
	  new = old; /* make new settings same as old settings */
	  new.c_lflag &= ~ICANON; /* disable buffered i/o */
	  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
	  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
	}

	/* Restore old terminal i/o settings */
	void resetTermios(void) 
	{
	  tcsetattr(0, TCSANOW, &old);
	}

	/* Read 1 character - echo defines echo mode */
	char getch_(int echo) 
	{
	  char ch;
	  initTermios(echo);
	  ch = getchar();
	  resetTermios();
	  return ch;
	}

	/* Read 1 character without echo */
	char getch(void) 
	{
	  return getch_(0);
	}
/// ------------------------------------------------------