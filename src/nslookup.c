#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

static int lookup_host(const char* host)
{
	struct addrinfo hints, *res;
	int errcode;
	char addrstr[100];
	void *ptr;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = PF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags |= AI_CANONNAME;

	errcode = getaddrinfo(host, NULL, &hints, &res);
	if (errcode != 0)
	{
		perror("getaddrinfo");
		return -1;
	}

	printf("Non-authoritative answer:\n");
	while(res)
	{
		inet_ntop(res->ai_family, res->ai_addr->sa_data, addrstr, 100);

		switch (res->ai_family)
		{
		case AF_INET:
			ptr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
			break;
		case AF_INET6:
			ptr = &((struct sockaddr_in6 *) res->ai_addr)->sin6_addr;
			break;
		}

		inet_ntop(res->ai_family, ptr, addrstr, 100);
		printf("Name:\t%s\n", res->ai_canonname ? res->ai_canonname : host);
		printf("Address: %s\n", addrstr);
		res = res->ai_next;
	}
	printf("\n");

	return 0;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s <domain>\n", argv[0]);
		return 0;
	}

	lookup_host(argv[1]);

	return EXIT_SUCCESS;
}

