from firebase import firebase

url = 'https://alarm-9363f.firebaseio.com/'
firebase = firebase.FirebaseApplication(url)
result = firebase.put("/Alarm","Value",1)
print(result)

print("Goodbye, World!")