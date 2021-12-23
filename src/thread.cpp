#include "thread.hpp"
#include "circle.hpp"

namespace mp
{
    
    Thread::Thread(int x, int y, int threadlength, int threadWidth)
    {
        
        m_x = x;
        m_y = y;
        m_threadWidth = threadWidth;
        m_threadlength = threadlength;
        m_shape = new sf::RectangleShape(sf::Vector2f(m_threadlength,m_threadWidth));
        m_shape->setFillColor(sf::Color::Blue);
        m_shape->setPosition(m_x, m_y);
        m_shape->setRotation(0);
    }
    Thread::~Thread()
    {
        delete m_shape;
    }
    void Thread::Position(int x, int y)
    {
        m_x = x;
        m_y = y;
        m_shape->setPosition(m_x, m_y);

    }
    sf::RectangleShape* Thread::Get() { return m_shape; }
    void Thread::Rotation(int bb)
    {
        m_shape->setRotation(bb);
    }

}