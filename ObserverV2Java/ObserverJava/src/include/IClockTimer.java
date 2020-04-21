package include;

public interface IClockTimer {
     int getHour();
     int getMinute();
     int getSecond();
     ISubscriber getSubscriber();
     void tick();
}
