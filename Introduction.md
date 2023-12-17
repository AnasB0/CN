🌐INTRODUCTION TO NETWORKING BASICS
aboratory Objective
Upon successful completion of this Lab the student will be able to:
➢ To understand the use of client/server architecture in application development.
➢ To understand and use elementary socket system calls and advanced socket system
calls.
➢ To understand how to use TCP and UDP based sockets.
Computer Network:
Computer networking is the engineering discipline concerned with communication between
computer systems or devices.
It is the practice of linking computing devices together with hardware and software that
supports data communications across these devices.
Key Concepts And Terms
Packet: A message or data unit that is transmitted between communicating processes.
Host: A computer system that is accessed by a user working at a remote location. It is the
remote process with which a process communicates. It may also be referred as Peer.
Channel: Communication path created by establishing a connection between endpoints.
Network: A group of two or more computer systems linked together
Server: In computer networking, a server is a computer designed to process requests and
deliver data to other computers over a local network or the Internet.
➢ Iterative servers: This server knows ahead of time about how long it takes to handle
each request & server process handles each request itself.
➢ Concurrent servers: The amount of work required to handle a request is unknown,
so the server starts another process to handle each request.
Client: A Client is an application that runs on a personal computer or workstation and relies
on a server to perform some operations.
Network Addresses: Network addresses give computers unique identities they can use to
communicate with each other. Specifically, IP addresses and MAC addresses are used on
most home and business networks.

Protocols: A Protocol is a convention or standard rules that enables and controls the
connection, communication and data transfer between two computing endpoints.
Port: An interface on a computer to which you can connect a device. It is a "logical
connection place" and specifically, using the Internet's protocol, TCP/IP.
A port is a 16-bit number, used by the host-to-host protocol to identify to which
higher-level protocol or application program (process) it must deliver incoming messages.
PORTS RANGE
Well-known ports 1-1023
Ephemeral ports 1024-5000
User-defined
ports
5001-65535
Connection: It defines the communication link between two processes.
Association: Association is used for 5 tuple that completely specifies the two processes that
make up a connection.
{ Protocol, local-address, local-process, foreign-address, foreign- process}
The local address and foreign address specify the network ID & Host-ID of the local host and
the foreign host in whatever format is specified by protocol suite.
The local process and foreign process are used to identify the specific processes on each
system that are involved in a connection.
We also define Half association as either
{ protocol, local-address, local process} or { protocol, local-address, local process}
which specify each half of a connection. This half association is called a Socket or transport
address.
OSI Model
A common way to describe the layers in a network is to use the International Organization for
Standardization (ISO) open systems interconnection (OSI) model for computer
communications. This is a seven-layer model, which we show in Figure below along with the
approximate mapping to the Internet protocol suite.
We consider the bottom two layers of the OSI model as the device driver and networking
hardware that are supplied with the system. The network layer is handled by the IPv4 and
IPv6 protocols. The transport layers that we can choose from are TCP and UDP


Layers in OSI model and Internet protocol suite.
The upper three layers of the OSI model are combined into a single layer called the
application. This is the Web client (browser) or whatever application we are using. With the
Internet protocols, there is rarely any distinction between the upper three layers of the OSI
model.
The sockets programming interfaces are interfaces from the upper three layers (the
"application") into the transport layer. The sockets provide the interface from the upper three
layers of the OSI model into the transport layer.
There are two reasons for this design:
• The upper three layers handle all the details of the application and know little about
the communication details. The lower four layers know little about the application,
but handle all the communication details: sending data, waiting for acknowledgments,
and so on.
• The second reason is that the upper three layers often form what is called a user
process while the lower four layers are normally provided as part of the operating
system (OS) kernel.
CLIENT-SERVER MODEL
Network applications can be divided into two process: a Client and a Server, with a
communication link joining the two processes.
Normally, from Client-side it is one-one connection. From the Server Side, it is many-one
connection.
The standard model for network applications is he Client-Sever model. A Server is a process
that is waiting to be contacted by a Client process so that server can do something for the
client.
Typical BSD Sockets applications consist of two separate application level processes; one
process (the client) requests a connection and the other process (the server ) accepts it.
Computer Networks Lab 160321733
Socket functions for elementary TCP client/server in Connection-oriented Scenario
The server process creates a socket, binds an address to it, and sets up a mechanism (called a
listen queue) for receiving connection requests. The client process creates a socket and
requests a connection to the server process. Once the server process accepts a client process's
request and establishes a connection, full-duplex (two-way) communication can occur
between the two sockets.
Socket functions for elementary TCP client/server in Connection-less Scenario
Byte-Ordering Functions
Consider a 16-bit integer that is made up of 2 bytes. There are two ways to store the two
bytes in memory: with the low-order byte at the starting address, known as little-endian byte
order, or with the high-order byte at the starting address, known as big-endian byte order.

