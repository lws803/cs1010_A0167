#task 2

def validate_card(card_no):
    visa_flag = False
    visa = ["4"]
    visa_length = [13,16]
    if card_no[0] in visa and len(card_no) in visa_length:
        visa_flag = True
    if not visa_flag:
        master = ['51','52','53','54','55']
        if card_no[0:2] in master and len(card_no) == 16:
            pass
        else:
            return "Not valid card, not visa or master (length/start digits)"

    values = list(card_no)
    for i in range(len(values)):
        if i % 2 == 0:
            values[i] = int(values[i]) * 2
            values[i] = str(values[i])

    newnumbers = ''
    for i in values:
        newnumbers += i

    total = 0
    for i in newnumbers:
        total += int(i)
        
    if total % 10 == 0:
        return True
    else:
        return False

#print(validate_card("4485315158822849"))

#task 2.2

def generate_id(n):
    valid_ID = []
    visa = '4'
    bankID = '26569'
    checkdigit = '3'
    
    increase = 0
    while len(valid_ID) != n:
        userid = str(increase)
        while len(userid) != 6:
            userid = '0' + userid
        print(userid)

        tempid = visa + bankID + userid + checkdigit
        valid = validate_card(tempid)
        if valid:
            valid_ID.append(tempid)
            print(True)
        increase += 1

    print(valid_ID)

generate_id(20)
            
        
    




















    
    
