#include <GameWindow.h>



using ScreenPoint = std::pair<int, int>;
using WorldPoint = std::pair<double, double>;

ScreenPoint toScreen(const WorldPoint& point, int W, int H, double z)
{
    int X = W + point.first * z;
    int Y = point.second * z - H;

    return { X, Y };
}

WorldPoint toWorld(const ScreenPoint& point, int W, int H, double z)
{
    double X = (point.first - W) / z;
    double Y = (H - point.second) / z;

    return { X, Y };
}

int main()
{
    GameWindow window;
    window.show(800, 600, "My Game");

    return 0;
}

