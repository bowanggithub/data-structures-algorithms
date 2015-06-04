#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H

#include <string>
#include <iostream>

class CreditCard {
public:
	CreditCard(const std::string& no,
		const std::string& mn, int lim, double bal=0); //constructor
	std::string	getNumber() const	{return number;} //accessor function
	std::string	getName() const		{return name;}
	double	getBalance() const	{return balance;}
	int	getLimit() const	{return limit;}

	bool chargelt(double price);
	void makePayment(double payment);

private:
	std::string number;
	std::string name;
	int limit;
	double balance;
};

std::ostream& operator<<(std::ostream& out, const CreditCard& c);
#endif

