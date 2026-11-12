# CrossInk v2.0.0 RC2 — Original X4 Myanmar Port

## Provenance

- Base: user-provided `v2.0.0(1).zip`, root `CrossInk-release-v2.0.0/`, version `2.0.0`.
- Integration: earlier CrossInk Myanmar X4 migration kit; four RC2 code/configuration patches **successfully applied with `git apply --check`** to this uploaded source.
- Font: shaping-only Myanmar TTF (63,000 bytes), bitmap glyph atlas (96,196 bytes).
- SD-card language file: `sdcard/.crossink/languages/myanmar.yaml`.
- Build target: original X4, PlatformIO environment `default`.

## Validation state

- ZIP integrity: checked.
- Patch applicability: checked.
- Toolchain build: **not executed in this environment**. SDK submodule absent from the uploaded release ZIP; CI workflow checks out exact upstream RC2 and copies matching FreeInk SDK revision.
- Firmware-size check: **not passed**. Prior experimental port exceeded the 6,553,600-byte OTA image limit. Treat this fresh port as experimental until a successful build and device test.
- No binaries in this ZIP. Do not flash based on successful patch application alone.

## GitHub Desktop steps

1. Create a new repository for this source (do not overwrite your working 1.6.1 backup).
2. Copy the contents of this ZIP into the repository root, commit, and push. If GitHub Desktop warns about the empty `freeink-sdk` directory, leave it empty: CI retrieves the exact RC2 submodule revision.
3. Actions > **X4 Fresh RC2 Baseline and Myanmar Build** > Run workflow > `baseline`.
4. If baseline succeeds, repeat with `myanmar`.
5. Download `X4-myanmar-diagnostics` even if its firmware-size check fails; include both ELF and map in further optimization.

**Note:** Source ZIPs obtained from GitHub releases do not carry Git submodule contents or pinned gitlink metadata. The workflow obtains the authoritative FreeInk SDK gitlink from upstream `v2.0.0-rc2`.
