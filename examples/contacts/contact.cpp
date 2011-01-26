/*
  This file is part of the Grantlee template system.

  Copyright (c) 2010 Stephen Kelly <steveire@gmail.com>

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

#include "contact.h"

Contact::Contact(QObject* parent)
  : QObject(parent)
{

}

QString Contact::name() const
{
  return m_name;
}

void Contact::setName(const QString& name)
{
  m_name = name;
}

QString Contact::email() const
{
  return m_email;
}

void Contact::setEmail(const QString& email)
{
  m_email = email;
}

QString Contact::phone() const
{
  return m_phone;
}

void Contact::setPhone(const QString& phone)
{
  m_phone = phone;
}

QString Contact::address() const
{
  return m_address;
}

void Contact::setAddress(const QString& address)
{
  m_address = address;
}

QString Contact::nickname() const
{
  return m_nickname;
}

void Contact::setNickname(const QString& nickname)
{
  m_nickname = nickname;
}

QString Contact::salaryCurrency() const
{
  return m_salaryCurrency;
}

void Contact::setSalaryCurrency(const QString& salaryCurrency)
{
  m_salaryCurrency = salaryCurrency;
}

double Contact::salary() const
{
  return m_salary;
}

void Contact::setSalary(double salary)
{
  m_salary = salary;
}

double Contact::rating() const
{
  return m_rating;
}

void Contact::setRating(double rating)
{
  m_rating = rating;
}

QDate Contact::birthday() const
{
  return m_birthday;
}

void Contact::setBirthday(const QDate &birthday)
{
  m_birthday = birthday;
}

QVariant Contact::data(int role) const
{
  if (role != Qt::DisplayRole)
    return QListWidgetItem::data(role);
  return m_name;
}

#include "contact.moc"
