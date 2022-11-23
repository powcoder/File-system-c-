https://powcoder.com
代写代考加微信 powcoder
Assignment Project Exam Help
Add WeChat powcoder
/** 
 * This file contains the command line functions. Search TODO to find the part you need to implement. 
 * Don't modify the other codes (you only need to work with three "else-if" blocks in the function "execute"). 
 * 
 * While debugging, you could add some cout statements to show different messages according to status code
 * returned by your file system functions, check how the skeleton codes do it.
 * 
 * But do remember to REMOVE the cout statements you write. You don't need to remove the existing cout 
 * statements in the skeleton codes, just remove the cout statements in the three "else-if" blocks implemented 
 * by yourself.
*/

#include <iostream>
#include "cli.h"
#include "utils.h"
#include "file_sys.h"
using namespace std;

const char NOT_IMPL[] = "Error: The file system function is not yet implemented!";
const char PARAM_NULL[] = "Error: NULL pointer passed as parameter!";

void startCLI(Dir *wd)
{
    cout << endl
         << "COMP2011 (2022 Spring) PA3 CLI" << endl
         << endl;
    bool exit = false;
    do
    {
        char line[MAX_CMD_LEN];
        cout << ">>> " << flush;
        cin.getline(line, MAX_CMD_LEN);
        wd = execute(wd, line, exit);
        if (wd == NULL)
        {
            cout << "Error: The working directory is NULL!" << endl;
            exit = true;
        }
    } while (!exit);
    cout << endl
         << "CLI terminating ..." << endl;
}

Dir *execute(Dir *wd, char *rest, bool &exit)
{
    trim(rest);

    // Case: empty command
    if (strlen(rest) == 0)
        return wd;

    // Get the command name
    Dir *wd_copy = wd;
    char cmd[MAX_CMD_LEN] = "";
    fetch(rest, cmd);

    // EXIT
    if (strcmp(cmd, "exit") == 0)
        exit = true;

    // CD
    else if (strcmp(cmd, "cd") == 0)
    {
        char dirname[MAX_CMD_LEN] = "";
        fetch(rest, dirname);
        Dir *target = getSubdir(wd, dirname);
        if (target == NULL)
            cout << "Error: Directory \"" << dirname << "\" not found!" << endl;
        else
        {
            return target;
        }
    }

    // PWD
    else if (strcmp(cmd, "pwd") == 0)
    {
        string path = absPath(wd);
        if (path == "")
            cout << PARAM_NULL << endl;
        else
            cout << path << endl;
    }

    // LS
    else if (strcmp(cmd, "ls") == 0)
    {
        string text = listDir(wd);
        if (text != "")
            cout << text << endl;
    }

    // LL
    else if (strcmp(cmd, "ll") == 0)
    {
        string text = listDetails(wd);
        if (text != "")
            cout << text << endl;
    }

    // TOUCH
    else if (strcmp(cmd, "touch") == 0)
    {
        char filename[MAX_CMD_LEN] = "";
        fetch(rest, filename);
        char size_str[MAX_CMD_LEN] = "";
        fetch(rest, size_str);
        char tag_str[MAX_CMD_LEN] = "";
        fetch(rest, tag_str);
        unsigned int size = 0;
        Tag tag = OTHER;

        if (!str2int(size_str, size))
            cout << "ERROR: Invalid file size \"" << size_str << "\"!" << endl;
        else if (!str2Tag(tag_str, tag))
            cout << "ERROR: Invalid file tag \"" << tag_str << "\"!" << endl;
        else
        {
            int code = createFile(wd, filename, size, tag);
            switch (code)
            {
            case -1:
                cout << NOT_IMPL << endl;
                break;
            case 1:
                cout << PARAM_NULL << endl;
                break;
            case 2:
                cout << "Error: File name \"" << filename << "\" is illegal!" << endl;
                break;
            case 3:
                cout << "Error: File \"" << filename << "\" already exists!" << endl;
                break;
            }
        }
    }

    /**
     * The three commands you need to implement start here.
    */

    // MKDIR
    else if (strcmp(cmd, "mkdir") == 0)
    {
        /**
         * TODO: Write your code here for the "mkdir" command
         * 
         * Remember to remove the cout statements here before submission.
         * This block should not print anything to the standard output.
        */


        /**
         * End of your code
        */
    }

    // RM
    else if (strcmp(cmd, "rm") == 0)
    {
        /**
         * TODO: Write your code here for the "rm" command
         * 
         * Remember to remove the cout statements here before submission.
         * This block should not print anything to the standard output.
        */


        /**
         * End of your code
        */
    }

    // MV
    else if (strcmp(cmd, "mv") == 0)
    {
        /**
         * TODO: Write your code here for the "mv" command
         * 
         * Remember to remove the cout statements here before submission.
         * This block should not print anything to the standard output.
        */

        
        /**
         * End of your code
        */
    }

    /**
     * All three commands finish here.
    */

    // TAG
    else if (strcmp(cmd, "tag") == 0) // TODO: Error msg
    {
        char tag_s[MAX_CMD_LEN] = "";
        fetch(rest, tag_s);
        Tag tag;
        if (!str2Tag(tag_s, tag))
            cout << "Error: Invalid tag \"" << tag_s << "\"" << endl;
        else
        {
            string s = listDetails(wd, tag);
            if (s != "")
                cout << s << endl;
        }
    }

    // TREE
    else if (strcmp(cmd, "tree") == 0)
    {
        cout << treeView(wd) << endl;
    }

    // HELP
    else if (strcmp(cmd, "help") == 0)
    {
        cout << "exit" << endl
             << "\texit the command line" << endl
             << endl;
        cout << "cd <dirname>" << endl
             << "\tchange directory given the dirrectory name" << endl
             << endl;
        cout << "pwd" << endl
             << "\tprint working directory" << endl
             << endl;
        cout << "ls" << endl
             << "\tlist the directories and files in working directory" << endl
             << "\tdirectories will be displayed with parentheses" << endl
             << endl;
        cout << "ll" << endl
             << "\tlist the details of the directories and files in working directory" << endl
             << endl;
        cout << "mkdir <dirname>" << endl
             << "\tmake a new directory under working directory" << endl
             << endl;
        cout << "touch <filename> <size> <tag>" << endl
             << "\tmake a new file under working directory" << endl
             << endl;
        cout << "rm [-r] <name>" << endl
             << "\tdelete a file / directory under the working directory given its name" << endl
             << "\tthe \"-r\" flag is optional, which means to recursively remove" << endl
             << endl;
        cout << "mv <target> <destination>" << endl
             << "\tmove the target (file / directory) to the destination (directory)" << endl
             << endl;
        cout << "tag <Tag>" << endl
             << "\tlist the details of the files of a certain tag, will search the working directory recursively" << endl
             << endl;
        cout << "tree" << endl
             << "\tdisplay the file system in a tree view, will search the working directory recursively" << endl
             << endl;
        cout << "help" << endl
             << "\tlist all the commands and their usages" << endl
             << endl;
    }

    // Case: command not found
    else
    {
        cout << "Error: Command \"" << cmd << "\" not found!" << endl;
    }
    return wd_copy;
}