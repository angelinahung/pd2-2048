#include "puzzle.h"
#include "ui_puzzle.h"

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QLCDNumber>
#include <cstdlib>
#include <time.h>
#include <QFont>
#include <QPainter>
#include <QMessageBox>
puzzle::puzzle(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::puzzle)
{
    ui->setupUi(this);

    score=0;
    n[0]=ui->lcdNumber;
    n[0]->display(0);
    lab[0]=ui->label_4;
    lab[1]=ui->label_5;
    lab[2]=ui->label_6;
    lab[3]=ui->label_7;
    lab[4]=ui->label_8;
    lab[5]=ui->label_9;
    lab[6]=ui->label_10;
    lab[7]=ui->label_11;
    lab[8]=ui->label_12;
    lab[9]=ui->label_13;
    lab[10]=ui->label_14;
    lab[11]=ui->label_15;
    lab[12]=ui->label_16;
    lab[13]=ui->label_17;
    lab[14]=ui->label_18;
    lab[15]=ui->label_19;
    for(int i=0;i<16;i++){
        lab[i]->setText("");
        calculate[i]=0;
    }
}

puzzle::~puzzle()
{
    delete ui;
    for(int i=0;i<16;i++)
    {
        delete lab[i];
    }
    delete res;
}


void puzzle::on_pushButton_clicked()
{
    this->close();
}

void puzzle::on_pushButton_2_clicked()
{
    emit reset();
    score=0;
    on_pushButton_3_clicked();
}

void puzzle::keyPressEvent(QKeyEvent *event)
{
    int i,j,k=0;
    if(event->key()==Qt::Key_Right){
        if(gameover()==1){
            for(i=0;i<13;i+=4){
                for(j=3;j>0;j--){
                    if(calculate[i+j]==0){
                        for(k=i+j;k>i+0;k--){
                            calculate[k]=calculate[k-1];
                            calculate[k-1]=0;

                        }
                    }
                }
            }
            for(i=0;i<13;i+=4){
                for(j=3;j>1;j--){
                    if(calculate[i+j]==0){
                        for(k=i+j;k>i+1;k--){
                            calculate[k]=calculate[k-1];
                            calculate[k-1]=0;
                        }
                    }
                }
            }
            for(i=0;i<13;i+=4){
                for(j=3;j>2;j--){
                    if(calculate[i+j]==0){
                        for(k=i+j;k>i+2;k--){
                            calculate[k]=calculate[k-1];
                            calculate[k-1]=0;
                        }
                    }
                }
            }
            addright();
            randomnum();
            output();
            over();
        }
    }
    if(event->key()==Qt::Key_Left){
        if(gameover()==1){
            for(i=0;i<13;i+=4){
                for(j=0;j<3;j++){
                    if(calculate[i+j]==0){
                        for(k=i+j;k<i+3;k++){
                            calculate[k]=calculate[k+1];
                            calculate[k+1]=0;
                        }
                    }
                }
            }
            for(i=0;i<13;i+=4){
                for(j=0;j<2;j++){
                    if(calculate[i+j]==0){
                        for(k=i+j;k<i+2;k++){
                            calculate[k]=calculate[k+1];
                            calculate[k+1]=0;
                        }
                    }
                }
            }
            for(i=0;i<13;i+=4){
                for(j=0;j<1;j++){
                    if(calculate[i+j]==0){
                        for(k=i+j;k<i+1;k++){
                            calculate[k]=calculate[k+1];
                            calculate[k+1]=0;
                        }
                    }
                }
            }
            addleft();
            randomnum();
            output();
            over();
        }
    }
    if(event->key()==Qt::Key_Up){
        if(gameover()==1){
            for(i=0;i<4;i++){
                for(j=0;j<12;j+=4){
                    if(calculate[i+j]==0){
                        for(k=i+j;k<i+12;k+=4){
                            calculate[k]=calculate[k+4];
                            calculate[k+4]=0;
                        }
                    }
                }
            }
            for(i=0;i<4;i++){
                for(j=0;j<8;j+=4){
                    if(calculate[i+j]==0){
                        for(k=i+j;k<i+8;k+=4){
                            calculate[k]=calculate[k+4];
                            calculate[k+4]=0;
                        }
                    }
                }
            }
            for(i=0;i<4;i++){
                for(j=0;j<4;j+=4){
                    if(calculate[i+j]==0){
                        for(k=i+j;k<i+4;k+=4){
                            calculate[k]=calculate[k+4];
                            calculate[k+4]=0;
                        }
                    }
                }
            }
            addup();
            randomnum();
            output();
            over();
        }
    }
    if(event->key()==Qt::Key_Down){
        if(gameover()==1){
            for(i=0;i<4;i++){
                for(j=12;j>0;j-=4){
                    if(calculate[i+j]==0){
                        for(k=i+j;k>i+0;k-=4){
                            calculate[k]=calculate[k-4];
                            calculate[k-4]=0;
                        }
                    }
                }
            }
            for(i=0;i<4;i++){
                for(j=12;j>1;j-=4){
                    if(calculate[i+j]==0){
                        for(k=i+j;k>i+1;k-=4){
                            calculate[k]=calculate[k-4];
                            calculate[k-4]=0;
                        }
                    }
                }
            }
            for(i=0;i<4;i++){
                for(j=12;j>1;j-=4){
                    if(calculate[i+j]==0){
                        for(k=i+j;k>i+1;k-=4){
                            calculate[k]=calculate[k-4];
                            calculate[k-4]=0;
                        }
                    }
                }
            }
            adddown();
            randomnum();
            output();
            over();
        }
    }
}

