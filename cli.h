https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
/**
 * Do not modify this file, it won't be submitted to ZINC.
 * Define your helper functions in file_sys.cpp
*/

#ifndef CLI_H
#define CLI_H

#include <string>
#include "file_sys.h"
using namespace std;

const int MAX_CMD_LEN = 60;

void startCLI(Dir *);
Dir *execute(Dir *, char *, bool &);

#endif