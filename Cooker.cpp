//
// EPITECH PROJECT, 2017
// Plazza project
// File description:
// Cooker.cpp
//

#include <fstream>
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
	id = nextId;
}

Cooker::~Cooker(){
	delete pizza;
}

Cooker::Cooker(const Cooker &origin) {
	id = origin.id;
	pizza = origin.pizza;
	busy = origin.busy;
}

Cooker &Cooker::operator=(Cooker const &origin) {
	if (this != &origin) {
		id = origin.id;
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

void Cooker::cookPizza(std::string const &pizza, std::string const &size, int timeBase, PizzaFactory *factory) {
	std::fstream file;
	std::string path;
	long int timeToWait;
	cookerMtx.lock();
	Kitchen *kitchen = getKitchen();
	kitchen->updateStatus(timeBase);

	path = "Txt/PizzaCooked/Pizzas.txt";
	file.open(path, std::fstream::app);
	if (file){
		file << "The " << pizza << " was cooked in kitchen " << kitchen->getId() <<  std::endl;
	}
	file.close();
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
	busy = false;
        kitchen->setNbOfBusyCookers(-1);
	kitchen->updateStatus(timeBase);
}

void Cooker::runThread(const std::string &aPizza, const std::string &aSize, int timeBase, PizzaFactory *factory) {
	std::thread cookerTh(&Cooker::cookPizza, this, aPizza, aSize, timeBase, factory);
	busy = true;
	cookerTh.join();
}

void Cooker::reset() {
	pizza = nullptr;
	busy = false;
}

bool Cooker::isBusy() {
	return busy;
}