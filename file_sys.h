https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
/**
 * Do not modify this file, it won't be submitted to ZINC.
 * Define your helper functions in file_sys.cpp
*/

#ifndef FILE_SYS_H
#define FILE_SYS_H

#include <cstring>
using namespace std;


const int MAX_NAME_LEN = 20;

enum Tag
{
    VIDEO,
    IMAGE,
    DOC,
    COMPRESSED,
    PROGRAM,
    MUSIC,
    OTHER
};

struct Dir;

struct File
{
    char name[MAX_NAME_LEN];
    unsigned int size;
    Tag tag;
    Dir *parent;
    File *next;
};

struct Dir
{
    char name[MAX_NAME_LEN];
    Dir *parent;
    Dir *subdir;
    File *subfile;
    Dir *next;
};

// Creation
int createFile(Dir *, const char *, unsigned int, Tag = OTHER);
int createDir(Dir *, const char *);

// Deletion
int deleteFile(Dir *, const char *);
int deleteDir(Dir *, const char *, bool = false);

// Size
unsigned int getSize(const Dir *);

// Tag
const File **filesOfTag(const Dir *, Tag, unsigned int &);

// Movement
int moveFile(File *, Dir *);
int moveDir(Dir *, Dir *);

#endif