#ifndef PASSWORDSETUP_H
#define PASSWORDSETUP_H

#include "ui_passwordsetup.h"
#include <QtGui/QWidget>
class PasswordSetup: public QWidget
{
    Q_OBJECT
public:
    PasswordSetup();
    ~PasswordSetup();

private:
    Ui::PasswordSetupDialog ui;

};

#endif // PASSWORDSETUP_H
