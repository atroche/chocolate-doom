#!/bin/sh
echo "going to try to run doom for one tic to test that it can start up"
if [ ! -f build/microdoom ]; then
  echo "microdoom binary not found, make sure you run build.sh"
else
  (build/microdoom -onetictest && echo "all good!") || echo "uh oh, failure!"
fi
