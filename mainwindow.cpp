#include "mainwindow.h"
#include "ui_mainwindow.h"


#define LED_PWM 26

#define LED_BASE 200

#define dataPin 24
#define clockPin 1
#define latchPin 23

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wiringPiSetup () ;
    sr595Setup (LED_BASE, 8, dataPin, clockPin, latchPin) ;
    pinMode (LED_PWM, PWM_OUTPUT);
    pwmWrite(LED_PWM, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    
    pwmWrite (LED_PWM, 1000);
    digitalWrite (LED_BASE + 0,HIGH) ; 
    digitalWrite (LED_BASE + 1,HIGH) ; 
    digitalWrite (LED_BASE + 2,HIGH) ; 
    digitalWrite (LED_BASE + 3,HIGH) ; 
    digitalWrite (LED_BASE + 4,HIGH) ; 
    digitalWrite (LED_BASE + 5,HIGH) ; 
    digitalWrite (LED_BASE + 6,HIGH) ; 
    digitalWrite (LED_BASE + 7,HIGH) ;  
    
    QThread::msleep(1000);
    
    
    digitalWrite (LED_BASE + 0,LOW) ;
    digitalWrite (LED_BASE + 1,LOW) ;
    digitalWrite (LED_BASE + 2,LOW) ;
    digitalWrite (LED_BASE + 3,LOW) ;
    digitalWrite (LED_BASE + 4,LOW) ;
    digitalWrite (LED_BASE + 5,LOW) ;
    digitalWrite (LED_BASE + 6,LOW) ;
    digitalWrite (LED_BASE + 7,LOW) ;
    pwmWrite (LED_PWM, 0);
    
    
    
}
