$cppOutput = Get-Content hard-problems\inp\inp-A.txt | .\hard-problems\exe\pA

$expectedOutput = @'
3
the treasure is lost!
4
'@

$actualLines = $cppOutput -split "`n"
$expectedLines = $expectedOutput -split "`n"

function CheckTreasureResult($actual, $expected) {
    $pass = $true

    for ($i = 0; $i -lt $actual.Count; $i++) {
        $actualLine = $actual[$i].Trim()
        $expectedLine = $expected[$i].Trim()

        if ($actualLine -eq $expectedLine) {
            Write-Host -ForegroundColor Green "$($i + 1): Pass"
        } else {
            Write-Host -ForegroundColor Red "$($i + 1): Fail (Expected: '$expectedLine', Actual: '$actualLine')"
        }
    }
}

CheckTreasureResult $actualLines $expectedLines
