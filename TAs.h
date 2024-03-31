#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class TAs
{
	int Student_Id;
	string Status;
	int Year_Hired;
	int Working_Hours;

	int TAs_Number = 0;

	vector <TAs> TAs_Vector;

	ifstream inFile;
	ofstream outFile;

public:
	TAs();

	TAs(const TAs&);

	void copyInfo(); //Copies the data from TAs.txt into a vector of TA objects and displays it

	void modifyInfo(); //Updated the data from TAs.txt using the vector of TA objects

	void getInfo(); //Displays the content of the vector of TA objects

	void addNewTAs(); //Lets the user enter as many TAs as they'd like 

	void sortTAS(); //Lets the user choose their desired way to sort TAs 
};

