#include "../src/Notifier.cpp"

class ClockTimer: public IClockTimer
{
    public:
        ClockTimer(ISubscriber* subscriber):refCount(0),notifier(new Notifier(subscriber)) {
            acquire();
            m_hours = 0;
            m_minutes = 0;
            m_seconds = 0;
            std::cout << "ClockTimer::ClockTimer" << std::endl;
            this->subscriber = subscriber;
        }

        virtual ~ClockTimer(){
            std::cout << "ClockTimer::~ClockTimer" << std::endl;
            notifier->release();
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
            return this->subscriber;
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

        //IMemoryManagement interface implementation

        void acquire(){
            refCount++;
        }

        void release(){
            if(--refCount == 0)
                delete this;
        }

    private:
        int refCount;
        int m_hours;
        int m_minutes;
        int m_seconds;
        ISubscriber* subscriber;
        INotifier* notifier;
        
};


