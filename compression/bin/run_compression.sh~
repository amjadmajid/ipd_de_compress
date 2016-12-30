#!/bin/sh

cd ..
./compress
cd python
# default Python interpreter is 'python' from your $PATH; set the $PYTHON
# environment variable to override it
: ${PYTHON:=python3}
export PYTHONPATH="$(dirname $0)/..:$PYTHONPATH"

exec "$PYTHON" -m intelFormat 
