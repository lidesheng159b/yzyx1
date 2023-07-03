#pragma once
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QRandomGenerator>
#include "Maze.h"
#include <QTimer>
#include<QObject>
// ʵ���࣬��Һ͵��˶��̳д���
class Entity : public QObject
{
    Q_OBJECT // ���Q_OBJECT��
public:
    Entity(int x, int y);

    int getX()const;
    int getY()const;
    void setX(int x);
    void setY(int y);
    QGraphicsEllipseItem* getItem();

private:
    int posX, posY;
    QGraphicsEllipseItem* item;
};

// �����
class PacMan : public Entity
{
public:
    enum Direction { UP, DOWN, LEFT, RIGHT };
    PacMan(int x, int y);
    void move(Direction direction, const Maze& maze);
};

// ������
class Ghost : public Entity
{

public:
    Ghost(int x, int y);

//public slots:
//    void move(const PacMan& pacMan, const Maze& maze);
//
//private:
//    //QTimer* timer;
};
