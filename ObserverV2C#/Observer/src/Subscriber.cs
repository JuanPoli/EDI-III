using Observer.include;
using System;
using System.Collections.Generic;
using System.Text;

namespace Observer.src
{
   public class Subscriber: ISubscriber {

        public Subscriber() {

        }

        public void Attach(IObserver o)
        {
            observers.Add(o);
        }
        public void Detach(IObserver o)
        {
            observers.Remove(o);
        }

        public List<IObserver> GetSubscribers()
        {
            return observers;
        }

        private List<IObserver> observers = new List<IObserver>();
    }
}
