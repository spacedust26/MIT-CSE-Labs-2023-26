# Exercise 1

Configure the PCs (hosts) with IPv4 address and Subnet Mask according to the IP addressing table 
given above  

## Configuration

Configure each PC by setting a static IP address, default gateway and subnet mask in Fast Ethernet.

- **PC0**
  - IP Address: 192.168.1.2
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.1.1

- **PC1**
  - IP Address: 192.168.1.3
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.1.1

- **PC2**
  - IP Address: 192.168.2.2
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.2.1

- **PC3**
  - IP Address: 192.168.2.3
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.2.1

- **Router1**
```bash
  enable
  config t
  interface fa0/0
  ip address 192.168.1.1 255.255.255.0
  no shutdown
  exit
  interface se2/0
  ip address 11.0.0.1 255.255.255.0
  no shutdown
  exit

  ip route 192.168.2.0 255.255.255.0 11.0.0.2
```
- **Router2**
```bash
  enable
  config t
  interface fa0/0
  ip address 192.168.2.1 255.255.255.0
  no shutdown
  exit
  interface se2/0
  ip address 11.0.0.2 255.255.255.0
  no shutdown
  exit

  ip route 192.168.1.0 255.255.255.0 11.0.0.1
  ```

## Test connectivity

**For PC0**
- ping 192.168.1.3
- ping 192.168.2.3