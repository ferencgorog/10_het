#include <stdio.h>

int main()
{
    int matrix[6][6] = 
    {
        {3, 8, 0, 1, 4, 1},
        {7, 6, 3, 0, 9, 5},
        {6, 7, 2, 8, 4, 3},
        {3, 6, 8, 1, 0, 5},
        {0, 4, 6, 7, 9, 4},
        {3, 5, 2, 2, 9, 8}
    };
    
    int meret = 6;
    int atlo = meret;
    
    for(int i = 0; i < meret; ++i)
    {
        for(int j = meret; j != 0; --j)
        {
            if(j == atlo)
            {
                printf("%d ", matrix[i][atlo - 1]);
            }
        }
        --atlo;
    }
    puts("");
    
    return 0;
}