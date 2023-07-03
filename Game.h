#pragma once
#include "Entity.h"
#include "Maze.h"
#include <QGraphicsScene>
#include <QTimer>

class Game : public QObject
{
    Q_OBJECT

public:
    Game();
    QGraphicsScene* getScene();
    PacMan* getPacMan();
    const Maze& getMaze() const;

public slots:
    void update();
    //void moveGhost();
private:
    QGraphicsScene scene;
    PacMan* pacMan;
    Ghost* ghost;
    Maze maze;
    QTimer* ghostTimer;
};
