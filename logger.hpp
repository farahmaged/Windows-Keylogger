#ifndef LOGGER_H
#define LOGGER_H

#include <string>

using namespace std;

class Logger {
public:
    Logger(string filename);
    void log(const std::string &message);

private:
    string getTimeStamp();
    string filename;
};

#endif // LOGGER_H
