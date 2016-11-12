#include "stdafx.h"
#include "vector"
#include "algorithm"
#include "iostream"
#include "string"
#include "fstream"
using namespace std;
int option;
void readFile()
{
	ifstream fileIn("Text.txt");
	string keywords, line;
	cout << "=====================\nInput key words\n=====================\n";
	getline(cin, keywords);
	while (getline(fileIn, line)) {
		if (line.find(keywords) != string::npos) {
			cout << line << "\n";
		}
	}
	fileIn.close();
}
void writeFile()
{
	ofstream fileOut("Text.txt", ios_base::app | ios_base::out);
	string line;
	cout << "=====================\nInput new data\nForm: (Name Surname, Address, Phone)\n=====================\n";
	getline(cin, line);
	fileOut << endl << line << endl;
	cout << "Input successful!\n";
	fileOut.close();
}
void showFile()
{
	string line;
	ifstream fileIn("Text.txt");
	while (getline(fileIn, line)) {
		cout << line << endl;
	}
	fileIn.close();
}
void deleteFile()
{
	ifstream fileIn("Text.txt");
	ofstream fileOut("Text.txt", ios_base::app | ios_base::out);
	ofstream temp("Temp.txt", ios_base::app | ios_base::out);
	string keywords, line;
	cout << "=====================\nInput key words\n=====================\n";
	getline(cin, keywords);
	while (getline(fileIn, line)) {
		if (line.find(keywords) != string::npos) {
			cout << "=====================\nLine '" << line << "' was deleted\n";
			continue;
		}
		else temp << line << endl;
	}
	fileIn.close();
	fileOut.close();
	temp.close();
	remove("Text.txt");
	rename("Temp.txt", "Text.txt");
	remove("Temp.txt");
}
int main()
{
	cout << "=====================\n====Choose action====\n1. Search for info\n2. Add info\n3. Delete info\n4. Output whole base\n5. Close Application\n=====================\n";
	cin >> option;
	cin.ignore();
	if (option == 1) readFile();
	if (option == 2) writeFile();
	if (option == 3) deleteFile();
	if (option == 4) showFile();
	if (option == 5) return 0;
	main();
}