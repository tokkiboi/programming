<?

$fp = fopen('data.txt', 'rt') or die;
# ==> bsd/sys/mips/drivers/xlr/xlr_tlb.c
#     [b5389751be919d1e94ed77886fe50b51]
#     | 123: #define MIPS_COP_0_CAUSE_REG    $13
#     | 124: #define MIPS_COP_0_STATUS       $12
#     | 125: #define MIPS_COP_0_CAUSE        $13
# ==> bsd/sys/mips/include/regdef.h
#     [c50f64ca20013f16fe9b741222b6a16a]
#     | 58: #define fp      $30     /* frame pointer */
#     | 59: #define s8      $30     /* callee saved */
# ==> bsd/sys/mips/include/rm7000.h
#     [0086f6e8f65b479736130a20d7d417e6]
#     | 76: #define	PCNT_SRC_MULSTALL	0x1d	/* Multiplier stall cycles  */
#     | 77: #define	PCNT_SRC_ELDSTALL	0x1d	/* Excepion stall due to non-b ld */
# ==> bsd/sys/mips/include/sg/sg_debug.h
#     [0c26cfa98670d77e522b5256cc17dc9d]
#     | 292: #define MSP_DBG_IOCTL_MSP_XLR_PERF_SM _IOWR('z', 206, uintptr_t)
#     | 295: #define MSP_DBG_IOCTL_LOCAL_JFRAME_32    _IOWR('z', 205, u_int32_t)

?>
<html>
<head>
<script>
function submit_good(good_or_bad, hash) {
    w=window.open("good.php?good_or_bad="+good_or_bad+"&hash="+hash, 'newname', 'height=100,width=100,left=0');
    w.onload = function(){w.close()};
}
</script>
</head>
<body>
<table border=1>
<?php
$lines_printed = 0;
while (($line = fgets($fp)) != FALSE) {
    if(preg_match('{^==> (.+?)\s*$}s', $line, $matches)) {
        if ($lines_printed > 0) {
            print '</pre></td></tr>'."\n";
        }
        print '<tr>';
        $filenameline = htmlspecialchars($matches[1]."\n");
    }
    elseif(preg_match('{^\s*\[([0-9a-f]+)\]\s*}s', $line, $matches)) {
        $hash = $matches[1];
        print "<td>\n";
        print "<button type=\"button\" onclick=\"submit_good('good', '$hash');\">Good</button>\n";
        print "<button type=\"button\" onclick=\"submit_good('bad', '$hash');\">Bad</button>\n";
        print "</td>\n";
        print "<td><pre>$filenameline";
        $lines_printed++;
        print htmlspecialchars($line);
        $lines_printed++;
    }
    else {
        print htmlspecialchars($line);
        $lines_printed++;
    }
}
print '</td></tr>'."\n";
fclose($fp);
?>
</table></body></html>

