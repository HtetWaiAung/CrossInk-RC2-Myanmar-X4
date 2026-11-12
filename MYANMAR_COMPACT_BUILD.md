# RC2 X4 Myanmar compact build — experimental

## Situation
The normal Myanmar firmware ELF exceeds the X4 dual-OTA limit (6,553,600 bytes) by 181,747 bytes in the supplied build. The uploaded linked-symbol report identifies 583,107 bytes attributed to the built-in Lexend Deca fonts.

## What changed
A new GitHub Actions `myanmar-compact` build input excludes the Lexend Deca **built-in font tables**, while keeping their existing font IDs, size choices (10/12/14/16), and regular/bold/italic/bold-italic slots. Those slots temporarily use the size/style-matched **Bitter** data, so neither text layout nor typography is identical when the user chooses Lexend Deca. Inter UI fonts and the default Bitter reader fonts are unchanged. Both Myanmar HarfBuzz runtime TTF and glyph atlas remain embedded and unchanged. Normal `baseline` and `myanmar` options remain unmodified.

### Important limitation
The Lexend Deca font option now displays with Bitter's appearance in the compact firmware. This is an explicit visual tradeoff, NOT full fidelity. Preserve a separate set of SD-card font files if you want genuine Lexend Deca on the device; installing and selecting such SD fonts should be tested. We do not assert SD font installation automatically overrides the built-in Lexend option.

## Use
In GitHub Actions, open `X4 Fresh RC2 Baseline and Myanmar Build`, select `myanmar-compact`, and run. Download `X4-myanmar-compact-diagnostics` whether the size check succeeds or fails. This workflow retrieves the upstream RC2 submodule at its pinned gitlink.

## Status / limitations
Source-only experimental build. It has NOT been compiled here because the release source archive omits the `freeink-sdk` submodule and PlatformIO dependencies. Estimated reduction is based on 583,107 bytes of linked Lexend symbols, NOT a verified final program-size delta. Linker overhead/alignment may alter savings. Do not flash before passing size checks and validating English+Myanmar EPUB glyph positioning, pagination, and font selection.
