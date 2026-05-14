#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

typedef struct {
    char nev[50];
} Hallgato;

int main() {
    FILE *fp = fopen("nevek.csv", "r");
    if (fp == NULL) {
        fprintf(stderr,"Hiba a fájl megnyitásakor");
        exit(1);
    }

    Hallgato pti_sek[100];
    int darab = 0;
    char sor[100];

    while (fgets(sor, sizeof(sor), fp) != NULL && darab < 100) {
        sor[strlen(sor - 1)] = '\0';

        char *nev = strtok(sor, ",");
        char *kor = strtok(NULL, ",");
        char *szak = strtok(NULL, ",");

        if (szak != NULL && strcasecmp(szak, "pti") == 0) {
            if (nev[0] != '\0') {
                nev[0] = toupper(nev[0]);
            }
            strcpy(pti_sek[darab].nev, nev);
            darab++;
        }
    }
    fclose(fp);

    for (int i = 0; i < darab - 1; i++) {
        for (int j = 0; j < darab - i - 1; j++) {
            if (strcmp(pti_sek[j].nev, pti_sek[j + 1].nev) > 0) {
                Hallgato temp = pti_sek[j];
                pti_sek[j] = pti_sek[j + 1];
                pti_sek[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < darab; i++) {
        printf("%s", pti_sek[i].nev);
        if (i < darab - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}