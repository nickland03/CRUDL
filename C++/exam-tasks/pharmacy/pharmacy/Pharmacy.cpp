#include "../medicine/Medicine.h"
#include "Pharmacy.h"
#include <string>
#include <iomanip>
#include <utility>

Pharmacy::Pharmacy()
{
	std::cout << "Pharmacy name: ";
	std::getline(std::cin, m_name);

	std::cout << "Number of available meds: ";
	std::cin >> m_medsAmount;

	m_medicines = new Medicine[m_medsAmount];

	for (unsigned int i = 0; i < m_medsAmount; i++) {
		m_medicines[i].readData();
	}
}

Pharmacy::Pharmacy(std::string name, unsigned int medsAmount)
{
	m_name = std::move(name);
	m_medsAmount = medsAmount;

	m_medicines = new Medicine[m_medsAmount];

	for (unsigned int i = 0; i < m_medsAmount; i++) {
		m_medicines[i].readData();
	}
}

Pharmacy::~Pharmacy()
{
	delete[] m_medicines;
}

void Pharmacy::printAllMeds() const
{
	for (unsigned i = 0; i < m_medsAmount; i++) {
		m_medicines[i].printData();
	}
}

void Pharmacy::addNewMed()
{
	m_medsAmount++;
	Medicine* currMeds = m_medicines;
	m_medicines = new Medicine[m_medsAmount];
	for (unsigned int i = 0; i < m_medsAmount - 1; i++) {
		m_medicines[i] = currMeds[i];
	}
	m_medicines[m_medsAmount - 1].readData();
	delete[] currMeds;
}

void Pharmacy::deleteMed()
{
	std::string regId;
	std::cout << "Enter an medicine registration ID: ";
	std::cin >> regId;
	if (!hasMedicineByRegId(regId)) {
		std::cout << "\n\t\t[INFO]: There is no such medicine with that registration ID." << std::endl << std::endl;
		return;
	}
	Medicine* currMeds = m_medicines;
	m_medsAmount--;
	m_medicines = new Medicine[m_medsAmount];
	for (unsigned int i = 0; i < m_medsAmount + 1; i++) {
		if (currMeds[i].getId() != regId) {
			m_medicines[i] = currMeds[i];
		}
	}
	delete[] currMeds;
}

void Pharmacy::printById() const
{
	std::string regId;
	std::cout << "Enter an medicine registration ID: ";
	std::cin >> regId;
	if (!hasMedicineByRegId(regId)) {
		std::cout << "\n\t\t[INFO]: There is no such medicine with that registration ID. " << std::endl << std::endl;
		return;
	}

	for (unsigned int i = 0; i < m_medsAmount; i++) {
		if (m_medicines[i].getId() == regId) {
			m_medicines[i].printData();
		}
	}
}

void Pharmacy::printCheapestByMedName() const
{
	std::string medName;
	std::cout << "Enter medicine name: ";
	std::cin >> medName;
	Medicine cheapest;

	if (!hasMedicineByName(medName)) {
		std::cout << "\n\t\t[INFO]: There is no med with that name." << std::endl << std::endl;
		return;
	}

	for (unsigned int i = 0; i < m_medsAmount; i++) {
		if (m_medicines[i].getName() == medName) {
			cheapest = m_medicines[i];
			break;
		}
	}

	for (unsigned int i = 0; i < m_medsAmount; i++) {
		if (m_medicines[i].getName() == medName && cheapest > m_medicines[i]) {
			cheapest = m_medicines[i];
		}
	}

	cheapest.printData();
}

bool Pharmacy::hasMedicineByRegId(const std::string& regId) const
{
	for (unsigned int i = 0; i < m_medsAmount; i++) {
		if (m_medicines[i].getId() == regId) {
			return true;
		}
	}
	return false;
}

bool Pharmacy::hasMedicineByName(const std::string& name) const
{
	for (unsigned int i = 0; i < m_medsAmount; i++) {
		if (m_medicines[i].getName() == name) {
			return true;
		}
	}
	return false;
}
