#include "TAs.h"

TAs::TAs() : Student_Id{ 0 }, Status{ "None" }, Year_Hired{ 2023 }, Working_Hours{ 0 } {
}

TAs::TAs(const TAs& TA) {

	this->Student_Id = TA.Student_Id;
	this->Status = TA.Status;
	this->Year_Hired = TA.Year_Hired;
	this->Working_Hours = TA.Working_Hours;
}

void TAs::copyInfo() {

	inFile.open("TAs.txt");

	if (inFile.is_open()) {

		TAs TA;

		inFile >> TAs_Number;

		cout << "Initial Student File:\n";
		cout << TAs_Number << endl;

		while(inFile >> TA.Student_Id >> TA.Status >> TA.Year_Hired >> TA.Working_Hours) {

			cout << TA.Student_Id << "\t";
			cout << TA.Status << "\t";
			cout << TA.Year_Hired << "\t";
			cout << TA.Working_Hours << endl;

			if (TA.Status != "Alum") {

				TAs_Vector.push_back(TA);

			}
		}

		cout << endl;

		TAs_Number = TAs_Vector.size();

		inFile.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void TAs::modifyInfo() {

	outFile.open("TAs.txt");

	if (outFile.is_open()) {

		outFile << TAs_Number;

		for (int x = 0; x < TAs_Number; x++) {

			outFile << endl;

			outFile << TAs_Vector[x].Student_Id << "\t";
			outFile << TAs_Vector[x].Status << "\t";
			outFile << TAs_Vector[x].Year_Hired << "\t";
			outFile << TAs_Vector[x].Working_Hours;
		}

		outFile.close();
	}
	else {
		cout << "Unable to open file";
	}
}

void TAs::getInfo() {

	cout << "After Correction:\n";

	cout << TAs_Number << endl;

	for (int x = 0; x < TAs_Number; x++) {

		cout << TAs_Vector[x].Student_Id << "\t";
		cout << TAs_Vector[x].Status << "\t";
		cout << TAs_Vector[x].Year_Hired << "\t";
		cout << TAs_Vector[x].Working_Hours << endl;
	}
}

void TAs::addNewTAs() {

	int new_TAS;

	cout << "How many TAs should we add: ";
	cin >> new_TAS;

	cout << "\nFormat: Student_ID  Status  Year_Hired  Working_Hours\n\n";

	TAs NewTA;

	bool restriction = true;

	for (int y = 1; y <= new_TAS; y++) {

		restriction = true;

		while (restriction == true) {

			try {

				cout << "TA number " << y << ": ";

				cin >> NewTA.Student_Id >> NewTA.Status >> NewTA.Year_Hired >> NewTA.Working_Hours;

				if (cin.fail()) {

					cin.clear();

					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					throw invalid_argument("Invalid input! Please enter an integer for Student_ID, Year_Hired and Working_Hours\n");
				}
				else if (NewTA.Status == "Alum") {

					cin.clear();

					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					throw invalid_argument("Alumni are ineligible! Please enter 'Grad' or 'UGrad' as Status\n");
				}
				else if (NewTA.Status != "Grad" && NewTA.Status != "UGrad") {

					cin.clear();

					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					throw invalid_argument("Invalid input! Please enter 'Grad' or 'UGrad' as Status\n");
				}
				else {

					for (int z = 0; z < TAs_Number; z++) {

						if (TAs_Vector[z].Student_Id == NewTA.Student_Id) {

							cin.clear();

							cin.ignore(numeric_limits<streamsize>::max(), '\n');

							throw invalid_argument("The Student_ID entered already exist! Please enter a different Student_ID\n");
						}
					}
				}

				TAs_Vector.push_back(NewTA);

				TAs_Number++;

				restriction = false;
			}
			catch (const invalid_argument& exception) {

				cout << "Error: " << exception.what() << endl;

			}
		}
	}

	cout << endl;
}

void TAs::sortTAS() {

	int sort_option_1;
	int sort_option_2;

	cout << endl;
	cout << "1. Sort by Student_ID\n";
	cout << "2. Sort by Status\n";
	cout << "3. Sort by Year_Hired\n";
	cout << "4. Sort by Working_Hours\n\n";

	bool restriction_1 = true;
	bool restriction_2 = true;

	while (restriction_1 == true) {

		cout << "How would you like the TAs to be sorted: ";

		try {
			cin >> sort_option_1;

			if (cin.fail() && sort_option_1 < 1 && sort_option_1 > 4) {

				cin.clear();

				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				throw invalid_argument("Invalid input! Please enter an integer between 1 and 4\n");
			}

			cout << "\n1. Ascending Order\n";
			cout << "2. Descending Order\n\n";

			while (restriction_2 == true) {

				try {
					cout << "By Ascending (1) or by Descending (2) order?: ";
					cin >> sort_option_2;
					cout << endl;

					if (cin.fail()) {

						cin.clear();

						cin.ignore(numeric_limits<streamsize>::max(), '\n');

						throw invalid_argument("Invalid input! Please enter an either 1 or 2\n");
					}

				}
				catch (const invalid_argument& int_exception) {

					cout << "Error: " << int_exception.what() << endl;

				}

				restriction_2 = false;
			}

			//Sorting incoming
			//std::sort(TAs_Vector.begin(), TAs_Vector.end());

			restriction_1 = false;
		}
		catch (const invalid_argument& int_exception) {

			cout << "Error: " << int_exception.what() << endl;

		}
	}

}
