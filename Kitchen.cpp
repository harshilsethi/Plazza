/*
** EPITECH PROJECT, 2017
** Plazza project
** File description:
** Kitchen.cpp
*/

#include <future>
#include <zconf.h>
#include "Kitchen.h"

Kitchen::Kitchen(int _id, int _nbCookers) {
	id = _id;
	nbBusyCookers = 0;
	nbMaxCookers = _nbCookers;
}

Kitchen::~Kitchen() = default;

int Kitchen::getId() {
	return id + 1;
}

int Kitchen::getNbCookers() {
	return nbBusyCookers;
}

std::list<Cooker> &Kitchen::getCookers() {
	return cookers;
}

void Kitchen::addOrder(std::string &anOrder) {
	orders.push(anOrder);
}

std::string Kitchen::giveOrder() {
	return (orders.front());
}

void Kitchen::deleteOrder() {
	orders.pop();
}

void Kitchen::dispatch(Team &aTeam, int baseTime, PizzaFactory *factory) {
	std::list<Cooker>::iterator it;
	std::string pizza;
	std::string size;

	for (unsigned int i = 0; i < orders.size(); ++i){
		cookers.push_back(aTeam.takeCooker());
		nbBusyCookers++;
	}
	std::cout << "Nb of busy cookers : " << nbBusyCookers << std::endl;
	for (it = cookers.begin(); it != cookers.end(); ++it){
		it->setKitchen(this);
		if (orders.front().find("XL") != std::string::npos){
			size = "XL";
			pizza = orders.front().substr(0,orders.front().size() -2);
		} else if (orders.front().find("L") != std::string::npos){
			size = "L";
			pizza = orders.front().substr(0,orders.front().size() -1);
		}else if (orders.front().find("*M")){
			size = "M";
			pizza = orders.front().substr(0,orders.front().size() -1);
		}
		it->runThread(pizza, size, baseTime, factory); //timeBase
		orders.pop();
	}
	//std::cout << " NB : " << getNbOfBusyCookers() << std::endl;
}

void Kitchen::updateStatus() {
	nbBusyCookers--;
	std::cout << "\e[31m" << nbMaxCookers - nbBusyCookers << " cookers still free in kitchen " << this->getId() << " !\e[0m" << std::endl;
	std::cout << "BUSY COOKERS : " << nbBusyCookers << std::endl;
	if (nbBusyCookers == 0) {
		quit();
		std::cout << "Timer Start" << std::endl;
		nbBusyCookers = nbMaxCookers;
		// début timer et quand timer = 5 T destruction process + threads associés
	}
}

int Kitchen::getNbOfBusyCookers() {
	return static_cast<int>(cookers.size());
}

void Kitchen::quit() {
	try {
		while (!cookers.empty()) {
			cookers.back().reset();
			cookers.pop_back();
		}
	} catch (std::exception &e) {
	}
	std::cout << " QUIT : cookers.size() de Kitchen id# " << getId() << " : " << cookers.size() << std::endl;
	exit(0);
}