Little-endian byte order and big-endian byte order for a 16-bit integer.
In this figure, we show increasing memory addresses going from right to left in the top, and
from left to right in the bottom. We also show the most significant bit (MSB) as the leftmost
bit of the 16-bit value and the least significant bit (LSB) as the rightmost bit.
The terms "little-endian" and "big-endian" indicate which end of the multi-byte value, the
little end or the big end, is stored at the starting address of the value.
We refer to the byte ordering used by a given system as the host byte order. We must deal
with these byte ordering differences as network programmers because networking protocols
must specify a network byte order. Our concern is therefore converting between host byte
order and network byte order. We use the following four functions to convert between these
two byte orders.
#include <netinet/in.h>
#include <sys/types.h>
unsigned long htonl(unsigned long hostlong) ;
unsigned short htons(unsigned short hostshort) ;
unsigned long ntohl(unsigned long netlong) ;
unsigned short ntohs(unsigned short netshort) ;
htons
htonl
ntohs
ntohl
host to network short
host to network long
network to host short
network to host long
Sockets Overview
The operating system includes the Berkeley Software Distribution (BSD) inter process
communication (IPC) facility known as sockets. Sockets are communication channels that
enable unrelated processes to exchange data locally and across networks. A single socket is
one end point of a two-way communication channel.
In the operating system, sockets have the following characteristics:
• A socket exists only as long as a process holds a descriptor referring to it.
• Sockets are referenced by file descriptors and have qualities similar to those of a
character special device. Read, write, and select operations can be performed on
sockets by using the appropriate subroutines.
• Sockets can be created in pairs, given names, or used to rendezvous with other sockets
in a communication domain, accepting connections from these sockets or exchanging
messages with them.

Sockets Background
Sockets were developed in response to the need for sophisticated interprocess facilities to
meet the following goals:
• Provide access to communications networks such as the Internet.
• Enable communication between unrelated processes residing locally on a single host
computer and residing remotely on multiple host machines.
Socket Facilities
Socket subroutines and network library subroutines provide the building blocks for IPC. An
application program must perform the following basic functions to conduct IPC through the
socket layer:
• Create and name sockets.
• Accept and make socket connections.
• Send and receive data.
• Shut down socket operations.
Socket Interface
The Socket interface provides a standard, well-documented approach to access kernel
network resources.
Socket Header Files to be Included:
Socket header files contain data definitions, structures, constants, macros, and options used
by socket subroutines. An application program must include the appropriate header file to
make use of structures or other information a particular socket subroutine requires.
Commonly used socket header files are:
/usr/include/netinet/in.h Defines Internet constants and structures.
/usr/include/netdb.h Contains data definitions for socket subroutines.
/usr/include/sys/socket.h Contains data definitions and socket structures.
/usr/include/sys/types.h Contains data type definitions.
/usr/include/arpa.h Contains definitions for internet operations.
/usr/include/sys/errno.h Defines the errno values that are returned by drivers
and other kernel-level code.
Internet address translation subroutines require the inclusion of the inet.h file. The inet.h file
is located in the /usr/include/arpa directory.
Socket Addresses
Sockets can be named with an address so that processes can connect to them. Most socket
functions require a pointer to a socket address structure as an argument. Each supported
protocol suite defines its own socket address structure. The names of these structures begin
with sockaddr_ and end with a unique suffix for each protocol suite.
Generic socket address structure: Many of the Networking system calls require a pointer
to a socket address structure as an argument.
Definition of this structure is in
#include<sys/socket.h>
struct sockaddr {
unsigned short sa_family; /* address family : AF_xxx Value */
char sa_data[14]; /* up to 14 bytes of protocol- specific address */
};

Internet Socket address structure
The protocol specific structure sockaddr_in is identical in size to generic
structure which is 16 bytes.
#include <netinet/in.h>
struct sockaddr_in {
short sin_family; /* AF_INET
unsigned short sin_port; /* 16-bit port number */
/* Network-byte ordered */
struct in_addr sin_addr; /* 32-bit netid/hostid*/
/* Network-byte ordered */
char sin_zero[8]; /* unused*/
};
struct in_addr {
unsigned long s_addr; /* 32-bit netid/hostid */
/* network byte ordered*/
};
sin_zero is unused member, but we always set it to 0 when filling in one of these structures.
Socket address structures are used only on a given host: the structure itself is now
communicated between different hosts, although certain fields (eg: IP Address & ports) are
used for communication.
* The protocol-specific structure sockaddr_in is identical in size to generic structure sockaddr
which is 16 bytes.
