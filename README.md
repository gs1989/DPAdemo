# Demo of power analysis against unmasked tiny AES
A demo for power analysis against unmasked tiny-AES running on an ARM M3 processor
## Info
- Captured traces: 16 Sbox in the first round, 625*32ns=20us
- Target device: LPC1313 12MHz working frequency
- Target implementation: Tiny-AES at https://github.com/kokke/tiny-AES-c
- Target leakage: first round Sbox output
- Attack methodology: Hamming Weight CPA
## Requirements
Python3 + numpy + scipy.stats + matplotlib
## Directory organisation
- Acquisition/: files for trace acquistion with picoscope 2000 series
- TinyAES: Tiny-AES fitted to the SCALE boards' setup
- AESAttack.py: python3 script for running the demo
- TRSReader.py: TRS reading library for AESAttack.py
- README.md: This file

## Combine of acquisition and attack
- Need sudo on linux
- Need picoscope (software; not SDK) installed
- python library pyserial + (time, random, secrets) 
- Acquisition setup: channel B 2V trigger/5V range, repeat posedge 10%, 100us/div;
                     channel A 1V range
- Once a while, the program will run 50 encryptions, whereas the scope shows the traces
