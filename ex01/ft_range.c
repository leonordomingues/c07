#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	i = 0;
	if (min >= max)
		return(0);
	range = (int*)malloc((max - min) * sizeof(int));
	while (min < max)
	{
		range[i] = min++;
		i++;
	}
	return (range);
}

/*int	main()
{
	int	i = 0;
	int min = 4;
	int max = 20;
	int	*range = ft_range(min, max);
	int	size = max - min;
	
	while(i < size)
	{
		printf("%d\n", range[i]);
		i++;
	}
}*/
