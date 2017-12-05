#include <iostream>
#include "Manager.h"
#include "Order.h"


int main() {
	Manager manager;
	std::string input1 = "Margarita L 3 ; American XL 3; Fantasia L 3";
	Order order1(input1);

	manager.convertInputIntoOrder(order1);
	
	std::cout << "===================================" << std::endl << std::endl;
	
	std::queue<std::string> res = manager.getPizzas();
	manager.manageKitchens(6);
	while(!res.empty()){
		std::cout << res.front() << std::endl;
		res.pop();
	}

	return 0;
}