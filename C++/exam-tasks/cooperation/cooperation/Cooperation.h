#pragma once
#include <iostream>
#include <string>
#include "../apartament/Apartament.h"

namespace project15 {
	class Cooperation
	{
	private:
		std::string m_name;
		unsigned int m_size;
		Apartament* m_apartaments;
	public:
		Cooperation();
		Cooperation(std::string name, unsigned int size);
		~Cooperation();
		void printAllApartaments() const;
		void printDataByOwner() const;
		void printByBiggestFamilyOnFloor() const;
		unsigned int getApartamentIdByOwner(const std::string& owner) const;
		bool ownerExists(const std::string& owner) const;
		bool ApartamentExists(unsigned int number) const;
		bool hasApartamentOnFloor(unsigned int floor) const;
		void renewOwner();
		void deleteOwner();
		void fetchMenu() const;
		void start();
	};
}