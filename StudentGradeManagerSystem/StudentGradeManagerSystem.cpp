#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student {
	string name = "";
	int id = 0;
	float mark = 0;

};

//f1
void addStudent(ofstream& file);

//f2
void calculateAverageGrade(ifstream& file, float* average);

//f3
void search(ifstream& file, int idSearch);


int main()
{
	float average = 0;
	float* average_pointer = &average;
	int id_search = 0;
	string answer = "";

	cout << "do you want to add a new student: ";
	cin >> answer;
	if(answer=="yes")
	{
		ofstream fout;
		addStudent(fout);
	}


	ifstream fin;
	calculateAverageGrade(fin, average_pointer);
	cout << endl << "the average is: " << *average_pointer << endl;

	cout << endl << "please enter the id you want to search for: ";
	cin >> id_search;

	ifstream fin2;
	search(fin2, id_search);


}




void addStudent(ofstream& file) {
	file.open("student.txt", ios::app);
	if (file.is_open())
	{
		int iteration = 0;
		float DataInNumber = 0;
		cout << "please enter the number of students you want to add (example: 3) : "; cin >> iteration;
		string data = "";


		for (int c = 0;c < iteration;c++) {

			cout << "please enter the name of the student: ";
			cin >> data;
			file << data << "\t";
			cout << "name added successfully" << endl;

			cout << "please enter the id of the student: ";
			cin >> data;
			file << data << "\t";
			cout << "id added successfully" << endl;

		start:
			cout << "please enter the mark of the student: ";
			cin >> data;
			DataInNumber = stoi(data);
			try
			{
				if ((DataInNumber >= 0) && (DataInNumber <= 100))
				{
					file << data << "\n";
					cout << "mark added successfully" << endl;
				}

				else
					throw - 1;


			}
			catch (...) {
				cout << "invalid input marks can't be smaller than '0' or greater than '100'" << endl;
				goto start;
			}

			cout << endl << endl << "data of student number " << c + 1 << " added successfully" << endl;

		}

		file.close();


	}
	else
		cout << "couldn't open file" << endl;
}

void calculateAverageGrade(ifstream& file, float* average) {
	file.open("student.txt");
	if (file.is_open())
	{
		int i = 0;
		float aver = 0;
		student array[10] = {};
		while (!file.eof()) {

			file >> array[i].name >> array[i].id >> array[i].mark;
			aver += array[i].mark;
			i++;
		}
		aver /= (i - 1);
		*average = aver;
		



		file.close();

	}

	else
		cout << "can't open file please try again later" << endl;

}

void search(ifstream& file, int idSearch) {

	file.open("student.txt");
	if (file.is_open())
	{
		bool found = 0;
		int c = 0;
		student arr[10] = {};
		while (!file.eof()) {
			file >> arr[c].name >> arr[c].id >> arr[c].mark;
			if (arr[c].id == idSearch) {
				found = 1;
				break;
			}

		}
		if (found) {
			cout << "found id in line : " << c + 1 << endl;
		}
		else
			cout << "id not found" << endl;

		file.close();
	}
	else
		cout << "couldn't open file " << endl;
	

}