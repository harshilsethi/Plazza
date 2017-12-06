//
// EPITECH PROJECT, 2017
// 
// File description:
//
//

#ifndef PLAZZAV1_AKITCHEN_H
#define PLAZZAV1_AKITCHEN_H


#include "Pizza/PizzaFactory.h"

class AKitchen {
private:
	int id;
	PizzaFactory pizzaFactory;
public:
	int getId() const;
};


#endif //PLAZZAV1_AKITCHEN_H
