#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

void creerPipe(char input[]);

void creerPipe(char input[]){
   int fd;
      char* nom_tube = "pipe2";
   if(mkfifo(nom_tube, 0666) != 0) {
      printf("Impossible de créer %s\n", nom_tube);
      exit (1);
   }
   system(input);
   fd = open("pipe", O_WRONLY);
   dup2(fd, 1);
   close(fd);
}

int main() {
   int fd;
   char message[100];
   char* nom_tube = "pipe2";

   for(int i=0; i<sizeof(message);i++){
      message[i] = '\0';
   }

   fd = open("pipe", O_RDONLY);
   if (fd != 1){
      read(fd, message, sizeof(message));
      printf("Recu par le lecteur: ");
      printf("%s", message);
      for(int i = 0; i<sizeof(message); i++){
         if(message[i]==' ' && message[i+1] == ' '){
            message[i] = '\0';
            printf("%d", i);
            break;
         }
      }

      /*while ((n = read(fd,&input ,1)) > 0) {
         printf("%c", input);
      }*/
      printf("Le lecteur se termine!\n");
   } else{
      printf("desole, le tube n’est pas disponible\n");
   }

   close ( fd ) ;
   unlink("pipe");
   if(fork() == 0){

   creerPipe(message);
      unlink(nom_tube);



}
return 0;
}
