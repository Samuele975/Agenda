#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int calendar(int day, int mounth, int years)    // creiamo la funzione calendar che stampa la data immessa e legge gli eventi giornalieri
{
    FILE *file;                                 //puntatore che punta al file che apriremo

    char *lmounth[12] = {                       //vettore contenente i nomi dei mesi dell'anno
        "Gennaio",
        "Febbraio",
        "Marzo",
        "Aprile",
        "Maggio",
        "Giugno",
        "Luglio",
        "Agosto",
        "Settembre",
        "Ottobre",
        "Novembre",
        "Dicembre"};

    printf("\n\nHai selezionato la data del %d %s %d\n", day, lmounth[mounth - 1], years);         // stampa la data immessa

    char strd[3];
    char strm[3];
    char stry[5];

    sprintf(strd, "%d", day);                                      //converte la data immessa da int a stringa
    sprintf(strm, "%d", mounth);
    sprintf(stry, "%d", years);

    char namefile[30] = "fileevent/";

    strcat(namefile, strd);                                   //genera il nome del file
    strcat(namefile, strm);
    strcat(namefile, stry);
    strcat(namefile, ".txt");

    file = fopen(namefile, "r");                                  //apre il file

    if(file==NULL)                                                             // verifica se il file è vuoto o inesistente
    {    printf("\n\n\n\t        Per questo giorno non ci sono programmi!\n\n");
         return 0;
    }

    printf("\n\nEventi:\n\n");

    char row[40] = "";
    for(;!feof(file);)           //stampa il contenuto del file aperto
    {
        fscanf(file, "%s", row);
        puts(row);
    }

    fclose(file);                   //chiude il file

    return 0;
}
