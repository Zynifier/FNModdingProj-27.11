#!/bin/bash
# Packages FortniteGame for Windows (Win64) using the Windows engine, run inside the Parallels VM.
# Note: this engine distribution has no Client target type, so the Game target is packaged (it is the playable client).
# Output goes to the default stage location: <project>/Saved/StagedBuilds/Windows (no archive step).

# ---- settings -------------------------------------------------------------------------------
VM_NAME="Windows 11"
ENGINE_DIR_MAC="$HOME/Downloads/Windows/Engine"     # Windows installed-build engine (must be inside $HOME)
CLIENT_CONFIG="Development"                          # Development | Shipping | DebugGame | Test
# ---------------------------------------------------------------------------------------------

set -u
PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
UPROJECT_NAME="$(basename "$(ls "$PROJECT_DIR"/*.uproject | head -1)")"

case "$PROJECT_DIR" in "$HOME"/*) ;; *) echo "Project must live inside $HOME so the VM can see it as Z:\\"; exit 1;; esac
case "$ENGINE_DIR_MAC" in "$HOME"/*) ;; *) echo "Engine must live inside $HOME so the VM can see it as Z:\\"; exit 1;; esac

# Mac path -> Windows path on the Z: drive (Parallels "Mac Home"). Everything uses Z: so Unreal never sees a UNC path.
to_win() { local rel="${1#$HOME/}"; echo "Z:\\${rel//\//\\}"; }
WIN_PROJECT="$(to_win "$PROJECT_DIR")\\$UPROJECT_NAME"
WIN_ENGINE="$(to_win "$ENGINE_DIR_MAC")"

command -v prlctl >/dev/null || { echo "prlctl not found. Is Parallels Desktop installed?"; exit 1; }

STATE="$(prlctl list -a 2>/dev/null | grep -F "$VM_NAME" | awk '{print $2}')"
if [ "$STATE" != "running" ]; then
  echo "Starting VM '$VM_NAME'..."
  prlctl start "$VM_NAME" >/dev/null || exit 1
  until prlctl exec "$VM_NAME" cmd /c "exit 0" >/dev/null 2>&1; do sleep 3; done
fi

mkdir -p "$PROJECT_DIR/Saved/Logs"
LOG="$PROJECT_DIR/Saved/Logs/PackageWindowsClient.log"
WIN_CMD_MAC="$PROJECT_DIR/Saved/PackageWindowsClient.cmd"
WIN_CMD="$(to_win "$WIN_CMD_MAC")"

# Windows-side script. The engine's bundled dotnet is x64-only, so on an ARM64 VM we point
# the engine's dotnet lookup at it directly (it runs under emulation).
cat > "$WIN_CMD_MAC" <<EOF
@echo off
if not exist Z:\\ net use Z: \\\\Mac\\Home /persistent:no >nul 2>&1
set UE_DOTNET_VERSION=6.0.302
set UE_DOTNET_DIR=$WIN_ENGINE\\Binaries\\ThirdParty\\DotNet\\6.0.302\\windows
set PATH=%UE_DOTNET_DIR%;%PATH%
set DOTNET_ROOT=%UE_DOTNET_DIR%
set DOTNET_MULTILEVEL_LOOKUP=0
set DOTNET_ROLL_FORWARD=LatestMajor
call "$WIN_ENGINE\\Build\\BatchFiles\\RunUAT.bat" BuildCookRun ^
  -project="$WIN_PROJECT" ^
  -noP4 -utf8output -unattended ^
  -platform=Win64 -clientconfig=$CLIENT_CONFIG ^
  -build -cook -stage -pak ^
  -ubtargs="-MaxParallelActions=5"
exit /b %ERRORLEVEL%
EOF

echo "Packaging $UPROJECT_NAME  (Windows client / $CLIENT_CONFIG)"
echo "Log: $LOG"
echo "Output: $PROJECT_DIR/Saved/StagedBuilds/Windows"
echo

# --current-user runs in your logged-in Windows session, where Z: is already mapped by Parallels.
prlctl exec "$VM_NAME" --current-user cmd /c "$WIN_CMD" 2>&1 | tee "$LOG"
RC=${PIPESTATUS[0]}

echo
if [ "$RC" -eq 0 ]; then
  echo "Done. Staged build: $PROJECT_DIR/Saved/StagedBuilds/Windows"
  open "$PROJECT_DIR/Saved/StagedBuilds" 2>/dev/null
else
  echo "Packaging FAILED (exit code $RC). See $LOG"
fi
read -n 1 -s -r -p "Press any key to close..."
exit "$RC"
