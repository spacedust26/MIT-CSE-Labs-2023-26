# Classful Addressing
![nethostdata](https://github.com/user-attachments/assets/692a7146-7afb-476b-8533-c1f47e88fbaf)

# Exercise 1

As a network Engineering, you are required to subnet the 192.168.1.0 network to provide IP addresses 
to the given network. Show all calculations. What is the  Then configure all devices and ensure that 
PCs can ping each other.    

## Configuration

- Identify the base network:
  192.168.1.0 with a subnet mask of /24, i.e 255.255.255.0, takes 24 bits for network and 8 bits for hosts.
- Determine the number of subnets needed: 
  From the figure, we find 4 subnets
  - Subnet 1 - 6 PCs connected to switch 0
  - Subnet 2 - 6 PCs connected to switch 1
  - Subnet 3 - 3 Pcs connected to switch 2
  - Subnet 4 - Connecting routers
  For 4 subnets, we need 2 bits (2^2 = 4)
- Calculate the new subnet mask:
  Borrowing 2 bits from host address, we get /24 + 2 = /26 as the new subnet mask, i.e 255.255.255.192 
- Calculate number of hosts per subnet:
  26 bits for network leaves 6 bits for host.
  Therefore, number of hosts per subnet is 2^6 = 64.
  Reserve the first and the last address, so that leaves 62 hosts per subnet.
- Creating subnet ranges:
  - Subnet 1 - 192.168.1.0 - 192.168.1.63
  - Subnet 2 - 192.168.1.64 - 192.168.1.127
  - Subnet 3 - 192.168.1.128 - 192.168.1.191
  - Subnet 4 - 192.168.1.192 - 192.168.1.255

## Subnet 1

- **PC0**
  - IP Address: 192.168.1.1
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.62
  - GNS3 -  ip 192.168.1.1 255.255.255.192 192.168.1.62

- **PC1**
  - IP Address: 192.168.1.2
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.62
  - GNS3 -  ip 192.168.1.2 255.255.255.192 192.168.1.62

- **PC2**
  - IP Address: 192.168.1.3
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.62
  - GNS3 -  ip 192.168.1.3 255.255.255.192 192.168.1.62

- **PC3**
  - IP Address: 192.168.1.4
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.62
  - GNS3 -  ip 192.168.1.4 255.255.255.192 192.168.1.62

- **PC4**
  - IP Address: 192.168.1.5
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.62
  - GNS3 -  ip 192.168.1.5 255.255.255.192 192.168.1.62

- **PC5**
  - IP Address: 192.168.1.6
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.62
  - GNS3 -  ip 192.168.1.6 255.255.255.192 192.168.1.62

## Subnet 2

- **PC6**
  - IP Address: 192.168.1.65
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.126
  - GNS3 - ip 192.168.1.65 255.255.255.192 192.168.1.126

- **PC7**
  - IP Address: 192.168.1.66
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.126
  - GNS3 - ip 192.168.1.66 255.255.255.192 192.168.1.126

- **PC8**
  - IP Address: 192.168.1.67
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.126
  - GNS3 - ip 192.168.1.67 255.255.255.192 192.168.1.126

- **PC9**
  - IP Address: 192.168.1.68
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.126
  - GNS3 - ip 192.168.1.68 255.255.255.192 192.168.1.126

- **PC10**
  - IP Address: 192.168.1.69
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.126
  - GNS3 - ip 192.168.1.69 255.255.255.192 192.168.1.126

- **PC11**
  - IP Address: 192.168.1.70
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.126
  - GNS3 - ip 192.168.1.70 255.255.255.192 192.168.1.126

## Subnet 3

- **PC12**
  - IP Address: 192.168.1.129
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.190
  - GNS3 - ip 192.168.1.129 255.255.255.192 192.168.1.190

- **PC13**
  - IP Address: 192.168.1.130
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.190
  - GNS3 - ip 192.168.1.130 255.255.255.192 192.168.1.190

- **PC14**
  - IP Address: 192.168.1.131
  - Subnet Mask: 255.255.255.192
  - Default Gateway:  192.168.1.190
  - GNS3 - ip 192.168.1.131 255.255.255.192 192.168.1.190

## Subnet 4

- **Router1**
```bash
  enable
  config t
  interface fa0/0
  ip address 192.168.1.62 255.255.255.192
  no shutdown
  exit
  interface se2/0
  ip address 192.168.1.193 255.255.255.192
  no shutdown
  exit

  ip route 192.168.1.64 255.255.255.192 192.168.1.126
  ip route 192.168.1.128 255.255.255.192 192.168.1.190
```
- **Router2**
```bash
  enable
  config t
  interface fa0/0
  ip address 192.168.1.126 255.255.255.192
  no shutdown
  exit
  interface fa1/0
  ip address 192.168.1.190 255.255.255.192
  no shutdown
  exit
  interface se2/0
  ip address 192.168.1.194 255.255.255.192
  no shutdown
  exit

  ip route 192.168.1.0 255.255.255.192 192.168.1.62
```

## Test connectivity
By pinging

![Screenshot 2024-11-03 122304](https://github.com/user-attachments/assets/855194c8-d308-49d1-b678-4823b0f509ab)

# Exercise 2

You are a network technician assigned to design and implement a new network for a client. Given the 
Class C network of 192.168.5.0/24, subnet the network to create the network as shown with the host 
requirements shown. Show sample hosts and ensure connectivity

# Subnetting with Variable Length Subnet Masking (VLSM)

## Step 1: Calculate Required Subnet Sizes
Each subnet requires a certain number of host IPs, and we calculate the subnet size based on these needs.

### netB and netE (each requires 28 hosts)
- **Minimum host requirement**: 28
- **Subnet size**: Requires at least 32 addresses (2^5 = 32).
- **Subnet mask**: /27 (255.255.255.224), providing 32 addresses with 30 usable host IPs.

### netA (requires 14 hosts)
- **Minimum host requirement**: 14
- **Subnet size**: Requires at least 16 addresses (2^4 = 16).
- **Subnet mask**: /28 (255.255.255.240), providing 16 addresses with 14 usable host IPs.

### netD (requires 7 hosts)
- **Minimum host requirement**: 7
- **Subnet size**: Requires at least 8 addresses (2^3 = 8).
- **Subnet mask**: /29 (255.255.255.248), providing 8 addresses with 6 usable host IPs.

### netC (requires 2 hosts)
- **Minimum host requirement**: 2
- **Subnet size**: Requires at least 4 addresses (2^2 = 4).
- **Subnet mask**: /30 (255.255.255.252), providing 4 addresses with 2 usable host IPs.

## Step 2: Allocate Subnet Ranges Using VLSM
Starting from **192.168.5.0** and moving upward, we allocate addresses for each subnet, starting with the largest.

### netB (28 hosts)
- **Subnet**: 192.168.5.0/27
- **Range**: 192.168.5.0 - 192.168.5.31
- **Usable IPs**: 192.168.5.1 - 192.168.5.30
- **Broadcast**: 192.168.5.31

### netE (28 hosts)
- **Subnet**: 192.168.5.32/27
- **Range**: 192.168.5.32 - 192.168.5.63
- **Usable IPs**: 192.168.5.33 - 192.168.5.62
- **Broadcast**: 192.168.5.63

### netA (14 hosts)
- **Subnet**: 192.168.5.64/28
- **Range**: 192.168.5.64 - 192.168.5.79
- **Usable IPs**: 192.168.5.65 - 192.168.5.78
- **Broadcast**: 192.168.5.79

### netD (7 hosts)
- **Subnet**: 192.168.5.80/29
- **Range**: 192.168.5.80 - 192.168.5.87
- **Usable IPs**: 192.168.5.81 - 192.168.5.86
- **Broadcast**: 192.168.5.87

### netC (2 hosts)
- **Subnet**: 192.168.5.88/30
- **Range**: 192.168.5.88 - 192.168.5.91
- **Usable IPs**: 192.168.5.89 - 192.168.5.90
- **Broadcast**: 192.168.5.91

## Step 3: Assign IP Addresses
Using the allocated subnets:

- **netB**: Assign IPs from **192.168.5.1 - 192.168.5.30** to hosts in this subnet.
- **netE**: Assign IPs from **192.168.5.33 - 192.168.5.62** to hosts in this subnet.
- **netA**: Assign IPs from **192.168.5.65 - 192.168.5.78** to hosts in this subnet.
- **netD**: Assign IPs from **192.168.5.81 - 192.168.5.86** to hosts in this subnet.
- **netC**: Assign IPs **192.168.5.89** and **192.168.5.90** to the router interfaces for the link between routers.
