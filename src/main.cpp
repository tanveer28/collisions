#include <iostream>
#include <SFML/Graphics.hpp>
#include "circle.h"
#include "AABB.h"
#include "OBB.h"
#include "Shape.h"
#include "CollisionsManager.h"

using namespace std;


void main()
{
	sf::Clock clock;//clock for updating frames
	sf::RenderWindow Window(sf::VideoMode(1200,950), "Collisions"); //sets a render window using SFMl
	Circle* m_circle = new Circle(sf::Vector2f(50,50), 50); //top left circle
	Circle* m_circle2 = new Circle(sf::Vector2f(50,151), 50); //circle underneath other circle. chamge ypos to 150 for circle circle test
	AABB* m_AABB = new AABB(sf::Vector2f(126,50),50,50); //first rectangle to the left of the circle. change xpos to 125 for circle aabb test
	AABB* m_AABB2 = new AABB(sf::Vector2f(177,50),50,50); //rectangle to the right of the first rectangle. change xpos to 176 for aabb aabb test
	OBB* m_OBB = new OBB(sf::Vector2f(136,150),50,50,45); //rotated aabb next to bottom circle. xpos to 135 for obb circle text
	CollisionsManager* m_CollisionsManager = new CollisionsManager();


	while (Window.isOpen())
	{
		Window.clear(sf::Color::White);//sets the window colour to white

		sf::Event event;
		while (Window.pollEvent(event));
		{
			//window closed
			if(event.type== sf::Event::Closed)
			{
				Window.close();
			}
		
		//find out elapsed time
		float fElapsedTime = clock.getElapsedTime().asSeconds();
		
		if(fElapsedTime>0.017)
		{
			if (m_CollisionsManager->CircletoCircleCollision(*m_circle,*m_circle2) ==true)
			{
				std::cout<<"i collided"<<endl; //circle with circle collision test
			}

			if (m_CollisionsManager->OBBtoCircleCollision(*m_OBB,*m_circle2) ==true)
			{
				std::cout<<"i collided"<<endl; //obb to circle collision text
			}

			if (m_CollisionsManager->AABBtoCircleCollision(*m_AABB,*m_circle) ==true)
			{
				std::cout<<"i collided"<<endl; //aabb to circle collision text
			}
			if (m_CollisionsManager->AABBtoAABBCollision(*m_AABB,*m_AABB2) ==true)
			{
				std::cout<<"i collided"<<endl; //aabb to aabb collision test
			}

			clock.restart(); //restart the clock to update frames	
		}

			Window.draw(*m_circle);
			Window.draw(*m_circle2);
			Window.draw(*m_AABB);
			Window.draw(*m_AABB2);
			Window.draw(*m_OBB);

			Window.display();//display the window
		}

	}
}