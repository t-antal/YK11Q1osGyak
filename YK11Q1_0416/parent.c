#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main (int argc, char *argv[],char *env[])
{
	int status, pid, ppid, gpid;
	
	ppid = getpid();        /* Szulo pid-jet elkaptuk */

	if ((pid = fork()) == 0)   
	{ 	/* innen a gyermek processz */
		printf("\n A gyermek pid = %d \n", getpid());
		status = execl("/home/torma/Asztal/child","child",(char *)0);
		if (status == -1)
		{	perror("parent execl failed");
			exit (1);
		}
	}

	/* innen a szulo process */
	
	printf("\n %d.sz. szulo var a %d.sz. gyermekre.\n ", ppid,pid);
	if (pid != wait(&status)) perror(" Szulo - varakozas hiba ");
    printf("A gyermek lefutott!\n");
    return 0;
}
