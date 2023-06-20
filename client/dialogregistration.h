#ifndef DIALOGREGISTRATION_H
#define DIALOGREGISTRATION_H

#include <QDialog>

namespace Ui {
class DialogRegistration;
}

class DialogRegistration : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRegistration(QWidget *parent = nullptr);
    ~DialogRegistration();

private:
    Ui::DialogRegistration *ui;
};

#endif // DIALOGREGISTRATION_H
