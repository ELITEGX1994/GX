#include "share_synch.h"
// #include "msrp_sm.h"

struct share_memory* pSM = NULL;
int shmID = -1;
int semSetID = -1;
union semun su;

void produce(struct share_memory * shared, int running){
    printf("Enter some text:\n");
    printf("share_memory has been ...\n");
    shared->cmd_t = running;
    shared->attribute.talk_listen.StreamId[0] = running;
    shared->attribute.talk_listen.StreamId[1] = running;
    shared->attribute.talk_listen.StreamId[2] = running;
    shared->attribute.talk_listen.StreamId[3] = running;
    shared->attribute.talk_listen.StreamId[4] = running;
    shared->attribute.talk_listen.StreamId[5] = running;
    shared->attribute.talk_listen.StreamId[6] = running;
    shared->attribute.talk_listen.StreamId[7] = running;
    shared->attribute.talk_listen.DeclarationType = running;
    shared->attribute.talk_listen.DataFrameParameters.VlanID = running;
    shared->attribute.talk_listen.TSpec.MaxFrameSize = running;
    shared->attribute.talk_listen.TSpec.MaxIntervalFrames = running;
    shared->attribute.talk_listen.PriorityAndRank = running;
    shared->attribute.talk_listen.AccumulatedLatency = running;
    shared->attribute.talk_listen.FailureInformation.FailureBridgeId[0] = running;
    shared->attribute.talk_listen.FailureInformation.FailureBridgeId[1] = running;
    shared->attribute.talk_listen.FailureInformation.FailureCode = running;
	printf("\n\n");
}

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
    
    su.val = 1;
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
    }

    int running = 15;
    while(running--){
        waitSem(semSetID, 0);
        waitSem(semSetID, 2);
        produce(pSM, running);
        sigSem(semSetID, 2);
        sleep(1);
        sigSem(semSetID, 1);
    }
    /*
    if(shmdt(pSM) == -1){
		fprintf(stderr, "shmdt failed\n");
		exit(EXIT_FAILURE);
	}

	if(shmctl(shmID, IPC_RMID, 0) == -1){
		fprintf(stderr, "shmctl(IPC_RMID) failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
    */

}