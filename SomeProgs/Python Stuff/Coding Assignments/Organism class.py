class Organism():
    '''A living thing that lives in a tide pool'''
    
    def __init__(self,name,x,y):
        '''A living thing that is at location (x,y) in the tide pool.'''

        self.name = name
        self.x = x
        self.y = y

    def __str__(self):
        '''Return a string representation of this Organism'''
        return("{0},[{1},{2}]".format(self.name,self.x,self.y))

    def can_eat(self,food):
        '''Report whether this Organism can eat the given food. Since we don't
        know anything about what a generic organism eats, this always returns
        false.'''
        return False

    def move(self):
        '''Ask the Organism to move. By default, this does nothing,
        sinc we don't know anything about how fast or how far a generic
        organism would move'''
        return

class Arthropod(Organism):
    '''An arthropod with a fixed number of legs'''
    def __init__(self, name, x, y, legs):
        '''An orthropod with the given number of legs that exists at location
        (x,y) in the tide pool.'''

        Organism.__init__(self, name, x, y)
        self.legs = legs

    def __str__(self):
        '''Returns a string representation of this Arthropod'''
        return("{0},{1},[{2},{3}]".format(self.name,self.legs,self.x,self.y))

    def is_decapod(self):
        '''Return True is this Arthropod is a decapod'''
        return (self.legs == 10)

    def leg_count(self):
        '''Rethrn the number of legs this Arthropod possesses'''
        return self.legs

    
