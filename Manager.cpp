/*
** EPITECH PROJECT, 2017
** Plazza project
** File description:
** Manager.cpp
*/

#include "Manager.h"
#include <boost/algorithm/string.hpp>

Manager::Manager() : managerTeam(30){
	std::cout << "Manager : I'm the Plazza's manager !" << std::endl;
	orderID = 1;
	idKitchen = 0;
}

Manager::~Manager() {
	while(!kitchens.empty()){
		delete kitchens.front();
		kitchens.pop_front();
	}
}

static inline std::string &ltrim(std::string &s) {
	s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
	return s;
}

template <class Container>
void split5(const std::string& str, Container& cont,
	    const std::string& delims = ";")
{
	boost::split(cont, str, boost::is_any_of(delims));
}

std::queue<std::string> Manager::convertInputIntoOrder(Order order) {
	std::string orderToConvert = order.getCommand();
	std::vector<std::string> result;
	int pizzaCounter;
	int cpt;

	ltrim(orderToConvert);
	std::cout << orderToConvert << std::endl;
	split5(orderToConvert, result);
	std::copy(result.begin(), result.end(),
		  std::ostream_iterator<std::string>(std::cout, "\n"));
	for (auto &entry : result){
		pizzaCounter = 0;
		cpt = 1;
		while (entry.back() > 47 && entry.back() < 58){
			pizzaCounter = pizzaCounter + ((entry.back() - 48) * cpt);
			cpt = cpt * 10;
			entry.pop_back();
		}
		for (int i = 0; i < pizzaCounter; ++i) {
			pizzas.push(entry);
		}
	}

	return pizzas;
}

void Manager::setTime(int timeBase) {
	baseTime = timeBase;
}

int Manager::getTime() {
	return (baseTime);
}

std::queue<std::string> Manager::getPizzas() {
	return pizzas;
}

unsigned int Manager::getOrderID() {
	return orderID;
}

void Manager::nextOrderID() {
	++orderID;
}

void Manager::manageKitchens(unsigned int maxCookers, PizzaFactory *factory) {
	int nbKitchens = pizzas.size() / maxCookers;
	int nbOfKitchensToRecreate = 0;
	int nbFreeCookers = getNbOfFreeCookers();

	if (nbFreeCookers < static_cast<int>(pizzas.size())) {
		nbOfKitchensToRecreate = static_cast<int>((pizzas.size() - nbFreeCookers) / maxCookers);
		if ((pizzas.size() - nbFreeCookers) % maxCookers != 0)
			nbOfKitchensToRecreate++;
	}

	std::cout << "%%%%%%% nbOfKitchensToRecreate : " << nbOfKitchensToRecreate << std::endl;
	for (int i = 0; i < nbOfKitchensToRecreate; ++i) {
		kitchens.push_front(new Kitchen(idKitchen, maxCookers));
		++idKitchen;
	}

	//security: limit of 10 processes
	if (nbKitchens > 10)
		nbKitchens = 10;
	else if (nbKitchens < 1)
		nbKitchens = 1;
	else if (pizzas.size() % maxCookers != 0)
		nbKitchens++;

	for (int i = 0; i < nbKitchens; ++i) {
		/*kitchens.push_front(new Kitchen(idKitchen, maxCookers));
		++idKitchen;*/
		if (pizzas.size() < maxCookers){
			maxCookers = pizzas.size();
		}
		for(unsigned int j = 0; j < maxCookers; ++j) {
			if ((kitchens.front()->getNbMaxCookers() - kitchens.front()->getNbBusyCookers()) > 0) {
				kitchens.front()->addOrder(pizzas.front());
				pizzas.pop();
			}
		}

		switch (fork()){
			case -1:
				std::cerr << "Fatal error: can't create process!" << std::endl;
				exit(1);
			case 0:
			std::cout << "ENFANT" << std::endl;
				//if ((kitchens.front()->getNbMaxCookers() - kitchens.front()->getNbBusyCookers()) > 0)
					kitchens.front()->dispatch(managerTeam, baseTime, factory);
				exit(0);
			default:
				std::cout << "PERE " << std::endl;
		}
	}
}

std::list<Kitchen *> Manager::getKitchens() {
	return kitchens;
}

std::list<int> Manager::getKitchenStatus() {
	std::list<Kitchen *> kitchens = getKitchens();
	std::list<int> cookers;

	for (auto &kitchen : kitchens) {
		cookers.push_back(kitchen->getNbBusyCookers());
	}
	std::cout << "==== KITCHEN STATUS ====" << std::endl;
	for (auto &value : cookers)
		std::cout << " VALUE " <<  value << std::endl;
	return cookers;
}

int Manager::getNbOfFreeCookers() {
	int nbFreeCookers = 0;
	for (auto &kitchen : kitchens) {
		nbFreeCookers += kitchen->getNbMaxCookers() - kitchen->getNbBusyCookers();
	}
	return nbFreeCookers;
}
