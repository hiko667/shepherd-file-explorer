#define _DEFAULT_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "files.h"
#include "syslog_wrapper.h"

void countFilesInDirectory(char * path, int * count){
    int counter = 0;
    struct dirent * entry;
    DIR * dir = opendir(path);

    if (dir == NULL) return; // Zawsze sprawdzaj, czy otwarto katalog

    while((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        counter++;
    }
    closedir(dir);
    (*count) = counter;
}

void readFilesToStruct(struct entry ** readFiles, char * path, int count){
	DIR *dir = opendir(path);
	struct dirent *entry;
	int counter = 0;
	
	while ((entry = readdir(dir)) != NULL){
		if(counter > count - 1) break;
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) continue;
		readFiles[counter] = malloc(sizeof(struct entry));
        if (entry->d_type == DT_DIR){
			readFiles[counter]->type = (entry->d_name[0] == '.') ? HIDEN_DIR_ENTRY : DIR_ENTRY;
        }
		else{
			readFiles[counter]->type = (entry->d_name[0] == '.') ? HIDEN_FILE_ENTRY : FILE_ENTRY;
		}
		readFiles[counter]->name = strdup(entry->d_name);
		counter++;
		
    } 
    closedir(dir);
}