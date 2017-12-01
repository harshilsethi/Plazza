//
// EPITECH PROJECT, 2017
// 
// File description:
//
//

#ifndef PLAZZAV1_ORDER_H
#define PLAZZAV1_ORDER_H

#include <string>

class Order {
public:
	Order(std::string &order);
	virtual ~Order();

	int getId() const;

private:
	int id;
	std::string command;
};


#endif //PLAZZAV1_ORDER_H
