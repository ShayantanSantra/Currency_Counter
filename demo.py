import serial
import time
import smtplib


 
TO = 'santrashayantan@gmail.com'
GMAIL_USER = 'santrashayantan@gmail.com'
GMAIL_PASS = ''//Enter your password!
 
SUBJECT = 'Currency Counter Status'

  
ser = serial.Serial('COM3', 9600)
 
def send_email():
    print("Sending Email")
    smtpserver = smtplib.SMTP("smtp.gmail.com",587)
    smtpserver.ehlo()
    smtpserver.starttls()
    smtpserver.ehlo
    smtpserver.login(GMAIL_USER, GMAIL_PASS)
    header = 'To:' + TO + '\n' + 'From: ' + GMAIL_USER
    header = header + '\n' + 'Subject:' + SUBJECT + '\n'
    print(header)
    msg ='Money counting sucessful. Check LCD screen for total value'
    smtpserver.sendmail(GMAIL_USER, TO, msg)
    smtpserver.close()
    
while True:
    message = ser.readline()
    print(message)
    if message == b'White Color\r\n' :
        send_email()
        print("sending email...")
    time.sleep(0.5)
