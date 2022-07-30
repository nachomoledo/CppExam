#include "observer.h"

class ISubject {
    public:
        virtual ~ISubject(){};
        virtual void attach(IUserInputObserver *observer) = 0;
        virtual void detach(IUserInputObserver *observer) = 0;
    private:
        virtual void notify(void) = 0;
};