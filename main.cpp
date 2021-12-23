#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
#include <iomanip>
#include "circle.hpp"
#include "thread.hpp"
#define M_PI 3.14159265358979323846264338327950288
#define M_G 9.8
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
const double alpha0 = 30.0; // начальный угол отклонения нити
const double alpha1 = -30.0; 

const int x_top = 767;
const int y_top = 40;
const int x_2 = 533;
const int y_2 = 40;

const int x_b = 500;
const int y_b = 0;

const int threadLength = 175; // длина нити
const int threadWidth = 4; // толщина нити

const int threadLength2 = 175; 
const int threadWidth2 = 4;

const sf::Color threadColor(0, 0, 255); // цвет нити
const sf::Color threadColor2(0, 0, 255);

const int radius2 = 20;
const int radius = 20; // радиус шарика

const sf::Color ballColor(255, 255, 0); // цвет шарика
const sf::Color ballColor2(255, 255, 0);

double delta_t = 0.1; // насколько будет меняться время при переходе к следующему кадру
const int blockLength = 300; 
const int blockWidth = 40; 
const sf::Color blockColor(60, 60, 60);

const int N = 2;


int main()
{
    
    sf::RenderWindow window(sf::VideoMode(1024, 768), " ");

    window.setFramerateLimit(60); // устанавливаем частоту обновления экрана на 60 fps

    double rads = M_PI / 180; // вспомогательный коэффициент, необходимый для перевода углов из градусов в радианы
    double q = sqrt(M_G / threadLength); // вспомогательный коэффициент, участвующий в формуле расчёта колебаний 


    std::vector<mt::Circle*> circles;
    for (int i = 0; i < N; i++)
        circles.push_back(new mt::Circle(0, 0, radius));
    
    std::vector<mp::Thread*> threads;
    for (int i = 0; i < N; i++)
        threads.push_back(new mp::Thread(0, 0, threadLength, threadWidth));

   

    sf::RectangleShape block(sf::Vector2f(blockLength, blockWidth));
    block.setPosition(sf::Vector2f(x_b, y_b));
    block.setFillColor(blockColor);

    threads[0]->Position(x_top, y_top);
    threads[1]->Position(x_2, y_2);
    
    double t = 0.0; // текущий момент времени

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        double alpha = alpha0 * cos(q * t); // вычисляем текущий угол отклонения
        double alpha_rad = alpha * rads; // переводим текущий угол из градусов в радианы
        double alpha2 = alpha1 * cos(q * t); 
        double alpha_rad2 = alpha2 * rads;

        
        threads[0]->Rotation(90-alpha);
        threads[1]->Rotation(90 - alpha2);
        
        circles[0]->Move(x_top + (threadLength + radius) * sin(alpha_rad), y_top + (threadLength + radius) * cos(alpha_rad));
        circles[1]->Move(x_2 + (threadLength2 + radius2) * sin(alpha_rad2), y_2 + (threadLength2 + radius2) * cos(alpha_rad2));

        std::stringstream ss;
        ss << "Time: " << std::setprecision(3) << t;
        

        window.clear();
       
       
        for (const auto& thread : threads)
            window.draw(*thread->Get());
        for (const auto& circle : circles)
            window.draw(*circle->Get());
        
        window.draw(block);
        window.display();

        t += delta_t;
    }

    for (const auto& circle : circles)
        delete circle;
    circles.clear();
    for (const auto& thread : threads)
        delete thread;
    threads.clear();

    return 0;
}