#ifndef ORDERSPAGE_H
#define ORDERSPAGE_H

#include <QWidget>

#include "./basepage.h"

namespace Ui {
class OrdersPage;
}

class OrdersPage : public BasePage
{
    Q_OBJECT

public:
    explicit OrdersPage(QWidget *parent = nullptr);
    ~OrdersPage();

    virtual void setApiClient(api::GogApiClient *apiClient) override;

private:
    api::GogApiClient *apiClient;
    api::OrderFilter filter;
    Ui::OrdersPage *ui;

    void fetchData();

public slots:
    virtual void clear() override;
    virtual void initialize() override;
private slots:
    void on_searchEdit_textChanged(const QString &arg1);
};

#endif // ORDERSPAGE_H
