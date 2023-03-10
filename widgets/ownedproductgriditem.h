#ifndef OWNEDPRODUCTGRIDITEM_H
#define OWNEDPRODUCTGRIDITEM_H

#include <QNetworkReply>
#include <QWidget>

#include "../api/gogapiclient.h"
#include "../api/models/ownedproduct.h"

namespace Ui {
class OwnedProductGridItem;
}

class OwnedProductGridItem : public QWidget
{
    Q_OBJECT

public:
    explicit OwnedProductGridItem(const api::OwnedProduct &data,
                                  api::GogApiClient *apiClient,
                                  QWidget *parent = nullptr);
    ~OwnedProductGridItem();

signals:
    void navigateToProduct(quint64 id);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    quint64 itemId;
    QNetworkReply *imageReply;
    Ui::OwnedProductGridItem *ui;
};

#endif // OWNEDPRODUCTGRIDITEM_H
