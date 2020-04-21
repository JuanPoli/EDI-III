using Observer.include;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Observer.src
{
   public class Notifier: INotifier {

        public Notifier(ISubscriber subs) {
            subscribers = subs;
        }

        public void Notify()
        {
            List<IObserver> observers = subscribers.GetSubscribers();
            for (int i = 0; i< observers.Count; i++)
            {
                observers.ElementAt(i).Update();
            }
        }

        private ISubscriber subscribers;
    }
}
