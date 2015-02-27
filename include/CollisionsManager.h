#ifndef COLLISIONSMANAGER_H
#define COLLISIONSMANAGER_H

#include "OBB.h"
#include "AABB.h"
#include "Circle.h"


class CollisionsManager
{
protected:


private:


public:
	CollisionsManager();
	bool AABBtoCircleCollision(AABB &aabb,Circle &circle);
	bool AABBtoAABBCollision(AABB &aabb,AABB &aabb2);
	bool OBBtoCircleCollision(OBB &obb, Circle &circle);
	bool CircletoCircleCollision(Circle &circle, Circle &circle2);


};
#endif