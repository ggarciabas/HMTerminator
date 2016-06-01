
#ifndef INCLUDES_H_
#define INCLUDES_H_
	#include <stdio.h>
	#include <stdlib.h>

	#include <termios.h>
	#include <pthread.h>
	#include <time.h>
	#include <unistd.h>


	extern pthread_mutex_t m;
	extern struct termios old, new;
#endif // INCLUDES_H_