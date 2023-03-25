from microdot_asyncio import Microdot, Response, send_file
from microdot_asyncio_websocket import with_websocket
import time
import machine

try:
    import uasyncio as asyncio
except ImportError:
    import asyncio
    
async def run_wdt():
    wdt = machine.WDT(timeout=2000)
    while True:
        await asyncio.sleep(1)
        wdt.feed()
        
print("Starting WDT")
asyncio.create_task(run_wdt())

# Initialize MicroDot
app = Microdot()
Response.default_content_type = 'text/html'

flusher_contact = machine.Pin(17, machine.Pin.IN, machine.Pin.PULL_UP)
head_break_beam = machine.Pin(16, machine.Pin.IN, machine.Pin.PULL_UP)

# root route

@app.route('/ws')
@with_websocket
async def read_sensor(request, ws):
    print("new connection")
    while True:
        try:
            data = await ws.receive()
            flusher_is_pulled = "1" if not flusher_contact.value() else "0"
            beam_is_broken = "1" if not head_break_beam.value() else "0"
            await ws.send(str(beam_is_broken + ":" + flusher_is_pulled))
        except: 
            print("connection closed")
            break

try:
    print("running webserver")
    app.run(port=6969)
except KeyboardInterrupt:
    pass



