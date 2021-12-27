def dragEnterEvent(self, event):
        if event.mimeData().hasUrls():
            event.accept()
        else:
            event.ignore()
 
def dropEvent(self, event):
    files = [u.toLocalFile() for u in event.mimeData().urls()]
    for f in files:
        print(f)