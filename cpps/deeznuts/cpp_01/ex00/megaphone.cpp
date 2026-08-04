#include <bits/stdc++.h>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (0);
	}
	int i = 1;
	int j = 0;
	// std::cout << "argc: " << argc << std::endl;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (isalpha(argv[i][j]))
				argv[i][j] = toupper(argv[i][j]);

			std::cout << argv[i][j];
			j++;
		}
		i++;
	}
	return (0);
}