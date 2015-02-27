#ifndef AABB_H
#define AABB_H

#include "Shape.h"
#include<SFML\Graphics.hpp>

class AABB : public Shape
{
private:
	float m_fWidth;
	float m_fHeight;
	sf::Vector2f m_vMax;
	sf::Vector2f m_vMin;

protected:



public:

	AABB(sf::Vector2f position, float width, float height);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float getHalfWidth();
	float getHalfHeight();
	sf::Vector2f getMin();
	sf::Vector2f getMax();
};
#endif