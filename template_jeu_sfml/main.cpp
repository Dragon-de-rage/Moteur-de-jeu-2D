#include <GameWindow.h>



using ScreenPoint = std::pair<int, int>;
using WorldPoint = std::pair<double, double>;

ScreenPoint toScreen(const WorldPoint& point, int W, int H, double z)
{
    int X = W / 2 + point.first * z;
    int Y = H / 2 - point.second * z;

    return { X, Y };
}

int main()
{
    GameWindow window;
    window.show(800, 600, "My Game");

    return 0;
}

