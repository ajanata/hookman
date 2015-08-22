The "HMDatbas" appvar contains a list of known hooking apps on the current calculator. It is not useful to transfer to another calculator, although one may do so if on really wants to do so. It is used to present a list of hooks to the user when constructing chains and to track applications when pages change due to deleted apps.

# Outline overview: #

  1. Signature.
  1. Length-prefixed offset table.
  1. Application entries.

# Definitions: #

**Signature:** "HMDB",dbversion (currently $00)

**Offset table:** Byte indicating count of entries following, followed by that many words of offsets from the end of the offset table to application entires. The "appid" byte in hook nodes (see Active Hook Chain List Format) is a reference into this table. New entries **always** go at the end of the table.

**Application entries:** Eight bytes for application name (as present in the application's header, so may vary by app but should always be consistent on a given calculator), followed by one byte of last known base page, followed by one byte indicating the number of hooks in the application. For each hook, one byte for hook number, one byte for basepage offset (i.e., the hook is on page basepage-pageoffset), one word for hook address ($83 byte).