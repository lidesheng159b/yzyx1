#include "GameWindow.h"
#include <QTimer> 
GameWindow::GameWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // 创建游戏对象
    game = new Game();

    // 创建 QGraphicsView 对象，并将 Game 的 QGraphicsScene 对象设置为其场景
    view = new QGraphicsView(game->getScene(), this);

    // 设置窗口为 QGraphicsView 对象
    setCentralWidget(view);


    // 设置窗口大小
    setFixedSize(800, 600);

    // 设置窗口标题
    setWindowTitle("My Game");


    // 允许窗口接收键盘事件
    setFocusPolicy(Qt::StrongFocus);
}

GameWindow::~GameWindow()
{}
