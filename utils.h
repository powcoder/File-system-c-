https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
/**
 * Do not modify this file, it won't be submitted to ZINC.
 * Define your helper functions in file_sys.cpp
*/

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "file_sys.h"
#include "cli.h"
using namespace std;

const int NUM_TAG = 7;
const char TAG_NAME[NUM_TAG][MAX_NAME_LEN] = {"VIDEO", "IMAGE", "DOC", "COMPRESSED", "PROGRAM", "MUSIC", "OTHER"};

// File system
Dir *emptySystem();
Dir *sampleSystem();
Dir *delSystem(Dir *);
bool valSystem(const Dir *);
string sys2str(const Dir *dir);

// Absolute path
string absPath(const Dir *);
string absPath(const File *);

// File system printing
string listDir(const Dir *);
string listDetails(const Dir *);
string listDetails(const Dir *dir, Tag tag);
string treeView(const Dir *);

// Get a subdir / subfile by name
Dir *getSubdir(Dir *, const char *);
File *getSubfile(Dir *, const char *);

// Directory length & deepth
int getLength(const Dir *); // (#subfiles + #subdirs)
int getDepth(const Dir *);  // (tree depth)

// String operations
bool str2Tag(const char *, Tag &);
bool str2int(const char *, unsigned int &);
const char WHITESPACE[] = " \n\r\t\f\v";
void ltrim(char *);
void rtrim(char *);
void trim(char *);
void rpad(string *, int, unsigned int = 2);
void fetch(char *, char *);

#endif