https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
/**
 * Do not modify this file, it won't be submitted to ZINC.
 * Define your helper functions in file_sys.cpp
*/

#include <iostream>
#include "utils.h"
#include "file_sys.h"
using namespace std;

Dir *emptySystem()
{
    Dir *root = new Dir();
    strcpy(root->name, "/");
    root->parent = root;
    root->subdir = NULL;
    root->subfile = NULL;
    root->next = NULL;
    return root;
}

Dir *sampleSystem()
{
    Dir *root = emptySystem();
    // /comp2011
    Dir *comp2011 = new Dir();
    strcpy(comp2011->name, "comp2011");
    comp2011->parent = root;
    comp2011->subdir = NULL;
    comp2011->subfile = NULL;
    comp2011->next = root->subdir;
    root->subdir = comp2011;
    // /download
    Dir *download = new Dir();
    strcpy(download->name, "download");
    download->parent = root;
    download->subdir = NULL;
    download->subfile = NULL;
    download->next = root->subdir;
    root->subdir = download;
    // /memo.txt
    File *memo = new File();
    strcpy(memo->name, "memo.txt");
    memo->size = 2;
    memo->tag = DOC;
    memo->parent = root;
    memo->next = root->subfile;
    root->subfile = memo;
    // /download/lecture_1.mp4
    File *v1 = new File();
    strcpy(v1->name, "lecture_1.mp4");
    v1->size = 94;
    v1->tag = VIDEO;
    v1->parent = download;
    v1->next = download->subfile;
    download->subfile = v1;
    // /download/lecture_2.mp4
    File *v2 = new File();
    strcpy(v2->name, "lecture_2.mp4");
    v2->size = 176;
    v2->tag = VIDEO;
    v2->parent = download;
    v2->next = download->subfile;
    download->subfile = v2;
    // /download/lecture_3.mp4
    File *v3 = new File();
    strcpy(v3->name, "lecture_3.mp4");
    v3->size = 153;
    v3->tag = VIDEO;
    v3->parent = download;
    v3->next = download->subfile;
    download->subfile = v3;
    // /download/VSCODE
    File *vsc = new File();
    strcpy(vsc->name, "VSCODE");
    vsc->size = 354;
    vsc->tag = COMPRESSED;
    vsc->parent = download;
    vsc->next = download->subfile;
    download->subfile = vsc;
    // /comp2011/PA3
    Dir *pa3 = new Dir();
    strcpy(pa3->name, "PA3");
    pa3->parent = comp2011;
    pa3->subdir = NULL;
    pa3->subfile = NULL;
    pa3->next = comp2011->subdir;
    comp2011->subdir = pa3;
    // /comp2011/PA3/about.pdf
    File *about = new File();
    strcpy(about->name, "about.pdf");
    about->size = 50;
    about->tag = DOC;
    about->parent = pa3;
    about->next = pa3->subfile;
    pa3->subfile = about;
    // /comp2011/PA3/main.cpp
    File *main = new File();
    strcpy(main->name, "main.cpp");
    main->size = 10;
    main->tag = OTHER;
    main->parent = pa3;
    main->next = pa3->subfile;
    pa3->subfile = main;
    // /comp2011/PA3/main.cpp
    File *bin = new File();
    strcpy(bin->name, "main");
    bin->size = 5;
    bin->tag = PROGRAM;
    bin->parent = pa3;
    bin->next = pa3->subfile;
    pa3->subfile = bin;

    return root;
}

Dir *delSystem(Dir *root)
{
    int code = 0;
    while (root->subfile != NULL)
    {
        code = deleteFile(root, root->subfile->name);
        if (code == -1)
            break;
    }
    while (root->subdir != NULL)
    {
        code = deleteDir(root, root->subdir->name, true);
        if (code == -1)
            break;
    }
    delete root;
    return NULL;
}

bool valSystem(const Dir *prnt, const File *file)
{
    if (file == NULL || prnt == NULL)
        return true;
    if (file->parent != prnt)
        return false;
    return valSystem(prnt, file->next);
}

