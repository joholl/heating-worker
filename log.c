#include <stdio.h>
#include <stdarg.h>

#include "log.h"

#if LOGLEVEL != LOGL_NONE

static const char *log_strings[] = {
    "none     ",
    "ERROR    ",
    "WARNING  ",
    "info     ",
    "debug    ",
    "trace    ",
};

void doLog(log_level loglevel, const char *file, int line, const char *func,
           const char *msg, ...) {
    int size = snprintf(NULL, 0, "%s%s:%d:%s() %s" LOG_LINE_TERM,
                        log_strings[loglevel], file, line, func, msg);
    char fmt[size+1];
    snprintf(fmt, sizeof(fmt), "%s%s:%d:%s() %s" LOG_LINE_TERM,
             log_strings[loglevel], file, line, func, msg);

    va_list vaargs;
    va_start(vaargs, msg);
    vfprintf(stderr, fmt,
             /* log_strings[loglevel], module, file, func, line, */
             vaargs);
    va_end(vaargs);
}

#endif