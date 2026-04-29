#define _DEFAULT_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "files.h"

//procedure stolen from group project https://github.com/hiko667/orthus/blob/main/src/utils.c
//use git blame to find author, I chalange you

void countFilesInDirectory(char * path, int * count){
    int counter = 0;
	struct dirent * entry;
	DIR * dir = opendir(path);
	while((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] == '.' || entry->d_type != DT_REG) continue;
		count++;
	}
	closedir(dir);
    (*count) = counter;
}

void readFilesToStruct(struct entry ** readFiles, char * path){
    
}

struct entry ** getEntryNames(char * path, int * count){
    
}