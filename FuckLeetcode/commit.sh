#!/bin/sh

git add "$1"
git commit -m "leetcode ${1%\.*} $2"