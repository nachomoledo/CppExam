class IUserInputObserver {
 public:
  virtual ~IUserInputObserver(){};
  virtual void update(int input) = 0;
};