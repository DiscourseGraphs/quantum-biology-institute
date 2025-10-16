This repository demonstrates the integration of a [Discourse Graph](https://discoursegraphs.com/) layer on an existing FAIR-first open notes workflow for the [Quantum Biology Institute](https://www.quantumbiology.org/). 

The example data here is from the multi-omics microbial magnetosensitivity project, whose goal is to test the bold hypothesis that *all* life responds to magnetic fields (i.e., non-response *never happens*). 
- The project description is in [prj-multi-omics-microbial-magnetosensitivity](prj-multi-omics-microbial-magnetosensitivity.md). Existing FAIR-first open notes and assets for the two subprojects ([eln-twinleaf-calibration](twinleaf_calibration/1_eln_twinleaf_calibration/eln-twinleaf-calibration.md) and [eln-ecoli-growth-curves](ecoli_growth_curves/1_eln_ecoli_growth_curves/eln-ecoli-growth-curves.md) are in the project folders `twinleaf_calibration` and `ecoli_growth_curves`, with subfolders within each for the different types of assets, e.g., `1_eln`, `2_curated_datasets`, `3_code`, and `4_auxiliary_files`).
- The repo at present uses `myst` to publish the eln/code/data to a publicly viewable JupyterBook, and will later incorporate other publishing scripts/code to simultaneously publish the lab notebooks, data/code, and (hopefully also) results in a FAIR manner (e.g., via DesciNodes).
## What the Discourse Graph layer adds and how

The Discourse Graph is a simple information model of scientific argumentation and processes, that describes how **Experiments** are motivated by the desire to answer or inform scientific unknowns (**Questions**) with generalizable **Claims** (or conclusions or hypotheses) that are justified by sufficient empirical **Evidence**.
![](Discourse%20Graph%20model.png)



This Obsidian vault includes a set of plugins and workflows that demonstrate how this information model can be integrated to support a small set of new workflows that **enhance in-team synthesis and coordination**:
1. **Marking potentially significant observations** that could be the basis of empirical evidence to share and incorporate into a scientific argument or theory about magnetosensivitity, without breaking the flow of the day to day work of documenting procedures and observations in the electronic lab notebook ([demo](https://www.loom.com/share/fc454a0b664b4f99988ac04bb020808a?t=3&sid=f6890caf-5f53-49ce-b29a-22527a59393c))
2. **Revisiting potentially significant observations and formalizing them into discrete empirical evidence "micropublications"** to support within-team sensemaking ([demo](https://www.loom.com/share/fc454a0b664b4f99988ac04bb020808a?t=64&sid=3e1feeb9-81a4-4c15-96de-34d516dd0aa2))
3. **Gathering and visually synthesizing discrete empirical evidence micropublications** into a scientific argument to support reflection and planning of next steps ([demo](https://www.loom.com/share/fc454a0b664b4f99988ac04bb020808a?t=296&sid=d4251348-9b60-4c0f-928c-be913bce52cc)). 

These workflows are designed to add to, rather than detract from or materially change, the existing workflows here of documenting observations in the ELNs, archiving code and data for sharing, and so on.

Critically for QBI's interests in FAIR science, because each scientific element (question, claim, evidence, or experiment) in this new workflow is already a discrete object with its own unique ID and type ID (along with typed relations to other objects), they can be easily published in a FAIR manner. These new workflows thus **enable FAIR micropublishing of scientific context and insights** --- which the Discourse Graph provides --- alongside artifacts like data, code, and lab notebooks.
## Some technical details and how to try

To try out this vault, simply download the vault (via git or zip), open Obsidian, and open this directory as a a vault in Obsidian.
### Folder structure and new files
This vault includes a third top-level project folder, called `results`, to host internal files for tracking and making sense of results. This folder includes:
- a `discourse_graph` subfolder that houses individual empirical results that can each be micropublished in a FAIR manner in the same manner as the other assets (e.g., eln, data/code). Each individual result will have typed links back to the `eln`, and are individually referenceable, providing scientific context for these lab notebooks and their associated code/data.
- an `evidence.base` [Bases](https://help.obsidian.md/bases) query over these empirical results across the (sub)projects in this directory
- a `results-sensemaking-workbench` file that includes this query and can house higher level notes on the project
- a `results-sensemaking.canvas` that can be used in obsidian to collect and make sense of the results 
- an experimental `results-sensemaking` Discourse Graph canvas that enables visual sensemaking with [TLDraw](https://www.tldraw.com/), right in Obsidian.
## Plugins
The vault also includes the following plugins to support the above workflows. Since the vault includes the `.obsidian/` files, these plugins and their settings are already set up.
### Core plugins
- `Bases` for easy querying of Discourse Graph nodes
### Community plugins
- Core functionality
	- `Discourse Graph` - enacts the main workflows for documenting and formalizing discrete empirical observations described above
	- `Datacore` - dependency for `Discourse Graph`
	- `BRAT` - dependency for `Discourse Graph` and `Datacore`
- QOL
	- `Better Search Views` - easier exploration of candidate nodes, with more context
	- `Copy Block Link`- easier linking to specific spots in ELN, esp. entries with candidate evidence
	- `Better Search Views`- came with the example vault
	- `Natural Language Dates`- nice to have
## Other notes

No code or procedures are yet implemented in this vault for FAIR micropublishing, but it should be quite technically feasible to include a publishing script that a) "serializes" whatever FAIR metadata is desired to the published Jupyterbook from this vault, and simultaneously b) publishes desired objects (including Discourse Graph nodes and their associated relations and metadata) to FAIR repositories like DesciNodes via API or similar.

