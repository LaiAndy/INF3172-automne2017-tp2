#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void creerPipe(char input[]);

void creerPipe(char input[]){
   int fd;
      char* nom_tube = "pipe";
   if(mkfifo(nom_tube, 0666) != 0) {
      printf("Impossible de créer %s\n", nom_tube);
      exit (1);
   }
   printf("%s", input);
   fd = open("pipe", O_WRONLY);
   dup2(fd, 1);
   close(fd);
   

}

int main(int argc, char* argv[]){
   int fd;
   char message[1000];

   char input[100];
   char* nom_tube = "pipe";

   printf("Veuillez entrer la commande UNIX : ");
   printf("%s", input);
   scanf("%[^\n]%*c", input);
   for(int i = 0; i<sizeof(input); i++){
      if(input[i]==' ' && input[i+1] == ' '){
         input[i] = '\0';
         break;
      }
   }


   creerPipe(input);
   if(fork() == 0){
   fd = open("pipe2", O_RDONLY);
   if (fd != 1){
      read(fd, message, sizeof(message));
      printf("Recu par le lecteur: ");
      printf("%s", message);
      printf("Le lecteur se termine!\n");
   } else{
      printf("desole, le tube n’est pas disponible\n");
   }
   close (fd) ;
      unlink(nom_tube);
   }

   /*while ((n = read(fd,&input ,1)) > 0) {
      printf("%c", input);
   }*/

/*
   fd = open("pipe", O_WRONLY);
   dup2(fd, 1);
   system("ls");
   sprintf(message, "allo");
   if (fd != 1){
      write(fd, message, strlen(message));
   }else{
      printf("desole, le tube n’est pas disponible\n");
   }*/




   return 0;
}
