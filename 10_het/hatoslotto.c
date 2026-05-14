#include <stdio.h>

int main() {
    int s1, s2, s3, s4, s5, s6;
    int cel_osszeg = 90;
    long cel_szorzat = 996300;

    for (s1 = 1; s1 <= 40; s1++)
    {
        for (s2 = s1 + 1; s2 <= 41; s2++)
        {
            for (s3 = s2 + 1; s3 <= 42; s3++)
            {
                for (s4 = s3 + 1; s4 <= 43; s4++)
                {
                    for (s5 = s4 + 1; s5 <= 44; s5++)
                    {
                        for (s6 = s5 + 1; s6 <= 45; s6++)
                        {
                            
                            if (s1 + s2 + s3 + s4 + s5 + s6 == cel_osszeg)
                            {
                                
                                
                                if ((long)s1 * s2 * s3 * s4 * s5 * s6 == cel_szorzat)
                                {
                                    printf("A nyeroszamok: %d, %d, %d, %d, %d, %d\n", 
                                            s1, s2, s3, s4, s5, s6);
                                    return 0; 
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}