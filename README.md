# RFOutletControl
In this project, I used a 433Mhz transmitter and a 433Mhz receiver to wirelessly control many Etekcity outlets with my Raspberry Pi. First I soldered a 17cm copper antenna to my transmitter to receive a better range (through walls, etc.). Then I properly wired the transmitter and receiver to their corresponding pins on the Raspberry Pi's GPIO board. Following the instructions of an online manual*, I then used two programs receive.py* and send.py* to collect frequencies and send frequencies. Firstly, I used the receive.py program to determine what frequencies (On and Off) that the Elekcity remote emitted for each paired outlet. Next, using the send.py program I was able to copy the frequencies from the previous program and use them in the send.py program which allowed my Raspberry Pi to act as the Elekcity remote. Now, as my intentions were to set a timed schedule to perform these tasks for me, and so that I could turn on certain lights at certain times of day, I went ahead and created my own program in which I did these things. The result of my project was a complete success.

* The files for the receive.py and send.py come from the following links respectively:
- https://github.com/milaq/pri-rf/blob/master/scripts/pri-rf_send
- https://github.com/milaq/pri-rf/blob/master/scripts/pri-rf_receive
