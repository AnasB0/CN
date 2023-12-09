Compilation and Execution Process for 2a.c

/* cc is used for compiling the program */
compilation : cc udp_client.c
/* Then execute the client program. a.out is the default compiled executable file. To view
its contents we use ./a.out */
execution : ./a.out 192.168.0.6 7 (7 is the port for standard echo service)

Compilation and Execution Process for 2b.c

compilation : cc udp_client.c
execution : ./a.out 192.168.0.6 13 (13 is the port for standard daytime service)

Compilation and Execution Process for 2c.c

compilation : cc udp_client.c
execution : ./a.out 192.168.0.6 19 (19 is the port for standard char-gen service)

Compilation and Execution Process for 2d.c

compilation : cc udp_client.c
execution : ./a.out 192.168.0.6 37 (37 is the port for time protocol service)

