#include <fstream>
#include <string>

using namespace std;

int main (int argc, char **argv)
{
	char c;
	string str = "", temp;
	
	if (argc < 2)
		return -1;
	
	ifstream f1(argv[1]);
	if (f1.file())
		return -1;
	while (f1.get(c)) {
		if (c == '[') {
			temp = c;
			while (c != ']' && f1.get(c)) {
				temp += c;
			}
			if (c != ']')
				str += temp;
		}
		else
			str += c;
	}
	
	ofstream f2(argv[1]);
	f2 << str;
	f2.close();
	
	return 0;
}
