import cantools
import can
from can.interfaces import pcan
import sys,os,time

def send_message(can_bus, db, message_id, signals):
	blank_message = db.get_message_by_frame_id(message_id)
	data = blank_message.encode(signals)
	message = can.Message(arbitration_id=blank_message.frame_id, data = data, extended_id=False)
	can_bus.send(message)

def main():
	can_bus = can.interface.Bus("vcan0", bustype='socketcan')
	db = cantools.database.load_file("./test.dbc")
	var1 = 1
	var2 = 2
	while True:
		send_message(can_bus, db, message_id=2022, signals={'TEST_CHEN1': var1, 'TEST_CHEN2': var2})
		var1 = var1 + 2
		var2 = var2 + 3
		print("var 1 and 2 are:{},{}".format(var1, var2))
		time.sleep(2)


main()