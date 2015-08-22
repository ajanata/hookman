This document describes the format of the active hook chain list application variable ("HMChains").

# Outline overview #

```
  1. Signature.
  2. Offset pointer table for every hook chain. $00 if no hooks defined for a given chain. Calculate location of head of chain as (varloc)+len(header)+((offset-1)*len(chainnode))   where header includes the offset table
  3. Hook chains.
  4. $FE appvar terminator.
```

# Definitions #

Signature: "HMCL",chainlistversion (currently $00)

Offset pointer table: In hook ID number order (see hooklist.inc).

Hook chains: Consist of a string of hook nodes executed in order:

```
hook - 1 byte - identification number of the hook (defined in hooklist.inc), $FF if end of chain (rest of node irrelevant)
basepage - 1 byte - used to identify other hooks from same app   
hookpage - 1 byte - may be the same as basepage
hookaddr - 1 word - address of $83 byte in hook
appid - 1 byte - offset into (local!) application database, for recovering from deleted apps causing pages to shift. Currently unused and set to $00.
```

basepage is used to reference all(!) other hooks to re-load the proper information into all of the required hook RAM blocks.