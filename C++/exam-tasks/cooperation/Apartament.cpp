#include "Apartament.h"

project15::Apartament::Apartament()
	: m_id(0), m_owner(""), m_floor(0), m_residents(0)
{}

project15::Apartament::Apartament(
	unsigned int id,
	std::string owner, 
	unsigned int floor, 
	unsigned int residents
) : m_id(id), m_owner(owner), m_floor(floor), m_residents(residents)
{}

void project15::Apartament::printData() const
{
	std::cout << "Data for apartament [" << m_id << "]" << std::endl;

	std::cout << "Owner: " << m_owner << std::endl;
	std::cout << "Floor: " << m_floor << std::endl;
	std::cout << "Residents: " << m_residents << "\n" << std::endl;
}

void project15::Apartament::readData()
{
	std::cout << "Owner: ";
	std::getline(std::cin, m_owner);

	std::cout << "Apartament floor: ";
	std::cin >> m_floor;

	std::cout << "Residents of the apartament: ";
	std::cin >> m_residents;

	std::cout << "Number of the apartament: ";
	std::cin >> m_id;
}

void project15::Apartament::setNewOwner()
{
	std::cout << "Renew the owner for apartament [" << m_id << "]" << std::endl;
	std::cout << "New owner: ";
	std::cin.ignore();
	do {
		std::getline(std::cin, m_owner);
		if (m_owner.empty())
			std::cout << "New owner: ";
	} while (m_owner.empty());
}

void project15::Apartament::deleteOwner()
{
	m_owner = NO_AVAILABLE_OWNER;
}

bool project15::Apartament::operator>(Apartament const& other) const
{
	return this->m_residents > other.m_residents;
}