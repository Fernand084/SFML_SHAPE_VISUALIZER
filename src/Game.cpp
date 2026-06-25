#include "Game.h"

Game::Game() : m_window("Chapter 2", sf::Vector2u(800, 600))
{
    m_circleTexture.loadFromFile("../sprites/Circle-Sprite.png");
    m_circle.setTexture(m_circleTexture);
    m_increment = sf::Vector2i(400, 400);
}

Game::~Game() {}

void Game::HandleInput() {}

void Game::Update()
{
    m_window.Update();
    MoveShape();
}

void Game::MoveShape()
{
    sf::Vector2u l_windSize = m_window.GetWindowSize();
    sf::Vector2u l_textureSize = m_circleTexture.getSize();

    if ((m_circle.getPosition().x >
             l_windSize.x - l_textureSize.x &&
         m_increment.x > 0) ||
        (m_circle.getPosition().x < 0 && m_increment.x < 0))
    {
        m_increment.x = -m_increment.x;
    }
    if ((m_circle.getPosition().y >
             l_windSize.y - l_textureSize.y &&
         m_increment.y > 0) ||
        (m_circle.getPosition().y < 0 && m_increment.y < 0))
    {
        m_increment.y = -m_increment.y;
    }

    float fElapsed = m_elapsed.asSeconds();

    m_circle.setPosition(
        m_circle.getPosition().x + (m_increment.x * fElapsed),
        m_circle.getPosition().y + (m_increment.y * fElapsed));
}

void Game::Render()
{
    m_window.BeginDraw();
    m_window.Draw(m_circle);
    m_window.EndDraw();
}

Window *Game::GetWindow()
{
    return &m_window;
}

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.restart(); }