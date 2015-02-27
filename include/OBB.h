#ifndef OBB_H
#define OBB_H

#include "Shape.h"
#include<SFML\Graphics.hpp>

class OBB : public Shape
{
private:
	float m_fWidth;
	float m_fHeight;
	float m_fAngle;


protected:



public:

	OBB(sf::Vector2f position, float width, float height, float angle);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float getHalfWidth();
	float getHalfHeight();
	float getAngle();

};
#endif