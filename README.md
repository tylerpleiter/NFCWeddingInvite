# NFCWeddingInvite
NFC Energy Harvesting Wedding Invite

![alt text](https://github.com/tylerpleiter/NFCWeddingInvite/blob/main/Images/InviteFront.jpg "Completed Invite")

## Description:

To bring a part of my hobbies into my wedding, I created wedding invites using PCBs. The invite combines several ideas including: 
- An NFC energy harvesting tag IC, allowing a guest to hold it to the back of a compatible smartphone to power the invite and be redirected to a website.
- Hand-drawn artwork by my now wife, scanned, converted to a vector graphic, then imported as the solder mask layer, allowing for gold artwork when finished using gold ENIG.
- Tiny LEDs soldered throughout the artwork, programmed to flicker like fireflies.
- A PIC microcontroller to run the LEDs.
- A QR code leading to our wedding website, containing further information on the wedding.
- An artwork map on the back allowing for guests to find the tricky to locate venue.

## Building:
 
All PCB design done in Altium. Bare PCBs were manufactured overseas, then assembled by hand. 

Firmware was written and built in MPLAB. It was then programmed onto the device using a makeshift pogo pin programmer soldered to a SNAP Programmer. 

Finally the NFC tags were written onto the device using a smartphone NFC writer. 

Approximatley 30 were completed and sent off. 

## Issues:

- Due to tolerance or capability issues, one of the LED traces was etched through, preventing the LED from lighting.
- Due to a rushed timeline, comprehensive phone testing was not completed, and only some Android devices could successfully power the invite. Many devices did not read NFC tags frequently enough. 
