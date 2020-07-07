//--------------------------
//Name:Elmira Mirza
//Seneca email:emirza2@myseneca.ca
//Seneca ID:130828197   
//Date:06/07/2020
//---------------------------
#include <iostream>
#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H


namespace sdds {

	struct Fruit
	{
		char m_name[30 + 1]; // the name of the fruit
		double m_qty;        // quantity in kilograms
	};
	class Basket {

		Fruit* m_fruits;
		int  m_cnt;
		double m_price;
	public:
		Basket();
		void SetEmpty();
		void display(std::ostream& os) const;
		Basket(Fruit* fruits, int cnt, double price);
		Basket(const Basket&);
		Basket& operator=(const Basket&);

		~Basket();
		void setPrice(double price);
		operator bool() const;
		Basket& operator+=(Fruit fruit);
		friend std::ostream& operator<< (std::ostream& os, const Basket& bas);
	};
}
#endif

