#include <stdio.h>
#include <windows.h>

int main(int argc, char** argv)
{
	HANDLE hTimer = NULL;
	LARGE_INTEGER liDueTime;

	liDueTime.QuadPart = -100000000LL;

	// create an unnamed waitable timer
	hTimer = CreateWaitableTimer(NULL, TRUE, NULL);
	if (hTimer == NULL)
	{
		printf("CreateWaitableTimer failed\n", GetLastError());
		return(EXIT_FAILURE);
	}

	printf("waiting 10 seconds . . . . . \n");

	// set timer to wait for 10 seconds
	if (!SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, 0))
	{
		printf("SetWaitableTimer failed\n");
		return(EXIT_FAILURE);
	}

	// wait for timer
	if (WaitForSingleObject(hTimer, INFINITE) != WAIT_OBJECT_0)
		printf("WaitForSingleObject failed (%d)\n", GetLastError());
	else
		printf("Timer was signaled properly\n");

	getchar();
	return(EXIT_SUCCESS);
}
