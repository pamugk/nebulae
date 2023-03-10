#ifndef TAG_H
#define TAG_H

#include <QtGlobal>
#include <QString>

namespace api
{
    struct Tag
    {
        QString id;
        QString name;
        qint32 productCount;
    };
}

#endif // TAG_H
