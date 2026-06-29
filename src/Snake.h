#include <SFML/Graphics.hpp>

struct SnakeSegment
{
    SnakeSegment(int x, int y) : position(x, y) {}
    sf::Vector2i position; // represent the position of a segment in a grid
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction
{
    None,
    Up,
    Down,
    Left,
    Right
};

class Snake
{
public:
    Snake(int l_blockSize);
    ~Snake();

    // Helper methods
    void SetDirection(Direction l_dir);
    Direction GetDirection();
    Direction GetPhysicalDirection();
    int GetSpeed();
    sf::Vector2i GetPosition();
    int GetLives();
    int GetScore();
    void IncreaseScore();
    bool HasLost();

    void Lose(); // Handling losing here
    void ToggleLost();

    void Extend(); // grow snake
    void Reset();  // Reset to starting position

    void Move();
    void Tick(); // Update method
    void Cut(int l_segments);
    void Render(sf::RenderWindow &l_window);

private:
    void CheckCollision();

    SnakeContainer m_snakeBody; // segment vector
    int m_size;                 // size of graphics
    Direction m_dir;            // current direction
    int m_speed;                // snake speed
    int m_lives;
    int m_score;
    bool m_lost;
    sf::RectangleShape m_bodyRect; // shape use in rendering
};