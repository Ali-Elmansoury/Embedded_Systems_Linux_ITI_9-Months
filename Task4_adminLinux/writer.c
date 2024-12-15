#include <stdio.h>  
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main ()
{
    key_t shm_key = ftok("shm_keyFile", 1);
    int shm_id = shmget(shm_key, SHM_SIZE, 0666 | IPC_CREAT);
    char* data = (char*)shmat(shm_id, (void*)0, 0);
    printf("Write data to be shared: ");
    fgets(data, SHM_SIZE, stdin);
    printf("Data written in shared memory: %s\n", data);
    shmdt(data);
    return 0;
}