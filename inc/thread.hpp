#pragma once
#include <SFML/Graphics.hpp>
namespace mp
{
    class Thread
    {
    public:
        Thread(int x, int y, int threadlength, int threadWidth);

        ~Thread();

        sf::RectangleShape* Get();
        void Rotation(int bb);
        void Position(int x, int y);

    private:
        int m_x, m_y;
        
        sf::RectangleShape* m_shape;
        
        int m_threadlength;
        int m_threadWidth;
    };

}
