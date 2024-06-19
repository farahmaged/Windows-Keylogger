#include <ctime>
#include <fstream>
#include <utility>
#include "logger.hpp"

using namespace std;

Logger::Logger(std::string filename) : filename(std::move(filename)) {}

void Logger::log(const std::string &message) {
    ofstream logfile(filename, std::ios::app);
    if (logfile.is_open()) {
        logfile << "[" << getTimeStamp() << "] " << message << "\n";
        logfile.close();
    }
}

string Logger::getTimeStamp() {
    time_t now = std::time(nullptr);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    return buffer;
}
