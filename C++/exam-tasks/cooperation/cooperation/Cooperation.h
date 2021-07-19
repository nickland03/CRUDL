#pragma once

#include <iostream>
#include <string>
#include "../apartament/Apartament.h"

namespace project15 {
    class Cooperation {
    private:
        std::string m_name;
        unsigned int m_size{};
        Apartament *m_apartaments;
    public:
        Cooperation();

        Cooperation(std::string name, unsigned int size);

        ~Cooperation();

        void printAllApartaments() const;
        void printDataByOwner() const;
        void printByBiggestFamilyOnFloor() const;
        void renewOwner() const;
        void deleteOwner();
        void start();
        static void fetchMenu();

        unsigned int getApartamentIdByOwner(const std::string &owner) const;
        int getApartamentIdxByApartamentId(unsigned int apartamentId) const;
        bool ownerExists(const std::string &owner) const;
        bool hasApartamentOnFloor(unsigned int floor) const;
    };
}