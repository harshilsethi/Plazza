//
// EPITECH PROJECT, 2017
// Plazza project
// File description:
// Cooker.cpp
//

#include "Cooker.h"
#include "Pizza/Margarita.h"
#include "Pizza/American.h"
#include "Pizza/Fantasia.h"
#include "Pizza/Regina.h"
#include "Kitchen.h"

static int nextId = 0;

Cooker::Cooker() {
	nextId++;
	pizza = nullptr;
	//kitchen = nullptr;
	id = nextId;
}

Cooker::~Cooker(){
	delete pizza;
}

Cooker::Cooker(const Cooker &origin) /*: kitchen(origin.kitchen) */{
	id = origin.id;
	pizza = origin.pizza;
	busy = origin.busy;
}

Cooker &Cooker::operator=(Cooker const &origin) {
	if (this != &origin) {
		id = origin.id;
		//kitchen = origin.kitchen;
		pizza = origin.pizza;
		busy = origin.busy;
	}
	return *this;
}

int Cooker::getId() const{
	return (id);
}

Kitchen *Cooker::getKitchen() const {
	return kitchen;
}

void Cooker::setKitchen(Kitchen *kitchen) {
	this->kitchen = kitchen;
}

const APizza &Cooker::getPizza() const {
	return *pizza;
}

void Cooker::cookPizza(std::string pizza, std::string size, int timeBase, PizzaFactory *factory) {
	long int timeToWait;
	cookerMtx.lock();
	Kitchen *kitchen = getKitchen();
        //kitchen->setNbOfBusyCookers(1);
	kitchen->updateStatus(timeBase);
	std::cout << "Cooking the pizza: " << pizza << " in kitchen " << kitchen->getId() << std::endl;
	if (pizza == "Margarita") {
		std::unique_ptr<APizza> pizzaCooked = factory->createPizza(factory->MARGARITA, size);
		timeToWait = static_cast<long>(pizzaCooked->getCookTime() * timeBase);
		std::this_thread::sleep_for(std::chrono::milliseconds(timeToWait));
	} else if (pizza == "American") {
		std::unique_ptr<APizza> pizzaCooked = factory->createPizza(factory->AMERICAN, size);
		timeToWait = static_cast<long>(pizzaCooked->getCookTime() * timeBase);
		std::this_thread::sleep_for(std::chrono::milliseconds(timeToWait));
	} else if (pizza == "Fantasia") {
		std::unique_ptr<APizza> pizzaCooked = factory->createPizza(factory->FANTASIA, size);
		timeToWait = static_cast<long>(pizzaCooked->getCookTime() * timeBase);
		std::this_thread::sleep_for(std::chrono::milliseconds(timeToWait));
	} else if (pizza == "Regina") {
		std::unique_ptr<APizza> pizzaCooked = factory->createPizza(factory->REGINA, size);
		timeToWait = static_cast<long>(pizzaCooked->getCookTime() * timeBase);
		std::this_thread::sleep_for(std::chrono::milliseconds(timeToWait));
	}
	cookerMtx.unlock();
	busy = false; //at the end
        kitchen->setNbOfBusyCookers(-1);
	kitchen->updateStatus(timeBase);
}

void Cooker::runThread(const std::string &aPizza, const std::string &aSize, int timeBase, PizzaFactory *factory) {
	std::thread cookerTh(&Cooker::cookPizza, this, aPizza, aSize, timeBase, factory);
	busy = true;
	cookerTh.join();
}

void Cooker::reset() {
	//kitchen = -1; // not sure ...
	pizza = nullptr;
	busy = false;
}

bool Cooker::isBusy() {
	return busy;
}