bool valSystem(const Dir *prnt, const Dir *dir)
{
    if (dir == NULL || prnt == NULL)
        return true;
    if (dir->parent != prnt)
        return false;
    if (!valSystem(dir, dir->subfile) || !valSystem(dir, dir->subdir))
        return false;
    return valSystem(prnt, dir->next);
}

bool valSystem(const Dir *root)
{
    if (root == NULL || root->parent != root || root->next != NULL)
        return false;
    if (strcmp(root->name, "/") != 0)
        return false;
    return valSystem(root, root->subfile) && valSystem(root, root->subdir);
}

string sys2str(const File *file)
{
    string result = "";
    if (file == NULL)
        return result;
    result += "file,\"" + string(file->name) + "\",parent,";
    if (file->parent == NULL)
        result += "NULL,";
    else
        result += "\"" + string(file->parent->name) + "\",";
    result += "size," + to_string(file->size) + ",";
    result += "tag," + string(TAG_NAME[file->tag]) + ",";
    result += "next,";
    if (file->next == NULL)
        result += "NULL";
    else
        result += "\"" + string(file->next->name) + "\"";
    return result;
}

string sys2str(const Dir *dir)
{
    string result = "";
    if (dir == NULL)
        return result;
    result += "dir,\"" + string(dir->name) + "\",parent,";
    if (dir->parent == NULL)
        result += "NULL,";
    else
        result += "\"" + string(dir->parent->name) + "\",";
    result += "subfile,";
    if (dir->subfile == NULL)
        result += "NULL,";
    else
        result += "\"" + string(dir->subfile->name) + "\",";
    result += "subdir,";
    if (dir->subdir == NULL)
        result += "NULL,";
    else
        result += "\"" + string(dir->subdir->name) + "\",";
    result += "next,";
    if (dir->next == NULL)
        result += "NULL";
    else
        result += "\"" + string(dir->next->name) + "\"";
    const File *fp = dir->subfile;
    while (fp != NULL)
    {
        result += "\n";
        result += sys2str(fp);
        fp = fp->next;
    }
    const Dir *dp = dir->subdir;
    while (dp != NULL)
    {
        result += "\n";
        result += sys2str(dp);
        dp = dp->next;
    }
    return result;
}

string absPath(const Dir *dir)
{
    if (dir == NULL)
        return "";
    string path = dir->name;
    while (dir->parent != dir)
    {
        dir = dir->parent;
        if (string(dir->name) == "/")
            path = "/" + path;
        else
            path = string(dir->name) + "/" + path;
    }
    return path;
}

string absPath(const File *file)
{
    if (file == NULL)
        return "";
    string path = absPath(file->parent);
    path += (path == "/") ? "" : "/";
    path += string(file->name);
    return path;
}

void strRtrim(string &);

string listDir(const Dir *dir)
{
    string result = "";
    if (dir == NULL)
        return result;
    Dir *dp = dir->subdir;
    while (dp != NULL)
    {
        result = result + "(" + string(dp->name) + ") ";
        dp = dp->next;
    }
    File *fp = dir->subfile;
    while (fp != NULL)
    {
        result = result + string(fp->name) + " ";
        fp = fp->next;
    }
    strRtrim(result);
    return result;
}

string listDetails(const Dir *dir)
{
    if (dir == NULL)
        return "";
    int length = getLength(dir);
    if (length == 0)
        return "";
    length++;
    string *names = new string[length];
    string *sizes = new string[length];
    string *tags = new string[length];
    names[0] = string("NAME");
    sizes[0] = string("SIZE");
    tags[0] = string("TAG\n");
    Dir *dp = dir->subdir;
    int i = 1;
    while (dp != NULL)
    {
        names[i] = "(" + string(dp->name) + ")";
        sizes[i] = to_string(getSize(dp));
        tags[i] = "\n";
        dp = dp->next;
        i++;
    }
    File *fp = dir->subfile;
    while (fp != NULL)
    {
        names[i] = fp->name;
        sizes[i] = to_string(fp->size);
        tags[i] = string(TAG_NAME[fp->tag]) + "\n";
        fp = fp->next;
        i++;
    }
    rpad(names, length);
    rpad(sizes, length);

    string result = "";
    for (int i = 0; i < length; ++i)
        result += names[i] + sizes[i] + tags[i];
    delete[] names;
    delete[] sizes;
    delete[] tags;
    strRtrim(result);
    return result;
}

