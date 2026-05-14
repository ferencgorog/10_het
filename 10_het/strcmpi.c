#include <stdio.h>
#include <string.h>
#include <ctype.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int strcmpi(const char* s1, const char* s2)
{
    int hossz1 = strlen(s1);
    int hossz2 = strlen(s2);
    int max_hossz = max(hossz1, hossz2);
    int kulonbozet = 0;
    for(int i = 0; i < max_hossz; ++i)
    {
        if(tolower(s1[i]) != tolower(s2[i]) && hossz1 > hossz2)
        {
            kulonbozet = tolower(s2[i]) - tolower(s1[i]);
            return kulonbozet;
        }
        if(tolower(s1[i]) != tolower(s2[i]) && hossz1 < hossz2)
        {
            kulonbozet = tolower(s1[i]) - tolower(s2[i]);
            return kulonbozet;
        }
    }
    return 0;
}

int main()
{
    char* szo1 = "alma";
    char* szo2 = "Almak";
    int megoldas = strcmpi(szo1, szo2);

    if(megoldas == 0)
    {
        printf("A két szó megegyezik.\n");
        printf("%d\n", megoldas);
    }
    else
    {
        printf("A két szó nem egyezik meg.\n");
        printf("%d\n", megoldas);
    }

    return 0;
}