#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static unsigned int	unsignedint_mes_hex(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

char	*sixteen_base(unsigned int n)
{
	unsigned int	len;
	char			*str;
	char			*hex_base;

	len = unsignedint_mes(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	hex_base = "0123456789abcdef";
	str[len--] = '\0';
	str[len--] = hex_base[n % 16];
	n = n / 16;
	while (n > 0)
	{
		str[len--] = hex_base[n % 16];
		n = n / 16;
	}
	return (str);
}

int	main()
{
	char	*re_str;
	
	re_str = sixteen_base(123);
	printf("%s\n", re_str);
	free(re_str);
	re_str = NULL;
	return (0);
}
