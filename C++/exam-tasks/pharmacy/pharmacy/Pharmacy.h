#pragma once

#include <iostream>
#include "../medicine/Medicine.h"

class Pharmacy
{
public:
	Pharmacy();
	Pharmacy(std::string name, unsigned int medsAmount);
	~Pharmacy();
	void printAllMeds() const;
	void addNewMed();
	void deleteMed();
	void printById() const;
	void printCheapestByMedName() const;
	bool hasMedicineByRegId(const std::string& regId) const;
	bool hasMedicineByName(const std::string& name) const;
private:
	std::string m_name;
	unsigned int m_medsAmount{};
	Medicine* m_medicines;
};