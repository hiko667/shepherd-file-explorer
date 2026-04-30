#include <windows.h>
#include <stdio.h>
#include <string.h>

#include "files.h"


void countFilesInDirectory(char * path, int * count){
    WIN32_FIND_DATA findData;
    (*count) = 0;
    HANDLE hFind = NULL;
    hFind = FindFirstFile(path, &findData);
    if (hFind == INVALID_HANDLE_VALUE) count = NULL;
    do{
        if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0) continue;
        if((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) || 
            !(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) (*count) ++;
    }while (FindNextFile(hFind, &findData) != 0);
    FindClose(hFind);
}

void readFilesToStruct(struct entry ** readFiles, char * path, int count){
    WIN32_FIND_DATA findData;
    HANDLE hFind = NULL;
    hFind = FindFirstFile(path, &findData);
    if (hFind == INVALID_HANDLE_VALUE) return;
    int counter = 0;

    do{
        if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0) continue;
        if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            readFiles[counter]->type = (findData.cFileName[0] == '.') ? HIDEN_DIR_ENTRY : DIR_ENTRY;
        } 
        else {
            readFiles[counter]->type = (findData.cFileName[0] == '.') ? HIDEN_FILE_ENTRY : FILE_ENTRY;
        }
        readFiles[counter]->name = _strdup(findData.cFileName);
        counter++;
    } while(FindNextFile(hFind, &findData) != 0);
    FindClose(hFind);
}

