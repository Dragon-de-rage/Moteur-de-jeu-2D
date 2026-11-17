#include "RectangularCollision.h"
#include "CircularCollision.h"
#include <math.h>

RectangularCollision::RectangularCollision(double x, double y, double width, double height)
    : m_width(width), m_height(height)
{
    m_x = x;
    m_y = y;
}

bool RectangularCollision::is_colliding(Collision* collider, auto callback)
{
    if (RectangularCollision* rect_col = dynamic_cast<RectangularCollision*>(collider)) // if rect - rect
    {
        if (m_x < rect_col->X() + rect_col->Width() &&
            m_x + m_width > rect_col->X() &&
            m_y < rect_col->Y() + rect_col->Height() &&
            m_height + m_y > rect_col->Y())
        {
            // collision détectée
            // apply effect if any (callback)
            callback();
            return true;
        }
        else
            return false;
    } else // if rect - circle
    {
        CircularCollision* circ_col = dynamic_cast<CircularCollision*>(collider);
        double distX = std::abs(circ_col->X() - m_x-m_width/2);
        double distY = std::abs(circ_col->Y() - m_y-m_height/2);

        if (distX > (m_width/2 + circ_col->Radius())) { return false; }
        if (distY > (m_height/2 + circ_col->Radius())) { return false; }

        if (distX <= (m_width/2)) {
            callback();
            return true;
        }
        if (distY <= (m_height/2)) {
            callback();
            return true;
        }

        double dx = distX-m_width/2;
        double dy = distY-m_height/2;
        if (dx*dx+dy*dy <= (circ_col->Radius()*circ_col->Radius())) {
            callback();
            return true;
        }
        else
            return false;
    }
}
