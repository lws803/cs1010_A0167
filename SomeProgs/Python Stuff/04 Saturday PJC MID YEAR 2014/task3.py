class Node(object):
    def __init__ (self,coeff = 0.0,expon = 0,ptr = None):
        self.coeff = float(coeff)
        self.expon = int(expon)
        self.ptr = ptr

    def get_coeff(self):
        return self.coeff
    def set_coeff(self,newcoeff):
        self.coeff = newcoeff

    def get_expon(self):
        return self.expon
    def set_expon(self,newexpon):
        self.expon = newexpon

    def get_ptr(self):
        return self.ptr
    def set_ptr(self,newptr):
        self.ptr = newptr

    def display(self):
        text = ''
        text = str(self.coeff) + "x^" + str(self.expon)
        return text

class Polynomial(object):
    def __init__ (self):
        self.start = Node()
        self.length = 0

    def display(self):
        text = ''
        number = self.length
        current = self.start.get_ptr()
        while number != 0:
            if number == 1:
                text += current.display()
            else:
                text += current.display() + " + "
            current = current.get_ptr()
            number -= 1
        return text

    def isEmpty(self):
        return self.length == 0

    def length(self):
        return self.length

def createPolynomial():
    expon = -1
    poly = Polynomial()
    print("Enter the polynomial from the highest exponent.")
    while expon != 0:
        coeff = eval(input("Enter the coefficient: "))
        expon = eval(input("Enter the exponent: "))
        newnode = Node(coeff,expon)

        if poly.isEmpty():
            poly.start.set_ptr(newnode)
            poly.length += 1
        else:
            current = poly.start.get_ptr()
            while current.get_ptr() != None:
                current = current.get_ptr()
            current.set_ptr(newnode)
            poly.length += 1
    return poly

def add2Polynomials(p1,p2):
    p3 = Polynomial()
    current1 = p1.start.get_ptr()
    current2 = p2.start.get_ptr()
    while current1.get_ptr() != None or current2.get_ptr() != None:
        if current1.expon > current2.expon:
            newnode = Node(current1.coeff,current1.expon,None)
            current1 = current1.get_ptr()
            
        elif current1.expon < current2.expon:
            newnode = Node(current2.coeff,current2.expon,None)
            current2 = current2.get_ptr()
            
        elif current1.expon == current2.expon:
            newcoeff = current1.coeff + current2.coeff
            newexpon = current1.expon
            newnode = Node(newcoeff,newexpon,None)
            current1 = current1.get_ptr()
            current2 = current2.get_ptr()            
            
        if p3.isEmpty():
            p3.start.set_ptr(newnode)
            p3.length += 1
        else:
            current = p3.start.get_ptr()
            while current.get_ptr() != None:
                current = current.get_ptr()
            current.set_ptr(newnode)
            p3.length += 1

    newcoeff = current1.coeff + current2.coeff
    newexpon = current1.expon
    newnode = Node(newcoeff,newexpon,None)

    current = p3.start.get_ptr()
    while current.get_ptr() != None:
        current = current.get_ptr()
    current.set_ptr(newnode)
    p3.length += 1
        
    return p3

def main():
    p1 = createPolynomial()
    print(p1.display())
    print()
    p2 = createPolynomial()
    print(p2.display())
    print()
    p3 = add2Polynomials(p1,p2)
    print(p3.display())

main()
    
