class Tower(object):  
    def __init__(self, i):  
        self.disks = []  
    def add(self, d):  
        if len(self.disks) > 0 and self.disks[-1] <= d:  
            print("Error placing disk %s" % d)  
        else:  
            self.disks.append(d)  
    def move_top_to(self, t):  
        if len(self.disks) > 0:  
            t.disks.append(self.disks.pop(-1))  
    def move_disks(self, n, destination, buffer):  
        if n == 0:  
            return  
        if n == 1:  
            self.move_top_to(destination)  
        else:  
            self.move_disks(n - 1, buffer, destination)  
            self.move_top_to(destination)  
            buffer.move_disks(n - 1, destination, self)  
    def get_disks(self):  
        return self.disks  
