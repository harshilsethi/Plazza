/*
** EPITECH PROJECT, 2017
** Plazza Project
** File description:
** APizza.h
*/

#ifndef PIZZA_H__
#define PIZZA_H__

#include <string>

class APizza {
public:
	explicit APizza(const std::string &size);
	virtual ~APizza() = default;;

	virtual std::string getSize();
	virtual float getCookTime();

protected:
	const std::string size;
};

#endif /* ! PIZZA_H__ */