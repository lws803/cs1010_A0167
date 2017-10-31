import datetime

last_id = 0    #Store the next available id for all notes

class Note(object):
    '''Represent a note in the notebook.
    Match against a string in seachers and stores tags for each note.'''

    def __init__(self,memo, tags = ''):
        '''Initialise a note with memo and optional space-seperated tags.
        Automatically set the note's creation date and a unique id.'''
        self.memo = memo
        self.tags = tags
        self.creation_date = datetime.date.today()

        global last_id
        last_id += 1
        self.id = last_id

    def match(self,item):
        '''Determine if this note matches the item.'''
        return (item in self.memo) or (item in self.tags)

    def __str__(self):
        text = ''
        text += "Memo: {0}\n".format(self.memo)
        text += "Tags: {0}\n".format(self.tags)
        text += "Creation Date: {0}\n".format(self.creation_date)
        text += "Note ID: {0}".format(self.id)
        return text

class Notebook(object):
    '''Represent a collection of notes that can be tagged, modified and
    searched'''

    def __init__(self):
        '''initialise a notebook with an empty list'''
        self.notes = []

    def add_new_note(self,memo,tags=''):
        '''Create a new note and add it to the list'''
        self.notes.append(Note(memo,tags))

    def search(self,item):
        '''Find all the notes that match the given item'''
        foundList = []
        for i in self.notes:
            if i.match(item):
                foundList.append(i)
        return foundList

    def modify_memo(self, note_id, memo):
        '''Find the note with the given id and change its memo to
           the given value'''
        found_note = False
        for note in self.notes:
            if note.id == note_id:
                note.memo = memo
                found_note = True

        if found_note == False:
            return "Unable to find note."
        else:
            return "Changes have been saved."
            

    def modify_tags(self,note_id,tags):
        '''Find the note with the given id and change its tags to the
           given value.'''

        found_note = False
        for note in self.notes:
            if note.id == note_id:
                note.tags = tags
                found_note = True

        if found_note == False:
            return "Unable to find note."
        else:
            return "Changes have been saved."

    def __str__(self):
        text = ''
        for item in self.notes:
            text += "Memo: {0}\n".format(item.memo)
            text += "Tags: {0}\n".format(item.tags)
            text += "Creation Date: {0}\n".format(item.creation_date)
            text += "Note ID: {0}\n".format(item.id)
        return text
