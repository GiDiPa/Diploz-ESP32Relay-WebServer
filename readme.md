Hi everyone!

This is just a demonstration of the ESP32 capabilities!

In this case ESP32 works as a Server, so no need to connect under a Wifi network. You can choose the address you want changing the line 91 (default is 192.168.1.1). You could also change SSID and Password of your ESP Access Point by changing 24 and 25 lines.

I use two fixed buttons has 'press and release' functionality and an array of switch toggle relays.
You can insert as many button as you want editing the main.cpp file under 'src' folder and customize the web style as you want editing files under 'data' folder!

The ESP32 accept a maximum of 10 simultaneous connections, so if reaching the maximum it resets connections again. 

It is possible to save the states of switch relay by saving them on EEPROM but you need to manage on your own(quite simple).

The Web Interface is based on bootstrap 5.0.2, so you can refer to the documentation to edit what you want. Of course you need to download files locally to make it work. 

For any questions, contact me.

P.S.: Sadly is not possible (if you have any solution please contact me) to make the server offline secure(https) so is not possible to let the service worker doing the job: in few terms, no PWA in this moment.