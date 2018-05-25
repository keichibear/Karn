#include "Deck.h"
#include <algorithm>
#include <random>
#include <iostream>
using namespace std;

CDeck::CDeck(CARD_CLASS &cards, std::random_device &rd) : m_rnd(rd())
{
	for (CARD_CLASS::const_iterator c = cards.begin(); c != cards.end(); c++)
	{
		string cardname = c->first;
		size_t number = c->second;

		for (size_t i = 0; i < number; i++)
			m_library.push_back(cardname);
	}
}

void CDeck::show() const
{
	for (size_t i = 0; i < m_library.size(); i++)
	{
		cout << m_library[i] << endl;
	}
}

void CDeck::show(size_t number) const
{
	for (size_t i = 0; i < number; i++)
	{
		cout << m_library[i] << endl;
	}
}

void CDeck::shuffle()
{		
	std::shuffle(std::begin(m_library), std::end(m_library), m_rnd);	
}

bool CDeck::checkHand(size_t turn, const CARD_CLASS *rule) const
{
	for (CARD_CLASS::const_iterator it = rule->begin(); it != rule->end(); it++)
	{
		string name = it->first;
		size_t number = it->second;

		int counted = std::count(m_library.begin(), m_library.begin() + 7 + turn, name);		
		if (counted < number)
			return false;
	}

	return true;
}

CDeck::~CDeck()
{
}
