#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    FILE *f;
    int i, count, count1, n, j;
    n = 256;
    i = 0;
    j = 0;
    count = 0;
    count1 = 0;


    char s[100], s1[100], * last, * last1;
    f = fopen("input.txt", "r");
    fgets(&s, 100, f);
    fclose(f);

    f = fopen("output.txt", "a+");
    fprintf(f, "zadacha 1A (uberem lishnie probeli)\n");
    strcpy(s1, s);
    char * pch = strtok (s," ");
    fprintf(f, "otvet:\n");
    while (pch != NULL)
    {
        fprintf(f, "%s", pch);
        pch = strtok(NULL," ");
        if (pch != NULL)
        {

            if (strcmp(pch, ".") != 0)
            {
                fprintf(f, " ");
                last = pch;
                count1++;
            }

        }
    }
    fprintf(f, "\n");
    //puts(s1);
    char a[50][50];

    fprintf(f, "\nzadacha 2, udalit slova, sovpadaushie s poslednim\n");

    last1 = last;
    if (last[strlen(last) - 1] == '.')
        last[strlen(last) - 1] = '\0';

    char * pch1 = strtok (s1," ");
    fprintf(f, "otvet:\n");
    while (pch1 != NULL)
    {
        if (pch1 != NULL)
        {
            if (strcmp(pch1, ".") != 0)
            {
                if (strcmp(pch1, last) != 0)
                {
                    if (count1 > 0)
                    {
                        fprintf(f, "%s ", pch1);
                        strcpy(a[i], pch1);
                        i++;
                        count++;
                    }
                }
                count1--;
            }

        }
        pch1 = strtok(NULL," ");
    }
    fprintf(f, "\n\nzadacha 3, pomenyat 1 i poslednyu bukvu kazhdogo slova\n");
    fprintf(f, "otvet:\n");

    char word[50];
    char sym = " ";

    for (i = 0; i < count; i++)
    {
        strcpy(word, a[i]);
        sym = word[0];
        word[0] = word[strlen(word) - 1];
        word[strlen(word) - 1] = sym;
        fprintf(f, "%s ", word);
    }




    fclose(f);

    return 0;
}
