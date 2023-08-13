#include <stdio.h>
#include <string.h>

char text[80] = "JIM_SAW_ME_IN_BARBER_SHOP";
char pattern[20] = "BARBER";
int stable[128];
int m, n;

void shiftTable()
{
    m = strlen(pattern);
    n = strlen(text);

    for (int i = 0; i < 127; i++)
    {
        stable[i] = m;
    }
    for (int i = 0; i < m - 1; i++)
    {
        stable[pattern[i]] = m - i - 1;
    }
    for (int i = 0; i < 127; i++)
    {
        printf("%d\t", stable[i]);
    }
}

int horspool()
{
    int i = m - 1;
    while (i < n)
    {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k])
        {
            if (k == m)
            {
                return i - m + 1;
            }
            else
                i += stable[text[i]];
        }
    }
    return -1;
}

void main()
{
    shiftTable();
    int ans = horspool();
    if (ans == -1)
    {
        printf("String not found\n");
    }
    else
    {
        printf("String found at position %d\n", ans);
    }
}