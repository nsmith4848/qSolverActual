# Source
Takes any number of command lines arguments of any value. If there are command line arguments, logging will be enabled, otherwise logging will not occur.

main() declares almost all variables that will be used. It also prints out version, license, and author data and some instructions for the user.
If logging is enabled, it will create log.txt if it does not exist, or open it in append mode if it does exist. It will print the current date and time to the log file.
main() has a while loop that first calls getLine() and will continue to do so until validateInputs() does not find a problem and there are exactly three input values.
Outside of the while loop, qSolve and createOutput will be called.