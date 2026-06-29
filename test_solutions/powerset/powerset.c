#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

long long ft_power(int x)
{
	int i = 0;
	long long res = 1;
	while (i < x)
	{
		res *= 2;
		i++;
	}
	return (res);
}

int check_args(int argc, char **argv)
{
    /*
     * VALIDACIÓN DE ARGUMENTOS:
     * - Verificar que todos los argumentos son números válidos
     * - Permitir números negativos (comenzando con '-')
     * - Permitir números positivos (opcionalmente con '+')
     */
    int i = 1;
    while (i < argc)
    {
        int j = 0;
        
        // Saltar signo inicial si existe
        if (argv[i][j] == '+' || argv[i][j] == '-')
            j++;
        
        // Verificar que el resto son dígitos
        while (argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return 0; // No es un número válido
            j++;
        }
        i++;
    }
    return 1; // Todos los argumentos son válidos
}

int main(int ac, char **av)
{
    if (ac == 1 || (ac >= 2 && av[1][0] == '0' && av[1][1] == '\0'))
    {
        printf("\n");
        return 1;
    }
    
    if(!check_args(ac, av))
	    return (1);

	int i = 0;
	int j = 0;
	long long x = ft_power(ac -2);
	int *set;
	long long sum;
	int to_find = atoi(av[1]);

	if(ac - 2 <= 0)
	       return (1);	
	set = malloc (sizeof(int *) * (ac -2));
	if(!set)
		return(1);
	while (i < (ac - 2))
	{
		set[i] = atoi(av[i+2]);
		i++;
	}
	i = 1;
	while (i < x)
	{
		j = 0;
		sum = 0;
		while(j < (ac -2))
		{
			if(((i >> j) & 1) == 1)
				sum += set[j];
			j++;
		}
		j = 0;
		if (sum == to_find)
		{
			while(j < (ac - 2))
			{
				if(((i >> j) & 1)  == 1 )
				{
					printf("%d", set[j]);
					if(j != ac - 3)
						printf(" ");
				}
				j++;
			}
			printf("\n");
		}
		i++;
	}	
}
