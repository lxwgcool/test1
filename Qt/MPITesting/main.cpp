#include <iostream>
#include <mpi.h>
#include <string.h>

using namespace std;


//int main(int argc, char** argv)
//{
//    int iMyid, iNumProcs;
//    int iNameLen;
//    char cProcessor_name[MPI_MAX_PROCESSOR_NAME];

//    string strMessage = "";
//    MPI_Status msStatus;
//    char cpMessage[30];
//    char message[20];
//    strcpy(cpMessage, "Active");
//    cout << cpMessage << endl;


//    // Initialize the MPI environment
//    MPI_Init(&argc, &argv);
//    MPI_Comm_rank(MPI_COMM_WORLD, &iMyid);
//    MPI_Comm_size(MPI_COMM_WORLD, &iNumProcs);
//    MPI_Get_processor_name(cProcessor_name, &iNameLen);

//    // Print off a hello world message
//    cout << "Hello World!"
//         << " Process " << iMyid
//         << ", of " << iNumProcs
//         << ", on " << cProcessor_name << endl;

//    if(iMyid == 0)
//    {
//        strcpy(message,"Hello,process 1");
//        MPI_Send(message,strlen(message),MPI_CHAR,1,99,MPI_COMM_WORLD);
//    }
//    else if(iMyid == 3)
//    {
//        MPI_Recv(message,20,MPI_CHAR,0,99,MPI_COMM_WORLD,&msStatus);
//        printf("received:%s/n",message);
//    }

//    cout << " ---- " << endl;
//    // Finalize the MPI environment.
//    MPI_Finalize();

//    return 0;
//}

//char* message = new char[30];

int main(int argc,char *argv[])
{
        int iMyid, iNumProcs;
        int iNameLen;
        char cProcessor_name[MPI_MAX_PROCESSOR_NAME];
       char message[30];
       int myrank = -1;
       MPI_Status status;
       MPI_Init(&argc,&argv);
       MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
       MPI_Comm_size(MPI_COMM_WORLD, &iNumProcs);
       MPI_Get_processor_name(cProcessor_name, &iNameLen);

       // Print off a hello world message
       cout << "Hello World!"
            << " Process " << myrank
            << ", of " << iNumProcs
            << ", on " << cProcessor_name << endl;
//       //printf("Hello World!  Process &d, , of , %d, on %s/n", myrank, iNumProcs, cProcessor_name);
//       printf("Hello World!  Process %d/n", myrank);
//        if(myrank==0)
//        {
//             strcpy(message,"Hello,process 1");
//             MPI_Send(message,strlen(message),MPI_CHAR,1,99,MPI_COMM_WORLD);
//        }
//        else if(myrank==2)
//        {
//             MPI_Recv(message,20,MPI_CHAR,0,99,MPI_COMM_WORLD,&status);
//             printf("received:%s/n",message);
//        }

      if(myrank == 1)
      {
             strcpy(message,"Hello,process lxwgcool");
             MPI_Send(message, 30, MPI_CHAR, 3, 990, MPI_COMM_WORLD);
      }
      else if(myrank == 3)
      {
             MPI_Recv(message, 30, MPI_CHAR, 1, 990, MPI_COMM_WORLD, &status);
             //cout << myrank << " Process Received: " << message << endl;
             printf(" %d received:%s/n", myrank, message);
      }

//      if(myrank==0)
//      {
//             strcpy(message,"Hello,process lxwgcool");
//             MPI_Send(message,strlen(message),MPI_CHAR,1,99,MPI_COMM_WORLD);
//      }
//      else if(myrank==1)
//      {
//             MPI_Recv(message,30,MPI_CHAR,0,99,MPI_COMM_WORLD,&status);
//             printf(" %d received:%s/n", myrank, message);
//      }

       cout << " ---- " << endl;
       MPI_Finalize();
       return 0;
}
