#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//-2345
//-5432 2345 - 1
// #include <stdio.h>

int	main(void)
{
	char	c[100];
	char	e[] = {0, 0};

	ft_memset(c, 'A', 100);
	printf("%s", (char *)ft_memcpy(c, e, 3));
	printf("%s", (char *)memcpy(c, e, 3));
}
