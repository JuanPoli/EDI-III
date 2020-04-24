function AnalogClock(clockTimer) {
    this.timer = clockTimer;
    this.timer.getSubscriber().attach(this);
}

AnalogClock.prototype.update = function() {
    this.draw();
};

AnalogClock.prototype.draw = function() {
    var hours = this.timer.getHour().toString();
    var minutes = this.timer.getMinute().toString();
    var seconds = this.timer.getSecond().toString();
    
    if(hours.length == 1){hours = "0"+hours;}
    if(minutes.length == 1){minutes = "0"+minutes;}
    if(seconds.length == 1){seconds = "0"+seconds;}
    console.log("I am Analog: "+hours+":"+minutes+":"+seconds);
}


function ClockTimer(subscriber){
    this.subscriber = subscriber;
    this.notifier = new Notifier(subscriber);
    this.hours = 0;
    this.minutes = 0;
    this.seconds = 0;
}

ClockTimer.prototype.getHour = function() {
    return this.hours;
};

ClockTimer.prototype.getMinute = function() {
    return this.minutes;
};

ClockTimer.prototype.getSecond = function() {
    return this.seconds;
};

ClockTimer.prototype.getSubscriber = function() {
    return this.subscriber;
};

ClockTimer.prototype.getSecond = function() {
    return this.seconds;
};

ClockTimer.prototype.tick = function(){
    this.seconds++;
        if(this.seconds == 60) {
            this.seconds = 0;
            this.minutes++;
            if(this.minutes == 60) {
                this.seconds = 0;
                this.minutes = 0;
                this.hours++;
                if(this.hours == 24) {
                    this.seconds = 0;
                    this.minutes = 0;
                    this.hours = 0;
                }
            }
        }
    this.notifier.notify();
};


function DigitalClock(clockTimer) {
    this.timer = clockTimer;
    this.timer.getSubscriber().attach(this);
}

DigitalClock.prototype.update = function() {
    this.draw();
};

DigitalClock.prototype.draw = function() {
    hours = this.timer.getHour().toString();
    minutes = this.timer.getMinute().toString();
    seconds = this.timer.getSecond().toString();
    
    if(hours.length == 1){hours = "0"+hours;}
    if(minutes.length == 1){minutes = "0"+minutes;}
    if(seconds.length == 1){seconds = "0"+seconds;}
    console.log("I am Digital: "+hours+":"+minutes+":"+seconds);
}


function Notifier(subscriber){
    this.subscriber = subscriber;
}

Notifier.prototype.notify = function() {
    var observers = new Array();
    observers = subscriber.getSubscribers();
        for (i = 0 ; i< observers.length; i++) {
            observers[i].update();
        }
};


function Subscriber(){
    this.observers = new Array();
}

Subscriber.prototype.attach = function(o) {
    this.observers.push(o)
};

Subscriber.prototype.detach = function(o) {
    this.observers.pop(o);
};

Subscriber.prototype.getSubscribers = function() {
    return this.observers;
};


var subscriber = new Subscriber();
var clockTimer = new ClockTimer(subscriber);
var analogClock = new AnalogClock(clockTimer);
var digitalClock = new DigitalClock(clockTimer);

clockTimer.tick();
clockTimer.tick();
clockTimer.tick();
clockTimer.tick();
clockTimer.tick();
clockTimer.tick();






