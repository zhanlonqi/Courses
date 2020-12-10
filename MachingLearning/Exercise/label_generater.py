import sys
labels=['duck1','cannon2','car3','cat4','anacin5','car6','harmer7','medicine8','tylenol9','vaseline10','mashroom11','cup12','pig13','14','15','medicine16','cup17','cup18','car19','20']
for i in range(1,len(labels)+1):
    for j in range(72):
        f=open(sys.path[0]+'/label/obj%d'%i+'__%d'%j+'.xml',"a")
        f.seek(0)
        f.truncate()
        origin=open(sys.path[0]+'/../obj10__0.xml')
        count=0
        for line in origin.readlines():
            if(count==2):
                f.write('	<filename>obj%d'%i+'__%d.png</filename>\n'%j)
            elif (count==3):
                f.write('	<path>'+sys.path[0]+'/coil-20-proc/obj%d'%i+'__%d.png'%j+'</path>\n')
            elif(count==14):
                f.write('		<name>%s</name>\n'%labels[i-1])
            else:
                f.write(line)
            count+=1
        f.close()