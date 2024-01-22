# TimerAndFilters

### What it is used for:
This library has two functions:
- Timer: A pair of timer classes which can be used in the way timers are often used in PLC's, either milli- or micro-second based.
- Filter: A pair of filter classes which can apply some filters over either a specified number of last measures or a specified time, both limitied by the size of its rotating buffer.
 

### Timer:
The two classes work similar with the following methods:

|------------------------------------------------|:----------------------------------------------------------:|
| evaluate(bool condition)                       |  If the condition is True it either starts the timer or if | 
|                                                |  it is already started, it reads a new timestamp and calc- |
|                                                |  ulates how much time has elapsed, returning true if the   |
|                                                |  results exceeds the delay time. If the condition is False,|
|                                                |  the timer is stopped and False is returned. Next time the |
|                                                |  condition is True the time starts from zero again.        |
|------------------------------------------------|:----------------------------------------------------------:|
| setTime(bool condition)                        |  Sets the delay time                                       |
|------------------------------------------------|:----------------------------------------------------------:|
| setTimeAndEvaluate(bool condition, int time)   |  Sets delay time and evaluates the timer right after that. |
|------------------------------------------------|:----------------------------------------------------------:|
| getDelay()                                     |  Returns the currently set delay                           |
|------------------------------------------------|:----------------------------------------------------------:|
| getElapsedTime()                               |  Returns the currently elapsed time since start of the     |
|                                                |  timer.                                                    |
|------------------------------------------------|:----------------------------------------------------------:|


### Filter:
In order to balance the needed precision with the memory footprint and execution speed, the two filter classes can be 
instantiated either with int, float or double as their basic data type.
example:  


The two classes currently the following methods:
|------------------------------------------------|:----------------------------------------------------------:|
| Construcor()                                   | Buffer gets default size of 10 measurements                |
|------------------------------------------------|:----------------------------------------------------------:|
| Construcor((unsigned int buffersize))          | Buffersize is set at instantiation                        |
|------------------------------------------------|:----------------------------------------------------------:|
| int reset()                                    | Reset fiter and set its buffer to 0                        |
|------------------------------------------------|:----------------------------------------------------------:|
| T measurement(T &measureToAdd)                 | Adds a measurement to buffer and returns the rolling ave-  |
|                                                | rage.                                                      |
|------------------------------------------------|:----------------------------------------------------------:|
| T measurementIfMinChange(T &measureToAdd,      | Add a measurement only when it differs minimal (more than  |
|                           T minChange)         | minChange) to last measurement and return rolling average. |
|------------------------------------------------|:----------------------------------------------------------:|
| int getAverage()                               | just get new rolling average (rounded integer)             |
|------------------------------------------------|:----------------------------------------------------------:|
| double getAverageDbl()                         | get average in double precicion                            |
|------------------------------------------------|:----------------------------------------------------------:|
| unsigned int getNbrMeas();                     | get Nbrs of Measurements currently contributing to the     |
|                                                | result                                                     |
|------------------------------------------------|:----------------------------------------------------------:| 
| T calcMinMax (bool return_max = false)         | calculate maximum and minimum and return the choosen       |
|                                                | (default: false = minimum)                                 |
|------------------------------------------------|:----------------------------------------------------------:|
| T getMin()                                     | Minimum calculated (must be called after calcMinMax(),     |
|                                                | otherwise result is potentially outdated)                  |
|------------------------------------------------|:----------------------------------------------------------:|
| T getMax()                                     | get maxima calculated (must be called after calcMinMax(),  |
|                                                | otherwise result is potentially outdated)                  |
|------------------------------------------------|:----------------------------------------------------------:|
| double calcFIRfiltered(double* fIRcoeffs,      | applying a FIR filter with a referenced array and its      |
|                         int fIRnbrOfCoeffs)    | length (number) of FIR-filter coefficents                  |
|                                                | (can be driven from: http://t-filter.|engineerjs.com/)     |
|                                                | in order to make this work the measurements must be done   |
|                                                | in a fixed interval which needs to match the one used to   |
|                                                | calculate the coefficents.                                 |
|------------------------------------------------|:----------------------------------------------------------:|

only for class CFilterAnalogOverTime:
|------------------------------------------------|:----------------------------------------------------------:|
| unsigned long setgetTargfiltT_micros           |                                                            |
|             (unsigned long targfilttime_micros)|                                                            | 
|------------------------------------------------|:----------------------------------------------------------:|

only for class CFilterAnalogOverMeasures:
|------------------------------------------------|:----------------------------------------------------------:|
| unsigned int setgetTargetMeasures              | set or get over how many measures the rolling average shall| 
|                    (unsigned int targMeasNbrs) | be taken                                                   | 
|------------------------------------------------|:----------------------------------------------------------:|
| double deriv1overLastNbr(short Nbr=2,          | calculatenfirst derivative over last 2-5 measures f_x =    |
|                           double dy=1)         | (-2*f[i-3]+9*f[i-2]-18*f[i-1]+11*f[i+0])/(6*1.0*h**1)      |
|                                                | from https://web.media.mit.edu/~crtaylor/calculator.html   |
|------------------------------------------------|:----------------------------------------------------------:|
| double deriv2overLastNbr(short Nbr=2,          | calculate second derivaive over last 5 measures f_xx =     |
|                           double dy=1)         | (-1*f[i-3]+4*f[i-2]-5*f[i-1]+2*f[i+0])/(1*1.0*h**2)        |
|                                                | from https://web.media.mit.edu/~crtaylor/calculator.html   |
|------------------------------------------------|:----------------------------------------------------------:|


### Example: 
[CondorRudderPedal_ESP8622](https://github.com/flyfuri/CondorRudderPedal_ESP8622)


