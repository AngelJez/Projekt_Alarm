import smtplib
from datetime import datetime

now = datetime.now() #Obecna data
data_string = now.strftime("%d/%m/%Y %H:%M:%S")  #Data jako string
 
server_gmail = 'smtp.gmail.com'
port_gmail = 587 
uzytkownik_gmail = 'angelika.jezierska@gmail.com'
haslo_gmail = 'alleswasihrtut94'

odbiorca = 'angelika.jezierska@gmail.com'
temat = "----------Alarm----------"
zawartosc = data_string + "--> Alarm zostal uruchomiony"
 
class KlasaEmail:
    def sendmail(self, recipient, subject, content):
         
        #Naglowek
        headers = ["From: " + uzytkownik_gmail, "Subject: " + subject, "To: " + recipient,
                   "MIME-Version: 1.0", "Content-Type: text/html"]
        headers = "\r\n".join(headers)
 
        #Polaczenie z serwerem
        sesja = smtplib.SMTP(server_gmail, port_gmail)
        sesja.ehlo()
        sesja.starttls()
        sesja.ehlo()
 
        #Logowanie
        sesja.login(uzytkownik_gmail, haslo_gmail)
 
        #Wyslanie maila
        sesja.sendmail(uzytkownik_gmail, recipient, headers + "\r\n\r\n" + content)

        #Zakonczenie sesji
        sesja.quit
 
sender = KlasaEmail()

sender.sendmail(odbiorca, temat, zawartosc) 