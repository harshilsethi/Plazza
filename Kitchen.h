/*                                                                              
** EPITECH PROJECT, 2017                                                        
**                                                                   
** File description:                                                            
**                                                           
*/

//
// Created by jerome on 02/12/17.
//

#ifndef PLAZZAV1_KITCHEN_H
#define PLAZZAV1_KITCHEN_H

#include <list>
#include <queue>
#include <string>
#include "AKitchen.h"
#include "Cooker.h"

class Kitchen : public AKitchen{
private:
	int nbCookers;
	std::queue<std::string> orders;
	std::list<Cooker> cookers;
public:
	Kitchen(int);
	~Kitchen();
	int getNbCookers();
	std::list<Cooker> getCookers();
	void addOrder(std::string &);
	void dispatch();
	bool getStatut();
};


#endif //PLAZZAV1_KITCHEN_H
