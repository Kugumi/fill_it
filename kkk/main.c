#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

int main(int argc, char *argv[])
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * ft_strlen(argv[1]) + 1)))
		return (0);
	while (argv[1][i])
	{
		if (ft_isalpha(argv[1][i]))
		{
			s[i] = argv[1][i] - 32;
			i++;
		}
		else
		{
			s[i] = argv[1][i];
			i++;
		}
	}
	s[i] = '\0';
	printf("%s\n", s);
	free(s);
	return (0);
}