void puzzle::on_pushButton_3_clicked()
{
    int rand1,rand2;
    srand(time(NULL));
    for(int i=0;i<16;i++){
        lab[i]->setText("");
        calculate[i]=0;
    }
    rand1=rand()%16;
    rand2=rand()%16;
    while(rand1==2){
        rand2=rand()%16;
    }
    calculate[rand1]=2;
    calculate[rand2]=4;
    output();
    n[0]->display(0);
}

void puzzle::output(){
    for(int i=0;i<16;i++){
        if(calculate[i]==0){
            lab[i]->setPixmap(QPixmap(":/new/prefix1/z.png"));
            lab[i]->setScaledContents(true);
            lab[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        }
        if(calculate[i]==2){
            lab[i]->setText("2");
            lab[i]->setAlignment(Qt::AlignCenter);
            /*lab[i]->setPixmap(QPixmap(":/new/prefix1/2.jpg"));
            lab[i]->setScaledContents(true);
            lab[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
            */
        }
        if(calculate[i]==4){
            lab[i]->setText("4");
            lab[i]->setAlignment(Qt::AlignCenter);
            //lab[i]->setPixmap(QPixmap(":/new/prefix1/4.jpg"));
            //lab[i]->setScaledContents(true);
            //lab[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        }
        if(calculate[i]==8){
            lab[i]->setText("8");
            lab[i]->setAlignment(Qt::AlignCenter);
            //lab[i]->setPixmap(QPixmap(":/new/prefix1/8.jpg"));
            //lab[i]->setScaledContents(true);
            //lab[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        }
        if(calculate[i]==16){
            lab[i]->setText("16");
            lab[i]->setAlignment(Qt::AlignCenter);
            //lab[i]->setPixmap(QPixmap(":/new/prefix1/16.jpg"));
            //lab[i]->setScaledContents(true);
            //lab[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        }
        if(calculate[i]==32){
            lab[i]->setText("32");
            lab[i]->setAlignment(Qt::AlignCenter);
            //lab[i]->setPixmap(QPixmap(":/new/prefix1/32.jpg"));
            //lab[i]->setScaledContents(true);
            //lab[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        }
        if(calculate[i]==64){
            lab[i]->setText("64");
            lab[i]->setAlignment(Qt::AlignCenter);
            //lab[i]->setPixmap(QPixmap(":/new/prefix1/64.jpg"));
            //lab[i]->setScaledContents(true);
            //lab[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        }
        if(calculate[i]==128){
            lab[i]->setText("128");
            lab[i]->setAlignment(Qt::AlignCenter);
            //lab[i]->setPixmap(QPixmap(":/new/prefix1/128.jpg"));
            //lab[i]->setScaledContents(true);
            //lab[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        }
        if(calculate[i]==256){
            lab[i]->setText("256");
            lab[i]->setAlignment(Qt::AlignCenter);
            //lab[i]->setPixmap(QPixmap(":/new/prefix1/256.jpg"));
            //lab[i]->setScaledContents(true);
            //lab[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        }
        if(calculate[i]==512){
            lab[i]->setText("512");
            lab[i]->setAlignment(Qt::AlignCenter);
            //lab[i]->setPixmap(QPixmap(":/new/prefix1/512.jpg"));
            //lab[i]->setScaledContents(true);
            //lab[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        }
        if(calculate[i]==1024){
            lab[i]->setText("1024");
            lab[i]->setAlignment(Qt::AlignCenter);
            //lab[i]->setPixmap(QPixmap(":/new/prefix1/1024.jpg"));
            //lab[i]->setScaledContents(true);
            //lab[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        }
        if(calculate[i]==2048){
            lab[i]->setText("2048\n WIN!");
            lab[i]->setAlignment(Qt::AlignCenter);
            lab[i]->setPixmap(QPixmap(":/new/prefix1/2048.jpg"));
            lab[i]->setScaledContents(true);
            lab[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
            res=new result;
            res->show();
        }
    }
    n[0]->display(score);
}
int puzzle::randomnum(){
    int x,y;
    srand(time(NULL));
    x=rand()%16;
    while(calculate[x]!=0){
        x=rand()%16;
    }
    y=rand()%2;
    if(y==0){
        calculate[x]=2;
    }
    if(y==1){
        calculate[x]=4;
    }
    return 0;
}

void puzzle::addright(){
    int j;
    for(j=0;j<13;j+=4){
        for(int i=0;i<1;i++){
            if(calculate[3+j]==calculate[2+j]){
                if(calculate[1+j]!=calculate[0+j]){
                    calculate[3+j]=calculate[3+j]+calculate[2+j];
                    calculate[2+j]=calculate[1+j];
                    calculate[1+j]=calculate[0+j];
                    calculate[0+j]=0;
                    score=score+calculate[3+j];
                    break;
                }
                if(calculate[1+j]==calculate[0+j]){
                    calculate[3+j]=calculate[3+j]+calculate[2+j];
                    calculate[2+j]=calculate[1+j]+calculate[0+j];
                    calculate[1+j]=0;
                    calculate[0+j]=0;
                    score=score+calculate[3+j]+calculate[2+j];
                    break;
                }
            }
            if(calculate[2+j]==calculate[1+j]){
                calculate[2+j]=calculate[2+j]+calculate[1+j];
                calculate[1+j]=calculate[0+j];
                calculate[0+j]=0;
                score=score+calculate[2+j];
                break;
            }
            if(calculate[1+j]==calculate[0+j]){
                calculate[1+j]=calculate[1+j]+calculate[0+j];
                calculate[0+j]=0;
                score=score+calculate[1+j];
                break;
            }
        }
    }
}
void puzzle::addleft(){
    int j;
    for(j=0;j<13;j+=4){
        for(int i=0;i<1;i++){
            if(calculate[0+j]==calculate[1+j]){
                if(calculate[2+j]!=calculate[3+j]){
                    calculate[0+j]=calculate[0+j]+calculate[1+j];
                    calculate[1+j]=calculate[2+j];
                    calculate[2+j]=calculate[3+j];
                    calculate[3+j]=0;
                    score=score+calculate[0+j];
                    break;
                }
                if(calculate[2+j]==calculate[3+j]){
                    calculate[0+j]=calculate[0+j]+calculate[1+j];
                    calculate[1+j]=calculate[2+j]+calculate[3+j];
                    calculate[2+j]=0;
                    calculate[3+j]=0;
                    score=score+calculate[0+j]+calculate[1+j];
                    break;
                }
            }
            if(calculate[1+j]==calculate[2+j]){
                calculate[1+j]=calculate[1+j]+calculate[2+j];
                calculate[2+j]=calculate[3+j];
                calculate[3+j]=0;
                score=score+calculate[1+j];
                break;
            }
            if(calculate[2+j]==calculate[3+j]){
                calculate[2+j]=calculate[2+j]+calculate[3+j];
                calculate[3+j]=0;
                score=score+calculate[2+j];
                break;
            }
        }
    }
}
void puzzle::addup(){
    int j;
    for(j=0;j<4;j++){
        for(int i=0;i<1;i++){
            if(calculate[0+j]==calculate[4+j]){
                if(calculate[8+j]!=calculate[12+j]){
                    calculate[0+j]=calculate[0+j]+calculate[4+j];
                    calculate[4+j]=calculate[8+j];
                    calculate[8+j]=calculate[12+j];
                    calculate[12+j]=0;
                    score=score+calculate[0+j];
                    break;
                }
                if(calculate[8+j]==calculate[12+j]){
                    calculate[0+j]=calculate[0+j]+calculate[4+j];
                    calculate[4+j]=calculate[8+j]+calculate[12+j];
                    calculate[8+j]=0;
                    calculate[12+j]=0;
                    score=score+calculate[0+j]+calculate[4+j];
                    break;
                }
            }
            if(calculate[4+j]==calculate[8+j]){
                calculate[4+j]=calculate[4+j]+calculate[8+j];
                calculate[8+j]=calculate[12+j];
                calculate[12+j]=0;
                score=score+calculate[4+j];
                break;
            }
            if(calculate[8+j]==calculate[12+j]){
                calculate[8+j]=calculate[8+j]+calculate[12+j];
                calculate[12+j]=0;
                score=score+calculate[8+j];
                break;
            }
        }
    }
}
void puzzle::adddown(){
    int j;
    for(j=0;j<4;j++){
        for(int i=0;i<1;i++){
        if(calculate[12+j]==calculate[8+j]){
            if(calculate[4+j]!=calculate[0+j]){
                calculate[12+j]=calculate[12+j]+calculate[8+j];
                calculate[8+j]=calculate[4+j];
                calculate[4+j]=calculate[0+j];
                calculate[0+j]=0;
                score=score+calculate[12+j];
                break;
            }
            if(calculate[4+j]==calculate[0+j]){
                calculate[12+j]=calculate[12+j]+calculate[8+j];
                calculate[8+j]=calculate[4+j]+calculate[0+j];
                calculate[4+j]=0;
                calculate[0+j]=0;
                score=score+calculate[12+j]+calculate[8+j];
                break;
            }
        }
        if(calculate[8+j]==calculate[4+j]){
            calculate[8+j]=calculate[8+j]+calculate[4+j];
            calculate[4+j]=calculate[0+j];
            calculate[0+j]=0;
            score=score+calculate[8+j];
            break;
        }
        if(calculate[4+j]==calculate[0+j]){
            calculate[4+j]=calculate[4+j]+calculate[0+j];
            calculate[0+j]=0;
            score=score+calculate[4+j];
            break;
        }
        }
    }
}
int puzzle::gameover(){
    int i,j;
    for(i=0;i<13;i+=4){
        for(j=0;j<4;j++){
            if(j-1>=0){
                if(calculate[i+j-1]==calculate[i+j]){
                    return 1;
                }
            }
            if(j+1<4){
                if(calculate[i+j+1]==calculate[i+j]){
                    return 1;
                }
            }
            if(i-4>=0){
                if(calculate[i+j-4]==calculate[i+j]){
                    return 1;
                }
            }
            if(i+4<13){
                if(calculate[i+j+4]==calculate[i+j]){
                    return 1;
                }
            }
        }
    }
    for(i=0;i<16;i++){
        if(calculate[i]==0){
            return 1;
        }
    }
    return 0;
}
void puzzle::over(){
    if(gameover()==0){
        QMessageBox::information(this,"YOU　LOSE!!","GAME OVER");
    }
}
