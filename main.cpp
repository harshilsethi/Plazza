//
// EPITECH PROJECT, 2017
// Plazza project
// File description:
// main.cpp
//

#include <iostream>
#include "Manager.h"
#include "WindowFront.h"

void launchOrder (Manager *manager, Order anOrder, int cookersNb, PizzaFactory *factory){
	manager->convertInputIntoOrder(anOrder);
	manager->manageKitchens(cookersNb, factory);
	//std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>> ORDER #" << manager->getOrderID() << " READY !" << std::endl;
	manager->nextOrderID();
}

int main(int argc,char *argv[]) { //./a.out []
	int baseTime;
	int cookersNb;
	if (argc < 3) {
		std::cout << "Default parameters assigned : base time is 2000 ms and there are 5 cookers per kitchen" << std::endl;
		baseTime = 2000;
		cookersNb = 5;
	} else {
		baseTime = static_cast<int>(strtol(argv[1], nullptr, 10));
		cookersNb = static_cast<int>(strtol(argv[2], nullptr, 10));
		if((!baseTime) || (!cookersNb))
			throw std::invalid_argument("\e[91mPlease choose numbers for the base time & the number of cookers\e[0m");

		std::cout << "Base time chosen : 1 T = " << baseTime << " ms" << std::endl;
		std::cout << "Number of cookers per kitchen choosen : " << cookersNb << std::endl;
	}
	Manager manager;
	std::list<Order> orders;
	WindowFront windowFront;
	PizzaFactory factory;

	orders = windowFront.getOrders();
	manager.setTime(baseTime);

	for (auto &order : orders) {
		std::cout << "COMMAND : " << order.getCommand() << std::endl;
		launchOrder(&manager, order, cookersNb, &factory);
	}

	std::cout << std::endl
		  << "===================================" << std::endl
		  << std::endl;

	std::queue<std::string> res = manager.getPizzas();
	manager.manageKitchens(cookersNb, &factory);
	return (EXIT_SUCCESS);
}