#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 100
#define TAILLEMIN 3
#define TAILLEMAX 24
#define WIN 1
#define LOOSE 0
#define VIEMAX 10


int main ()
{
    int rejouer = WIN;
    while(rejouer == WIN){
        char Mot[TAILLE];
        char Lettre;
        int vie = VIEMAX, i=0;
        int estPareil = LOOSE, aTrouverUneLettre = LOOSE;


        //Boucle où l'utilisateur entre le mot à trouver
        do{
                printf("Entrer votre mot: ");
                gets(Mot);
                Mot[strlen(Mot)+1]='\0';
                printf("le mot fait %i lettre\n", strlen(Mot));
        }while (strlen(Mot) > TAILLEMAX || strlen(Mot) <TAILLEMIN);

        char MotTrouve[TAILLE];

        //On affiche des barres à la place des lettres
        for(i=0;i<=strlen(Mot);i++){
                if(i!=strlen(Mot))
                    MotTrouve[i] = '-';
                if (i==strlen(Mot))
                    MotTrouve[i]='\0';

        }

        //Boucle où l'utilisateur entre une lettre qui sera testée pour voir si elle est présente dans le mot à trouver
        while(estPareil != WIN && vie != LOOSE){
             fflush(stdin);

             printf("Avancement du mot:\n%s\n", MotTrouve);
             printf("Essais restants: %d\n",vie);

             printf("Entrer une lettre: ");
             scanf("%c", &Lettre);

                // Recherche des lettres
                //Si la lettre est présente, les tirets dans Mottrouve sont remplacés par les lettres
                for(i = 0; i < strlen(Mot); i++){
                    if(Lettre == Mot[i]){
                        MotTrouve[i] = Lettre;
                        printf("Une occurence %c a ete trouve!\n", Lettre);
                        aTrouverUneLettre = WIN;
                    }
                }
                //Si le joueur a rentré une lettre non présente, il perd une vie
                if(aTrouverUneLettre != WIN)
                vie -= 1;

                aTrouverUneLettre = LOOSE;

                i=0;
                //Tant que les lettre correspondent, la boucle continue, si on arrive à la fin alors les mots sont les mêmes et le joueur a donc gagné
                while(i < strlen(Mot) && MotTrouve[i] == Mot[i])
                        i++;

                    if(i == strlen(Mot))
                        estPareil = WIN;
                    else
                        estPareil = LOOSE;

        }

        if(vie != LOOSE)
            printf("Bien jouer, ta gagner allez a+\n");

        else
            printf("Ca te dirais d'ouvrir un dico ?\n");


        printf("Tu veut rejouer? (Oui = 1;Non = 0)");
        scanf("%d",&rejouer);
    }


system("pause");
return 0;
}




/*strlen(Mot)+1
Programme Pendu
    //BUT: Retrouver le mot caché lettre par lettre avant d'avoir perdu toutes ses chances
    //ENTREES: La lettre que le joueur veut tester
    //SORTIES: Le programme renvoit le mot mis à jour si la lettre testée est présente dans le mot caché


    VAR
    rejouer,vie,estPareil,aTrouveUneLettre,i:ENTIER;
    Mot,MotTrouve:CHAINE;
    Lettre:CARACTERE;

        DEBUT
         vie<--10;
         i<--0;
         estPareil<--0;
         aTrouveUneLettre<--0;

         REPETER
                ECRIRE "Entrez votre mot:";
                LIRE Mot
                ECRIRE "Votre mot fait"&LONGUEUR(Mot);
            TANT QUE (Mot <3 ET Mot>10);
         FIN REPETER

         POUR i ALLANT de 1 à (LONGUEUR(Mot)) FAIRE
                MotTrouve[i]<--"-";

        REPETER
                ECRIRE "Avancement du mot: "&MotTrouve;
                ECRIRE "Essais restants: "&vie;
                ECRIRE "Entrez une Lettre: ";
                LIRE Lettre;

                POUR i ALLANT de 1 à LONGUEUR(Mot) FAIRE
                    DEBUT
                        SI (Lettre=Mot[i] ALORS
                            DEBUT
                                MotTrouve[i]<--Lettre;
                                ECRIRE "Une occurence de la lettre "&Lettre&" a été trouvée";
                                aTrouveUneLettre<--1;
                            FIN SI
                    FIN POUR

                SI (aTrouveUneLettre<>1)ALORS
                    vie<--vie-1;

                aTrouveUneLettre<--0;

                i<--0;

                REPETER
                        i<--i+1;

                    TANT QUE (i<LONGUEUR(Mot) ET MotTrouve[i]=Mot[i])
                FIN REPETER

                SI (i=LONGUEUR(Mot)) ALORS
                    estPareil<--1;
                SINON
                    estPareil<--0;
                FIN SI
            TANT QUE (estPareil<>1 ET vie<>0)
        FIN REPETER

        Si (vie<>0) ALORS
            ECRIRE "Bien Joué";
        SINON
            ECRIRE "Ouvre un Dico";
        FIN SI
    FIN
*/

