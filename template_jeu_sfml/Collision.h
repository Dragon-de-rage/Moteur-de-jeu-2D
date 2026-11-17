#pragma once
#ifndef COLLISION_H
#define COLLISION_H

class Collision
{
protected:
    double m_x;
    double m_y;

public:
    Collision();
    //getters
    double X() { return m_x; }
    double Y() { return m_y; }

    virtual bool is_colliding() = 0;
};

#endif // COLLISION_H

/* detection algorithms :
 *
 * rect - rect :
 *      if (
          rect1.x < rect2.x + rect2.width &&
          rect1.x + rect1.width > rect2.x &&
          rect1.y < rect2.y + rect2.height &&
          rect1.height + rect1.y > rect2.y
        ) {
          // collision détectée !
        }
 * circle - circle :
 *      var dx = circle1.x - circle2.x;
        var dy = circle1.y - circle2.y;
        var distance = Math.sqrt(dx * dx + dy * dy);

        if (distance < circle1.radius + circle2.radius) {
          // collision détectée !
        }
 * rect - circle :
 *      // return true if the rectangle and circle are colliding
        function RectCircleColliding(circle,rect){
            var distX = Math.abs(circle.x - rect.x-rect.w/2);
            var distY = Math.abs(circle.y - rect.y-rect.h/2);

            if (distX > (rect.w/2 + circle.r)) { return false; }
            if (distY > (rect.h/2 + circle.r)) { return false; }

            if (distX <= (rect.w/2)) { return true; }
            if (distY <= (rect.h/2)) { return true; }

            var dx=distX-rect.w/2;
            var dy=distY-rect.h/2;
            return (dx*dx+dy*dy<=(circle.r*circle.r));
        }
*/