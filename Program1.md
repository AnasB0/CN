PROGRAM 1
Understanding Networking Commands 
Understanding and using the following commands ifconfig, netstat, ping, arp, telnet, tftp, ftp.
Program Description
In this we will study few networking commands to gain an understanding of the commands
and their usage along with their options.
i) ifconfig 
Name
ifconfig - configure a network interface
Synopsis
ifconfig [interface]
ifconfig interface [aftype] options | address ...
Description
Ifconfig is used to configure the kernel-resident network interfaces. It is used at boot time to
set up interfaces as necessary.
If no arguments are given, ifconfig displays the status of the currently active interfaces. If a
single interface argument is given, it displays the status of the given interface only; if a single
-a argument is given, it displays the status of all interfaces, even those that are down.
Otherwise, it configures an interface.
Address Families
If the first argument after the interface name is recognized as the name of a supported address
family, that address family is used for decoding and displaying all protocol addresses.
Currently supported address families include inet (TCP/IP, default), inet6 (IPv6), ax25
(AMPR Packet Radio), ddp (Appletalk Phase 2), ipx (Novell IPX) and netrom (AMPR
Packet radio).
Options
interface: The name of the interface. This is usually a driver name followed by a unit
number, for example eth0 for the first Ethernet interface.
up: This flag causes the interface to be activated
down: This flag causes the driver for this interface to be shut down.
[-]arp: Enable or disable the use of the ARP protocol on this interface.
[-]promisc: Enable or disable the promiscuous mode of the interface
metric N: This parameter sets the interface metric.
mtu N: This parameter sets the Maximum Transfer Unit (MTU) of an
interface.
dstaddr addr : Set the remote IP address for a point-to-point link (such as PPP).
netmask addr : Set the IP network mask for this interface.
add addr/prefixlen: Add an IPv6 address to an interface.
del addr/prefixlen: Remove an IPv6 address from an interface.
tunnel aa.bb.cc.dd: Create a new SIT (IPv6-in-IPv4) device, tunneling to the given
destination
io_addr addr : Set the start address in I/O space for this device.
mem_start addr : Set the start address for shared memory used by this device
media type: Set the physical port or medium type to be used by the device
multicast : Set the multicast flag on the interface.
address : The IP address to be assigned to this interface.

ii) netstat
Name
netstat - Print network connections, routing tables, interface statistics, masquerade
connections, and multicast memberships
Synopsis
netstat [address_family_options] [--tcp|-t] [--udp|-u] [--raw|-w] [--listening|-l] [--all|-a] [--
numeric|-n] [--numeric-hosts][--numeric-ports][--numeric-ports] [--symbolic|-N] [--extend|-
e[--extend|-e]] [--timers|-o] [--program|-p] [--verbose|-v] [--continuous|-c] [delay] netstat {--
route|-r}
Description
Netstat prints information about the Linux networking subsystem. The type of information
printed is controlled by the first argument, as follows:
--route , -r
Display the kernel routing tables.
--groups , -g
Display multicast group membership information for IPv4 and IPv6.
--masquerade , -M
Display a list of masqueraded connections.
Options
--verbose , -v: Verbose output
--numeric , -n: Show numerical addresses instead of trying to determine symbolic
host, port or user names.
--numeric-hosts: Shows numerical host addresses but does not affect the resolution of
port or user names.
--numeric-ports: Shows numerical port numbers but does not affect the resolution of
host or user names.
--numeric-users: Shows numerical user IDs but does not affect the resolution of host or
port names.
-c, --continuous: This will cause netstat to print the selected information every second
continuously.
-e, --extend: Display additional information. Use this option twice for maximum
detail.
-o, --timers: Include information related to networking timers.
-p, --program: Show the PID and name of the program to which each socket belongs.
-l, --listening: Show only listening sockets. (These are omitted by default.)
-a, --all: Show both listening and non-listening sockets. Interfaces that are not
marked
-F: Print routing information from the FIB. (This is the default.)
-C: Print routing information from the route cache.

