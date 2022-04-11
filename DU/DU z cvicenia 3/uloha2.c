int main()
{
	char p1, p2, p3;
	int i;
	scanf("%c %c %c", &p1, &p2, &p3);
	if (p1 < 91)
	{
		p1 +=32;
	}
	if (p2 < 91)
	{
		p2 +=32;
	}
	if (p2 < 91)
	{
		p2 +=32;
	}

	printf("Male pismena zoradene podla abecedy: ");
	if (p1 <= p2 && p1 <= p3)
	{
		if (p2 <= p3)
		{
			printf("%c %c %c", p1, p2, p3);
		}
		else
		{
			printf("%c %c %c", p1, p3, p2);
		}
	}
	else if (p2 <= p1 && p2 <= p3)
	{
		if (p1 <= p3)
		{
			printf("%c %c %c", p2, p1, p3);
		}
		else
		{
			printf("%c %c %c", p2, p3, p1);
		}
	}
	else if (p3 <= p1 && p3 <= p2)
	{
		if (p1 <= p2)
		{
			printf("%c %c %c", p3, pismena[0], p2);
		}
		else
		{
			printf("%c %c %c", p3, p2, p1);
		}
	}
	return 0;
}