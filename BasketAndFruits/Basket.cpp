//--------------------------
//Name:Elmira Mirza
//Seneca email:emirza2@myseneca.ca
//Seneca ID:130828197   
//Date:06/07/2020
//---------------------------
#define _CRT_SECURE_NO_WARNINGS

#include "Basket.h"
using namespace std;
namespace sdds {
	Basket::Basket():m_fruits{ nullptr },m_cnt(0),m_price(0)

	{
		SetEmpty();
	}
	void Basket::SetEmpty()
	{
		int i = 0;
		m_cnt = 0;
		m_price = 0;

		for (i = 0; i < m_cnt; i++)
		{
			m_fruits[i].m_name[0] = '\0';
			m_fruits[i].m_qty = 0;

		}
	}
	Basket::Basket(Fruit* fruits, int cnt, double price) :m_fruits{ nullptr },m_cnt(0), m_price(0)

	{
		if (m_cnt < 0 || m_price < 0 || m_fruits != nullptr)
		{
			SetEmpty();

		}
		else {
			if (m_fruits != nullptr)
				m_fruits = nullptr;
			m_cnt = cnt;
			m_price = price;
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++)
			{
				m_fruits[i] = fruits[i];

			}

		}
		
	}
	Basket::Basket(const Basket& bas) :m_fruits{ nullptr },m_cnt(0), m_price(0)

	{

		m_cnt = bas.m_cnt;
		m_price = bas.m_price;
		if (bas.m_cnt < 0 || bas.m_price < 0 || bas.m_fruits != nullptr)
		{
			m_fruits = new Fruit[m_cnt];

			for (int i = 0; i < m_cnt; i++)
			{

				m_fruits[i] = bas.m_fruits[i];

			}

		}
		else {
			delete[] m_fruits;
			m_fruits = nullptr;
		}
	}
	Basket& Basket:: operator=(const Basket& basket) {
		m_cnt = basket.m_cnt;
		m_price = basket.m_price;
		if (basket.m_cnt < 0 || basket.m_price < 0 || basket.m_fruits != nullptr)
		{
			m_fruits = new Fruit[m_cnt];
			for (int i = 0; i < m_cnt; i++)
			{

				m_fruits[i] = basket.m_fruits[i];
			}

		}
		else {
			delete[] m_fruits;
			m_fruits = nullptr;
		}

		return *this;


	}

	void Basket::setPrice(double price) {
		m_price = price;
	}
	Basket::operator bool() const {
		bool res = false;
		if (m_fruits != nullptr)
			res = true;

		return res;
	}
	Basket& Basket:: operator+=(Fruit fruit)
	{
		bool IsValid = fruit.m_name[0] != '\0';
		Fruit* temp = new Fruit[m_cnt + 1];

		if (IsValid)
		{
			for (int i = 0; i < m_cnt; i++)
			{


				temp[i] = m_fruits[i];

			}
			temp[m_cnt++] = fruit;
			delete[] m_fruits;
			m_fruits = temp;
		}
		else
		{
			delete[] temp;
		}
		return *this;
	}


	Basket::~Basket() {

		delete[] m_fruits;
		m_fruits = nullptr;
	}

	void Basket::display(ostream& os) const {
		if (m_fruits != nullptr)
		{
			os << "Basket Content:" << endl;

			for (int i = 0; i < m_cnt; i++)
			{
				os.precision(2);
				os.setf(ios::fixed);
				os.width(10);

				os << m_fruits[i].m_name << ": " << m_fruits[i].m_qty << "kg" << endl;
				os.unsetf(ios::fixed);
				os.precision(10);
			}

			os.precision(2);
			os.setf(ios::fixed);
			os << "Price: " << m_price << endl;
		}
		else
		{
			os << "The basket is empty!" << endl;
		}
	}
	std::ostream& operator<< (ostream& os, const Basket& bas) {

		bas.display(os);

		return os;
	}
}