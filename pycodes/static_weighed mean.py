import serial
import math
import time
import numpy as np
import matplotlib.pyplot as plt
import datetime

def avg(s):
    return sum(s)*1.0/len(s)
std=[]
ser = serial.Serial('COM4', 9600)
for j in range(10):
    
    print j
    plt.axis([0, 10, 0, 200])
    plt.ioff()
    name=str(j)+"test.xls"
    pic=str(j)+"test.png"
    with open(str(name), "w") as text_file:
        hst= "time"+"\t"+ "Sensor 1"+"\t"+ "Sensor 2"+"\t"+ " mean"+"\t"+" weighed average"+"\n"
        print hst
        text_file.write(hst)
        arry=[]
        arrz=[]
        arra=[]
        arrtrip=[]
        arrdouble=[]
        
        for i in range(10):
        
                        
            #print ser.readline()
            ts = time.time()
            st = (datetime.datetime.fromtimestamp(ts).strftime('%Y-%m-%d %H:%M:%S'))
            y=0
            z=0
            try :
                while(y==0 or z==0):
                    x=int(ser.readline());
                    if x==1:
                        y= float(ser.readline())
                        print "1"
                                            
                    elif x==2:
                        print "2"
                        z= float(ser.readline());
                print z 
                print y
                trip=(z+y)/2
                double=((y/0.3076694484336517)+(z/0.5511587297881209))/((1/0.3076694484336517)+(1/0.5511587297881209))##0.8588281782217726
                
            except ValueError :
                time.sleep(3)
                i=i-1
                continue                
            arry.append(y)
            arrz.append(z)
            arrtrip.append(trip)
            arrdouble.append(double)
            st= st+"\t"+ str(y)+"\t"+ str(z)+"\t"+ str(trip)+"\t"+ str(double)+"\n"
            print st
            text_file.write(st)
            plt.plot(i, y, 'ro', i, z, 'bs', i, double, 'g^', i, trip, 'go')
            time.sleep(10) 
            plt.savefig(str(pic))

