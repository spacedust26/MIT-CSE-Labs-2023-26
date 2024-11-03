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