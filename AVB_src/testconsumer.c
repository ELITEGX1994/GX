#include "msrp_sm.h"

struct share_memory* pSM = NULL;
int shmID = -1;
int semSetID = -1;
union semun su;

int main(int argc, char * argv[]){

    if((shmID = shmget((key_t)12345, SHM_SIZE, SHM_MODE | IPC_CREAT)) < 0){
        perror("create shared memory failed\n");
        exit(EXIT_FAILURE);
    }

    pSM = (struct share_memory *)shmat(shmID, 0, 0);


    if((semSetID = semget((key_t)54321, 3, SEM_MODE | IPC_CREAT)) < 0){
        perror("create  semphores failed\n");
        exit(EXIT_FAILURE);
    }
    
    /*su.val = 1;
    if(semctl(semSetID, 0, SETVAL, su) < 0){
        perror("semctl failed\n");
        exit(EXIT_FAILURE);
    }

    su.val = 0;
    if(semctl(semSetID, 1, SETVAL, su) < 0){
        perror("semctl failed\n");
        exit(EXIT_FAILURE);
    }

    su.val = 1;
    if(semctl(semSetID, 2, SETVAL, su) < 0){
        perror("semctl failed\n");
        exit(EXIT_FAILURE);
    }*/
    while(1){
        waitSem(semSetID, 1);
        waitSem(semSetID, 2);
        log_msrp_consume(pSM);
        sigSem(semSetID, 2);
        sigSem(semSetID, 0);
        sleep(2);
    }

    /*if(shmdt(pSM) == -1){
		fprintf(stderr, "shmdt failed\n");
		exit(EXIT_FAILURE);
	}

	if(shmctl(shmID, IPC_RMID, 0) == -1){
		fprintf(stderr, "shmctl(IPC_RMID) failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);*/
}


