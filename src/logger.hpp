#pragma once

#include <iostream>
#include <utility>
#include <memory>
#include <ostream>
#include <sstream>
#include "space.hpp"
#include "singleton.hpp"

std::string const LOG_CREATE = "Create Object: ";
std::string const LOG_DAMAGE = "Damage Object: ";
std::string const LOG_DESTRUCTION = "Destruction Object: ";

class Logger : public Singleton<Logger>
{

public:
  template<typename T>
  Logger & operator << (T const & object)
  {
    std::ostringstream m_os;
    m_os << object;
    os += m_os.str();
    return *this;
  }

  template<typename T, template<typename, typename...> class C, typename... Args>
  Logger & operator << (C<T, Args...> const & objs)
  {
    std::ostringstream m_os;
    m_os << "COLLECTION: ";
    for (auto const & obj : objs)
      m_os << objs << "; ";
    os += m_os.str();
    return *this;
  }
  
private:
  Logger() = default;
  std::string os;
  friend class Singleton<Logger>;

};
