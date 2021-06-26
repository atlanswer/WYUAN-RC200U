import ctypes
from msl.loadlib import Server32

class OurMifare(Server32):
    def __init__(self, host, port, **kwargs):
        super().__init__("OUR_MIFARE", "windll", host, port, kwargs)

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
        return self.lib.pcdbeep(ctypes.c_ulong(xms))
