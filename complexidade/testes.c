#include <stdio.h>

int main()
{
        int n = 5, c = 0;

        for(int i = 0; i < n; i++)
        {
                printf("---\n");
		for(int j = n; j > i; j--)
                {
                        c++;
                        printf("%d\n", c);
                }
        }
        return 0;
}
