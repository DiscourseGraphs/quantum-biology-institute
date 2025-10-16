Obsidian Canvas --> [[results-sensemaking.canvas|results-sensemaking]]
DG Canvas: [results-sensemaking](../Discourse%20Canvas/results-sensemaking.md)
# Results so far

## Candidates
```query
tag:#evd-candidate
-path:build/
```

## Formalized

Note: Anything in status "to share" will be rolled up into `myst.yml` for publishing on JupyterBook and DeSci Nodes.

![[evidence.base]]

# Todos

- [ ] probably good idea to systematically document robustness to the variations
	- see note for 10-15 below
# Notes

## [2025-10-15](2025-10-15)

summary so far from the ecoli experiments....

seems like we have a fairly robust result across multiple replicates: [EVD - Hypomagnetic fields extended the lag phase of E coli growth, beginning with growth-phase cells](discourse_graph/EVD%20-%20Hypomagnetic%20fields%20extended%20the%20lag%20phase%20of%20E%20coli%20growth,%20beginning%20with%20growth-phase%20cells.md)

seems like we may also have a similar, but less stable observation for stationary phase cells:
- we have an observation of a more pronounced lag phase effect: [EVD - Hypomagnetic fields extended the lag phase of E coli growth, beginning with stationary-phase cells](discourse_graph/EVD%20-%20Hypomagnetic%20fields%20extended%20the%20lag%20phase%20of%20E%20coli%20growth,%20beginning%20with%20stationary-phase%20cells.md)
- but in these replicates we have a "negative" (no diff in growth rate) result in one run (could be too high OD though) [EVD - Stationary phase E coli showed no difference in growth rate under hypomagnetic conditions](EVD%20-%20Stationary%20phase%20E%20coli%20showed%20no%20difference%20in%20growth%20rate%20under%20hypomagnetic%20conditions)

we've also tested for variations:
- light/dark
- polarity of magnet
- air availability (sealed vs gas exchange)

from the twinleaf calibration work, we've also got some neat results around the effects of the degaussing procedure. it's maybe not the scientific focus per se, but could be a really useful methodological result to share.

overall, let's decide which of these we want to formalize and publish.
then also maybe open q whether/how we want to combine these into a single result