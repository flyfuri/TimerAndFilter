namespace TIMER{

class CTimer {
  protected:
    unsigned long ms_at_start;
    unsigned long ms_delay;
    bool timer_started;
    virtual unsigned long m__getTimestamp() = 0;
    
  public:
    CTimer();      
    bool evaluate(bool condition);  //starts the timer if condition is true or read new timestamp and calculates how much time has elapsed, returning true if it exceeds the delay time.
    void setTime(int time); //sets the delay time 
    bool setTimeAndEvaluate(bool condition, int time);  //sets delay time and evaluates the timer right after that
    unsigned long getDelay(); //returns the currently set delay
    unsigned long getElapsedTime(); //returns the currently elapsed time since start of the timer
};

class CTimerMillis : public CTimer{
  private:
    unsigned long m__getTimestamp();

  public:
  CTimerMillis();
};

class CTimerMicros : public CTimer{
  private:
    unsigned long m__getTimestamp();

  public:
  CTimerMicros();
};

}