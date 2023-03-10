#ifndef CATALOG_H
#define CATALOG_H

#include <QtGlobal>

#include <QString>
#include <QVector>

#include "./filters.h"
#include "./metatag.h"

namespace api
{
    struct Money
    {
        QString amount;
        QString currency;
    };

    struct CatalogPrice
    {
        QString final;
        QString base;
        QString discount;
        Money finalMoney;
        Money baseMoney;
    };

    struct PreferredLanguage
    {
        QString code;
        bool inAudio;
        bool inText;
    };

    struct CatalogProduct
    {
        QString id;
        QString slug;
        QVector<MetaTag> features;
        QVector<QString> screenshots;
        PreferredLanguage userPreferredLanguage;
        QString releaseDate;
        QString productType;
        QString title;
        QString coverHorizontal;
        QString coverVertical;
        QVector<QString> developers;
        QVector<QString> publishers;
        QVector<QString> operatingSystems;
        CatalogPrice price;
        QString productState;
        QVector<MetaTag> genres;
        QVector<MetaTag> tags;
        quint8 reviewsRating;
    };

    struct SearchCatalogResponse
    {   quint16 pages;
        quint32 productCount;
        QVector<CatalogProduct> products;
        StoreFilters filters;
    };
}

#endif // CATALOG_H
