#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int fd[2], nbytes;
    pid_t childpid;
    char string[] = "Torma Antal YK11Q1"; 
    char buffer[64]; 
    
    pipe(fd);
    if ((childpid = fork()) == -1)
    {
        perror("fork");
        exit(1);
    }
    if (childpid == 0)
    {
        close(fd[0]);
        write(fd[1], string, (strlen(string)+1));
        exit(0);
    }
    else
    {
        close(fd[1]);
        nbytes = read(fd[0], buffer, sizeof(buffer));
        printf("%s\n", buffer);
    }
    return 0;
}
