#include "vhitles.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    //Get OS Name
    printf("OS: ");
    fflush(stdout);
    system("cat /etc/*-release | grep 'DISTRIB_DESCRIPTION' | cut -f 2 -d \"=\"");

    //Get Processor Name
    printf("Proccessor: ");
    fflush(stdout);
    system("lscpu | grep 'Model name' | cut -f 2 -d \":\" | awk '{$1=$1}1'");

    //Get GPU Name
    printf("GPU:");
    fflush(stdout);
    system("lspci | grep \"VGA\" | cut -f 3 -d \":\" | sed '2d;3d;4d;5d;6d;7d;8d;9d;10d'");
}

//lscpu | grep 'Model name' | cut -f 2 -d ":" | awk '{$1=$1}1'
//cat /etc/*-release | grep 'DISTRIB_DESCRIPTION' | cut -f 2 -d "="
//lspci | grep "VGA" | cut -f 3 -d ":" | sed '2d;3d;4d;5d;6d;7d;8d;9d;10d'