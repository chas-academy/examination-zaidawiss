#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ANTAL_ELEVER 5
#define ANTAL_PROV 13
#define MAXNAMN 11  // max 10 tecken + nulltecken

typedef struct {
    char namn[MAXNAMN];
    int resultat[ANTAL_PROV];
    float medel;
} Elev;

// Gör första bokstaven versal och resten gemener
void tillVersal(char *namn) {
    namn[0] = toupper(namn[0]);
    for (int i = 1; namn[i] != '\0'; i++) {
        namn[i] = tolower(namn[i]);
    }
}

int main() {
    Elev elever[ANTAL_ELEVER];
    float totalMedel = 0.0;

    // Läs in data
    for (int i = 0; i < ANTAL_ELEVER; i++) {
        scanf("%s", elever[i].namn);
        int summa = 0;
        for (int j = 0; j < ANTAL_PROV; j++) {
            scanf("%d", &elever[i].resultat[j]);
            summa += elever[i].resultat[j];
        }
        elever[i].medel = summa / (float)ANTAL_PROV;
        totalMedel += elever[i].medel;
    }

    // Hitta elev med högst medel
    int maxIndex = 0;
    for (int i = 1; i < ANTAL_ELEVER; i++) {
        if (elever[i].medel > elever[maxIndex].medel) {
            maxIndex = i;
        }
    }

    // Skriv ut namn med versal
    tillVersal(elever[maxIndex].namn);
    printf("%s\n", elever[maxIndex].namn);

    // Beräkna total medel
    float klassMedel = totalMedel / ANTAL_ELEVER;

    // Skriv ut elever under medel
    for (int i = 0; i < ANTAL_ELEVER; i++) {
        if (elever[i].medel < klassMedel) {
            tillVersal(elever[i].namn);
            printf("%s\n", elever[i].namn);
        }
    }

    return 0;
}


