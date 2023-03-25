# boot.py -- run on boot-up
import network
import utime
import machine

try:
    import uasyncio as asyncio
except ImportError:
    import asyncio

# Replace the following with your WIFI Credentials
SSID = "Studio Metric"
SSI_PASSWORD = "functionfirst"

def do_connect():
    sta_if = network.WLAN(network.STA_IF)
    if not sta_if.isconnected():
        print('trying to connect...')
        sta_if.active(True)
        sta_if.ifconfig(('192.168.1.69', '255.255.255.0', '192.168.1.1', '8.8.8.8'))
        sta_if.connect(SSID, SSI_PASSWORD)
        count = 0
        while not sta_if.isconnected():
            if count < 5:
                print('not connected, waiting')
                utime.sleep(1)
            else:
                print('failing to connect; resetting')
                machine.reset()

    print('Connected! Network config:', sta_if.ifconfig())

    
print("Connecting to your wifi...")
do_connect()






