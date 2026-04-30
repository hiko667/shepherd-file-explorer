#ifndef SYSLOG_WRAPPER_H
#define SYSLOG_WRAPPER_H
enum logType {
    ACTION
};
typedef enum logType logType_t;
void SystemLog(const char * additionalInformation, enum logType type);
#endif