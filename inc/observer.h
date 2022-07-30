#ifndef I_USER_INPUT_OBSERVER
#define I_USER_INPUT_OBSERVER

class IUserInputObserver {
 public:
  virtual ~IUserInputObserver(){};
  virtual void update(int input) = 0;
};

#endif