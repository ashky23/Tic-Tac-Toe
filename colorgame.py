import tkinter 
import random
import time
colors=['Purple','Green','White','Orange','Blue','Black','Yellow','Red','Brown','Pink']
score=0
#timeleft=int(input("Enter the time length of the game"))
timeleft=int(input("Enter the time-length of the game!"))
x=timeleft
def startGame(event):
    if timeleft==x:
        countdown()
#        print("hutiya")
    nextcolor()
   
    if timeleft==0:
        label.destroy()
        e.destroy()
        labeler=tkinter.Label(master,text="The End",font=("Helvetica",50))
        labeler.pack()
        scorelabel.config(text="Your Score is "+str(score),font=('Helvetica',20))
        
        timelabel.destroy()#for destroying the timelabel
        instructions.destroy()
#        time.sleep(5)
#        master.destroy()
            
def nextcolor():
    global score
    global timeleft
    if timeleft>0:
        e.focus_set()
        if e.get().lower() == colors[1].lower():#color Matching
            score+=1
        e.delete(0,tkinter.END)#removing the already-written text
        random.shuffle(colors)
        label.config(fg=str(colors[1]),text=str(colors[0]))
        scorelabel.config(text="Score: "+str(score))
def countdown():
    global timeleft
    if timeleft>0:
        timeleft-=1
#        print("hutiya2")
        timelabel.config(text="timeleft: "+str(timeleft))
        timelabel.after(1000,countdown)
#driver Code
master=tkinter.Tk()
master.title("ColorGame")
master.geometry("400x250")
#instructions
instructions=tkinter.Label(master,text="Type in the color of words ,and not the word text!")
instructions.pack()
#End
#Score
scorelabel=tkinter.Label(master,text="Press Enter to start",font=('Times',12))
scorelabel.pack()
#End
#timelabel
timelabel=tkinter.Label(master,text="Time left: "+str(timeleft),font=('Times',12))
timelabel.pack()
#End
#Color
label=tkinter.Label(master,font=('Helvetica',60))
label.pack()
#End
#Entry
e=tkinter.Entry(master)
master.bind('<Return>',startGame)
#print("hutiya3")
e.pack()
e.focus_set()
master.mainloop()
