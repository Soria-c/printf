int str_len(char *str)
{
	int i;

	for (i = 0; *(str + i) != '\0'; i++)
		continue;
	return (i);
}
