#ifndef SHAPE_H
#define SHAPE_H

#include <SFML\Graphics.hpp>

class Shape : public sf::Drawable
{
private:




protected:
	sf::Vector2f m_vPosition;
	sf::Vector2f m_vOrigin;



public:

	Shape();

	void setPosition(sf::Vector2f pos);

	sf::Vector2f getPosition();


};
#endif