template<typename T>
int	easyfind(T it, int value)
{
	for (unsigned int i = 0; i < it.size(); i++)
	{
		if (it[i] == value)
			return (i);
	}
	return (-1);
}