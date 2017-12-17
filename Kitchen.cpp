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

int Kitchen::getNbOfBusyCookers() {
	return nbBusyCookers;
}

void Kitchen::setNbOfBusyCookers(int add) {
	nbBusyCookers = nbBusyCookers + add;
}

int Kitchen::getMaxCookers() {
	return nbMaxCookers;
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
	std::cout << "\e[31m" << nbMaxCookers - nbBusyCookers << " cookers still free in kitchen " << this->getId() << " !\e[0m" << std::endl;
	std::cout << "\e[32mBUSY COOKERS : " << nbBusyCookers << "\e[0m" << std::endl;

	if (nbBusyCookers == 0) {
		std::cout << "\e[90mTimer Start" << "\e[0m" << std::endl;
		nbBusyCookers = nbMaxCookers;
		timer(timeBase);
		quit();
	}
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
        std::string path = "";
	try {
		path = "Txt/kitchen" + std::to_string(getId()) + ".txt";
	} catch (std::exception const &e) {
		std::cerr << "The path of the file is incorrect" << std::endl;
	}

        int val = 0;
	try {
		val = std::remove(path.c_str());
		if (val != 0)
			std::cerr << "Warning: kitchen" << getId() << " hasn't been deleted";
	} catch (std::exception const &e) {
		std::cerr << "Warning: kitchen" << getId() << " hasn't been deleted";
	}

	exit(0);
}

void Kitchen::timer(int timeBase) {
	auto start = std::chrono::high_resolution_clock::now();
        int baseTime = 5;
	for(int i = 0; i < baseTime; ++i) {
		std::cout << "\e[90m" << (baseTime-i) << "T\e[0m" << std::endl;
		std::this_thread::sleep_until(start + (i + 1) * std::chrono::milliseconds(timeBase));
	}
}