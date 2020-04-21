using System;
using System.Collections.Generic;
using System.Text;

namespace Observer.include
{
    public interface ISubscriber {
        void Attach(IObserver observer);
        void Detach(IObserver observer);
        List<IObserver> GetSubscribers();
    }
}