iii) ping
Name
ping, ping6 - send ICMP ECHO_REQUEST to network hosts
Synopsis
ping [ -LRUbdfnqrvVaAB] [ -c count] [ -i interval] [ -l preload] [ -p pattern] [ -s packetsize]
[ -t ttl] [ -w deadline] [ -F flowlabel] [ -I interface] [ -M hint] [ -Q tos] [ -S sndbuf] [ -T
timestamp option] [ -W timeout] [ hop ...] destination
Description
ping uses the ICMP protocol's mandatory ECHO_REQUEST datagram to elicit an ICMP
ECHO_RESPONSE from a host or gateway. ECHO_REQUEST datagrams (``pings'') have
an IP and ICMP header, followed by a struct timeval and then an arbitrary number of ``pad''
bytes used to fill out the packet.
Options
-a: Audible ping.
-A: Adaptive ping.Allow pinging a broadcast address.
-B: Do not allow ping to change source address of probes.
-c count: Stop after sending count ECHO_REQUEST packets. With deadline option,
ping waits for count ECHO_REPLY packets, until the timeout expires.
-d: Set the SO_DEBUG option on the socket being used. Essentially, this socket
option is not used by Linux kernel.
-F flow label: Allocate and set 20 bit flow label on echo request packets. (Only ping6). If
value is zero, kernel allocates random flow label.
-f: Flood ping. For every ECHO_REQUEST sent a period ``.'' is printed, while
for ever ECHO_REPLY received a backspace is printed.
-i interval: Wait interval seconds between sending each packet.
-L: Suppress loopback of multicast packets.
-n: Numeric output only. No attempt will be made to lookup symbolic names for
host addresses.
-Q tos: Set Quality of Service -related bits in ICMP datagrams. tos can be either
decimal or hex number.
-q: Quiet output. Nothing is displayed except the summary lines at startup time
and when finished.
-r: Bypass the normal routing tables and send directly to a host on an attached
interface
-s packetsize: Specifies the number of data bytes to be sent. The default is 56.
-S sndbuf: Set socket sndbuf. If not specified, it is selected to buffer not more than one
packet.
-t ttl: Set the IP Time to Live.
-v: Verbose output.
-V: Show version and exit.
-w deadline: Specify a timeout, in seconds, before ping exits regardless of how many
packets have been sent or received.
-W timeout: Time to wait for a response, in seconds.

iv) telnet
Name
telnet - user interface to the TELNET protocol
Synopsis
telnet [-8EFKLacdfrx ] [-X authtype ] [-b hostalias ] [-e escapechar ] [-k realm ] [-l user ] [-n
tracefile ] [host [port ] ]
Description
The telnet command is used to communicate with another host using the TELNET protocol.
If telnet is invoked without the host argument, it enters command mode, indicated by its
prompt (telnet> ) In this mode, it accepts and executes the commands listed below. If it is
invoked with arguments, it performs an open command with those arguments.
The options are as follows:
-8: Specifies an 8-bit data path. This causes an attempt to negotiate the TELNET
BINARY option on both input and output.
-E: Stops any character from being recognized as an escape character.
-F: If Kerberos V5 authentication is being used, the -F option allows the local
credentials to be forwarded to the remote system, including any credentials
that have already been forwarded into the local environment.
-K: Specifies no automatic login to the remote system.
-L: Specifies an 8-bit data path on output. This causes the BINARY option to be
negotiated on output.
-X atype: Disables the atype type of authentication.
-a: Attempt automatic login
-b hostalias: Uses bind(2) on the local socket to bind it to an aliased address or to the
address of another interface than the one naturally chosen by connect(2).
-c: Disables the reading of the user's .telnetrc file.
-d: Sets the initial value of the debug toggle to TRUE
-e escapechar:Sets the initial telnet escape character to escapechar If escapechar is omitted,
then there will be no escape character.
-f: If Kerberos V5 authentication is being used, the -f option allows the local
credentials to be forwarded to the remote system.
-l user: When connecting to the remote system, if the remote system understands the
ENVIRON option, then user will be sent to the remote system as the value for
the variable USER. This option implies the -a option. This option may also be
used with the open command.
-n tracefile: Opens tracefile for recording trace information.
host: Indicates the official name, an alias, or the Internet address of a remote host.
port: Indicates a port number (address of an application). If a number is not specified, the
default telnet port is used.

