package src;

import include.IObserver;
import include.ISubscriber;

import java.util.ArrayList;

public class Subscriber implements ISubscriber {

    public Subscriber() {
        System.out.println("Subscriber::Subscriber");
    }

    public void attach(IObserver o) {
        observers.add(o);
    }

    public void detach(IObserver o) {
        observers.remove(o);
    }

    public ArrayList<IObserver> getSubscribers() {
        return observers;
    }

    private ArrayList<IObserver> observers = new ArrayList<IObserver>();
}
