#include "Calendario.c"

void vedi_eventi(void)                              //definizione della funzione che visualizza eventi di una data immessa
{
    int day, mounth, years;

    printf("Inserire data da visualizzare --> ");           //richiede data
    scanf("%d/%d/%d", &day, &mounth, &years);

    calendar(day, mounth, years);                        //richiama la funzione calendar
}


void crea_eventi(void)                              //definizione della funzione che crea eventi
{
    int day1, mounth1, years1;

    printf("Inserire data dell'evento da creare --> ");           //richiede data
    scanf("%d/%d/%d", &day1, &mounth1, &years1);

    char strd[3];
    char strm[3];
    char stry[5];

    sprintf(strd, "%d", day1);                                      //converte la data immessa da int a stringa
    sprintf(strm, "%d", mounth1);
    sprintf(stry, "%d", years1);

    char namefile[30] = "fileevent/";

    strcat(namefile, strd);                                   //genera il nome del file
    strcat(namefile, strm);
    strcat(namefile, stry);
    strcat(namefile, ".txt");

    puts(namefile);
    FILE *file;

    NUOVO_EVENTO:                       //etichetta nel caso l'utente voglia aggiungere un altro evento

    if(fopen(namefile, "r") == NULL)                           //verifica se il file esiste o no
        file = fopen(namefile, "w");                           // se non esiste lo apre in modalità write
    else
        file = fopen(namefile, "a");                           //se esiste lo aprirà in modalità append

    char evento[30];                            //stringa che conterrà l'evento

    printf("\nInserire l'evento da aggiungere(con _ al posto degli spazi) --> ");
    scanf("%s", evento);

    fprintf(file, "-%s", evento);            //aggiunge il contenuto nel file

    char cont;                                           //chiede ed esegue se l'utente vuol aggiungere un altro evento
    printf("\n\nVuoi aggiungere un altro evento?(y/n)");
    scanf("   %c", &cont);

    if(cont == 'y')
        goto NUOVO_EVENTO;

    fclose(file);
}
