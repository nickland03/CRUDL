#pragma once
#include <iostream>
#include <string>

const std::string NO_AVAILABLE_OWNER  = "Currently has no owner";

namespace project15 {
	class Apartament
	{
	private:
		std::string m_owner;
		unsigned m_id, m_floor, m_residents;
	public:
		Apartament();
		Apartament(
			unsigned int id,
			std::string owner,
			unsigned int floor,
			unsigned int residents
		);
		void printData() const;
		void readData();
		void setNewOwner();
		void deleteOwner();
		bool operator>(Apartament const& other) const;
		unsigned int getID() const { return m_id; }
		std::string getOwner() const {
			return (m_owner != NO_AVAILABLE_OWNER) ? m_owner : "";
		}
		unsigned int getFloor() const { return m_floor; }
	};
}