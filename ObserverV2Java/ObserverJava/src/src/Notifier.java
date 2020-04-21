package src;

import include.INotifier;
import include.IObserver;
import include.ISubscriber;

import java.util.Iterator;
import java.util.List;

public class Notifier implements INotifier {

    Notifier(ISubscriber subs) {
        subscribers = subs;
    }

    public void _notify() {
        List<IObserver> observers = subscribers.getSubscribers();
        for (int i = 0; i < observers.size(); i++) {
            observers.get(i).update();
        }
    }

    private ISubscriber subscribers;
}
