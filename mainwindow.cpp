#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QFontDialog>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOtworz_triggered()
{
    QString nazwaPliku = QFileDialog::getOpenFileName(this,"Otwieranie pliku");
    QFile plik(nazwaPliku);
    sciezkaPliku=nazwaPliku;
    if(!plik.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"..","Nie da się otworzyć pliku");
        return;
    }
    QTextStream wej(&plik);
    QString tekst = wej.readAll();
    ui->textEdit->setText(tekst);
    plik.close();
}


void MainWindow::on_actionWytnij_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionNowy_triggered()
{
    sciezkaPliku = "";
    ui->textEdit->setText("");
}


void MainWindow::on_actionZapisz_triggered()
{
    QFile plik(sciezkaPliku);
    if(!plik.open(QFile::WriteOnly | QFile::Text))
    {
        if(sciezkaPliku==nullptr)
        {
            MainWindow::on_actionZapisz_jako_triggered();
            return;
        }
        else
        {
            QMessageBox::warning(this,"..","Błąd podczas zapisu pliku");
            return;
        }
    }
    QTextStream wyj(&plik);
    QString tekst =ui->textEdit->toPlainText();
    wyj<<tekst;
    plik.flush();
    plik.close();
    zmiana=false;
}


void MainWindow::on_actionZapisz_jako_triggered()
{
    QString nazwaPliku = QFileDialog::getSaveFileName(this,"Zapisywanie pliku","",tr("TXT(.txt)"));
    QFile plik(nazwaPliku);
    sciezkaPliku=nazwaPliku;
    if(!plik.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"..","Błąd podczas zapisu pliku");
        return;
    }
    QTextStream wyj(&plik);
    QString tekst =ui->textEdit->toPlainText();
    wyj<<tekst;
    plik.flush();
    plik.close();
    zmiana=false;
}


void MainWindow::on_actionKopiuj_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionWklej_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionPrzywroc_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionCofnij_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_textEdit_textChanged()
{
    QString tekst = ui->textEdit->toPlainText();
    int ilosc=0;
    for(int i=0;i<tekst.size();i++)
    {
        ilosc++;
    }
    ui->label->setText(QString::number(ilosc));
    zmiana=true;
}


void MainWindow::on_actionCzcionka_triggered()
{
    bool ok;
    QFont czcionka;
    czcionka=QFontDialog::getFont(&ok,this);
    ui->textEdit->setFont(czcionka);
}


void MainWindow::on_actionGodzina_data_triggered()
{
    QDateTime czas;

    ui->textEdit->insertPlainText(czas.currentDateTime().toString("hh:mm dd.MM.yyyy"));
}


void MainWindow::on_actionZamknij_triggered()
{
    if(zmiana==false)
    {
    close();
    }
    else
    {
    MainWindow::on_actionZapisz_triggered();
    close();
    }
}

void MainWindow::on_poprzedniBtn_clicked()
{
    ui->textEdit->find(ui->lineEdit->text(),QTextDocument::FindBackward);
}


void MainWindow::on_nastepnyBtn_clicked()
{
    ui->textEdit->find(ui->lineEdit->text());
}


void MainWindow::on_actionPowieksz_triggered()
{
    ui->textEdit->zoomIn();
}


void MainWindow::on_actionPomniejsz_triggered()
{
    ui->textEdit->zoomOut();
}


void MainWindow::on_actionPogrubienie_triggered()
{
    if(!pogrubiony)
    {
        QTextCharFormat format;
        format.setFontWeight(QFont::Bold);
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.mergeCharFormat(format);
        pogrubiony = true;
    }
    else if(pogrubiony)
    {
        QTextCharFormat format;
        format.setFontWeight(QFont::Normal);
        QTextCursor cursor = ui->textEdit->textCursor();
        cursor.mergeCharFormat(format);
        pogrubiony = false;
    }
}


void MainWindow::on_actionO_nas_triggered()
{
    QString about_text;
        about_text = " Autorzy : Grudzień Adrian , Macias Dominik , Skowron Kewin\n";
        about_text += " Data : 13.09.2021\n";
        about_text += " (C) Notatnik (R)";

        QMessageBox::about(this,"About Notepad", about_text);
}

