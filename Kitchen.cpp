/*
** EPITECH PROJECT, 2017
** Plazza project
** File description:
** Kitchen.cpp
*/

#include <future>
#include <zconf.h>
#include "Kitchen.h"

Kitchen::Kitchen(int _nbCookers) {
	nbCookers = _nbCookers;
}

Kitchen::~Kitchen() = default;

int Kitchen::getNbCookers() {
	return nbCookers;
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

void Kitchen::dispatch(Team &aTeam, int baseTime) {
	std::list<Cooker>::iterator it;
        std::string pizza;
        std::string size;

	for (unsigned int i = 0; i < orders.size(); ++i){
		cookers.push_back(aTeam.takeCooker());
	}
	std::cout << "SIZE : " << cookers.size() << std::endl;
	for (it = cookers.begin(); it != cookers.end(); ++it){
		//it->setKitchen(this);
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
                it->runThread(pizza, size, baseTime); //timeBase
		orders.pop();
	}
	//std::cout << " NB : " << getNbOfBusyCookers() << std::endl;
}

void Kitchen::updateStatus() {
	if (getNbOfBusyCookers() <= 0) {
		std::cout << "NO BUSY COOKERS" << std::endl;
		//quit();
		// début timer et quand timer = 5 T destruction process + threads associés
	} else {
		// Stop timer
	}
}

int Kitchen::getNbOfBusyCookers() {
	int nbOfBusyCookers = 0;
	/*for (auto &cooker : getCookers()) {
		if (cooker.isBusy())
			nbOfBusyCookers++;
	}*/
	return nbOfBusyCookers;
}

void Kitchen::quit() {/*
	try {
		while (!cookers.empty()) {
			delete cookers.back();
			cookers.pop_back();
		}
	} catch (std::exception &e) {
	}
	exit(0);*/
}