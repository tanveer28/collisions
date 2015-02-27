#include "collisionsmanager.h"



CollisionsManager::CollisionsManager()
{
	//default constructor
}


bool CollisionsManager::AABBtoCircleCollision(AABB &aabb,Circle &circle)
{

	sf::Vector2f CirclePos = circle.getPosition()-aabb.getPosition(); //create a temporary circle position with the balls position minus the box's position
	sf::Vector2f CirclePos2 = CirclePos; //create a copy of the circles position
	sf::Vector2f RectanglePos; 
	RectanglePos.x=0;
	RectanglePos.y=0; //create a temporary vector for the rectangles popsition with the values (0,0)

	sf::Vector2f Distance; 
	Distance = (CirclePos - RectanglePos); //create a distance vector with the values of the new circle position minus the rectangle position


	sf::Vector2f clamp; //create a vector for a clamp

	if(Distance.x >= 0)clamp.x = std::min(Distance.x,aabb.getHalfWidth());
	if(Distance.x < 0) clamp.x = std::max(Distance.x,-aabb.getHalfWidth());
	if(Distance.y >= 0)clamp.y = std::min(Distance.y,aabb.getHalfHeight()); 
	if(Distance.y < 0) clamp.y = std::max(Distance.y,-aabb.getHalfHeight()); //gets the value for the clamp vector

	sf::Vector2f vDifference;

	vDifference =  Distance - clamp; //gets the difference of the distance minus the clamp

	float fmagnitude = sqrt(pow(vDifference.x, 2) +(pow(vDifference.y,2))); //gets the magnitude 

	float fDistance = (fmagnitude - circle.getRadius()); //gets the distance between the ball and box

	if (fDistance <=0) //if distance <= 0, a collision has happened
	{
		return true;
	}
	
	else
	{
		return false;
	}
}


bool CollisionsManager::AABBtoAABBCollision(AABB &aabb,AABB &aabb2)
{
	if(aabb.getMax().x < aabb2.getMin().x  || aabb.getMin().x > aabb2.getMax().x) return false;
	if(aabb.getMax().y < aabb2.getMin().y  || aabb.getMin().y > aabb2.getMax().y) return false;
	return true;
}


bool CollisionsManager::OBBtoCircleCollision(OBB &obb, Circle &circle)
{
	float radians = obb.getAngle()/(180/3.14); //converts the box' angle to radians

	sf::Vector2f CirclePos = circle.getPosition()-obb.getPosition(); //create a temporary circle position with the balls position minus the box's position
	sf::Vector2f CirclePos2 = CirclePos; //create a copy of the circles position
	sf::Vector2f RectanglePos; 
	RectanglePos.x=0;
	RectanglePos.y=0; //create a temporary vector for the rectangles popsition with the values (0,0)

	CirclePos.x=(CirclePos.x*(cos(radians))) + (CirclePos.y*(sin(radians))); 

	CirclePos.y=(CirclePos2.x*(-sin(radians))) + (CirclePos2.y*(cos(radians))); //apply a rotation matrix to the circles position



	sf::Vector2f Distance; 
	Distance = (CirclePos - RectanglePos); //create a distance vector with the values of the new circle position minus the rectangle position


	sf::Vector2f clamp; //create a vector for a clamp

	if(Distance.x >= 0)clamp.x = std::min(Distance.x,obb.getHalfWidth());
	if(Distance.x < 0) clamp.x = std::max(Distance.x,-obb.getHalfWidth());
	if(Distance.y >= 0)clamp.y = std::min(Distance.y,obb.getHalfHeight()); 
	if(Distance.y < 0) clamp.y = std::max(Distance.y,-obb.getHalfHeight()); //gets the value for the clamp vector


	sf::Vector2f vDifference;

	vDifference =  Distance - clamp; //gets the difference of the distance minus the clamp



	float fmagnitude = sqrt(pow(vDifference.x, 2) +(pow(vDifference.y,2))); //gets the magnitude 

	float fDistance = (fmagnitude - circle.getRadius()); //gets the distance between the ball and box

	sf::Vector2f vDifferenceRotated;


	vDifferenceRotated.x=(vDifference.x*(cos(radians))) + (vDifference.y*(-sin(radians)));
	vDifferenceRotated.y=(vDifference.x*(sin(radians))) + (vDifference.y*(cos(radians))); //rotate the difference vector back

	sf::Vector2f normal(vDifferenceRotated.x,vDifferenceRotated.y);	//calculates the normal
			
	sf::Vector2f unitnormal;

	unitnormal.x=normal.x/fmagnitude;
	unitnormal.y=normal.y/fmagnitude; //calculate the unit normal


	if (fDistance <=0) //if distance <= 0, a collision had happened
		{
			return true;			
		}
	
	else
	{
		return false;
	}
}

bool CollisionsManager::CircletoCircleCollision(Circle &circle, Circle &circle2)
{
	sf::Vector2f vDistance = circle.getPosition()-circle2.getPosition();

	float mag = std::sqrt(vDistance.x * vDistance.x + vDistance.y * vDistance.y);

	float radii = circle.getRadius()+circle2.getRadius();

	float distance = mag - radii;

	if(distance<=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}