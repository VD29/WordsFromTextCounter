#include <fstream>
#include <string>
#include <iostream>

using namespace std;

bool find_substring(const string& word_to_find, const string& target) {
	size_t found = target.find(word_to_find);
	if (found == string::npos) {
		return false;
	}
	else {
		return true;
	}
}

int main()
{
	ifstream fin;
	string path = "RomeoAndJuliet.txt";
	string word_to_find{};
	string word_read{};

	long word_count{ 0 };
	long match_count{ 0 };


	fin.open(path);

	if (!fin) {
		cerr << "Error opening file" << endl;
		return 1;
	}

	cout << "Enter the substring to search for: ";
	cin >> word_to_find;

	while (fin >> word_read) {
		++word_count;
		if (find_substring(word_to_find, word_read)) {
			++match_count;
		}
	}

	cout << endl << word_count << " words were searched..." << endl << endl;
	cout << "The substring " << word_to_find << " was found " << match_count << " times" << endl;

	fin.close();
	cout << endl << endl;

	return 0;
}