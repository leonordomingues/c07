#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int*)malloc((max - min) * sizeof(int));
	if (!*range)
		return (-1);
	while (min < max)
		(*range)[i++] = min++;


	return (i);
}

int main()
{
	int *range;
	int min = 6;
	int max = 24;
	int i = 0;
	int size = ft_ultimate_range(&range, min, max);
	while(i < size)
	{
		printf("%d\n", range[i]);
		i++;
	}
}
