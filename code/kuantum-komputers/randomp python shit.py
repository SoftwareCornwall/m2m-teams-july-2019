users = ["will", "ok", "roberto", "nou"]
LoggedIn=False
while not LoggedIn:
    user = input("Username>> ")
    for i in range(len(users)-1):
        if user == users[i]:
            password = input("Password>> ")
            if password == users[i+1]:
                print("Correct login details")
                LoggedIn=True
        else:
            print("User details wrong")
