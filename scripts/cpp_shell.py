from optparse import OptionParser

import datetime
import os

class NewCpp:
    def __init__(self):
        self._className = 'Temp'
        self._fileName = 'temp.py'
        self._filePath = '.'
        self._includes = []
        self._std = []
        return
    
    def _parseOptions(self):
        parser = OptionParser(usage="%prog [-f] [-g]", version="%prog 0.01")
        parser.add_option('--class-name', dest='classname', default='Temp', help='Select the name of the class.')
        parser.add_option("--filename", dest='filename', default='temp.py', help='Select the name of the new file.')
        parser.add_option('--file-path', dest='filePath', default='..%s' % os.sep, help='Select where to create the file. Default: CWD')
        parser.add_option('--includes', dest='includes', default='', help='Select includes, comma delimited, no "<>". Default: None')
        parser.add_option('--std', dest='std', default='', help='Select using std:: headers, comma delimited.')
        (options, args) = parser.parse_args()
        
        self._className = options.classname
        self._fileName = options.filename
        self._filePath = options.filePath
        self._includes = [i for i in options.includes.split(',')]
        self._std = [s for s in options.std.split(',')]
        
    def execute(self):
        self._parseOptions()
        self._writeFile()
        return
    
    def _writeFile(self):
        file = open('%s%s%s' % (self._filePath, os.sep, self._fileName), 'w')
        file.write('//Programmer: George Mausshardt\n')
        file.write('//File: %s\n' % self._fileName)
        file.write('//Generated on: %s\n\n' % str(datetime.datetime.now().strftime("%A %B %d, %Y")))
        for currInclude in self._includes:
            if currInclude != '':
                file.write('#include <%s>\n' % currInclude)
        
        file.write('\n')
        for currStd in self._std:
            if currStd != '':
                file.write('using std::%s;\n' % currStd)
    
        file.write('\n\n')
        file.write('class %s\n' % self._className)
        file.write('{\n')
        file.write('  public:\n\n')
        file.write('  private:\n\n')
        file.write('};')
        
        file.close()
        return
    
NewCpp().execute()
