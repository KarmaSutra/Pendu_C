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


        //Boucle o� l'utilisateur entre le mot � trouver
        do{
                printf("Entrer votre mot: ");
                gets(Mot);
                Mot[strlen(Mot)+1]='\0';
                printf("le mot fait %i lettre\n", strlen(Mot));
        }while (strlen(Mot) > TAILLEMAX || strlen(Mot) <TAILLEMIN);

        char MotTrouve[TAILLE];

        //On affiche des barres � la place des lettres
        for(i=0;i<=strlen(Mot);i++){
                if(i!=strlen(Mot))
                    MotTrouve[i] = '-';
                if (i==strlen(Mot))
                    MotTrouve[i]='\0';

        }

        //Boucle o� l'utilisateur entre une lettre qui sera test�e pour voir si elle est pr�sente dans le mot � trouver
        while(estPareil != WIN && vie != LOOSE){
             fflush(stdin);

             printf("Avancement du mot:\n%s\n", MotTrouve);
             printf("Essais restants: %d\n",vie);

             printf("Entrer une lettre: ");
             scanf("%c", &Lettre);

                // Recherche des lettres
                //Si la lettre est pr�sente, les tirets dans Mottrouve sont remplac�s par les lettres
                for(i = 0; i < strlen(Mot); i++){
                    if(Lettre == Mot[i]){
                        MotTrouve[i] = Lettre;
                        printf("Une occurence %c a ete trouve!\n", Lettre);
                        aTrouverUneLettre = WIN;
                    }
                }
                //Si le joueur a rentr� une lettre non pr�sente, il perd une vie
                if(aTrouverUneLettre != WIN)
                vie -= 1;

                aTrouverUneLettre = LOOSE;

                i=0;
                //Tant que les lettre correspondent, la boucle continue, si on arrive � la fin alors les mots sont les m�mes et le joueur a donc gagn�
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
    //BUT: Retrouver le mot cach� lettre par lettre avant d'avoir perdu toutes ses chances
    //ENTREES: La lettre que le joueur veut tester
    //SORTIES: Le programme renvoit le mot mis � jour si la lettre test�e est pr�sente dans le mot cach�


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

         POUR i ALLANT de 1 � (LONGUEUR(Mot)) FAIRE
                MotTrouve[i]<--"-";

        REPETER
                ECRIRE "Avancement du mot: "&MotTrouve;
                ECRIRE "Essais restants: "&vie;
                ECRIRE "Entrez une Lettre: ";
                LIRE Lettre;

                POUR i ALLANT de 1 � LONGUEUR(Mot) FAIRE
                    DEBUT
                        SI (Lettre=Mot[i] ALORS
                            DEBUT
                                MotTrouve[i]<--Lettre;
                                ECRIRE "Une occurence de la lettre "&Lettre&" a �t� trouv�e";
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
            ECRIRE "Bien Jou�";
        SINON
            ECRIRE "Ouvre un Dico";
        FIN SI
    FIN
*/

