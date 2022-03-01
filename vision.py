import itertools
import time

from networktables import NetworkTablesInstance

ntinst = NetworkTablesInstance.getDefault()
# ntinst.initialize()

# ntinst.startClientTeam(830)
ntinst.startClient(('localhost', 1735))

table = ntinst.getTable("Shuffleboard")
dashboard = table.getSubTable("vision")

for i in itertools.count(1):
    dashboard.putNumber("test", i)
    print('wrote', i)
    time.sleep(1)
    print('read', dashboard.getNumber('test-robot', 0))
