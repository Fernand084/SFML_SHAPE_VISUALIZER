#include "Window.h"

class Game
{
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();
    Window *GetWindow();

    sf::Time GetElapsed();
    void RestartClock();

private:
    void MoveShape();
    Window m_window;
    sf::Vector2i m_increment;
    sf::Texture m_circleTexture;
    sf::Sprite m_circle;
    sf::Vector2u m_size;
    sf::Clock m_clock;
    sf::Time m_elapsed;
};