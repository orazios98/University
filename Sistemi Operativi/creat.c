#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int fd;
    //0600 indica la maschera 10 000 000
    //alternativa è: creat("pippo.txt", S_IRUSR | S_IWUSR);
    if((fd=creat("pippo.txt", 0600))== -1)
    {
        printf("Errore nella chiamata creat\n");
        exit(1);
    }

    printf("File creato con successo con descrittore di stato %d", fd);
}