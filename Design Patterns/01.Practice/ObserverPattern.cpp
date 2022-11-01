#include <iostream>
#include <vector>
#include <algorithm>

class subject; 

class observer
{
public:
    virtual ~observer() = default;
    virtual void update(subject&) = 0;
};

class subject
{
public:
    virtual ~subject() = default;
    void attach(observer &_Observer)
    {
        observers.push_back(&_Observer);
    }
    void detach(observer &_observer)
    {
        observers.erase(std::remove(observers.begin(), observers.end(), &_observer));
    }
    void notify()
    {
        for (auto *_observer : observers)
        {
            _observer->update(*this);
        }
    }

private:
    std::vector<observer *> observers;
};

class ClockTimer : public subject
{
public:
    void Set_Time(int _hour, int _min, int _sec)
    {
        this->hour = _hour;
        this->minute = _min;
        this->second = _sec;
    }
    int Get_Hour() const { return hour; };
    int Get_Minute() const { return minute; }
    int Get_Second() const { return second; }

private:
    int hour;
    int minute;
    int second;
};

class DigitalClock : public observer
{
public:
    explicit DigitalClock(ClockTimer &CT) : subject(CT)
    {
        subject.attach(*this);
    }
    ~DigitalClock()
    {
        subject.detach(*this);
    }
    void update(subject &ChangedSub)
    {
        if (&ChangedSub == &subject)
        {
            draw();
        }
    }
    void draw()
    {
        int hour = subject.Get_Hour();
        int min = subject.Get_Minute();
        int sec = subject.Get_Second();
        std::cout << "Digital time: " << hour << ":" << min << ":" << sec << std::endl;
    }

private:
    ClockTimer &subject;
};

class AnalogClock : public observer
{
public:
    explicit AnalogClock(ClockTimer &ChangedSub) : subject(ChangedSub)
    {
        subject.attach(*this);
    }
    ~AnalogClock()
    {
        subject.detach(*this);
    }
    void update(subject &ChangedSub)
    {
        if (&ChangedSub == &subject)
        {
            draw();
        }
    }
    void draw()
    {
        int hour = subject.Get_Hour();
        int min = subject.Get_Minute();
        int sec = subject.Get_Second();
        std::cout << "Digital time: " << hour << ":" << min << ":" << sec << std::endl;
    }

private:
    ClockTimer &subject;
};

int main()
{
    ClockTimer timer;

    DigitalClock digital(timer);
    AnalogClock analog(timer);

    timer.Set_Time(17, 30, 30);

    digital.update(timer);
    digital.draw();
    return 0;
}