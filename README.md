This repository demonstrates the integration of a [Discourse Graph](https://discoursegraphs.com/) layer on an existing FAIR-first open notes workflow for the [Quantum Biology Institute](https://www.quantumbiology.org/). The example data here is from the multi-omics microbial magnetosensitivity project, whose goal is to test the bold hypothesis that *all* life responds to magnetic fields (i.e., non-response *never happens*).

The project description is in [prj-multi-omics-microbial-magnetosensitivity](prj-multi-omics-microbial-magnetosensitivity.md). Existing FAIR-first open notes and assets for the two subprojects ([eln-twinleaf-calibration](twinleaf_calibration/1_eln_twinleaf_calibration/eln-twinleaf-calibration.md) and [eln-ecoli-growth-curves](ecoli_growth_curves/1_eln_ecoli_growth_curves/eln-ecoli-growth-curves.md) are in the project folders `twinleaf_calibration` and `ecoli_growth_curves`, with subfolders within each for the different types of assets, e.g., `1_eln`, `2_curated_datasets`, `3_code`, and `4_auxiliary_files`).

The repo uses `myst` to publish the eln/code/data to a publicly viewable JupyterBook, and will later incorporate other publishing scripts/code to simultaneously publish the lab notebooks, data/code, and (hopefully also) results in a FAIR manner (e.g., via DesciNodes).

To demonstrate how a Discourse Graph layer can facilitate in-team synthesis and coordination *and* make the resulting shared FAIR-ified eln/data/artifacts more interpretable and reusable, we've added a third main project folder `results` to host internal files for tracking and making sense of results. This folder includes:
- a `discourse_graph` subfolder that houses individual empirical results that can each be micropublished in a FAIR manner in the same manner as the other assets (e.g., eln, data/code). Each individual result will have typed links back to the `eln`, and are individually referenceable, providing scientific context for these lab notebooks and their associated code/data.
- an `evidence.base` query over these empirical results across the (sub)projects in this directory
- a `results-sensemaking-workbench` file that includes this query and can house higher level notes on the project
- a `results-sensemaking.canvas` that can be used in obsidian to collect and make sense of the results 



