import warnings
import awkward as ak
import numpy as np
import pandas as pd
import pickle
import array
import copy
import ROOT as rt
import root_numpy as rtnp
import hist as hs
from hist.intervals import ratio_uncertainty
from coffea import processor
from coffea.nanoevents.methods import vector, candidate
from numba import jit
from coffea.nanoevents import BaseSchema
import mplhep as hep
import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
from datetime import date
import matplotlib.pyplot as plt
import matplotlib
import gc
import os

today = date.today()
plt.style.use(hep.style.CMS)
# base = "/uscms/home/ahayrape/nobackup/BToPhiK_py/"


def deltaR(obj1_eta, obj2_eta, obj1_phi, obj2_phi):
    obj1 = {"eta":obj1_eta, "phi":obj1_phi}
    obj2 = {"eta":obj2_eta, "phi":obj2_phi}
    deltaEta = abs(obj1.eta - obj2.eta)
    deltaPhi = np.arctan2(np.sin(obj1.phi - obj2.phi), 
                          np.cos(obj1.phi - obj2.phi))
    deltaR = np.sqrt(deltaEta**2 + deltaPhi**2)
    return deltaR

