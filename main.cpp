https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
/**
 * While debugging, you can modify this file if you need. It won't be 
 * submitted to ZINC. Define your helper functions in file_sys.cpp
*/

#include <iostream>
#include "file_sys.h"
#include "utils.h"
#include "cli.h"
using namespace std;

int main()
{
    /**
     * Create a file system (a root directory). You can choose 
     * either sampleSystem(), which creates some files and directories 
     * for you to start with, or emptySystem() which gives you an
     * completely empty system.
     *
     * Choose only one and comment the other one.
    */
    Dir *root = sampleSystem();
    // Dir *root = emptySystem();

    /**
     * Run the command line, until you use 'exit' command.
     * 
     * If you don't want to use the CLI, simply comment
     * this line and write some tests yourself.
    */
    startCLI(root);

    /**
     * Release the allocated dynamic memories.
    */
    root = delSystem(root);
    return 0;
}