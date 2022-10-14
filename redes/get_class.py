<<<<<<< HEAD
# get class from a ip
def get_class_ip(ip):
    ip = ip.split('.')
    if int(ip[0]) <= 127:
        return 'A'
    elif int(ip[0]) <= 191:
        return 'B'
    elif int(ip[0]) <= 223:
        return 'C'
    elif int(ip[0]) <= 239:
        return 'D'
    elif int(ip[0]) <= 255:
        return 'E'
    else:
        return 'Invalid IP'
def get_red_direction(ip):
    


    
print(get_class_ip('216.14.55.137'))
print(get_class_ip('123.1.1.15'))
print(get_class_ip('150.127.221.244'))
=======
# get class from a ip
def get_class_ip(ip):
    ip = ip.split('.')
    if int(ip[0]) <= 127:
        return 'A'
    elif int(ip[0]) <= 191:
        return 'B'
    elif int(ip[0]) <= 223:
        return 'C'
    elif int(ip[0]) <= 239:
        return 'D'
    elif int(ip[0]) <= 255:
        return 'E'
    else:
        return 'Invalid IP'
def get_red_direction(ip):
    


    
print(get_class_ip('216.14.55.137'))
print(get_class_ip('123.1.1.15'))
print(get_class_ip('150.127.221.244'))
>>>>>>> 1b27c5a22e6f63eaf3e94606221b6f6299e36445
print(get_class_ip('194.125.35.199'))