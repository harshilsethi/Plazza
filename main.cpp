//
// EPITECH PROJECT, 2017
// Plazza project
// File description:
// main.cpp
//

#include <iostream>
#include "Manager.h"
#include "Order.h"
#include "WindowFront.h"
#include <ncurses.h>
#include <menu.h>
#include <cstring>
#include <ncurses.h>
#include <iostream>
#include <vector>

void launchOrder (Manager *manager, Order anOrder, int cookersNb){
	manager->convertInputIntoOrder(anOrder);
	manager->manageKitchens(cookersNb);
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>> ORDER #" << manager->getOrderID() << " READY !" << std::endl;
	manager->nextOrderID();
}

int main(int argc,char *argv[]) { //./a.out []
	if (argc < 3) {
		std::cout << "In order to enter the Plazza, please specify the base time and the number of cookers " << std::endl;
		std::cout << "Example : ./a.out [time] [cookers]" << std::endl;
	} else {
		int baseTime;
		int cookersNb;
		Manager manager;
		std::vector<std::string> lastCommand;
		std::string commandsToTransfer;
		std::list<Order> orders;
		std::list<Order> ordersToTransfer;
		WindowFront windowFront;

		orders = windowFront.getOrders();
		lastCommand = windowFront.getLastCommands();

		baseTime = static_cast<int>(strtol(argv[1], nullptr, 10));
		cookersNb = static_cast<int>(strtol(argv[2], nullptr, 10));

		manager.setTime(baseTime);

		std::cout << "1 T = " << baseTime << std::endl; //temp (for warnings)
		std::string input1 = "Margarita L 2 ; American XL 11; Fantasia L 7";
		std::string input2 = "Fantasia XL 4; Regina M 6";
		//Order order1(input1);
		//Order order2(input2);

		for (const auto &command : lastCommand) {
			std::cout << "COMMAND : " << command << std::endl;
			commandsToTransfer.append(command);
			commandsToTransfer.append(";");
		}

		for (auto &order : orders) {
			launchOrder(&manager, order, cookersNb);
		}

		//Order order1(commandsToTransfer);
		//manager.convertInputIntoOrder(order1);

		std::cout << std::endl
			  << "===================================" << std::endl
			  << std::endl;

//		launchOrder(&manager, order1, cookersNb);
//		launchOrder(&manager, order2, cookersNb);

		std::queue<std::string> res = manager.getPizzas();
		manager.manageKitchens(cookersNb);

		/*while(!res.empty()){
			std::cout << res.front() << std::endl;
			res.pop();
		}*/
	}

	return (EXIT_SUCCESS);
}