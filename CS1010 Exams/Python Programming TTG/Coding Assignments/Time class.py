class Time(object):
    '''Records time of day in the 24 hour format (hh:mm:ss)'''
    
    def __init__(self,hour,minute,second):
        '''Input the time in the format hour:minute:second (24 hour)'''
        self.hour = hour
        self.minute = minute
        self.second = second

    def __str__(self):
        '''This prints out the Time object in the form of hour:minute:second'''
        return("{0}:{1}:{2}".format(self.hour,self.minute,self.second))

    def print_time(self):
        '''This prints out the Time object in the form of hour:minute:second'''
        return("{0}:{1}:{2}".format(self.hour,self.minute,self.second))

    def valid_time(self):
        '''This validates the hour, minute and second of the Time object.'''
        if self.hour.isalpha() or self.minute.isalpha() or self.second.isalpha():
            return False

        if int(self.hour) >= 0 and int(self.hour) < 24:
            if int(self.minute) >= 0 and int(self.minute) < 60:
                if int(self.second) >= 0 and int(self.second) < 60:
                    return True
        else:
            return False

    def time_to_int(self):
        '''This function converts a Time object to integers.'''
        minutes = int(self.hour) * 60 + int(self.minute)
        seconds = minutes * 60 + int(self.seconds)
        return seconds

    def int_to_time(self,time):
        '''This function converts integers into a Time Object.'''
        minutes = time // 60
        seconds = time % 60
        hours = minutes // 60
        new_minute = minutes % 60
        
        time = Time(str(hours), str(new_minute) , str(seconds))
        
        return time

    def is_after(self, other_time):
        '''This function compares time and outputs true
        if self is after other time'''

        if int(self.hour) > int(other_time.hour):
            return True
        else:
            if int(self.minute) > int(other_time.minute):
                return True
            else:
                if int(self.second) > int(other_time.second):
                    return True
                else:
                    return False

    def add_time(self, other_time):
        '''Adds up 2 time objects and assigns the result to another Time object.'''
        minute = int(self.minute) + int(other_time.minute)
        get_second = (int(self.second) + int(other_time.minute)) % 60
        get_minute = minute + (int(self.second) + int(other_time.minute)) // 60
        get_hour = int(self.hour) + int(other_time.hour) + minute // 60

        new_time = Time(str(get_hour),str(get_minute),str(get_second))
        return new_time

    def sub_time(self, other_time):
        '''Subtract 2 time objects and assigns the result to another Time object.'''
        second = min(int(self.second) - int(other_time.second) , 0) 
        minute = min(int(self.minute) - int(other_time.minute) , 0)
        hour = min(int(self.hour) - int(other_time.hour) , 0)

        new_time = Time(str(hour),str(minute),str(second))
        return new_time

    def increment(self, increment):
        '''Adds 'increment' to the Time object in the seconds place. Increases minutes and hours if increment
        is larger than 60 or 3600.'''
        seconds = (int(self.second) + increment) % 60
        remainder = (int(self.second) + increment)// 60
        minutes = (int(self.minute) + remainder) % 60
        remainder = (int(self.minute) + remainder) // 60
        hours = int(self.hour) + remainder

        new_time = Time(str(hours),str(minutes),str(seconds))
        return new_time

    def mul_time(self, number):
        '''Multiplies Time object by number.'''
        seconds = (int(self.second) * number) % 60
        remainder = (int(self.second) * number) // 60
        minutes = ((int(self.minute) * number) + remainder )% 60
        remainder = ((int(self.minute) * number) + remainder )// 60
        hours =(int(self.hour) * number) + remainder

        new_time = Time(str(hours),str(minutes),str(seconds))
        return new_time
