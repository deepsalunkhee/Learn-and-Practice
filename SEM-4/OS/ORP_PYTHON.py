from tkinter import *

# Create the main window
window = Tk()
window.title(" Banker's Algorithm ")

# Set the window size to the maximum screen size
# width = window.winfo_screenwidth()
# height = window.winfo_screenheight()
window.geometry(f"500x500")
window.configure(bg='lightblue')
Label( text='Enter the number of Processes').pack()
prc = Entry()
prc.pack()

Label( text='Enter the number of Resources').pack()
rcs = Entry()
rcs.pack()

def Imput():
    NoOfProcesses = int(prc.get())
    NoOfResources = int(rcs.get())

    Label( text=f'Max Available Resources for {NoOfResources} processes', bg='lightblue', fg='#f00').pack()
    ar = Entry()
    ar.pack()

    AlWd = []
    for _ in range(NoOfProcesses):
        Label( text=f'Allocated Resource for Process {_+1}', bg='lightblue', fg='#f00').pack()
        temp = Entry()
        temp.pack()
        AlWd.append(temp)

    MaxWd = []
    for _ in range(NoOfProcesses):
        Label( text=f'Max Resource for Process {_+1}', bg='lightblue', fg='#f00').pack()
        temp = Entry()
        temp.pack()
        MaxWd.append(temp)

    def Compute():
        processes = int(prc.get())
        resources = int(rcs.get())
        max_resources = [int(x) for x in ar.get().split(' ')]
        currently_allocated = [[int(x) for x in _.get().split(' ')] for _ in AlWd]
        max_need = [[int(x) for x in _.get().split(' ')] for _ in MaxWd]

        allocated = [0] * resources
        for i in range(processes):
            for j in range(resources):
                allocated[j] += currently_allocated[i][j]
        output = f"\nTotal allocated resources : {allocated}"

        available = [max_resources[i] - allocated[i] for i in range(resources)]
        # print(f"total available resources : {available}\n")
        output += f"\nTotal available resources : {available}\n"

        output += "\nMax needs of resources: \n"
        for o in max_need:
            output += str(o)
            output += '\n'
        running = [True] * processes
        count = processes
        while count != 0:
            safe = False
            for i in range(processes):
                if running[i]:
                    executing = True
                    for j in range(resources):
                        if max_need[i][j] - currently_allocated[i][j] > available[j]:
                            executing = False
                            break
                    if executing:
                        output += f"\nprocess {i + 1} is executing"
                        # print(f"process {i + 1} is executing")
                        running[i] = False
                        count -= 1
                        safe = True
                        for j in range(resources):
                            available[j] += currently_allocated[i][j]
                        break
            if not safe:
                output += "\nProcesses are in an unsafe state."
                # print("the processes are in an unsafe state.")
                break

            output += f"\nProcess is in a safe state.\nAvailable resources : {available}\n"
         

        X = Label( text=output)
        X.pack()

    Compute = Button(text='Calculate', command = Compute)
    Compute.pack()
Imput = Button( text='Enter', command = Imput)
Imput.pack()
# Run the event loop
window.mainloop()
