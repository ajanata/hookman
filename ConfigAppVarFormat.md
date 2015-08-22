The "HMConfig" appvar contains main configuration data from HookMan. Initially this will only be flags for which hooks are currently managed by HookMan but may be expanded upon in the future to include the name of the chain appvar (allowing multiple chains to be switched between easily).

# Outline overview: #

  1. Signature.
  1. Hooks managed flags.

# Definitions: #

Signature: "HMCF",configversion (currently $00)

Hooks managed flags: A bit per hook. Bit 0 of the first byte is for hook 0, bit 1 for hook 1, and so on to bit 7 for hook 7. Bit 0 of the next byte is for hook 8, and so on, through bit 6 of the third byte for hook 22. See hooklist.inc for hook numbers.
