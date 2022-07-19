#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int	i;

	i = 0;
	dest = (char*)malloc(i * sizeof(char) + 1);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	if (dest == (NULL))
			return (0);
	return (dest);
}

/*int	main()
{
	char src[] = "copia";
	char *dest = ft_strdup(src);
	printf("%s\n", dest);
}*/
