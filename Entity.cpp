#include "Entity.h"
#include <QRandomGenerator>

Entity::Entity(int x, int y) : posX(x), posY(y) {
    item = new QGraphicsEllipseItem(x * 20, y * 20, 20, 20);
}

int Entity::getX() const {
    return posX;
}

int Entity::getY()const {
    return posY;
}

void Entity::setX(int x) {
    posX = x;
}

void Entity::setY(int y) {
    posY = y;
}

QGraphicsEllipseItem* Entity::getItem() {
    return item;
}

PacMan::PacMan(int x, int y) : Entity(x, y) {
    getItem()->setBrush(Qt::yellow);
}

void PacMan::move(Direction direction, const Maze& maze) {
    int dx = 0, dy = 0;

    switch (direction)
    {
    case UP:
        dy = -1;
        break;
    case DOWN:
        dy = 1;
        break;
    case LEFT:
        dx = -1;
        break;
    case RIGHT:
        dx = 1;
        break;
    }

    // 检查目标位置是否是墙壁
    if (!maze.isWall(getX() + dx, getY() + dy))
    {
        setX(getX() + dx);
        setY(getY() + dy);
        getItem()->setPos(getX() * 20, getY() * 20);
    }
}

Ghost::Ghost(int x, int y)
    : Entity(x, y)
{
    getItem()->setBrush(Qt::red);
}

//
//void Ghost::move(const PacMan& pacMan, const Maze& maze)
//{
//    // 实现敌人的移动逻辑
//    // 根据当前敌人和PacMan的位置、迷宫信息等进行移动操作
//
//    int currentX = getX();
//    int currentY = getY();
//    int pacManX = pacMan.getX();
//    int pacManY = pacMan.getY();
//
//    if (currentX < pacManX) {
//        setX(currentX + 1);
//    }
//    else if (currentX > pacManX) {
//        setX(currentX - 1);
//    }
//
//    if (currentY < pacManY) {
//        setY(currentY + 1);
//    }
//    else if (currentY > pacManY) {
//        setY(currentY - 1);
//    }
//
//    getItem()->setPos(getX() * 20, getY() * 20);
//}
