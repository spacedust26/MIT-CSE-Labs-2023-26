# Exercise 1

Design the Network with routing using RIP. Provide DHCP and DNS Configuration in R3 

## Configuration

### 1) Configure the routers

- **Router 1**
```bash
  enable
  configure terminal
  interface fastethernet0/0
  ip address 192.168.10.1 255.255.255.0
  no shutdown
  exit
  interface fastethernet1/0
  ip address 172.16.0.1 255.255.0.0
  no shutdown
  exit
  interface fastethernet2/0
  ip address 30.30.30.1 255.255.255.224
  no shutdown
  exit
```

- **Router 2**
```bash
  enable
  configure terminal
  interface fastethernet0/0
  ip address 30.30.30.2 255.255.255.224
  no shutdown
  exit
  interface fastethernet1/0
  ip address 20.20.20.1 255.255.255.240
  no shutdown
  exit
```

- **Router 3**
```bash
  enable
  configure terminal
  interface fastethernet0/0
  ip address 192.168.20.1 255.255.255.0
  no shutdown
  exit
  interface fastethernet1/0
  ip address 20.20.20.2 255.255.255.240
  no shutdown
  exit
```

### 2) Configure RIP for each of the routers

- **Router 1**
```bash
  router rip
  version 2
  network 192.168.10.0
  network 172.16.0.0
  network 30.30.30.0
  exit
  do wr
```

- **Router 2**
```bash
  router rip
  version 2
  network 30.30.30.0
  network 20.20.20.0
  exit
  do wr
```

- **Router 3**
```bash
  router rip
  version 2
  network 192.168.20.0
  network 20.20.20.0
  exit
  do wr
```

### 3) Configure R3 as a DNS server

- **Router 3**
```bash
  ip dns server
  ip name-server 20.20.20.2
  ip domain-name demo.com
  ip host www.demo.com 20.20.20.2
  exit
```

### 4) Statically assign IP to PC1 and test DNS
- **PC0**
  - ip 192.168.10.2 255.255.255.0 192.168.10.1
  - ip dns 20.20.20.2
  - ping www.demo.com

### 5) Configure R3 as DHCP server
- **Router 3**
```bash
  ip dhcp pool POOL-A
  network 192.168.10.0 255.255.255.0
  default-router 192.168.10.1
  exit
  ip dhcp pool POOL-B
  network 172.16.0.0 255.255.0.0
  default-router 172.16.0.1
  exit
  ip dhcp pool POOL-C
  network 192.168.20.0 255.255.255.224
  default-router 192.168.20.1
  exit
  # ip dhcp excluded-address 192.168.10.2 is the format to exclude 
  do wr
  ip dhcp pool POOL-A
  dns-server 20.20.20.2
  exit
  ip dhcp pool POOL-B
  dns-server 20.20.20.2
  exit
  ip dhcp pool POOL-C
  dns-server 20.20.20.2
  exit
  do wr
```

### 6) Assigning DHCP relay agent

- **Router 1**
```bash
  int fa0/0
  ip helper-address 20.20.20.2
  exit
  int fa1/0
  ip helper-address 20.20.20.2
  exit
  do wr
```
- **Router 2**
  Doesn't need helper address due to no direct networks

- **Router 3**
```bash
  int fa0/0
  ip helper-address 20.20.20.2
  exit
  do wr
```

### 7) Assigning IP to PC2 and testing DNS

- ***PC2***
  - dhcp
  - show ip
  - ping www.demo.com


![Screenshot 2024-11-03 190302](https://github.com/user-attachments/assets/f442ff4a-f901-4bb7-b8e2-13543e7d4718)





