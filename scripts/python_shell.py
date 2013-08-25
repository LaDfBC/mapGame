from optparse import OptionParser

import os

class NewPython:
    def __init__(self):
        self._className = 'Temp'
        self._fileName = 'temp.py'
        self._filePath = '.'
        self._imports = ''
        self._newVersion = '0.01'
        return
    
    def _parseOptions(self):
        parser = OptionParser(usage="%prog [-f] [-g]", version="%prog 0.01")
        parser.add_option('--class-name', dest='classname', default='Temp', help='Select the name of the class.')
        parser.add_option("--filename", dest='filename', default='temp.py', help='Select the name of the new file.')
        parser.add_option('--file-path', dest='filePath', default='.', help='Select where to create the file. Default: CWD')
        parser.add_option('--imports', dest='imports', default='', help='Select imports, comma delimited. Default: None')
        parser.add_option('--new-version', dest='newVersion', default='0.01', help='Give a version name to the new script.')
        (options, args) = parser.parse_args()
        
        self._className = options.classname
        self._fileName = options.filename
        self._filePath = options.filePath
        self._newVersion = options.newVersion
        self._imports = [i for i in options.imports.split(',')]
        
    def execute(self):
        self._parseOptions()
        self._writeFile()
        return
    
    def _writeFile(self):
        file = open('%s%s%s' % (self._filePath, os.sep, self._fileName), 'w')
        file.write('from optparse import OptionParser\n')
        for currImport in self._imports:
            if currImport != '':
                file.write('import %s\n' % currImport)
        
        file.write('\n')
        file.write('class %s:\n' % self._className)
        file.write('\tdef __init__(self):\n')
        file.write('\t\treturn\n\n')
        file.write('\tdef _parseOptions(self):\n')
        file.write('\t\tparser = OptionParser(usage=\"prog [-f] [-g]\", version=\"prog %s\")\n' % self._newVersion)
        file.write('\t\t(options, args) = parser.parse_args()\n')
        file.write('\n\t\treturn\n\n')
        file.write('\tdef execute(self):\n')
        file.write('\t\tself._parseOptions()\n')
        file.write('\t\treturn\n\n')
        file.write('if __name__ == \"__main__\":\n')
        file.write('\t%s().execute()\n' % self._className)
        
        file.close()
        return
        
        
if __name__ == '__main__':
    NewPython().execute()    
