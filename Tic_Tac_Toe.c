#include <stdio.h>
#include <stdlib.h>

#define GIOC1 1
#define GIOC2 2
#define MAXTURN 9

//Stampa griglia serve a stampare a schermo la griglia, qualunque sia la sua composizione.
void stampaGriglia(int griglia[3][3]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d", griglia[i][j]);
        }
        printf("\n");
    }

    //printf("\n");
}

//controlRigS controlla una sola riga, data in input tramite "rig".
int controlRigS(int griglia[3][3], int rig, int gioc){

    if(griglia[rig][0] == gioc && griglia[rig][1] == gioc && griglia[rig][2] == gioc){
       //printf("Riga %d apposto\n", rig);
        return 0;
    } else {
       //printf("Riga %d non apposto\n", rig);
        return 1;
    }

}

//controlRigTot utilizza controlRigS su ogni riga della griglia.
int controlRigTot(int griglia[3][3], int gioc){

    if(controlRigS(griglia, 0, gioc) == 0 || controlRigS(griglia, 1, gioc) == 0 || controlRigS(griglia, 2, gioc) == 0){
        return 0;
    } else
        return 1;
}

//controlColS controlla una sola colonna, data in input tramite "col".
int controlColS(int griglia[3][3], int col, int gioc){

    if(griglia[0][col] == gioc && griglia[1][col] == gioc && griglia[2][col] == gioc){
        //printf("Colonna %d apposto\n", col);
        return 0;
    } else
        //printf("Colonna %d non apposto\n", col);
        return 1;
}

//controlColTot utilizza controlColS su ogni colonna della griglia.
int controlColTot(int griglia[3][3], int gioc){

    if(controlColS(griglia, 0, gioc) == 0 || controlColS(griglia, 1, gioc) == 0 || controlColS(griglia, 2, gioc) == 0){
        return 0;
    } else
        return 1;
}

//controlDiagTot controlla se il giocatore ha fatto tris su almeno una delle due diagonali.
int controlDiagTot(int griglia[3][3], int gioc){

    if((griglia[0][0] == gioc && griglia[1][1] == gioc && griglia[2][2] == gioc) || (griglia[0][2] == gioc && griglia[1][1] == gioc && griglia[2][0] == gioc)){
        //printf("Diagonale apposto\n");
        return 0;
    } else{
        //printf("Diagonale non apposto\n");
        return 1;
    }
}


int controlWin(int griglia[3][3], int gioc){

    if(controlColTot(griglia, gioc) == 0 || controlRigTot(griglia, gioc) == 0 || controlDiagTot(griglia, gioc) == 0){
        //printf("Il giocatore %d ha vinto!\n", gioc);
        return 0;
    } else
        return 1;

}

int isValid(int griglia[3][3], int rig, int col){

    if(griglia[rig][col] == 0){
        return 0;
    } else{
        return 1;
    }
}


//mossa serve a inserire il simbolo del giocatore nella casella che preferisce.
int mossa(int griglia[3][3], int rig, int col, int gioc){

    int valid = isValid(griglia, rig, col);

    if(valid == 0){
        griglia[rig][col] = gioc;
        return 0;
    } else {
        printf("Mossa non valida, la casella è già occupata\n");
        return 1;
    }

    printf("-------------------------------------\n");

}


int main(){

    int griglia[3][3] = {{0}};
    int gioc = GIOC1;
    int rig = 0;
    int col = 0;
    int valid = 0;

    char s[80];

    stampaGriglia(griglia);

    for(int i = 0; i < MAXTURN; i++){

        printf("E' il turno del giocatore %d\n", gioc);

        printf("Inserisci la riga: ");
        fgets(s, sizeof(s), stdin);
        rig = atoi(s);

        printf("\nInserisci la colonna: ");
        fgets(s, sizeof(s), stdin);
        col = atoi(s);

        valid = mossa(griglia, rig, col, gioc);
        stampaGriglia(griglia);
        if(controlWin(griglia, gioc) == 0){
            printf("Il giocatore %d ha vinto!\n", gioc);
            return 0;
        }

        if(valid == 0){
            if(gioc == GIOC1){
                gioc = GIOC2;
            }else if(gioc == GIOC2){
                gioc = GIOC1;
            }
        }

        printf("----------------\n");

    }



    //mossa(griglia, 0, 0, GIOC1);
    //stampaGriglia(griglia);















}
