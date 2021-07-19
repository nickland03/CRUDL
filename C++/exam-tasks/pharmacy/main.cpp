#include <iostream>
#include "pharmacy/Pharmacy.h"

int main()
{
	Pharmacy pharmacy;
	unsigned int optionID;

	do {
		std::cout << "\n\t\t [MENU] " << std::endl;
		std::cout << "1. Add medicine to the pharmacy" << std::endl;
		std::cout << "2. Delete medicine from the pharmacy" << std::endl;
		std::cout << "3. Print all meds" << std::endl;
		std::cout << "4. Print by registration ID" << std::endl;
		std::cout << "5. Print cheapest med" << std::endl;
		std::cout << "Press 0 for exit" << std::endl;

		std::cout << "\n[Manager]: Choose an option: ";
		std::cin >> optionID;

		switch (optionID)
		{
		case 1:
			pharmacy.addNewMed();
			break;
		case 2:
			pharmacy.deleteMed();
			break;
		case 3:
			pharmacy.printAllMeds();
			break;
		case 4:
			pharmacy.printById();
			break;
		case 5:
			pharmacy.printCheapestByMedName();
			break;
		case 0:
			break;
		default:
			std::cout << "\n\t\t[INFO]: Invalid option" << std::endl;
		}
    
	} while (optionID);

	return 0;
}