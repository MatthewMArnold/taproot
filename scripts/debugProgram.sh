#!/bin/bash
echo Building and programming...
/usr/bin/env python3 $(which scons) program profile=debug
echo Done!