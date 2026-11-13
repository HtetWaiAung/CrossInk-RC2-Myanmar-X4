# X3 Myanmar cluster-safe wrapping fix (experimental)

## Root cause
`lib/Utf8/Utf8.h` did not classify Myanmar vowel signs, medials and virama as combining marks.
`ParsedText::splitTokenAtCodepointBoundary()` is used more often on narrow X3 layouts and previously split at UTF-8 codepoint boundaries even within Myanmar shaping syllables. Shaping the two halves independently detaches vowel signs / stacked consonants.

## Changes
- Extend combining-mark predicate with Myanmar mark ranges.
- Reject fallback break immediately before a mark or joiner, and after U+1039 (virama) / joiners.
- Avoid Latin hyphenation rules for tokens containing Myanmar; only use guarded fallback splitting when permitted.
- Keep GfxRenderer, HarfBuzz and glyph atlas unchanged, preserving X4 rendering.

## Verification
Static code changes only; firmware has NOT been rebuilt or tested on a device here.
Build `myanmar-compact` in GitHub Actions and check app binary fits <= 6,553,600 bytes; test both X3/X4 with the same EPUB at the same font size.
Also check stacked consonants, pre-base vowel U+1031, medial U+103B/U+103C, and kinzi U+1004 U+103A U+1039.

The photo shows very wide inter-word gaps as well as apparent mark displacement; that spacing may be a separate text justification issue. This patch targets illegal splitting, not justification.
