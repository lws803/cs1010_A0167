class Rectangle1():
    '''Represent a rectangular section of a image'''
    def __init__(self, x0,y0,x1,y1):
        '''Create a rectangle with a non zero area.
        (x0,y0) is the lower left corner
        (x1,y1) is the top right corner'''
        self.x0 = x0
        self.y0 = y0
        self.x1 = x1
        self.y1 = y1

    def area(self):
        '''Returns the area of the rectangle'''
        return (self.x1 - self.x0) * (self.y1 - self.y0)

    def contains(self,x,y):
        '''Return True if (x,y) is inside the rectangle, and False otherwise'''
        return self.x0 <= x <= self.x1 and self.y0 <= y <= self.y1

    def get_min_x(self):
        '''Return the minimum X coordinate'''
        return self.x0

    def get_min_y(self):
        '''Return the minimum Y coordinate'''
        return self.y0

    def get_max_x(self):
        '''Return the maximum X coordinate'''
        return self.x1

    def get_max_y(self):
        '''Return the maximum Y coordinate'''
        return self.y1

class Rectangle2():
    '''Represent a rectangular section of a image'''
    
    def __init__(self, x0, y0, width, height):
        '''Create a rectangle with a non zero area.
        (x0,y0) is the lower left corner
        width and height the X and Y extent.'''
        self.x0 = x0
        self.y0 = y0
        self.width = width
        self.height = height

    def area(self):
        '''Returns the area of the rectangle'''
        return self.width * self.height

    def contains(self, x, y):
        '''Return True ig (x,y) is inside the rectangle, and False otherwise'''
        return self.x0 <= x and self.x0 + self.width >= x and self.y0 <= y and self.y0 + self.height >= y

    def get_min_x(self):
        '''Return the minimum X coordinate'''
        return self.x0

    def get_min_y(self):
        '''Return the minimum Y coordinate'''
        return self.y0

    def get_max_x(self):
        '''Return the maximum X coordinate'''
        return self.x0 + self.width

    def get_max_y(self):
        '''Return the maximum Y coordinate'''
        return self.y0 + self.height

class square1(Rectangle1):

    def check_square(self):
        return (self.x1 - self.x0) == (self.y1 - self.y0)
