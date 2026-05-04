#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "linux_utlis.h"

void setLinuxRootPath(char ** path){
    struct passwd *pw = getpwuid(geteuid());
    char * temp = malloc((strlen(pw->pw_dir) + 2) * sizeof(char));
    sprintf(temp, "%s/", pw->pw_dir);
    *path = strdup(temp); free(temp); 
}

char * getLinuxRootPath(){
    struct passwd *pw = getpwuid(geteuid());
    char * temp = malloc((strlen(pw->pw_dir) + 2) * sizeof(char));
    sprintf(temp, "%s/", pw->pw_dir);
    return temp;
}

