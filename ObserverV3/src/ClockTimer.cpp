#include "../src/Notifier.cpp"
#include "../include/IClockTimer.h"
#include "../include/SmartPointer.h"

class ClockTimer: public IClockTimer
{
    public:
    ClockTimer(ISubscriber* subscriber): subs(subscriber),notifier(new Notifier(subscriber)) {
            m_hours = 0;
            m_minutes = 0;
            m_seconds = 0;
            std::cout << "ClockTimer::ClockTimer" << std::endl;
        }

        virtual ~ClockTimer(){
            std::cout << "ClockTimer::~ClockTimer" << std::endl;
        }

        int getHour( void ) {
            return this->m_hours;
        }

        int getMinute( void ) {
            return this->m_minutes;
        }

        int getSecond( void ) {
            return this->m_seconds;
        }

        ISubscriber* getSubscriber() {
            return  subs;
        }

        void tick () {
            m_seconds++;
            if(m_seconds == 60) {
                m_seconds = 0;
                m_minutes++;
                if(m_minutes == 60) {
                    m_seconds = 0;
                    m_minutes = 0;
                    m_hours++;
                    if(m_hours == 24) {
                        m_seconds = 0;
                        m_minutes = 0;
                        m_hours = 0;
                    }
                }
            }
            notifier->notify();
        }

    private:
        int m_hours;
        int m_minutes;
        int m_seconds;
        ISubscriber* subs;
        Smart_ptr<INotifier> notifier;
};


