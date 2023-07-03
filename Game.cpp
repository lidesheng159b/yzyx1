#include "Game.h"

Game::Game()
{
    pacMan = new PacMan(6, 6);
    ghost = new Ghost(19, 19);
    scene.addItem(pacMan->getItem());
    scene.addItem(ghost->getItem());

    //ghostTimer = new QTimer(this);
    //connect(ghostTimer, &QTimer::timeout, this, &Game::moveGhost);
    //ghostTimer->start(1000); // 设置定时器间隔时间

    for (int y = 0; y < maze.getHeight(); ++y)
    {
        for (int x = 0; x < maze.getWidth(); ++x)
        {
            if (maze.isWall(x, y))
            {
                int adjustedX = (x + 6) * 20;
                int adjustedY = (y + 6) * 20;

                auto item = new QGraphicsRectItem(adjustedX, adjustedY, 20, 20);
                item->setBrush(Qt::blue);
                scene.addItem(item);
            }
        }
    }
}

QGraphicsScene* Game::getScene()
{
    return &scene;
}

PacMan* Game::getPacMan()
{
    return pacMan;
}

const Maze& Game::getMaze() const
{
    return maze;
}

void Game::update()
{
    // 更新游戏状态
}

//void Game::moveGhost()
//{
//    const PacMan* pacMan = getPacMan();
//    const Maze& maze = getMaze();
//
//    ghost->move(*pacMan, maze);
//}
