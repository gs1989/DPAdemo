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
