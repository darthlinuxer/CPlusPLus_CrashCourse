# Check if Visual Studio Build Tools are installed
$vsBuildToolsPath = "C:\\Program Files (x86)\\Microsoft Visual Studio\\Installer\\vswhere.exe"
if (-Not (Test-Path $vsBuildToolsPath)) {
    Write-Host "Visual Studio Build Tools not found. Installing..."
    Invoke-WebRequest -Uri "https://aka.ms/vs/17/release/vs_buildtools.exe" -OutFile "vs_buildtools.exe"
    Start-Process -FilePath "vs_buildtools.exe" -ArgumentList "--quiet --wait --norestart --add Microsoft.VisualStudio.Workload.VCTools" -NoNewWindow -Wait
    Remove-Item -Path "vs_buildtools.exe"
} else {
    Write-Host "Visual Studio Build Tools are already installed."
}

# Check if CMake is installed
if (-Not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    Write-Host "CMake not found. Installing..."
    Invoke-WebRequest -Uri "https://github.com/Kitware/CMake/releases/latest/download/cmake-win64-x64.msi" -OutFile "cmake.msi"
    Start-Process -FilePath "msiexec.exe" -ArgumentList "/i cmake.msi /quiet /norestart" -NoNewWindow -Wait
    Remove-Item -Path "cmake.msi"
} else {
    Write-Host "CMake is already installed."
}

# Check if Ninja is installed
if (-Not (Get-Command ninja -ErrorAction SilentlyContinue)) {
    Write-Host "Ninja not found. Installing..."
    Invoke-WebRequest -Uri "https://github.com/ninja-build/ninja/releases/latest/download/ninja-win.zip" -OutFile "ninja.zip"
    Expand-Archive -Path "ninja.zip" -DestinationPath "C:\\ninja"
    $env:Path += ";C:\\ninja"
    Remove-Item -Path "ninja.zip"
} else {
    Write-Host "Ninja is already installed."
}

Write-Host "All dependencies are installed. You can now build the project."