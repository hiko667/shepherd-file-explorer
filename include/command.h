#ifndef COMMAND_H
#define COMMAND_H
enum command{
    SHEPHERD_QUIT,
    SHEPHERD_PICK,
    SHEPHERD_GO_BACK,
    SHEPHERD_CLEAR_CACHE,
    SHEPHERD_COPY,
    SHEPHERD_MOVE,
    SHEPHERD_RUN,
    SHEPHERD_UNKNOWN
};
typedef enum command command_t;
#endif