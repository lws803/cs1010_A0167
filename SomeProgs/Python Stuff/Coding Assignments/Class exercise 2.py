class Country(object):
    def __init__(self, name, population,area):
        self.name = name
        self.population = population
        self.area = area

    def is_larger(self, other_country):
        return self.area > other_country.area

    def population_density(self):
        density = self.population / self.area
        return density

    def __str__ (self):
        return('{0} has a population of {1} and is {2} square km.'.format(self.name, self.population, self.area))

class Continent(Country):

    def __init__(self, name, countries):
        self.name = name
        self.countries = countries

    def total_population(self):
        total_pop = 0
        for country in self.countries:
            total_pop = country.population + total_pop

        return(total_pop)

    def __str__(self):
        text = ''
        text = self.name + "\n"

        for country in north_america.countries:
            text = text + "{} has a population of {} and is {} in square km. \n".format(country.name,country.population,country.area)

        return text

class Person(object):
    '''A class used to catagorise a person in general.'''
    def __init__(self,name,age,sex,contact):  
        '''Initialise name, age, sex and contact number of the person.'''
        self.name = name
        self.age = age
        self.sex = sex
        self.contact = contact

    def __str__(self):
        '''Prints out person particulars in the format of Name, Age, Sex, Contact.'''
        return ("Name: {0},Age:{1},Sex:{2},Contact:{3}".format(self.name,self.age,self.sex,self.contact))

    def set_favourite_food(self):
        '''Stores the person's favourite food.'''
        food = input("Enter Favourite food: ")
        self.food = food

    def get_favourite_food(self):
        '''Returns the person's favourite food.'''
        return self.food

class Student(Person):
    '''A class that inherits the Person class attributes and methods and adds other attributes and methods.'''
    def __init__(self,name,age,sex,contact, school = None):
        '''Initialises Person class and attribute school.'''
        self.school = school
        Person.__init__(self,name,age,sex,contact)

    def __str__(self):
        '''Prints out person particulars in the format of Name, Age, Sex, Contact, School'''
        return ("Name: {0},Age:{1} ,Sex:{2} ,Contact:{3} , School:{4}".format(self.name,self.age,self.sex,self.contact,self.school))

    def set_pocket_money(self):
        '''Stores the amount of pocket money the student receives.'''
        money = input("Enter amount of pocket money: ")
        self.pocket_money = money

    def get_pocket_money(self):
        '''Returns the amount of pocket money the students recieves.'''
        return self.pocket_money

    def set_school(self):
        school = input("Enter school attending: ")
        self.school = school
        
class Book(object):
    def __init__(self,title,authors,publisher,price,isbn):
        self.title = title
        self.authors = authors
        self.publisher = publisher
        self.price = price
        self.isbn = isbn

    def __str__(self):
        return("Title: {0}, Author: {1}, Publisher: {2}, Price: {3}, ISBN: {4}".format(self.title,self.authors,self.publisher,self.price,self.isbn))

    def num_authors(self):
        no_authors = 0
        for author in self.authors:
            no_authors += 1

        return no_authors

    def __eq__(self, other_book):
        return self.isbn == other_book.isbn

class ebook(Book):
    def __init__(self,title,authors,publisher,price,isbn,device,file_format,pages):
        Book.__init__(self,title,authors,publisher,price,isbn)
        self.file_format = file_format
        self.device = device
        self.pages = pages

    def __str__(self):
        return("Title: {0}, Author: {1}, Publisher: {2}, Price: {3}, ISBN: {4}, Device: {5}, File format: {6}, pages: {7}".format(self.title,self.authors,self.publisher,self.price,self.isbn,self.device,self.file_format,self.pages))
