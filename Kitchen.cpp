//
// Created by jerome on 02/12/17.
//

#include "Kitchen.h"

Kitchen::Kitchen(int _nbCookers) {
	nbCookers = _nbCookers;
}

Kitchen::~Kitchen() = default;

int Kitchen::getNbCookers() {
	return nbCookers;
}

std::list<Cooker> Kitchen::getCookers() {
	return cookers;
}

void Kitchen::addOrder(std::string &anOrder) {
	orders.push(anOrder);
}

void Kitchen::dispatch() {
	//fait faire les pizzas par les cuisinier
	std::cout << "Cooking !" << std::endl;
}