#include "circle.hpp"

namespace mt
{
	Circle::Circle(int x, int y, float r)
	{
		m_x = x;
		m_y = y;
		m_r = r;
		m_shape = new sf::CircleShape(m_r);
		m_shape->setOrigin(m_r, m_r);
		m_shape->setFillColor(sf::Color::Yellow);
		m_shape->setPosition(m_x, m_y);
	}
	Circle::~Circle()
	{
		delete m_shape;
	}

	sf::CircleShape* Circle::Get() { return m_shape; }

	void Circle::Move(int x, int y)
	{
		m_x = x;
		m_y = y;
		m_shape->setPosition(m_x, m_y);
	}

	

	
}
