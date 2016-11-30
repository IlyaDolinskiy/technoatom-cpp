#pragma once
#include <iostream>
#include <memory>
#include "singleton.hpp"

class Factory : public Singleton<Factory>
{
public:
  template<typename T, typename... Args>
  std::unique_ptr<T> Create(Args && ... args)
  {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
  }

private:
  Factory() = default;
  friend class Singleton<Factory>;
};