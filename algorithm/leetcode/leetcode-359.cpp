class Logger {
private:
     // this record message last printed time
     unordered_map<string,int> msg_time;
public:
    /** Initialize your data structure here. */
    Logger():msg_time(unordered_map<string,int>()) {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(msg_time.find(message) == msg_time.end())
        {
            msg_time[message] = timestamp;
            return true;
        }
        else
        {
           int minTime = msg_time[message] + 10;
           
           if(timestamp >= minTime)
           {
               msg_time[message] = timestamp;
               return true;
           }
           return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

//use the end time directly
class Logger {
private:
    unordered_map<string,int> msg_time;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(msg_time.find(message) == msg_time.end()) {
            msg_time[message] = timestamp + 10;
            return true;
        }
        if( timestamp < msg_time[message] ) {
            return false;
        }
        
        msg_time[message] = timestamp + 10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */