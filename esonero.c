#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>



int main(){
  char stringa[128];
  char stringacod[128];
  char stringadecod[128];
  char key_Rand[128];
  char chiave [128];
  int lunghezza_stringa;
  int ch;
  time_t t;

    printf("salve, questo è un programma di cifratura\n");
    printf("digitare la frase che si vuole cifrare:\n");
    printf("(lunghezza massima 128 caratteri, doppio invio)\n");
    fgets (stringa, 128, stdin);
    lunghezza_stringa=strlen(stringa);
    //fflush(stdin);
    while((ch=getchar())!='\n' && ch != EOF);

    printf("adesso per cifrare la stringa si puo procedere in due maniere\n");
    printf("si puo digitare una chiave di cifratura o lasciare che il computer\n");
    printf("ne componga una casuale.\n");
    printf("quindi si vuole digitare una chiave di cifratura?[si/no]\n");

      char scelta [3];
    fgets(scelta,3,stdin);

    if (strcmp(scelta,"si")==0) {
            printf("digitare una chiave di cifratura.\n");
            printf("**attenzione** la chiave di cifratura deve essere lunga %d caratteri.\n", lunghezza_stringa );
            printf("(spazio = _)\n");
            scanf("%s", chiave);
            //fgets(chiave,128,stdin);
            int key_lenght;
            key_lenght=strlen(chiave);
                  if (key_lenght==lunghezza_stringa){

                     for (int i=0; i<lunghezza_stringa; ++i ){
                         stringacod[i]=stringa[i]^chiave[i];
                                         }
                              printf("stringa codificata:\n");
                               printf("%s\n", stringacod );

                     for(int i=0; i<lunghezza_stringa; ++i){
                        stringadecod[i]=stringacod[i]^chiave[i];
                                        }
                              printf("stringa decodificata:\n");
                              printf("%s\n",stringadecod );
                                         }
                  else {
                    printf("errore: lunghezza chiavbe di codifica errata\n");
                    printf("programma abortito\n");
                  }
          }
  else if (strcmp(scelta, "no")==0){
              for(int i=0; i<lunghezza_stringa; ++i){
                srand((unsigned) time(&t));
                key_Rand[i]=rand() %128;
              }
            printf("chiave generata automaticamente:\n");
            printf("%s\n", key_Rand);

            for (int i=0; i<lunghezza_stringa; ++i ){
                stringacod[i]=stringa[i]^key_Rand[i];
                                }
                     printf("stringa codificata:\n");
                      printf("%s\n", stringacod );

            for(int i=0; i<lunghezza_stringa; ++i){
               stringadecod[i]=stringacod[i]^key_Rand[i];
                               }
                     printf("stringa decodificata:\n");
                     printf("%s\n",stringadecod );
                                }


  else {
    printf("errore: scelta inserita non riconosciuta.\n");
    printf("programma abortito\n");

}

   return 0;
}
