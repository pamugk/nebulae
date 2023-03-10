#ifndef STOREGRIDTILE_H
#define STOREGRIDTILE_H

#include <QNetworkReply>
#include <QWidget>

#include "../api/gogapiclient.h"
#include "../api/models/catalog.h"

namespace Ui {
class StoreGridTile;
}

class StoreGridTile : public QWidget
{
    Q_OBJECT

public:
    explicit StoreGridTile(const api::CatalogProduct &data,
                           api::GogApiClient *apiClient,
                           QWidget *parent = nullptr);
    ~StoreGridTile();

signals:
    void navigateToProduct(quint64 id);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    quint64 itemId;
    QNetworkReply *imageReply;
    Ui::StoreGridTile *ui;
};

#endif // STOREGRIDTILE_H
