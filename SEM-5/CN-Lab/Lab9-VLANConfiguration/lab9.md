# Exercise 1

Create a topology as shown and Create 2 VLANs on the switch:  VLAN 10 and VLAN 20. You can give them custom names. 

## Configuration

- **PC0**
  - IP Address: 192.168.1.10
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.1.1

- **PC1**
  - IP Address: 192.168.1.20
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.1.1

- **PC2**
  - IP Address: 192.168.2.10
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.2.2

 - **PC3**
  - IP Address: 192.168.2.20
  - Subnet Mask: 255.255.255.0
  - Default Gateway:  192.168.2.2

- **Switch**
```bash
  enable
  configure terminal
  vlan 10
  name lab1
  exit
  vlan 20
  name lab2
  exit
  int fa0/1
  switchport mode access
  switchport access vlan 10
  exit
  int fa1/1
  switchport mode access
  switchport access vlan 10
  exit
  int fa3/1
  switchport mode access
  switchport access vlan 20
  exit
  int fa2/1
  switchport mode access
  switchport access vlan 20
  exit
  int fa4/1
  switchport mode trunk
```

- **Router**
```bash
  enable
  configure terminal
  interface fastethernet4/0
  no shutdown
  exit
  interface fastethernet4/0.10
  encapsulation dot1q 10
  ip address 192.168.1.1 255.255.255.0
  exit
  interface fastethernet4/0.20
  encapsulation dot1q 20
  ip address 192.168.2.2 255.255.255.0
  exit
```

![Screenshot 2024-11-03 161013](https://github.com/user-attachments/assets/00a226e4-066d-4534-acb4-b32afe333d9d)

## How to configure switch in GNS3
- Right click on the switch -> configure

![Screenshot 2024-11-03 171345](https://github.com/user-attachments/assets/c1147797-ebb6-42ab-9b7e-41f8278aa701)

![Screenshot 2024-11-03 171449](https://github.com/user-attachments/assets/f8eac833-00a7-43b3-81ad-c32f709201c6)