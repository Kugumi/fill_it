int paste(char *str, char *map, int cmp_sd, int str_i)
{
	int i;
	int b[4];

	i = 0;
	while (i < 4)
	{
		b[i] = (str[str_i] - 48) + (str[str_i + 4] - 48) * (cmp_sd + 1);
		i++;
		str_i++;
	}
	i = 0;
	while (i < (cmp_sd * (cmp_sd + 1) - 1))
	{
		if (map[b[0] + i] == '.' && map[b[1] + i] == '.' && map[b[2] + i] == '.' && map[b[3] + i] == '.')
			return (1);
		i++;
	}
	return (0);
}
