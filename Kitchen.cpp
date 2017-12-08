/*
** EPITECH PROJECT, 2017
** Plazza project
** File description:
** Kitchen.cpp
*/

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

void Kitchen::dispatch(Team &aTeam) { //????
	//fait faire les pizzas par les cuisiniers
	std::cout << "Cooking !" << std::endl;
	std::list<Cooker>::iterator it;
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>" << orders.size() << std::endl;
        std::string pizza;
        std::string size;


	for (unsigned int i = 0; i < orders.size(); ++i){
		cookers.push_back(aTeam.takeCooker());
	}
	for (it = cookers.begin(); it != cookers.end(); ++it){
                if (orders.front().find("XL") != std::string::npos){
                        size = "XL";
                        pizza = orders.front().substr(0,orders.front().size() -2);
                } else if (orders.front().find("L") != std::string::npos){
                        size = "L";
                        pizza = orders.front().substr(0,orders.front().size() -1);
                }else if (orders.front().find("M")){
                        size = "M";
                        pizza = orders.front().substr(0,orders.front().size() -1);
                }
                it->runThread(pizza, size, ); //timeBase
		orders.pop();
	}

}