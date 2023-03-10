#include "./reviewserialization.h"

#include <QJsonArray>

void parseRatingResponse(const QJsonObject &json, api::GetRatingResponse &data)
{
    data.value = json["value"].toDouble();
    data.count = json["count"].toInt();
}

void parseReview(const QJsonObject &json, api::Review &data)
{
    data.id = json["id"].toString();
    data.productId = json["productId"].toString();
    data.rating = json["rating"]["value"].toDouble();
    data.contentTitle = json["content"]["title"].toString();
    data.contentDescription = json["content"]["description"].toString();
    data.contentLanguage = json["content"]["language"].toString();
    data.downvotes = json["votes"]["downvotes"].toInt();
    data.upvotes = json["votes"]["upvotes"].toInt();
    data.date = QDateTime::fromString(json["date"].toString(),Qt::ISODate);
    data.creationDate = QDateTime::fromString(json["creationDate"].toString(),Qt::ISODate);

    auto labels = json["labels"].toArray();
    data.labels.resize(labels.count());
    for (int i = 0; i < labels.count(); i++)
    {
        data.labels[i] = labels[i].toString();
    }

    data.reviewer.id = json["reviewer"]["id"].toString();
    data.reviewer.username = json["reviewer"]["username"].toString();
    data.reviewer.counters.games = json["reviewer"]["counters"]["games"].toInt();
    data.reviewer.counters.reviews = json["reviewer"]["counters"]["reviews"].toInt();
    auto avatar = json["reviewer"]["avatar"]["links"].toVariant().toMap();
    foreach (QString avatarLink, avatar.keys())
    {
        data.reviewer.avatar[avatarLink] = avatar[avatarLink].toString();
    }
}

void parseReviewsResponse(const QJsonObject &json, api::GetReviewsResponse &data)
{
    data.page = json["page"].toInt();
    data.pages = json["pages"].toInt();
    data.limit = json["limit"].toInt();
    data.reviewCount = json["reviewCount"].toInt();
    data.overallAvgRating = json["overallAvgRating"].toDouble();
    data.filteredAvgRating = json["filteredAvgRating"].toDouble();
    data.reviewable = json["isReviewable"].toBool();
    data.mostHelpfulReviewId = json["mostHelpful"]["id"].toString();

    auto items = json["_embedded"]["items"].toArray();
    data.items.resize(items.count());
    for (int i = 0; i < items.count(); i++)
    {
        parseReview(items[i].toObject(), data.items[i]);
    }
}