v) ftp
Name
ftp - Internet file transfer program
Synopsis
ftp[-pinegvd][host]
pftp [-inegvd ] [host ]
DESCRIPTION
Ftp is the user interface to the Internet standard File Transfer Protocol. The program allows a
user to transfer files to and from a remote network site.
Options may be specified at the command line, or to the command interpreter.
-p: Use passive mode for data transfers. Allows use of ftp in environments where
a firewall prevents connections from the outside world back to the client
machine.
-i: Turns off interactive prompting during multiple file transfers.
-n: Restrains ftp from attempting auto-login upon initial connection.
-e: Disables command editing and history support, if it was compiled into the ftp
executable. Otherwise, does nothing.
-g: Disables file name globbing.
-v: Verbose option forces ftp to show all responses from the remote server, as
well as report on data transfer statistics.
-d: Enables debugging.
ascii: Set the file transfer type to network ASCII This is the default type.
bell: Arrange that a bell be sounded after each file transfer command is completed.
binary: Set the file transfer type to support binary image transfer.
bye : Terminate the FTP session with the remote server and exit ftp An end of file
will also terminate the session and exit.
case : Toggle remote computer file name case mapping during mget commands.
cd remote-directory:Change the working directory on the remote machine to remotedirectory
close: Terminate the FTP session with the remote server, and return to the command
interpreter. Any defined macros are erased.
cr: Toggle carriage return stripping during ascii type file retrieval.
delete remote-file:Delete the file remote-file on the remote machine.
disconnect: A synonym for close
help[command]:Print an informative message about the meaning of command If no
argument is given, ftp prints a list of the known commands.
idle[seconds]:Set the inactivity timer on the remote server to seconds seconds. If seconds is
ommitted, the current inactivity timer is printed.

vi) nslookup
Name
nslookup - query Internet name servers interactively
Synopsis
nslookup [-option][name|-][server]
DESCRIPTION
nslookup is a program to query Internet domain name servers. nslookup has two modes:
interactive and non-interactive. Interactive mode allows the user to query name servers for
information about various hosts and domains or to print a list of hosts in a domain. Noninteractive mode is used to print just the name and requested information for a host or
domain.
Arguments:
Interactive mode is entered in the following cases:
1. when no arguments are given (the default name server will be used)
2. when the first argument is a hyphen (-) and the second argument is the host name or
Internet address of a name server.
Non-interactive mode is used when the name or Internet address of the host to be looked up is
given as the first argument. The optional second argument specifies the host name or address
of a name server.
Options can also be specified on the command line if they precede the arguments and are
prefixed with a hyphen. For example, to change the default query type to host information,
and the initial timeout to 10 seconds, type:
nslookup -query=hinfo -timeout=10
Ex: nslookup google.com:
nslookup followed by the domain name will display the “A Record” (IP Address) of the
domain. Use this command to find the address record for a domain. It queries to domain
name servers and gets the details.
nslookup 192.168.0.10: Reverse DNS lookup
You can also do the reverse DNS look-up by providing the IP Address as an argument to
nslookup.

vii) traceroute:
Name
traceroute - print the route packets trace to network host
Synopsis
traceroute [options] host_Address [pathlength]
DESCRIPTION
traceroute tracks the route packets taken from an IP network on their way to a given host. It
utilizes the IP protocol’s time to live (TTL) field and attempts to elicit an ICMP
TIME_EXCEEDED response from each gateway along the path to the host.
The only required parameter is the name or IP address of the destination host. The optional
packet_length is the total size of the probing packet (default 60 bytes for IPv4 and 80 for
IPv6). The specified size can be ignored in some situations or increased up to a minimal
value.
This program attempts to trace the route an IP packet would follow to some internet host by
launching probe packets with a small ttl (time to live) then listening for an ICMP "time
exceeded" reply from a gateway. We start our probes with a ttl of one and increase by one
until we get an ICMP "port unreachable" (or TCP reset), which means we got to the
"host", or hit a max (which defaults to 30 hops). Three probes (by default) are sent at each
ttl setting and a line is printed showing the ttl, address of the gateway and round trip time
of each probe. The address can be followed by additional information when requested. If
the probe answers come from different gateways, the address of each responding system will
be printed. If there is no response within a 5.0 seconds (default), an "*" (asterisk) is printed
for that probe.
Options:
-4 Option: Use ip version 4 i.e. use IPv4
Syntax:
$ traceroute -4 google.com
-F Option: Do not fragment packet.
-m max_ttl Option: Set the max number of hops for the packet to reach the
destination.Default value is 30.
-n Option: Do not resolve IP addresses to their domain names.

Program Validation
Input: $ [command] {- options}
Output: Displays the result related to the entered command.
Conclusion: By using these commands we gain an understanding of networking basics
commands.
