#include <mpi.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char* argv[])
{
    int message;
    int rank;
    int size;
    MPI_Status status;
    int TAG = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (size == 1)
        cout << "Few processes";
    else
    {
       
            if (rank == 0)
            {
                cout << "enter number" << endl;
                cin >> message;
                for (int i = 1; i < size; i += 2) {
                    message *= 2;
                    MPI_Ssend(&message, 1, MPI_INT, i, TAG,MPI_COMM_WORLD);
                }
            }
            else
            {
                MPI_Recv(&message, 1, MPI_INT, 0, TAG,MPI_COMM_WORLD, &status);
                cout << "Rank= " << rank << "; Message= " << message << endl;
            }
    }
    MPI_Finalize();
    return 0;
}