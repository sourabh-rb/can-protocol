# can-protocol

The CAN bus is a broadcast type of bus. This means that all nodes can "hear" all transmissions. There is no way to send a message to just a specific node; all nodes will invariably pick up all traffic. The CAN hardware, however, provides local filtering so that each node may react only on the interesting messages, however, well suited in application requiring a large number of messages with high reliability in rugged Environment. It provides an inexpensive, durable network that helps multiple devices to communicate with each other, having a single interface to a system. In addition, every message has a priority, so if two nodes try to send messages simultaneously, the one with the higher priority gets transmitted and the one with the lower priority gets postponed.

  ## Hardware Used: ##
  LPC 2129 Single-chip 32-bit microcontroller; 256 KB ISP/IAP Flash with 10-bit ADC and CAN.

## CAN Registers ##
Name  | Description|Access|Resect Value| Address
------| -----------|------|------------|--------
AFMR  | Acceptance Filter Register|R/W|1|0xE003 C000
SFF_sa|Standard Frame Individual Start Address Register|R/W|0|0xE003 C004
SFF_GRP_sa|Standard Frame Group Start Address Register|R/W|0|0xE003 C008
EFF_sa|Extended Frame Start Address Register|R/W|0|0xE003 C00C
EFF_GRP_sa|Extended Frame Group Start Address Register|R/W|0|0xE003 C010


