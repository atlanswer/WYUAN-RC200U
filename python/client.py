import os
from msl.loadlib import Client64

class Wyuan(Client64):
    def __init__(self):
        super().__init__(module32="server", append_sys_path=os.path.dirname(__file__))
    
    def pcdbeep(self, xms):
        """Make the card reader beep.

        Parameters
        ----------
        xms : :class:`int`
            Beep duration.

        Returns
        -------
        :class:`int`
            Status code.
        """
        return self.request32("pcdbeep", xms)
