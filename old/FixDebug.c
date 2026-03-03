#include <stdio.h>
char B[4];
char M[100];
char s[200];
int main()
{
    int flag = 0;
    gets(s);
    for (int i = 0; i < 200; i++)
    {
        if (flag)
            break;
        if (s[i] == 'b'        //
            && s[i + 1] == 'o' //
            && s[i + 2] == 'r' //
            && s[i + 3] == 'n')
        {
            B[0] = s[i + 8];
            B[1] = s[i + 9];
            B[2] = s[i + 10];
            B[3] = s[i + 11];
        }
        int j = 0;
        if (s[i] == 'm'        //
            && s[i + 1] == 'a' //
            && s[i + 2] == 'j' //
            && s[i + 3] == 'o' //
            && s[i + 4] == 'r')
        {
            flag = 1;
            do
            {
                M[j] = s[i + 9 + j];
                j++;
            } while (s[i + 9 + j] != '.');
        }
    }
    printf("%c%c%c%c, ", B[0], B[1], B[2], B[3]);
    puts(M);
}