string listDetails(const Dir *dir, Tag tag)
{
    unsigned int length = 0;
    const File **files = filesOfTag(dir, tag, length);
    if (length == 0)
        return "";
    if (files == NULL)
        return "";
    string *names = new string[length + 1];
    string *sizes = new string[length + 1];
    string *paths = new string[length + 1];
    names[0] = string("NAME");
    sizes[0] = string("SIZE");
    paths[0] = string("PATH\n");
    const File *p;
    for (int i = 0; i < length; ++i)
    {
        p = files[i];
        names[i + 1] = p->name;
        sizes[i + 1] = to_string(p->size);
        paths[i + 1] = absPath(p) + "\n";
    }

    rpad(names, length + 1);
    rpad(sizes, length + 1);

    string result = "";
    for (int i = 0; i < length + 1; ++i)
        result += names[i] + sizes[i] + paths[i];
    delete[] names;
    delete[] sizes;
    delete[] paths;
    delete[] files;
    strRtrim(result);
    return result;
}

bool getChild(const unsigned int *iStack, const Dir **dStack, const File **fStack, unsigned int count)
{
    const Dir *dir = dStack[count - 1];
    unsigned int idx = iStack[count - 1];
    const Dir *dp = dir->subdir;
    if (dp == NULL)
    {
        const File *fp = dir->subfile;
        while (idx > 0)
        {
            fp = fp->next;
            idx--;
        }
        fStack[count] = fp;
        dStack[count] = NULL;
        return true;
    }

    while (idx > 0 && dp != NULL)
    {
        dp = dp->next;
        idx--;
    }
    if (dp != NULL)
    {
        fStack[count] = NULL;
        dStack[count] = dp;
        return false;
    }

    const File *fp = dir->subfile;
    while (idx > 0)
    {
        fp = fp->next;
        idx--;
    }
    fStack[count] = fp;
    dStack[count] = NULL;
    return true;
}

string getName(const File **fStack, const Dir **dStack, const bool *isFile, unsigned int count)
{
    if (isFile[count])
        return fStack[count]->name;
    return "(" + string(dStack[count]->name) + ")";
}

string treeView(const Dir *dir)
{
    string result = "";
    int depth = getDepth(dir);
    const File **fStack = new const File *[depth];
    const Dir **dStack = new const Dir *[depth];
    bool *isFile = new bool[depth];
    unsigned int *lStack = new unsigned int[depth];
    unsigned int *iStack = new unsigned int[depth];
    unsigned int *oStack = new unsigned int[depth];
    unsigned int count = 1;
    fStack[0] = NULL;
    dStack[0] = dir;
    isFile[0] = false;
    lStack[0] = getLength(dir);
    iStack[0] = 0;
    oStack[0] = 1;
    result += string(dir->name) + "\n";
    while (count != 0)
    {
        if (iStack[count - 1] == lStack[count - 1])
        {
            count--;
            continue;
        }
        isFile[count] = getChild(iStack, dStack, fStack, count);
        iStack[count - 1]++;
        iStack[count] = 0;
        lStack[count] = (isFile[count]) ? 0 : getLength(dStack[count]);
        for (int i = 1; i < count; ++i)
        {
            result += string(oStack[i - 1] / 2, ' ');
            result += ((iStack[i - 1] == lStack[i - 1]) ? "     " : "|    ");
        }
        result += string(oStack[count - 1] / 2, ' ');
        result += "|---> " + getName(fStack, dStack, isFile, count) + "\n";
        oStack[count] = getName(fStack, dStack, isFile, count).length() + 1;
        count++;
    }
    delete[] fStack;
    delete[] dStack;
    delete[] lStack;
    delete[] iStack;
    delete[] oStack;
    delete[] isFile;
    strRtrim(result);
    return result;
}

Dir *getSubdir(Dir *dir, const char *name)
{
    if (dir == NULL)
        return NULL;
    if (strcmp(name, "..") == 0)
        return dir->parent;
    if (strcmp(name, ".") == 0)
        return dir;
    Dir *p = dir->subdir;
    while (p != NULL)
    {
        if (strcmp(p->name, name) == 0)
            return p;
        p = p->next;
    }
    return NULL;
}

