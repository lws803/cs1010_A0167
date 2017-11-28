class Colour(object):
    '''An RGB colour with red green and blue components'''
    
    def __init__(self,r,g,b):
        '''A new colour with red value r, green value g and blue value b.
        All components are intergers in the range 0 - 255.'''
        self.red = r
        self.green = g
        self.blue = b

    def __str__(self):
        '''Return a string representation of this colour in the
        form of a tuple'''
        return ("{0}, {1}, {2}".format(self.red,self.green,self.blue))

    def __add__(self,other_colour):
        return Colour(min(self.red + other_colour.red , 255),
                      min(self.green + other_colour.green , 255),
                      min(self.blue + other_colour.blue , 255))

    def __sub__(self,other_colour):
        return Colour(min(self.red - other_colour.red , 0),
                      min(self.green - other_colour.green , 0),
                      min(self.blue - other_colour.blue , 0))

    def __eq__(self, other_colour):
        return (self.red == other_colour.red and
                self.green == other_colour.green and
                self.blue == other_colour.blue)
                    
    
    def lightness(self):
        '''Calculate the lightness of this colour'''
        strongest = max(self.red,self.blue,self.green)
        weakest = min(self.red,self.blue,self.green)
        return 0.5* (strongest + weakest) / 255
    
