/*
  This file is part of the Grantlee template system.

  Copyright (c) 2009,2010 Stephen Kelly <steveire@gmail.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either version
  2.1 of the Licence, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef GRANTLEE_TEMPLATE_P_H
#define GRANTLEE_TEMPLATE_P_H

#include "engine.h"
#include "template.h"

#if QT_VERSION < 0x040600
#include <QtCore/QPointer>
#else
#include <QtCore/QWeakPointer>
#endif

namespace Grantlee
{

class Engine;

class TemplatePrivate
{
  TemplatePrivate( Engine const *engine, bool smartTrim, TemplateImpl *t )
      : q_ptr( t ), m_error( NoError ), m_smartTrim( smartTrim )
#if QT_VERSION >= 0x040600
      , m_engine( engine )
#endif
  {
#if QT_VERSION < 0x040600
    m_engine = const_cast<Engine *>( engine );
#endif
  }

  void parse();
  NodeList compileString( const QString &str );
  void setError( Error type, const QString &message );

  Q_DECLARE_PUBLIC( TemplateImpl )
  TemplateImpl * const q_ptr;

  Error m_error;
  QString m_errorString;
  NodeList m_nodeList;
  bool m_smartTrim;
#if QT_VERSION < 0x040600
  QPointer<Engine> m_engine;
#else
  QWeakPointer<Engine const> m_engine;
#endif

  friend class Grantlee::Engine;
  friend class Parser;

};

}

#endif

