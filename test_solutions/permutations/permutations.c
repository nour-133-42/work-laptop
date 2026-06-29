#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


void ft_swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int ft_strlen(char *str)
{
	if(!str || !*str)
	{
		return (0);
	}
	int i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

char *get_swaped_string(char *str, int a, int b)
{
	char *res;
	int i = 0;


	res = malloc(ft_strlen(str) + 1);
	if(!res)
		return (NULL);
	while(str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	i = a + 1;
	ft_swap(&res[a], &res[b]);
	if(b > a + 1)
	{
		while(i < b)
		{
			ft_swap(&res[b], &res[i]);
			i++;
		}
	}
	return (res);
}

void ft_putstr(char *str)
{
	int i = 0;

	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void permutation(char *str,int i, int j)
{

	if(i == ft_strlen(str) - 1)
	{
		ft_putstr(str);
		write(1, "\n", 1);
		return ;
	}

	while(j < ft_strlen(str))
	{
		permutation(get_swaped_string(str, i, j), i + 1, i + 1);
		j++;
	}
}

char *ft_sort(char *strer)
{
	int i = 0;
	int j = 0;
	char *str;
	str = malloc (ft_strlen(strer) + 1);
	while(strer[i])
	{
		str[i] = strer[i];
		i++;
	}
	i = 0;
	while(str[i])
	{
		while(str[j])
		{
			if(str[j] < str[i])
				ft_swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
	return (str);
}

int main(int ac, char **av)
{
	if(ac != 2)
	{
		return (1);
	}
	char *str;

	str = ft_sort(av[1]);
	permutation(str, 0, 0);
	
	return (0);
}
