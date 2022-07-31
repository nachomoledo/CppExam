#ifndef I_USER_INPUT_OBSERVER_H
#define I_USER_INPUT_OBSERVER_H

class IUserInputObserver {
 public:
  virtual ~IUserInputObserver(){};
  virtual void update(int input) = 0;
};

#endif