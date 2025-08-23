#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);

	char *search = argv[1];
	char *str = argv[2];
	int i_search = 0;
	int i_str = -1;

	int found = -1;
	while (str[++i_str])
	{
		if (found != i_search && str[i_str] == search[i_search])
		{
			found = i_search;
			i_search++;
		}
	}
	if (!search[i_search])
		write(1, "1", 1);
	else
		write(1, "0", 1);
}
