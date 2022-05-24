#include <iostream>
#include <string>

using namespace std;

struct Student
{
	string Surname;
	string Group;
	int Nlist = 0;
	int Money = 0;
};


void inputArr(int size, Student* man) {
	cout << "Enter all information about student: " << endl;
	cout << "___\t" << "___\t" << "___\t" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << endl << "Surname: ";
		cin >> man[i].Surname;

		cout << "Group: ";
		cin >> man[i].Group;

		cout << "Number on the list: ";
		cin >> man[i].Nlist;

		cout << "Scholarship: ";
		cin >> man[i].Money;
	}
	cout << "___\t" << "___\t" << "___\t" << endl;
}

void sortStr(int size, Student* man) {

	Student** pman = new Student * [size];
	for (int i = 0; i < size; i++) {
		pman[i] = (man + i);
	}

	Student buffer;

	bool isSwap = false;

	for (int i = 0; i < size - 1; i++)
	{
		bool isSwap = false;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (man[j].Nlist > man[j + 1].Nlist) {
				buffer = *(pman[j]);
				*(pman[j]) = *(pman[j + 1]);
				*(pman[j + 1]) = buffer;
				isSwap = true;
			}
		}
		if (isSwap == false)
			break;
	}

	delete[] pman;
}

void outArr(int size, Student* man) {
	cout << endl << endl << '\t';
	cout << "... ... OUT STUDENTS: ... ..." << endl;
	for (int i = 0; i < size; i++) {
		cout << "Surname: " << man[i].Surname << endl;
		cout << "Group: " << man[i].Group << endl;
		cout << "Number on the list: " << man[i].Nlist << endl;
		cout << "Scholarship: " << man[i].Money << endl;
		cout << endl;
	}
}

void main()
{
	cout << "Enter number of students: ";
	int size;
	cin >> size;

	Student* man = new Student[size];

	inputArr(size, man);
	sortStr(size, man);
	outArr(size, man);

	delete[] man;
}