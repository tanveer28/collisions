#include "shape.h"

Shape::Shape()
{
}

void Shape::setPosition(sf::Vector2f pos)
{
	m_vPosition = pos;
}

sf::Vector2f Shape::getPosition()
{
	return m_vPosition;

}
