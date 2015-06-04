from bottle import route, run, get, post, request, template
from serial import *
from time import *
from threading import *

########## Initialize Serial Port Function  ###########
def InitSerial(PN, BR, T):
    se = Serial('/dev/ttyATH0', baudrate = BR, timeout =  T)
    if se.isOpen():
        se.close()
    se.open()
    return se
##########          Function End            ###########

REG = {'Moisture':b'\x00','UpperThreshold':b'\x01','LowerThreshold':b'\x02','ManualAuto':b'\x03','OnOff':b'\x04','Valve':b'\x05'}

def Read(Reg):
    se.write('R')
    se.write(Reg)
    se.write(b'\xff')
    se.write(b'\xff')
    value_H = ord(se.read())
    value_L = ord(se.read())
    value = value_L+(value_H<<8)
    return value

def Write(Reg,Val):
    Val_H = Val>>8
    Val_L = Val&255
    se.write('W')
    se.write(Reg)
    se.write(chr(Val_H))
    se.write(chr(Val_L))

def AnalogRead():
    se.write('A')
    se.write(b'\xff')
    se.write(b'\xff')
    se.write(b'\xff')
    value_H = ord(se.read())
    value_L = ord(se.read())
    value = value_L+(value_H<<8)
    return value

##########         Web            ###########




def GetValue(Value):
    return Value

@route('/')
def Home():
    return template('HomePage.txt')

@route('/AutoManual', method='GET')
def AutoManual():
    value = Read(REG['ManualAuto'])
    if(value==0):
        Write(REG['ManualAuto'],1)
    else:
        Write(REG['ManualAuto'],0)
    return {'AutoManualState':Read(REG['ManualAuto'])}

@route('/RunStop')
def RunStop():
    value = Read(REG['OnOff'])
    if(value==0):
        Write(REG['OnOff'],1)
    else:
        Write(REG['OnOff'],0)
    return {"RelayState":Read(REG['OnOff'])}

@route('/Refresh')
def Refresh():

    AutoManualState = Read(REG['ManualAuto'])
    RelayState = Read(REG['OnOff'])
    print 'Dampness: '+str(AnalogRead())
    return {"AutoManualState":Read(REG['ManualAuto']),"RelayState":Read(REG['OnOff'])}

@route('/UpdateThreshold', method='POST')
def UpdateThreshold():

    #global UpperThreshold
    #global LowerThreshold
    UpperThreshold = int(request.forms.get('UpperThreshold'))
    LowerThreshold = int(request.forms.get('LowerThreshold'))
    Write(REG['UpperThreshold'],UpperThreshold)
    Write(REG['LowerThreshold'],LowerThreshold)
    print Read(REG['UpperThreshold'])
    print Read(REG['LowerThreshold'])
    print AnalogRead()
    print Read(REG['Valve'])


def website():
    run(host='0.0.0.0', port=8080)

def background():
    while 1:
        #print AnalogRead()
        sleep(1)


#web = Thread(name = 'web', target = website)
#back = Thread(name = 'back', target = background)

se = InitSerial(6,9600,None)
#web.start()
#back.start()
website()
