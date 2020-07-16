import numpy as np
import matplotlib.pyplot as plt

data_set = np.loadtxt("/home/bmeirose/DATA/nbar_C_dat_100k_McStas_converted_R50_mcpl_copy.out")

index = data_set[:,0]
pdgcode = data_set[:,1]
ekin = data_set[:,2]
weight = data_set[:,10]

x = pdgcode==211
part = pdgcode[x]
ekin_part = ekin[x]
weight_part = weight[x]
print(ekin_part)

fig, ax = plt.subplots()
ax.hist(ekin_part,bins=400, weights=weight_part,range=[0., 1000.])
plt.xlabel("pi+_ekin[MeV]")
plt.show()

#plt.plot(ekin)
#plt.scatter(x,y,z)
#plt.show()

#Options:
#matplotlib.pyplot.hist(x, bins=None, range=None, density=None, weights=None, cumulative=False, bottom=None, histtype='bar', align='mid', 
#orientation='vertical', rwidth=None, log=False, color=None, label=None, stacked=False, normed=None, *, data=None, **kwargs)
