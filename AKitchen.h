//
// EPITECH PROJECT, 2017
// Plazza project
// File description:
// AKitchen.cpp
//

#ifndef AKITCHEN_H
#define AKITCHEN_H

#include "Pizza/PizzaFactory.h"

class AKitchen {
private:
	int id;
public:
	int getId() const;
	PizzaFactory pizzaFactory;
};

#endif //AKITCHEN_H
