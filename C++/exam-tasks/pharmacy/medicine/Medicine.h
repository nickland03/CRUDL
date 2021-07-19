#pragma once
#include <iostream>

class Medicine
{
public:
	Medicine();
	Medicine(std::string  name, std::string  id, std::string  package, float unitPrice, int quantity);
	void printData() const;
	void readData();
	bool operator>(Medicine const& other) const;
	std::string getId() const { return m_id; };
	std::string getName() const { return m_name; }
private:
	std::string m_name, m_id, m_package;
	float m_unitPrice;
	int m_quantity;
};