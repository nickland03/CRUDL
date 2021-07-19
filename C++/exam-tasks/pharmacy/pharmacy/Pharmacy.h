#pragma once

#include <iostream>
#include "../medicine/Medicine.h"

class Pharmacy
{
public:
	Pharmacy();
	Pharmacy(std::string name, unsigned int medsAmount);
	~Pharmacy();
	//Custom method
	void printAllMeds() const;
	void addNewMed();
	void deleteMed();
	void printById() const;
	void printCheapestByMedName() const;
	bool hasMedicineByRegId(std::string regId) const;
	bool hasMedicineByName(std::string name) const;
private:
	std::string m_name;
	unsigned int m_medsAmount;
	Medicine* m_medicines;
};