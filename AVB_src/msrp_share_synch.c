#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdint.h>
#include "share_synch.h"

void waitSem(int semSetId, int semNum){
    struct sembuf sb;
    sb.sem_num = semNum;
    sb.sem_op = -1;
    sb.sem_flg = SEM_UNDO;

    if(semop(semSetId, &sb, 1) < 0){
        perror("waitSem failed");
        exit(EXIT_FAILURE);
    }
}

void sigSem(int semSetId, int semNum){
    struct sembuf sb;
    sb.sem_num = semNum;
    sb.sem_op = 1;
    sb.sem_flg = SEM_UNDO;

    if(semop(semSetId, &sb, 1) < 0){
        perror("sigSem failed");
        exit(EXIT_FAILURE);
    }
}
