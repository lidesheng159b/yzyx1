#pragma once
#include"Game.h"
#include <QKeyEvent>  
#include <QtWidgets/QMainWindow>
#include "ui_GameWindow.h"

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget* parent = nullptr);
    ~GameWindow();
protected:
    void keyPressEvent(QKeyEvent* event)
    {
        const Maze& maze = game->getMaze(); // 获取迷宫对象
        switch (event->key())
        {
        case Qt::Key_W:
            game->getPacMan()->move(PacMan::UP, maze);
            break;
        case Qt::Key_S:
            game->getPacMan()->move(PacMan::DOWN, maze);
            break;
        case Qt::Key_A:
            game->getPacMan()->move(PacMan::LEFT, maze);
            break;
        case Qt::Key_D:
            game->getPacMan()->move(PacMan::RIGHT, maze);
            break;
        }
    }

private:
    Ui::GameWindowClass ui;
    Game* game;
    QGraphicsView* view;

};
