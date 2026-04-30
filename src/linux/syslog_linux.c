#include "syslog_wrapper.h"
#include <time.h>
#include <syslog.h>
#include <string.h>

void RemoveNewLine(char *s)
{
    s[strcspn(s, "\n")] = '\0';
}

void AddLogType(char *messgage, enum logType type)
{
    switch (type)
    {
    case ACTION:
        strcat(messgage, "PERFORMED ACTION: ");
        break;
    default:
        break;
    }
}

void AddTime(char *message)
{
    time_t currentTime;
    time(&currentTime);
    char *timeString = ctime(&currentTime);
    RemoveNewLine(timeString);
    strcat(message, timeString);
    strcat(message, ": ");
}

void CompleteMessage(char *message, const char *additionalInformation, enum logType type)
{
    message[0] = '\0';
    AddLogType(message, type);
    AddTime(message);
    strcat(message, additionalInformation);
}

void SystemLog(const char *additionalInformation, enum logType type)
{
    openlog("Orthus", LOG_PID, LOG_DAEMON);
    char message[1024];
    CompleteMessage(message, additionalInformation, type);
    syslog(LOG_INFO, "%s", message);
    closelog();
}