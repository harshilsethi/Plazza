//
// EPITECH PROJECT, 2017
// Plazza Project
// File description:
// Order.h
//

#ifndef PLAZZAV1_ORDER_H
#define PLAZZAV1_ORDER_H

#include <string>

class Order {
public:
	Order();

	explicit Order(std::string &order);
	virtual ~Order();

	int getId() const;
	std::string getCommand()const;
	void setCommand(std::string command);

private:
	int id;
	std::string command;
};


#endif //PLAZZAV1_ORDER_H
