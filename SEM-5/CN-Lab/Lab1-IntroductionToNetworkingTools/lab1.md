# Exercise 1

A client has requested that you set up a simple network with two PCs connected to a switch. Verify that the hardware, along with the given configurations, meet the requirements of the client.

## Configuration

Configure each PC by setting a static IP address and subnet mask in Fast Ethernet.

- **PC0**
  - IP Address: 192.168.10.10
  - Subnet Mask: 255.255.255.0

- **PC1**
  - IP Address: 192.168.10.11
  - Subnet Mask: 255.255.255.0

## Testing

Test connectivity by pinging from the command prompt:

- **From PC0**
  ```bash
  ping 192.168.10.11
## GNS3 Configurations
- Click on start
- Right click open console 
- PC0 `ip 192.168.10.10 255.255.255.0`
- PC1 `ip 192.168.10.11 255.255.255.0`

- To use wirehshark right click on the wire and start capture

# Exercise 2

Replicate the diagram

## Configuration

Configure each PC by setting a static IP address and subnet mask in Fast Ethernet.

- **PC0**
  - IP Address: 192.168.1.1
  - Subnet Mask: 255.255.255.0

- **PC1**
  - IP Address: 192.168.1.2
  - Subnet Mask: 255.255.255.0

- **PC2**
  - IP Address: 192.168.1.3
  - Subnet Mask: 255.255.255.0

- **PC3**
  - IP Address: 192.168.1.4
  - Subnet Mask: 255.255.255.0
## Testing

Test connectivity by pinging from the command prompt:

**From PC0**
 - ping PC1 `192.168.1.2`
 - ping PC2 `192.168.1.3`
 - ping PC3 `192.168.1.4`
 - ping PC4 `192.168.1.5`

 Repeat the same for other PCs

