#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include <QDialog>

namespace Ui {
class AuthDialog;
}

class AuthDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AuthDialog(QWidget *parent = nullptr);
    ~AuthDialog();

    void setUrl(const QUrl &authUrl);

private:
    Ui::AuthDialog *ui;
};

#endif // AUTHDIALOG_H
