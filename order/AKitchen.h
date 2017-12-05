//C++ exception with description "basic_string::_M_construct null not valid" thrown in the test body.unknown file: Failure
// EPITECH PROJECT, 2017
// 
// File description:
//
//

#ifndef PLAZZAV1_AKITCHEN_H
#define PLAZZAV1_AKITCHEN_H


#include "../Pizza/PizzaFactory.h"

class AKitchen {
private:
	int id;
	PizzaFactory pizzaFactory;
public:
	int getId() const;
};


#endif //PLAZZAV1_AKITCHEN_H
