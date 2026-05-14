#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

int main(int argc, char* argv[])
{
    char* fajlnev = argv[1];
    char sor[MAX];
    FILE *fp = fopen(fajlnev, "r");
    if(fp == NULL || argc != 2)
    {
        fprintf(stderr, "Hiba a fájl megyitásakor!\n");
        exit(1);
    }
    
    int *szamok = malloc(3000000 * sizeof(int));
    if(szamok == NULL)
    {
        fprintf(stderr, "Hiba! Nem sikerült elég tárterületet lefoglalni.");
        exit(1);
    }
    int db = 0;



    while(fgets(sor, MAX, fp) != NULL)
    {
        szamok[db] = atoi(sor);
        ++db;
    }

    for (int gap = db / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < db; i++)
        {
            int temp = szamok[i];
            int j;
            
            for (j = i; j >= gap && szamok[j - gap] > temp; j -= gap)
            {
                szamok[j] = szamok[j - gap];
            }
            
            szamok[j] = temp;
        }
    }

    

    for(int i = 0; i < db; i++)
    {
        printf("%d\n", szamok[i]);
    }


    fclose(fp);
    free(szamok);
    return 0;
}