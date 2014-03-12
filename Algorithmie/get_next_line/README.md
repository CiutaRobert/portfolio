Projet get_next_line

Note recu: 20 / 20

Implementation d'une fonction similaire a std::get_line en C++
Utilisation: cette fonction est destinee a etre utilise dans d'autre programme, pour l'utiliser il faut creer au moins une fonction main de ce genre:

int main()
{
	char *line;

	while (get_next_line(0, &line) > 0)
    {
		write(1, line, strlen(line));
    }
	return (0);
}
