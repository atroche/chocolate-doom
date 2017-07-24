#!/bin/sh
echo "running oclint. takes about 25 seconds on my MBP2015."
echo "make sure you run build.sh first and install oclint"
cp build/compile_commands.json ./ && oclint-json-compilation-database
rm compile_commands.json
