#pragma once
#include <iostream>
#include <utility>
#include <memory>
#include <ostream>
#include <sstream>
#include "logger.hpp"
#include "space.hpp"

enum class GameAction { Create, Damage, Destruction };

class Logger
{

public:

  template<typename T>
  static std::ostream & Log(std::ostream & os, GameAction action, T const & object)
  {
    switch (action)
    {
    case GameAction::Create:
      os << "Create Object: " << object << std::endl;
      break;
    case GameAction::Damage:
      os << "Damage Object: " << object << std::endl;
      break;
    case GameAction::Destruction:
      os << "Destruction Object: " << object << std::endl;
      break;
    }
    return os;
  }

  template<typename T, template<typename, typename...> class C, typename... Args>
  static std::ostream & Log(std::ostream & os, GameAction action, C<T, Args...> const & objs)
  {
    for (auto const & obj : objs)
      Log(os, action, obj);
    return os;
  }

};
