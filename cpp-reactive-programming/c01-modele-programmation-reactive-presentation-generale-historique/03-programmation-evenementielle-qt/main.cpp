#include <qapplication.h>
#include <qdialog.h>
#include <qmessagebox.h>
#include <qobject.h>
#include <qpushbutton.h>

class MyApp : public QDialog
{
    Q_OBJECT
public:
    MyApp(QObject * /*parent*/ = 0) : button(this)
    {
        button.setText("Bonjour le monde !");
        button.resize(100, 30);
        // Au clic du bouton, exécuter la fonction button_clicked
        connect(&button, &QPushButton::clicked, this, &MyApp::button_clicked);
    }

public slots:
    void button_clicked()
    {
        QMessageBox box;
        box.setWindowTitle("Bienvenue");
        box.setText("Vous avez cliqué sur le bouton");
        box.show();
        box.exec();
    }

protected:
    QPushButton button;
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MyApp myapp;
    myapp.show();
    return app.exec();
}