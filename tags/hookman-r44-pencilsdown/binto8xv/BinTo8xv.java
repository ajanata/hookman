/*
;    BinTo8xv - Converts any file to a TI-83+-family AppVar.
;    Copyright (C) 2007  Andy Janata
;
;    This program is free software; you can redistribute it and/or modify
;    it under the terms of the GNU General Public License as published by
;    the Free Software Foundation; either version 2 of the License, or
;    (at your option) any later version.
;
;    This program is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;    GNU General Public License for more details.
;
;    You should have received a copy of the GNU General Public License along
;    with this program; if not, write to the Free Software Foundation, Inc.,
;    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
;
;	 You can contact the author via electronic mail at <ajanata@gmail.com>,
;	 or by writing to Andy Janata, 178 E. 5th St., Brewster, OH 44613 USA.


	General notes: All 16-bit word values are stored little-endian (least significant
	byte first).

*/

import java.io.*;

public class BinTo8xv {

	public static void main(String args[]) {
		System.out.println("BinTo8xv version 1, Copyright (C) 2007 Andy Janata");
		System.out.println("BinTo8xv comes with ABSOLUTELY NO WARRANTY.");
		System.out.println("This is free software, and you are welcome to redistribute it");
		System.out.println("under certain conditions. See the file LICENSE.txt for details.");
		System.out.println();
		
		
		if (args.length < 3) showHelp();
		
		File infile = null;
		FileInputStream in = null;
		FileOutputStream out = null;
		
		try {
			infile = new File(args[0]);
			in = new FileInputStream(infile);
		} catch (IOException ioe) {
			System.out.println("Unable to open file for reading. It probably doesn't exist.");
			ioe.printStackTrace();
			System.exit(1);
		}
		
		try {
			out = new FileOutputStream(args[1]);
		} catch (IOException ioe) {
			System.out.println("Unable to open file for writing. You probably don't have permission.");
			ioe.printStackTrace();
			try {
				in.close();
			} catch (Exception e) {
			}
			System.exit(2);
		}
		
		try {
			// file header
			out.write("**TI83F*".getBytes("US-ASCII"));
			out.write(26);
			out.write(10);
			out.write(0);
			if (args.length >= 4) {
				String comment = args[3];
				if (comment.length() > 42) {
					comment = comment.substring(0,42);
					System.out.println("Warning: Comment longer than 42 bytes, truncating...");
				}
				out.write(String.format("%1$-42s", comment).getBytes("US-ASCII"));
			} else {
				out.write(String.format("%1$-42s", "File converted to 83+ AppVar by BinTo8xv").getBytes("US-ASCII"));
			}

			
			// the data section's length is the length of the input file plus 17 header bytes plus the two
			// size bytes in the variable data itself
			char datalen = (char)(infile.length() + 19);
			out.write(datalen & 0xFF);
			out.write(datalen >> 8);
			
			MyWriter w = new MyWriter(out);
			// length of header (word)
			w.put(13);
			w.put(0);
			// length of variable data
			// + 2 because the data len is in the variable itself as well
			w.put((int)(infile.length() + 2) & 0xFF);
			w.put((int)(infile.length() + 2)>> 8);
			// variable type (appvar)
			w.put(0x15);

			byte name[] = new byte[8];
			for (int i = 0; i < 8; i++) name[i] = 0;
			String varName = args[2];
			if (varName.length() > 8) varName = varName.substring(0,8);
			for (int i = 0; i < varName.length(); i++) {
				// yeah, this wastes time, but meh
				name[i] = varName.getBytes("US-ASCII")[i];
			}
			for (int i = 0; i < 8; i++) {
				w.put(name[i]);
			}
			name = null;
			varName = null;
			
			// version and flag bytes, we don't need them
			w.put(0);
			w.put(0);
			
			// length of variable data, again
			w.put((int)(infile.length() + 2) & 0xFF);
			w.put((int)(infile.length() + 2) >> 8);
			
			// now put the real length of the data
			w.put((int)infile.length() & 0xFF);
			w.put((int)infile.length() >> 8);
			
			
			// now the actual variable data
			int read;
			while ((read = in.read()) != -1) w.put(read);
			
			// write the checksum
			out.write(w.getSum() & 0xFF);
			out.write(w.getSum() >> 8);
			
			out.close();
			in.close();

			System.out.println(args[1] + " successfully created.");	
			
		} catch (Exception e) {
			System.out.println("Error while converting file.");
			e.printStackTrace();
			try {
				in.close();
			} catch (Exception ee) {
			}
			try {
				out.close();
			} catch (Exception ee) {
			}
			System.exit(4);
		}
		
	}
	
	
	private static void showHelp() {
		System.out.println("Usage: java BinTo8xv <source.bin> <dest.8xv> <varname> [\"42-char max Comment\"]");
		System.out.println();
		System.out.println("The contents of source.bin (which may be any file of any format) are put, in");
		System.out.println("their entirety, into dest.8xv, with the proper headers and checksums.");
		System.out.println("varname is the on-calculator variable name. Maximum length is 8 characters.");
		System.out.println("The optional comment is only used in the .8xv file; a default is used if none");
		System.out.println("is provided.");

		System.exit(-1);
	}
	
	private static class MyWriter {
		FileOutputStream fos;
		// the checksum in .8xv files is simply the low 16 bits of the sum of all bytes in the data section
		// (truncating any higher bits)
		// char is 16-bit unsigned which works out nicely
		char sum = 0;
		
		public MyWriter(FileOutputStream f) {
			fos = f;
		}
		
		public void put(int b) throws IOException {
			sum += (byte)b;
			fos.write(b);
		}
		
		public char getSum() {
			return sum;
		}
	}
	
}
