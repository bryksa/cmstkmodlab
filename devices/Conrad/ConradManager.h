#ifndef CONRADMANAGER_H
#define CONRADMANAGER_H

#include <QObject>
#include <ConradModel.h>

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#include <QDesktopServices>
#else
#include <QStandardPaths>
#endif


class ConradManager : ConradModel
{
  Q_OBJECT

public slots:

    void toggleVacuum();

};

#endif // CONRADMANAGER_H
