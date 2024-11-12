#include <stdio.h>
#include <string.h>

char    *ft_strnstr(char *str, char *to_find, int len)
{
        int     i;
        int     c;

        i = 0;
        if (*to_find == '\0')
                return (str);
        while (str[i] != '\0' && i < len)
        {
                c = 0;
                while (str[i + c] == to_find[c] && str[i + c] != '\0')
                        c++;
                if (to_find[c] == '\0')
                        return (&str[i]);
                i++;
        }
        return (0);
}

int     main()
{
        char    str[] = "eliminaCOPIAelimina";
        char    find[] = "P";
        printf("%s", ft_strnstr(str, find, 9));
}