File *getSubfile(Dir *dir, const char *name)
{
    if (dir == NULL)
        return NULL;
    File *p = dir->subfile;
    while (p != NULL)
    {
        if (strcmp(p->name, name) == 0)
            return p;
        p = p->next;
    }
    return NULL;
}

int getLength(const Dir *dir)
{
    int length = 0;
    const File *fp = dir->subfile;
    while (fp != NULL)
    {
        length++;
        fp = fp->next;
    }
    const Dir *dp = dir->subdir;
    while (dp != NULL)
    {
        length++;
        dp = dp->next;
    }
    return length;
}

int getSubDepth(const Dir *dir)
{
    int depth = 0;
    while (dir != NULL)
    {
        depth = max(depth, getDepth(dir));
        dir = dir->next;
    }
    return depth;
}

int getDepth(const Dir *dir)
{
    if (dir == NULL)
        return 0;
    int fileDepth = (dir->subfile == NULL) ? 0 : 1;
    int dirDepth = getSubDepth(dir->subdir);
    return max(fileDepth, dirDepth) + 1;
}

bool str2Tag(const char *tag_s, Tag &tag)
{
    bool match = false;
    for (int i = 0; i < NUM_TAG; ++i)
    {
        if (strcmp(tag_s, TAG_NAME[i]) == 0)
        {
            tag = static_cast<Tag>(i);
            match = true;
            break;
        }
    }
    return match;
}

bool str2int(const char *s, unsigned int &result)
{
    try
    {
        int size_input = stoi(string(s));
        if (size_input < 0)
            throw invalid_argument("invalid size");
        result = size_input;
    }
    catch (const exception e)
    {
        return false;
    }
    return true;
}

void shiftLeft(char *s, int d)
{
    int length = strlen(s);
    for (int i = d; i <= length; ++i)
        s[i - d] = s[i];
}

bool isWhite(char c)
{
    for (int i = 0; i < strlen(WHITESPACE); ++i)
    {
        if (c == WHITESPACE[i])
            return true;
    }
    return false;
}

bool firstWhite(char *s, int &idx)
{
    int length = strlen(s);
    bool found = false;
    for (int i = 0; i < length; ++i)
    {
        if (isWhite(s[i]))
        {
            found = true;
            idx = i;
            break;
        }
    }
    return found;
}

void ltrim(char *s)
{
    int length = strlen(s);
    int start = length;
    for (int i = 0; i < length; ++i)
    {
        if (!isWhite(s[i]))
        {
            start = i;
            break;
        }
    }
    shiftLeft(s, start);
}

void strRtrim(string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    s = (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

void rtrim(char *s)
{
    int length = strlen(s);
    int end = 0;
    for (int i = length - 1; i >= 0; --i)
    {
        if (!isWhite(s[i]))
        {
            end = i + 1;
            break;
        }
    }
    s[end] = '\0';
}

void trim(char *s)
{
    ltrim(s);
    rtrim(s);
}

void rpad(string *lines, int length, unsigned int margin)
{
    size_t maxL = 0;
    for (int i = 0; i < length; ++i)
        maxL = max(maxL, lines[i].length());

    maxL += margin;
    for (int i = 0; i < length; ++i)
    {
        size_t res = maxL - lines[i].length();
        lines[i] += string(res, ' ');
    }
}

void fetch(char *rest, char *fetched)
{
    if (rest == NULL || fetched == NULL)
    {
        cout << "Error: fetch() doesn't work for NULL pointer!" << endl;
        return;
    }
    fetched[0] = '\0';
    ltrim(rest);
    if (strlen(rest) == 0)
        return;
    int start;
    if (!firstWhite(rest, start))
    {
        strcpy(fetched, rest);
        rest[0] = '\0';
    }
    else
    {
        for (int i = 0; i < start; ++i)
            fetched[i] = rest[i];
        fetched[start] = '\0';
        shiftLeft(rest, start);
        ltrim(rest);
    }
}
