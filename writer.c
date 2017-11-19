#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){

   int fd;
   char message[26];
   char* nom_tube = "pipe";

   if(mkfifo(nom_tube, 0666) != 0) {
      printf("Impossible de créer %s\n", nom_tube);
      exit (1);
   }

   fd = open("pipe", O_WRONLY);
   dup2(fd, 1);
   system("ls");
   /*sprintf(message, "allo");
   if (fd != 1){
      write(fd, message, strlen(message));
   }else{
      printf("desole, le tube n’est pas disponible\n");
   }*/
   close(fd);

   unlink(nom_tube);

   return 0;
}
