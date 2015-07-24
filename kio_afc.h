/***************************************************************************
 *   Copyright (C) 2010 by Jonathan Beck <jonabeck@gmail.com>              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef __kio_afc_h__
#define __kio_afc_h__

#include <kio/global.h>
#include <kio/slavebase.h>

#include <kio/global.h>
#include <kio/slavebase.h>
#include <KLocalizedString>

#include <QUrl>
#include <QLoggingCategory>

#include "afcdevice.h"
#include "afcpath.h"

#include <libimobiledevice/libimobiledevice.h>


using namespace KIO;

Q_DECLARE_LOGGING_CATEGORY(LOG_KIO_AFC)

class AfcProtocol : public QObject, public KIO::SlaveBase
{
  Q_OBJECT
public:
  AfcProtocol( const QByteArray &pool, const QByteArray &app);
  virtual ~AfcProtocol();

  void ProcessEvent(const idevice_event_t *event);

  AfcPath checkURL( const QUrl& url );

  virtual void stat( const QUrl& url );

  virtual void get( const QUrl& url );

  virtual void put( const QUrl& url, int _mode,
                    KIO::JobFlags _flags );

  virtual void rename( const QUrl &src, const QUrl &dest,
                       KIO::JobFlags flags );
  virtual void symlink( const QString &target, const QUrl &dest,
                        KIO::JobFlags flags );

  virtual void listDir( const QUrl& url );
  virtual void mkdir( const QUrl& url, int permissions );
  virtual void setModificationTime( const QUrl& url, const QDateTime& mtime );
  virtual void del( const QUrl& url, bool isfile);
  virtual void open( const QUrl &url, QIODevice::OpenMode mode );
  virtual void read( KIO::filesize_t size );
  virtual void write( const QByteArray &data );
  virtual void seek( KIO::filesize_t offset );
  virtual void close();

  //cached user and group
  static QString m_user;
  static QString m_group;

private:

  QHash<QString, AfcDevice*> _devices;
  AfcDevice* _opened_device;

};

#endif

