#pragma once
#include <iostream>
#include <utility>
#include <memory>
#include <ostream>
#include <sstream>
#include "space.hpp"

std::string const LOG_CREATE = "Create Object: ";
std::string const LOG_DAMAGE = "Damage Object: ";
std::string const LOG_DESTRUCTION = "Destruction Object: ";

class Logger
{

public:

  template<typename T>
  static std::ostream & Log(std::ostream & os, std::string action, T const & object)
  {
      os << action << object << std::endl;

    return os;
  }

  template<typename T, template<typename, typename...> class C, typename... Args>
  static std::ostream & Log(std::ostream & os, std::string action, C<T, Args...> const & objs)
  {
    for (auto const & obj : objs)
      Log(os, action, obj);
    return os;
  }

};
