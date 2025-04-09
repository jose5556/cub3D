#include "../libft.h"

size_t ft_strspn(const char *s, const char *accept)
{
    size_t i;

    i = 0;
    while (s[i] && ft_strchr(accept, s[i]))
        i++;
    return (i);
}