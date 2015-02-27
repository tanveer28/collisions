#include "OBB.h"
#include "shape.h"



OBB::OBB(sf::Vector2f position, float width, float height,float angle)
{
	m_vPosition = position;
	m_fWidth = width;
	m_fHeight = height;
	m_fAngle = angle;
	m_vOrigin = (sf::Vector2f(m_fWidth/2,m_fHeight/2));

}

void OBB::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape Rectangle(sf::Vector2f(m_fWidth,m_fHeight));
	Rectangle.setFillColor(sf::Color::Red);
	Rectangle.setOrigin(m_vOrigin);
	Rectangle.setPosition(m_vPosition);
	Rectangle.setRotation(m_fAngle);
	target.draw(Rectangle);
}

float OBB::getHalfWidth()
{
	return m_fWidth/2;
}
float OBB::getHalfHeight()
{
	return m_fHeight/2;
}

float OBB::getAngle()
{
	return m_fAngle;
}