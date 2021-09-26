#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOtworz_triggered();

    void on_actionWytnij_triggered();

    void on_actionNowy_triggered();

    void on_actionZapisz_triggered();

    void on_actionZapisz_jako_triggered();

    void on_actionKopiuj_triggered();

    void on_actionWklej_triggered();

    void on_actionPrzywroc_triggered();

    void on_actionCofnij_triggered();

    void on_textEdit_textChanged();

    void on_actionCzcionka_triggered();

    void on_actionGodzina_data_triggered();

    void on_actionZamknij_triggered();

    void on_poprzedniBtn_clicked();

    void on_nastepnyBtn_clicked();

    void on_actionPowieksz_triggered();

    void on_actionPomniejsz_triggered();

    void on_actionPogrubienie_triggered();

    void on_actionO_nas_triggered();

private:
    Ui::MainWindow *ui;
    QString sciezkaPliku;
    bool zmiana=false;
    bool pogrubiony=false;
};
#endif // MAINWINDOW_H
