#pragma once
#include <SFML/Graphics.hpp>

namespace mt
{
	class Circle
	{
	public:
		Circle(int x, int y, float r);

		~Circle();

		sf::CircleShape* Get();

		void Move(int x, int y);

	private:
		int m_x, m_y;
		float m_r;
		sf::CircleShape* m_shape;
	};

}
