#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void my_strfry(char* s)
{
    srandom(time(NULL));
    int meret = strlen(s);

    for(int i = meret - 1; i >= 1; --i)
    {
        int j = rand() % (i + 1);
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    printf("%s\n", s);
}

int main()
{
    char s[] = "Sziasztok";
    my_strfry(s);

    return 0;
}