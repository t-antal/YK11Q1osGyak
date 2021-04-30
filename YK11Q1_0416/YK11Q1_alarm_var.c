#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void do_nothing();


int main ()
{


	signal(SIGALRM, do_nothing);
	printf("varok de meddig?\n");
	pause();
    printf("  Vegre, itt az alarm \n");
    return 0;
}	
void do_nothing(){ ;}
