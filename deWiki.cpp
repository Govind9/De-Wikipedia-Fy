#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void newline_discipline(const char *name)
{
	char c, p;
	string str = "";

	ifstream file(name);
	if (file.fail())
		return;

	while (file.get(c)) {
		if (c == '\n' && p == '\n')
			continue;
		str += c;
		p = c;
	}
	file.close();
	ofstream o(name);
	o << str;
	o.close();
}

void link_discipline(const char *name)
{
	char c;
	string str = "";
	
	ifstream file(name);
	if (file.fail())
		return;
	
	while (file.get(c)) {
		if (c == '[')
			while ((c == '[' || c == ']' || c == ',' || c < 0 
				|| (c >= '0' && c <= ':')) && file.get(c));
		str += c;
	}
	file.close();
	ofstream o(name);
	o << str;
	o.close();
}

int main (int argc, char **argv)
{
	if (argc < 2)
		return -1;
	link_discipline(argv[1]);
	newline_discipline(argv[1]);
	return 0;
}
