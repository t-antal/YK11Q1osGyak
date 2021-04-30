#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;
    char* myfifo = "./YK11Q1";
    mkfifo(myfifo, 0666);
    char arr1[64];
    char arr2[64];
    fd = open(myfifo, O_WRONLY);
    strcat(arr2, " Torma Antal\n");
    write(fd, arr2, strlen(arr2)+1);
    close(fd);
    fd = open(myfifo, O_RDONLY);
    read(fd, arr1, sizeof(arr1));
    printf("%s\n", arr1);
    close(fd);
    return 0;
}
