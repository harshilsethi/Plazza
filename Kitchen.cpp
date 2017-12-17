/*
** EPITECH PROJECT, 2017
** Plazza project
** File description:
** Kitchen.cpp
*/

#include <iostream>
#include <future>
#include <zconf.h>
#include "Kitchen.h"
#include <fstream>

Kitchen::Kitchen(int _id, int _nbCookers) {
	id = _id;
	nbBusyCookers = 0;
	nbMaxCookers = _nbCookers;
}

Kitchen::~Kitchen() = default;

int Kitchen::getId() {
	return id + 1;
}

int Kitchen::getNbBusyCookers() {
	return nbBusyCookers;
}

void Kitchen::addOrder(std::string &anOrder) {
	orders.push(anOrder);
}

void Kitchen::dispatch(Team &aTeam, int baseTime, PizzaFactory *factory) {
	std::list<Cooker>::iterator it;
	std::string pizza;
	std::string size;

	for (unsigned int i = 0; i < orders.size(); ++i){
		cookers.push_back(aTeam.takeCooker());
		nbBusyCookers++;
	}
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
		it->runThread(pizza, size, baseTime, factory);
		orders.pop();
	}
}

void Kitchen::updateStatus(int timeBase) {
        std::fstream file;
        std::string path;
        path = "Txt/kitchen" + std::to_string(getId()) + ".txt";
        file.open(path, std::ios::out | std::ios::trunc);
        if (file){
                file << "|----------------|" << std::endl;
                file << "|    Kitchen" << getId() << "    |" << std::endl;
                file << "|----------------|" << std::endl;
                file << "|  busy cookers  |" << std::endl;
                file << "|      " << nbBusyCookers << "/" << nbMaxCookers << "       |" << std::endl;
                file << "|----------------|" << std::endl;
        }
        file.close();
	if (nbBusyCookers == 0) {
		nbBusyCookers = nbMaxCookers;
		timer(timeBase);
		quit();
	}
}

void Kitchen::setNbOfBusyCookers(int add) {
        nbBusyCookers = nbBusyCookers + add;
}

void Kitchen::quit() {
	try {
		while (!cookers.empty()) {
			cookers.back().reset();
			cookers.pop_back();
		}
	} catch (std::exception &e) {
	}
        std::string path = "Txt/kitchen" + std::to_string(getId()) + ".txt";
        int val = std::remove(path.c_str());
        if (val != 0)
                std::cerr << "Warning: kitchen" << getId() << " hasn't been deleted";
	exit(0);
}

int Kitchen::getNbMaxCookers() {
	return nbMaxCookers;
}

void Kitchen::timer(int timeBase) {
	auto start = std::chrono::high_resolution_clock::now();
        int baseTime = 5;
	for(int i = 0; i < baseTime; ++i) {
		std::this_thread::sleep_until(start + (i + 1) * std::chrono::milliseconds(timeBase));
	}
}