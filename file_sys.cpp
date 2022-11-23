https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
/** 
 * This file contains the file system functions that you need to implement.
 * You can define helper functions in this file.
 * 
 * Remember to remove the initial statements in the functions.
 * They are only used so that your semi-finished codes can compile.
*/

#include <iostream>
#include "file_sys.h"
#include "utils.h"
using namespace std;

int createFile(Dir *dir, const char *name, unsigned int size, Tag tag)
{
    return -1;  // Remove this line after you finish.
}

int createDir(Dir *dir, const char *name)
{
    return -1;  // Remove this line after you finish.
}

int deleteFile(Dir *dir, const char *name)
{
    return -1;  // Remove this line after you finish.
}

int deleteDir(Dir *dir, const char *name, bool recursive)
{
    return -1;  // Remove this line after you finish.
}

unsigned int getSize(const Dir *dir)
{
    return 0;   // Remove this line after you finish.
}

const File **filesOfTag(const Dir *dir, Tag tag, unsigned int &length)
{
    length = 0;     // Remove these two lines after you finish.
    return NULL;    // ....
}

int moveFile(File *tgt, Dir *dest)
{
    return -1;     // Remove this line after you finish. 
}

int moveDir(Dir *tgt, Dir *dest)
{
    return -1;      // Remove this line after you finish.
}
