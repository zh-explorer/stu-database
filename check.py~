#! /usr/bin/python
from zio import *
import sys
import hashlib
port = 0

#io = zio((sys.argv[1],port))
io = zio("./student")
md5 = 'caf1db37276d60b34e2e943480fbd41e'


get = ''

#add 1
get += io.read_until("choose")

io.writeline('a')

get += io.read_until("num")

io.writeline("11111111")

get += io.read_until("student")

io.writeline('/bin/sh')

get += io.read_until('student:')

io.writeline('x')

get += io.read_until('student')

io.writeline('11')

get += io.read_until('1:')

io.writeline('11')

get += io.read_until('2:')

io.writeline('11')

get += io.read_until('3:')

io.writeline('11')

get += io.read_until('4:')

io.writeline('11')

get += io.read_until('5:')

io.writeline('11')

get += io.read_until('information')

io.writeline('a')
#add 2
get += io.read_until("choose")

io.writeline('a')

get += io.read_until("num")

io.writeline("11111110")

get += io.read_until("student")

io.writeline('aaa')

get += io.read_until('student:')

io.writeline('x')

get += io.read_until('student')

io.writeline('11')

get += io.read_until('1:')

io.writeline('11')

get += io.read_until('2:')

io.writeline('11')

get += io.read_until('3:')

io.writeline('11')

get += io.read_until('4:')

io.writeline('11')

get += io.read_until('5:')

io.writeline('11')

get += io.read_until('information')

io.writeline('a')

#add 3
get += io.read_until("choose")

io.writeline('a')

get += io.read_until("num")

io.writeline("22222222")

get += io.read_until("student")

io.writeline('aaa')

get += io.read_until('student:')

io.writeline('x')

get += io.read_until('student')

io.writeline('11')

get += io.read_until('1:')

io.writeline('11')

get += io.read_until('2:')

io.writeline('11')

get += io.read_until('3:')

io.writeline('11')

get += io.read_until('4:')

io.writeline('11')

get += io.read_until('5:')

io.writeline('11')

get += io.read_until('information')

io.writeline('a')

#query
get += io.read_until('choose')

io.writeline('q')

get += io.read_until('[Y?N]')

io.writeline('n')

get += io.read_until('num')

io.writeline('11111111')


#del
get += io.read_until("choose")

io.writeline('d')

get += io.read_until('delete')

io.writeline('11111111')


#query
get += io.read_until('choose')

io.writeline('q')

get += io.read_until('[Y?N]')

io.writeline('n')

get += io.read_until('num')

io.writeline('11111111')

m1 = hashlib.md5(get)
m = m1.hexdigest()
if m == md5:
    exit(0)
else:
    exit(1)
