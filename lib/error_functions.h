#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

// prints a message corresponding to errno on standard error (with newline character)
void errMsg(const char *format, ...);

#ifdef __GNUC__

#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

// prints a message corresponding to errno then if EF_DUMPCORE, call abort() else exit().
void errExit(const char* format, ...) NORETURN;
// prints a message corresponding to errno then if EF_DUMPCORE, call abort() else _exit().
void err_exit(const char* format, ...) NORETURN;
// prints a message corresponding to errnum then if EF_DUMPCORE, call abort() else exit().
void errExitEN(int errnum, const char* format, ...) NORETURN;
// prints a message then f EF_DUMPCORE, call abort() else exit().
void fatal(const char* format, ...) NORETURN;
// prints a message to help user know usage
void usageErr(const char* format, ...) NORETURN;
// prints a message to help command line
void cmdLineErr(const char* format, ...) NORETURN;
#endif
