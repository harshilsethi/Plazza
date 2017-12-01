#include <iostream>
#include "Manager.h"
#include "Order.h"

int main() {
	Manager manager;
	std::string input1 = "Margarita L 2 ; American XL 1";
	Order order1(input1);

	manager.convertInputIntoOrder(order1);

	return 0;
}