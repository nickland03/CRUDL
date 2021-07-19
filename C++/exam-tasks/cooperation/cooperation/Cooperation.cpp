#include "Cooperation.h"

project15::Cooperation::Cooperation()
{
	std::cout << "Coopration name: ";
	std::getline(std::cin, m_name);

	std::cout << "Number of apartaments: ";
	std::cin >> m_size;

	m_apartaments = new Apartament[m_size];

	for (unsigned int i = 0; i < m_size; i++) {
		std::cin.ignore();
		m_apartaments[i].readData();
	}
}

project15::Cooperation::Cooperation(std::string name, unsigned int size)
{
	m_name = name;
	m_size = size;

	std::cout << "\tThere are " << m_size << " available apartament(s)." << std::endl;

	m_apartaments = new Apartament[m_size];

	for (unsigned int i = 0; i < m_size; i++) {
		m_apartaments[i].readData();
	}
}

project15::Cooperation::~Cooperation()
{
	delete[] m_apartaments;
}

void project15::Cooperation::printAllApartaments() const
{
	for (unsigned i = 0; i < m_size; i++) {
		m_apartaments[i].printData();
	}
}

void project15::Cooperation::printDataByOwner() const
{
	std::string owner;
	std::cout << "Enter an owner: ";
	std::cin.ignore();
	std::getline(std::cin, owner);

	unsigned int apartamentID = (getApartamentIdByOwner(owner) - 1);

	if (ownerExists(owner)) {
		m_apartaments[apartamentID].printData();
	}
	else {
		std::cout << "There is no such owner." << std::endl;
	}
}

void project15::Cooperation::printByBiggestFamilyOnFloor() const
{
	Apartament largest;
	unsigned int floor;

	std::cout << "Enter a floor: ";
	std::cin >> floor;

	if (!hasApartamentOnFloor(floor)) {
		std::cout << "No apartament on this floor" << std::endl;
		return;
	}
	for (unsigned int i = 0; i < m_size; i++) {
		if ((m_apartaments[i].getFloor() == floor) && (m_apartaments[i] > largest)) {
			largest = m_apartaments[i];
		}
	}

	largest.printData();
}

unsigned int project15::Cooperation::getApartamentIdByOwner(const std::string& owner) const
{
	unsigned int apartamentId = 0;

	for (unsigned int i = 0; i < m_size; i++) {
		if (m_apartaments[i].getOwner() == owner && !owner.empty())
			apartamentId = i + 1;
	}
	return apartamentId;
}

bool project15::Cooperation::ownerExists(const std::string& owner) const
{
	for (unsigned int i = 0; i < m_size; i++) {
		if (m_apartaments[i].getOwner() == owner && !owner.empty()) {
			return true;
		}
	}
	return false;
}

bool project15::Cooperation::ApartamentExists(unsigned int apartamentId) const
{
	for (unsigned int i = 0; i < m_size; i++) {
		if (apartamentId == i + 1) {
			return true;
		}
	}
	return false;
}

bool project15::Cooperation::hasApartamentOnFloor(unsigned int floor) const {
	for (unsigned int i = 0; i < m_size; i++) {
		if (m_apartaments[i].getFloor() == floor) {
			return true;
		}
	}
	return false;
}

void project15::Cooperation::renewOwner()
{
	int apartamentId;
	std::cout << "Choose an apartament ID: ";
	std::cin >> apartamentId;

	if (!ApartamentExists(apartamentId)) {
		std::cout << "There is no apartament with that ID." << std::endl;
		return;
	}
	m_apartaments[apartamentId - 1].setNewOwner();
}

void project15::Cooperation::deleteOwner()
{
	int apartamentId;
	std::cout << "Choose an apartament ID: ";
	std::cin >> apartamentId;

	if (!ApartamentExists(apartamentId)) {
		std::cout << "There is no apartament with that ID." << std::endl;
		return;
	}

	m_apartaments[apartamentId - 1].deleteOwner();
}

void project15::Cooperation::fetchMenu() const
{
	std::cout << "\t\t Menu " << std::endl;
	std::cout << "\t 1. Print all apartaments." << std::endl;
	std::cout << "\t 2. Create new owner for an apartament." << std::endl;
	std::cout << "\t 3. Delete data for owner by apartament ID." << std::endl;
	std::cout << "\t 4. Print data by owner name." << std::endl;
	std::cout << "\t 5. Print largest family for specific floor." << std::endl;
	std::cout << "\t 0. [EXIT]" << std::endl;
}

void project15::Cooperation::start()
{
	unsigned optionID;

	do {
		fetchMenu();

		std::cin >> optionID;

		switch (optionID) {
		case 1:
			printAllApartaments();
			break;
		case 2:
			renewOwner();
			break;
		case 3:
			deleteOwner();
			break;
		case 4:
			printDataByOwner();
			break;
		case 5:
			printByBiggestFamilyOnFloor();
			break;
		case 0:
			exit(1);
			break;
		default:
			std::cout << "Incorrect option." << std::endl;
		}
	} while (optionID);
}