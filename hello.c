//#include <unistd.h>
#include <sys/syscall.h>

#ifndef DOCKER_IMAGE
	#define DOCKER_IMAGE "hello-world"
#endif

#ifndef DOCKER_GREETING
	#define DOCKER_GREETING "Hello from Docker!"
#endif

const char message[] =
	"\n"
	DOCKER_GREETING "\n"
	"This message shows that your installation appears to be working correctly.\n"
	"\n"
	"To generate this message, Docker took the following steps:\n"
	" 1. The Docker client contacted the Docker daemon.\n"
	" 2. The Docker daemon pulled the \"" DOCKER_IMAGE "\" image from the Docker Hub.\n"
	"\n";

void _start() {
	//write(1, message, sizeof(message) - 1);
	syscall(SYS_write, 1, message, sizeof(message) - 1);

	//_exit(0);
	syscall(SYS_exit, 0);
}
