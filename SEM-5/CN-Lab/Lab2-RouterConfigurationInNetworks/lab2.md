# Exercise 1

You are tasked with setting up a simple network for a client that includes three PCs connected to a 
routers. The objective is to ensure seamless communication between the PCs across these LANs 
using the configured router. 

## Configuration

Configure each PC by setting a static IP address, default gateway and subnet mask in Fast Ethernet.

- **PC0**
  - IP Address: 192.168.10.10
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.10.1

- **PC1**
  - IP Address: 192.168.20.10
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.20.1

- **PC2**
  - IP Address: 192.168.30.10
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.30.1

- **Router**
  ```bash
  enable
  configure terminal
  interface fastethernet0/0
  ip address 192.168.10.1 255.255.255.0
  no shutdown
  exit
  interface fastethernet1/0
  ip address 192.168.20.1 255.255.255.0
  no shutdown
  exit
   interface fastethernet6/0
  ip address 192.168.30.1 255.255.255.0
  no shutdown
  exit

## Testing

Test connectivity by pinging from the command prompt:

- **From PC0**
  ```bash
  ping 192.168.20.1
## GNS3 Configurations
- Click on start
- Right click open console ip [Ip4 address] [subnet mask] [default gateway]
- PC0 `ip 192.168.10.10 255.255.255.0 192.168.10.1`
- PC1 `ip 192.168.20.10 255.255.255.0 192.168.20.1`
- PC2 `ip 192.168.30.10 255.255.255.0 192.168.30.1`
- To use wirehshark right click on the wire and start capture

<div style="display: flex; gap: 10px;"> 
  <img src="https://github.com/user-attachments/assets/2d198296-8fc2-449c-b8f4-07cbb439964c" alt="Packet Tracer Screenshot" width="49%"> 
</div>

# Exercise 2

You have been tasked with designing and implementing a network infrastructure for a small 
organization with four distinct sections: Administration, Accounts and Finance, Information Technology 
(IT), and Database. The objective is to ensure efficient communication and data sharing among 
departments while maintaining security and scalability. 

## Configuration

Configure each PC by setting a static IP address and subnet mask in Fast Ethernet.

- **PC0**
  - IP Address: 10.0.0.1
  - Subnet Mask: 255.255.255.0
  - Default Gateway: 10.1.0.4

- **PC1**
  - IP Address: 10.0.0.2
  - Subnet Mask: 255.255.255.0
  - Default Gateway: 10.1.0.4

- **PC2**
  - IP Address: 20.0.0.1
  - Subnet Mask: 255.255.255.0
  - Default Gateway: 20.1.0.4

- **PC3**
  - IP Address: 20.0.0.2
  - Subnet Mask: 255.255.255.0
  - Default Gateway: 20.1.0.4

- **PC4**
  - IP Address: 30.0.0.1
  - Subnet Mask: 255.255.255.0
  - Default Gateway: 30.1.0.4

- **PC5**
  - IP Address: 30.0.0.2
  - Subnet Mask: 255.255.255.0
  - Default Gateway: 30.1.0.4

- **Server**
  - IP Address: 40.0.0.1
  - Subnet Mask: 255.255.255.0
  - Default Gateway: 40.1.0.4

- **Router**
  ```bash
  enable
  configure terminal
  interface fastethernet0/0
  ip address 10.1.0.4 255.255.255.0
  no shutdown
  exit
  interface fastethernet1/0
  ip address 20.1.0.4 255.255.255.0
  no shutdown
  exit
  interface fastethernet6/0
  ip address 30.1.0.4 255.255.255.0
  no shutdown
  exit
  interface fastethernet7/0
  ip address 40.1.0.4 255.255.255.0
  no shutdown
  exit
## Testing

Test connectivity by pinging from the command prompt:

**From PC0**
 - ping PC1 `192.168.1.2`
 - ping PC2 `192.168.1.3`
 - ping PC3 `192.168.1.4`
 - ping PC4 `192.168.1.5`

 Repeat the same for other PCs

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
  
 ![Screenshot 2024-11-02 210345](https://github.com/user-attachments/assets/175d7784-ec5f-415b-b27d-d5fd5d353b8d)
