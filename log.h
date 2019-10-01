#ifndef CAN_H
#define CAN_H

#define LOGL_NONE    0
#define LOGL_ERROR   1
#define LOGL_WARNING 2
#define LOGL_INFO    3
#define LOGL_DEBUG   4
#define LOGL_TRACE   5

typedef enum {
    LOGLEVEL_NONE      = LOGL_NONE,
    LOGLEVEL_ERROR     = LOGL_ERROR,
    LOGLEVEL_WARNING   = LOGL_WARNING,
    LOGLEVEL_INFO      = LOGL_INFO,
    LOGLEVEL_DEBUG     = LOGL_DEBUG,
    LOGLEVEL_TRACE     = LOGL_TRACE
} log_level;

#define LOG_LINE_TERM "\r\n"

#ifndef LOGLEVEL
#define LOGLEVEL      LOGL_WARNING
#endif

void doLog(log_level loglevel, const char *file, int line, const char *func,
           const char *msg, ...);

#if LOGLEVEL < LOGL_ERROR
#define LOG_ERROR(FMT, ...)
#else
#define LOG_ERROR(FMT, ...)                                                    \
    do {                                                                       \
        doLog(LOGL_ERROR, __FILE__, __LINE__, __func__, FMT, ## __VA_ARGS__);  \
    } while (0)
#endif

#if LOGLEVEL < LOGL_WARNING
#define LOG_WARNING(FMT, ...)
#else
#define LOG_WARNING(FMT, ...)                                                  \
    do {                                                                       \
        doLog(LOGL_WARNING, __FILE__, __LINE__, __func__, FMT, ## __VA_ARGS__);\
    } while (0)
#endif

#if LOGLEVEL < LOGL_INFO
#define LOG_INFO(FMT, ...)
#else
#define LOG_INFO(FMT, ...)                                                     \
    do {                                                                       \
        doLog(LOGL_INFO, __FILE__, __LINE__, __func__, FMT, ## __VA_ARGS__);   \
    } while (0)
#endif

#if LOGLEVEL < LOGL_DEBUG
#define LOG_DEBUG(FMT, ...)
#else
#define LOG_DEBUG(FMT, ...)                                                    \
    do {                                                                       \
        doLog(LOGL_DEBUG, __FILE__, __LINE__, __func__, FMT, ## __VA_ARGS__);  \
    } while (0)
#endif

#if LOGLEVEL < LOGL_TRACE
#define LOG_TRACE(FMT, ...)
#else
#define LOG_TRACE(FMT, ...)                                                    \
    do {                                                                       \
        doLog(LOGL_TRACE, __FILE__, __LINE__, __func__, FMT, ## __VA_ARGS__);  \
    } while (0)
#endif

#endif /* CAN_H */
