#include "gestione_eventi.c"

int main(void)
{
    int dd, mm, yyyy;

    printf("\n\t\t\tBenvenuto nella tua agenda personale\n\n\n");

    printf("E pregato di inserire la data odierna dd/mm/yyyy --> ");            // chiede e riceve la data di oggi
    scanf("%d/%d/%d", &dd, &mm, &yyyy);

    calendar(dd, mm, yyyy);                         //chiama la funzione calendar che stampa gli eventi giornalieri

    for(;;)
    {
        int scelta1;

        INPUT:              //etichetta nel caso l'utente immettesse un numero sbagliato

        printf("\n\nCosa desidera fare oggi?\n");       //chiede all'utente una scela tra le varie azioni
        printf("1) Visualizzare un evento\n");
        printf("2) Creare un nuovo evento\n\n");
        printf("Scegliere una delle 2 opzioni --> ");

        scanf("%d", &scelta1);

        switch(scelta1)                                   //istruzione di selezione che controlla l'input immesso
        {
            case 1:
                vedi_eventi();
                break;
            case 2:
                crea_eventi();
                break;
            default:
                printf("\n\tERROR: l'opzione %d non esiste\n", scelta1);
                goto INPUT;                             //nel caso sia sbagliato l'input ritorna all'etichetta
        }

        char cont;                                           //chiede ed esegue se l'utente vuol continuare
        printf("\n\nVuoi continuare?(y/n)");
        scanf("   %c", &cont);
        if(cont == 'y')
        {    goto INPUT;
        }

        else if(cont == 'n')
        {
            printf("\n\nArrivederci!\n\n");
            break;
        }
    }
    return 0;
}
