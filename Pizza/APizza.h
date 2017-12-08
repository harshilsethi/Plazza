/*
** EPITECH PROJECT, 2017
** Plazza Project
** File description:
** APizza.h
*/

#ifndef PIZZA_H__
#define PIZZA_H__

#include <string>
#include <utility>

class APizza {
public:
	explicit APizza(std::string size);
	virtual ~APizza() = default;;

	virtual std::string getSize();
	virtual float getCookTime();

protected:
	const std::string size;
};

#endif /* ! PIZZA_H__ */