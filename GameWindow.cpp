#include "GameWindow.h"
#include <QTimer> 
GameWindow::GameWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // ������Ϸ����
    game = new Game();

    // ���� QGraphicsView ���󣬲��� Game �� QGraphicsScene ��������Ϊ�䳡��
    view = new QGraphicsView(game->getScene(), this);

    // ���ô���Ϊ QGraphicsView ����
    setCentralWidget(view);


    // ���ô��ڴ�С
    setFixedSize(800, 600);

    // ���ô��ڱ���
    setWindowTitle("My Game");


    // �����ڽ��ռ����¼�
    setFocusPolicy(Qt::StrongFocus);
}

GameWindow::~GameWindow()
{}
