package include;

import java.util.ArrayList;

public interface ISubscriber {
    void attach(IObserver observer);
    void detach(IObserver observer);
    ArrayList<IObserver> getSubscribers();
}
