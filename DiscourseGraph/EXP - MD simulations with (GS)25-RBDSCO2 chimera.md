---
nodeTypeId: node_Qbdr-LbBCb_WjPFNTnjTX
targetQuestionOrHyp: "[[QUE - How do inert IDRs affect binding affinity?]]"
rel_5nnUOb6wBzlAwAF2Wk-ts:
  - "[[RES - repeated association and dissociation events between (rU)25 and the (GS)25-RBD constructs.md]]"
  - "[[RES - (GS)25-RBD suppressed RNA binding compared to the RBD alone.md]]"
project: "[[PRJ - Molecular determinants of evolutionary conservation in disordered protein regions]]"
status: Completed
---
# Resources

Protocol:
Git repo:
# Results

![[Results.base#Results from this Experiment]]
# Todos

# Log

## [[2022-09-22]]

New result! Discussed with team, looks like [[RES - (GS)25-RBD suppressed RNA binding compared to the RBD alone]]

![[CleanShot 2025-09-11 at 16.55.46.png]]

## [[2022-09-18]]

Discussed plots with team. Think we can say that there's [[RES - repeated association and dissociation events between (rU)25 and the (GS)25-RBD constructs]]

## [[2022-09-17]]

(GS)25 simulation completed! 

Plotted distances between (GS)25-RBD and (rU)25 COM over simulation time course.

To make distance threshold, fitted the COM distributions with dual Gaussians.
Then define threshold based on intersection that minimizes overlap of the distributions
NOTE: cutoff distance varies based on the size of the protein and RNA

Then plotted distance threshold to delineate the bound and unbound frames

![[CleanShot 2025-09-11 at 16.14.05.png]]
## [[2022-09-07]]

Successfully replaced NTDSCO2 with a length-matched GS repeat – (GS)25. (GS)25-RBDSCO2 chimera ready for simulation experiment!

![[CleanShot 2025-09-11 at 16.12.52.png]]