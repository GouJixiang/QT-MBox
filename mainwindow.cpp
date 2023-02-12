#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGridLayout>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <QFile>
#include <QMessageBox>
#include <QMenuBar>

// 导入样式表

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("QT-MBox");
    ui->menuBar->setNativeMenuBar(false);

    QFile *styleFile = new QFile(":/style/mainWindow.css");
    if (!styleFile->open(QFile::ReadOnly)) {
        int ret = QMessageBox::warning(NULL, "警告", "主窗口样式资源加载失败！", QMessageBox::Yes);
        if (ret==QMessageBox::Yes) {
            exit(1);
        }
    }
    // 创建central窗口
    QWidget *centralWidget = new QWidget();
    // 创建标题
    QLabel *mainTitleLabel = new QLabel("QT-MBox");
    mainTitleLabel->setObjectName("mainTitleLabel");
    mainTitleLabel->setAlignment(Qt::AlignCenter);
    ui->statusbar->showMessage("欢迎使用QT-MBox！，邮箱地址：tiamoer@outlook.com");
    // 创建工具集
    QPushButton *proxyBtn = new QPushButton("网络代理");
    QPushButton *eniveBtn = new QPushButton("环境管理");
    QPushButton *serviceBtn = new QPushButton("服务管理");
    QPushButton *base64Btn = new QPushButton("base64转换");
    // 设置布局
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(mainTitleLabel, 0, 0, 2, 3);
    mainLayout->addWidget(proxyBtn, 2, 0);
    mainLayout->addWidget(eniveBtn, 2, 1);
    mainLayout->addWidget(serviceBtn, 2, 2);
    mainLayout->addWidget(base64Btn, 3, 0);
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);
    // 设置主窗口样式
    QString styleSheet = QString(styleFile->readAll());
    centralWidget->setStyleSheet(styleSheet);
    styleFile->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
