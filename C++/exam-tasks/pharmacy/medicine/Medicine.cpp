#include "Medicine.h"
#include <iomanip>
#include <utility>

Medicine::Medicine()
	: m_name(""), m_id(""), m_package(""), m_unitPrice(0), m_quantity(0)
{}

Medicine::Medicine(std::string  name, std::string  id, std::string  package, float unitPrice, int quantity)
	: m_name(std::move(name)), m_id(std::move(id)), m_package(std::move(package)), m_unitPrice(unitPrice), m_quantity(quantity)
{}

void Medicine::printData() const
{
	std::cout << "Information for medicine with registration ID [" << m_id << "]" << std::endl;
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Package: " << m_package<< std::endl;
	std::cout << "Unit price: " << std::fixed << std::setprecision(2) << m_unitPrice << std::endl;
	std::cout << "Available quantity: " << m_quantity << std::endl << std::endl;
}

void Medicine::readData()
{
	std::cout << "Name: ";
	std::cin.ignore();
	std::getline(std::cin, m_name);

	std::cout << "Registration ID: ";
	std::cin >> m_id;

	std::cout << "Package: ";
	std::cin.ignore();
	std::getline(std::cin, m_package);

	std::cout << "Price: ";
	std::cin >> m_unitPrice;

	std::cout << "Quantity: ";
	std::cin >> m_quantity;

	std::cout << std::endl;
}

bool Medicine::operator>(Medicine const& other) const
{
	return this->m_unitPrice > other.m_unitPrice;
}
