#include "AABB.h"
#include "shape.h"



AABB::AABB(sf::Vector2f position, float width, float height)
{
	m_vPosition = position;
	m_fWidth = width;
	m_fHeight = height;
	m_vOrigin = (sf::Vector2f(m_fWidth/2,m_fHeight/2));

	m_vMin = sf::Vector2f(position.x-width/2,position.y-height/2);
	m_vMax = sf::Vector2f(position.x+width/2,position.y+height/2);
}

void AABB::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape Rectangle(sf::Vector2f(m_fWidth,m_fHeight));
	Rectangle.setFillColor(sf::Color::Red);
	Rectangle.setOrigin(m_vOrigin);
	Rectangle.setPosition(m_vPosition);
	target.draw(Rectangle);
}

float AABB::getHalfWidth()
{
	return m_fWidth/2;
}
float AABB::getHalfHeight()
{
	return m_fHeight/2;
}


sf::Vector2f AABB::getMin()
{
	return m_vMin;
}

sf::Vector2f AABB::getMax()
{
	return m_vMax;
}