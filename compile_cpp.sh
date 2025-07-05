#!/usr/bin/env bash
set -e

# ➊ Homebrew flags (unchanged) …
BREW_PREFIX=$(brew --prefix)
# … build up CPPFLAGS, LDFLAGS, PKG_CONFIG_PATH here …

# ➋ Compiler selection: override via CXX, or auto-detect latest Homebrew gcc
: "${CXX:=$(command -v g++)}"
# If user didn't override and it’s the system g++, switch to brew's latest gcc
if [[ "$(basename "$CXX")" == "g++" ]] && command -v brew &>/dev/null && brew list --versions gcc &>/dev/null; then
  MAJ=$(brew list --versions gcc | awk '{print $2}' | cut -d. -f1)
  CXX="g++-${MAJ}"
fi
COMPILER="$CXX"

# ➌ Base flags: trimmed + pedantic + format checks, opt + LOCAL macro
BASE_FLAGS=(
  -std=c++23
  -pedantic-errors
  -Wall
  -Wextra
  -Wshadow
  -Wsign-conversion   # narrower than -Wconversion
  -Wformat=2          # strict printf/scanf checks
  -O2
  -DLOCAL
)

# ➍ Optional compile-time profiling
if [[ -n "$PROFILE" ]]; then
  BASE_FLAGS+=( -ftime-report )
fi

# ➎ Dispatch based on args
if [ "$#" -eq 0 ]; then
  SRC="main.cpp"; OUT="main"
elif [ "$#" -eq 1 ]; then
  SRC="$1.cpp";   OUT="$1"
else
  echo "Usage: $0 [basename]" >&2
  exit 1
fi

# ➏ Compile
echo "$COMPILER" ${CPPFLAGS} ${LDFLAGS} "${BASE_FLAGS[@]}" "$SRC" -o "$OUT"
"$COMPILER" ${CPPFLAGS} ${LDFLAGS} "${BASE_FLAGS[@]}" "$SRC" -o "$OUT"

