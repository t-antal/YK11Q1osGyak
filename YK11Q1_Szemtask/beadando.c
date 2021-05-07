#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int lnko(int x, int y);

int main()
{
    int n, x, y, fd1, fd2;
    mknod("YK11Q1", S_IFIFO | 0666, 0);
    char buffer[100];
    fd1 = open("YK11Q1", O_WRONLY);
    FILE *fbe;
    if ((fbe = fopen("be.txt", "r")) == NULL)
    {
    	printf("Error at input!");
    	exit(1);
    }
    fscanf(fbe, "%d", &n);
    for(int i = 0; i < n; i++)
    {
        fscanf(fbe, "%d %d", &x, &y);
        write(fd1, &x, sizeof(x));
        write(fd1, &y, sizeof(y));
    }
    fd2 = open("YK11Q1", O_RDONLY);
    FILE *fki;
    fki = fopen("ki.txt", "w");
    for(int i = 0; i < n; i++)
    {
    	read(fd2, &x, sizeof(x));
    	read(fd2, &y, sizeof(y));
    	fprintf(fki,"%d %d %d\n", x, y, lnko(x,y));
    	
    }
    fclose(fbe);
    fclose(fki);
    close(fd1);
    close(fd2);
    return 0;
}

int lnko(int x, int y)
{
    int temp;
    while(y > 0)
    {
        temp = y;
        y = x%y;
        x = temp;
    }
    return x;
}
