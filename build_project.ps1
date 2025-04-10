# Delete all .obj files in the root folder
Get-ChildItem -Path . -Filter *.obj -File | Remove-Item -Force
Write-Host "Deleted all .obj files in the root folder."

# Function to compile a .cpp file
function Compile-CppFile {
    param (
        [string]$CppFile
    )

    $outputExe = "$($CppFile -replace '\.cpp$', '.exe')"
    $outputObj = "$PSScriptRoot\obj\$($CppFile -replace '^.*\\', '').obj"

    # Ensure the obj folder exists
    if (-Not (Test-Path "$PSScriptRoot\obj")) {
        New-Item -ItemType Directory -Path "$PSScriptRoot\obj" | Out-Null
    }

    Write-Host "Compiling $CppFile to $outputExe with .obj in obj folder using C++20..."

    & cl.exe /Zi /EHsc /nologo /std:c++20 /Fo$outputObj /Fe$outputExe $CppFile

    if ($LASTEXITCODE -ne 0) {
        Write-Host "Failed to compile $CppFile" -ForegroundColor Red
    } else {
        Write-Host "Successfully compiled $CppFile" -ForegroundColor Green
    }
}

# Get all .cpp files in the workspace
$cppFiles = Get-ChildItem -Path . -Recurse -Include *.cpp

if ($cppFiles.Count -eq 0) {
    Write-Host "No .cpp files found in the project." -ForegroundColor Yellow
    exit
}

# Compile each .cpp file
foreach ($file in $cppFiles) {
    Compile-CppFile -CppFile $file.FullName
}

Write-Host "Build process completed."