$cppOutput = Get-Content hard-problems\inp\inp-A.txt | .\hard-problems\exe\pA

$expectedOutput = @'
3
the treasure is lost!
4
5
3
the treasure is lost!
the treasure is lost!
'@

$output = $cppOutput -split "`n"
$expectedOutput = $expectedOutput -split "`n"

function CheckTreasureResult($actual, $expected) {
    for ($i = 0; $i -lt $actual.Count; $i++) {
        $actualOutput = $actual[$i].Trim()
        $expectedOutput = $expected[$i].Trim()

        if ($actualOutput -eq $expectedOutput) {
            Write-Host -ForegroundColor Green "$($i + 1): Pass"
        } else {
            Write-Host -ForegroundColor Red "$($i + 1): Fail (Expected: '$expectedOutput', Actual: '$actualOutput')"
        }
    }
}

CheckTreasureResult $output $expectedOutput
