# Exercise 1

Q1. Design the network which consist of   
a) HTTP server.   
b) FTP server.   
c) DNS server.   
d) Switch.   
e) Router.   
f) PC.  

## Configuration

Configure each PC by setting a static IP address, default gateway and subnet mask in Fast Ethernet.

- **PC0**
  - IP Address: 192.168.1.1
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.1.2

- **HTTP Server**
  - IP Address: 192.168.2.2
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.2.1
  - Go to web browser in PC0 and type 192.168.2.2
  - Welcome to cisco packet tracer appears

- **DNS Server**
  - IP Address: 192.168.2.3
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.2.1
  - DNS Server: 192.168.2.3
  - Don't forget to set DNS Server of PC0 as 192.168.2.3
  - Go to services , switch on HTTP and DNS
  - Under DNS add lab3.com as name with address 192.168.2.2
  - Go to web browser in PC0 and type 192.168.2.2
  - Welcome to cisco packet tracer appears

- **FTP Server**
  - IP Address: 192.168.2.4
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.2.1
  - Go to services , switch on FTP
  - Add a username, password, give write, read, delete, rename, list permissions, click on add
  - You can create a file in the text editor and name it as lab3.txt
  - Go to the command prompt of PC0 and type ftp 192.168.2.4, followed by username and password
  - If you want to send file do,  put lab3.txt
  - If you want to receive file do,  get lab3.txt
  - To check the file exists, perform dir

- **Router**
```bash
  enable
  configure terminal
  interface fastethernet0/0
  ip address 192.168.1.2 255.255.255.0
  no shutdown
  exit
  interface fastethernet1/0
  ip address 192.168.2.1 255.255.255.0
  no shutdown
  exit
```
  
## GNS3 Configurations
- **PC0**
  - ip 192.168.1.1 255.255.255.0 192.168.1.2

- **Router**
```bash
  enable
  configure terminal
  interface fastethernet0/0
  ip address 192.168.1.2 255.255.255.0
  no shutdown
  exit
  interface fastethernet1/0
  ip address 192.168.2.2 255.255.255.0
  no shutdown
  exit
```

- **Router 2 - HTTP Server**
```bash
  enable
  config t
  interface fastethernet0/0
  ip address 192.168.2.2 255.255.255.0
  no shutdown
  exit
  ip route 0.0.0.0 0.0.0.0 192.168.2.1
  exit
  show ip route

  enable
  config t
  ip http server  ( or ip http secure-server)
  ip http authentication local
  username admin privilege 15 secret adminpassword
  exit
  show ip http server status
```
  - On PC0 ping 192.168.2.2
- **Router 3 - DNS Server**
```bash
  enable
  config t
  interface fa0/0 
  ip address 192.168.2.3 255.255.255.0
  no shutdown
  exit
  ip route 0.0.0.0 0.0.0.0 192.168.2.1
  exit

  enable
  config t
  ip dns server
  ip host www.demo.com 192.168.2.2
  exit
```
  - On PC0 ip dns 192.168.2.3
    ping www.demo.com


- **Router 3 - DNS Server**
```bash
  enable
  config t
  interface fa0/0 
  ip address 192.168.2.4 255.255.255.0
  no shutdown
  exit
  ip route 0.0.0.0 0.0.0.0 192.168.2.1
  exit

  enable
  config t
  ip ftp username admin
  ip ftp password adminpassword
  exit
```
  - On PC0 ip ftp 192.168.2.4 (doesn't work)
    - get `<filename>`
    - put `<filename>`

# Exercise 2
DHCP Server configuration in router

## Configuration

- **Router**
```bash
  enable
  configure terminal
  interface fastethernet0/0
  ip address 10.0.0.4 255.255.255.0
  no shutdown
  exit
  interface fastethernet1/0
  ip address 20.0.0.4 255.255.255.0
  no shutdown
  exit

  ip dhcp excluded-address 10.0.0.4
  ip dhcp excluded-address 20.0.0.4
  ip dhcp pool 10series
  network 10.0.0.1 255.255.255.0
  default-router 10.0.0.4
  exit

  ip dhcp pool 20 series
  network 20.0.0.1 255.255.255.0 
  default-router 20.0.0.4
  exit
``` 
## Testing
- Enable DHCP in IP configuration for all the PCs to check the IP address assigned 

## GNS3 Configuration

- To check IP configurations type - show ip

**From PC0**
- ip 10.0.0.1 255.255.255.0 10.0.0.4

**From PC1**
- ip 10.0.0.2 255.255.255.0 10.0.0.4

**From PC2**
- ip 20.0.0.1 255.255.255.0 20.0.0.4

**From PC3**
- ip 20.0.0.2 255.255.255.0 20.0.0.4

**From PC4**
- ip 30.0.0.1 255.255.255.0 30.0.0.4

**From PC5**
- ip 30.0.0.2 255.255.255.0 30.0.0.4

- **Router**
  ```bash
  enable
  configure terminal
  interface fastethernet0/0
  ip address 10.0.0.4 255.255.255.0
  no shutdown
  exit
  interface fastethernet1/0
  ip address 20.0.0.4 255.255.255.0
  no shutdown
  exit
  interface fastethernet2/0
  ip address 30.0.0.4 255.255.255.0
  no shutdown
  exit
  interface fastethernet3/0
  ip address 40.0.0.4 255.255.255.0
  no shutdown
  exit