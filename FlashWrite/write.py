from subprocess import Popen
import sys
import struct
import os

try:
	if not sys.argv[1]:
		raise Exception
except Exception, e:
	print 'Argument : [filename]'
	exit();


# Fiile Data Read
file = open(sys.argv[1],'r')
data = file.read()
print 'File data loadded : ', len(data)
file.close()

# Temp Data Created
temp = data + struct.pack('4B',*([0]*4))
name = ".temp"
file = open(name,'wb')
file.write(temp)
file.close()

p = Popen(['pkill','-9','openocd'])
p.wait()

os.system('openocd -f interface/olimex-arm-usb-ocd.cfg -f target/stm32f2x.cfg -c "program .temp 0x080C0000;resume;exit"')
print "Finish"