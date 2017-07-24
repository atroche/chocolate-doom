#!/bin/sh
echo "going to try to run doom for one tic to test that it can start up"
if [ ! -f build/mindoom ]; then
  echo "mindoom binary not found, make sure you run build.sh"
else
  (build/mindoom -onetictest && echo "all good!") || echo "uh oh, failure!"
fi
