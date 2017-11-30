//
// EPITECH PROJECT, 2017
// 
// File description:
//
//

#include "APizza.h"

float APizza::getCookingTime() const {
	return cookingTime;
}

pizzaType APizza::getType() const {
	return type;
}

const std::string &APizza::getSize() const {
	return size;
}
