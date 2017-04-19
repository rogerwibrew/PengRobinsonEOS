# PengRobinsonEOS
A Peng-Robinson EOS solver for pure components.

A work in progress.  Currently it is a text based solver for pure components.  

The model works and provides compresability given a components Critical Pressure  
Critical Temperature and Accentric Factor.

For Temperatures below the critical Temperature the model gives the compresibility  
for all three solutions of the model.  The smallest value is the liquid, the largest  
is the gas and the middle is meaningless.  Unless the temperature and pressure  
specified lead to a saturated fluid, only one will be stable.  The model will  
be expanded to include fugacity calculation to determine with phase is stable.


To-Do:  
-Calculate fugacity and determine stable phase  
-Library of Components  
-Ability to calculate mixture properties  
-Density calculation   
-GUI  
