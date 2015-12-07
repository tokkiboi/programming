<?php
//
// See the data.txt file in this directory
// The first few likes look like this:
//
// ==> bsd/sys/mips/drivers/xlr/xlr_tlb.c
//     [b5389751be919d1e94ed77886fe50b51]
//     | 123: #define MIPS_COP_0_CAUSE_REG    $13
//     | 124: #define MIPS_COP_0_STATUS       $12
//     | 125: #define MIPS_COP_0_CAUSE        $13
// ==> bsd/sys/mips/include/rm7000.h
//     [0086f6e8f65b479736130a20d7d417e6]
//     | 76: #define    PCNT_SRC_MULSTALL    0x1d    /* Multiplier stall cycles  */
//     | 77: #define    PCNT_SRC_ELDSTALL    0x1d    /* Excepion stall due to non-b ld */
// ==> bsd/sys/mips/include/sg/sg_debug.h
//     [0c26cfa98670d77e522b5256cc17dc9d]
//     | 292: #define MSP_DBG_IOCTL_MSP_XLR_PERF_SM _IOWR('z', 206, uintptr_t)
//     | 295: #define MSP_DBG_IOCTL_LOCAL_JFRAME_32    _IOWR('z', 205, u_int32_t)
//     | 296: #define MSP_DBG_IOCTL_MSP_XLR_PERF_SM_32 _IOWR('z', 206, u_int32_t)
// ==> gpl-dist/rsync/zlib/trees.h
//     [11b1933ea8ccf8247072a0bce77be7c0]
//     | 79: 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
//     | 80: 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
//     | 81: 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
//
//
// I need for you to read this file and print it on the browser as an html table
// with two buttons on the left column.
//
// +----------+------------------------------------------------------------------------------------------+
// |          | ==> bsd/sys/mips/drivers/xlr/xlr_tlb.c                                                   |
// | +------+ |     [b5389751be919d1e94ed77886fe50b51]                                                   |
// | | Good | |     123: #define MIPS_COP_0_CAUSE_REG    $13                                             |
// | +------+ |     124: #define MIPS_COP_0_STATUS       $12                                             |
// | | Bad  | |     125: #define MIPS_COP_0_CAUSE        $13                                             |
// | +------+ |                                                                                          |
// +----------+------------------------------------------------------------------------------------------+
// | +------+ | ==> bsd/sys/mips/include/rm7000.h                                                        |
// | | Good | |     [0086f6e8f65b479736130a20d7d417e6]                                                   |
// | +------+ |     76: #define  PCNT_SRC_MULSTALL    0x1d    /* Multiplier stall cycles  */             |
// | | Bad  | |     77: #define  PCNT_SRC_ELDSTALL    0x1d    /* Excepion stall due to non-b ld */       |
// | +------+ |                                                                                          |
// +----------+------------------------------------------------------------------------------------------+
// | +------+ | ==> bsd/sys/mips/include/sg/sg_debug.h                                                   |
// | | Good | |     [0c26cfa98670d77e522b5256cc17dc9d]                                                   |
// | +------+ |     292: #define MSP_DBG_IOCTL_MSP_XLR_PERF_SM _IOWR('z', 206, uintptr_t)                |
// | | Bad  | |     295: #define MSP_DBG_IOCTL_LOCAL_JFRAME_32    _IOWR('z', 205, u_int32_t)             |
// | +------+ |     296: #define MSP_DBG_IOCTL_MSP_XLR_PERF_SM_32 _IOWR('z', 206, u_int32_t)             |
// +----------+------------------------------------------------------------------------------------------+
// | +------+ | ==> gpl-dist/rsync/zlib/trees.h                                                          |
// | | Good | |     [11b1933ea8ccf8247072a0bce77be7c0]                                                   |
// | +------+ |     79: 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,  |
// | | Bad  | |     80: 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  |
// | +------+ |     81: 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,  |
// +----------+------------------------------------------------------------------------------------------+
//
// If somebody presses the GOOD button you do this:
//   1. Pick up the text in square brackets just below the file name on the row of the button
//      e.g. b5389751be919d1e94ed77886fe50b51
//   2. extract the last two charachters, e.g. 51 in this case
//   3. Create a directory ~/xx/51 if it does not exist
//   4. Create a file named b5389751be919d1e94ed77886fe50b51 in that directroy.
//      No need to create any content in that file. You can close the file. It will
//      have zero bytes.
//
// If somebody presses the BAD button this is what you do:
//   1. If a file exists ~/xx/51/b5389751be919d1e94ed77886fe50b51, you just delete the file
//   2. Do not delete the directory ~/xx/51
//   3. If there is no file ~/xx/51/b5389751be919d1e94ed77886fe50b51, don't do anything

?>

<html>
<body>
<table border = "1" width = 100%>

<?php
$myfile = "data.txt";
$fp = fopen($myfile, "rt") or die ("cannot open file to read : $myfile\n");
$firsttime = 1;
while($line = fgets($fp))
{
    if(preg_match('{^==>}', $line))
    {
        if($firsttime == 1)
        {
            echo "<tr>
                    <td align=center><button type = button onclick=alert('$resultGood')>Good</button><br><button type = button onclick=alert('$resultBad')>Bad</button></td>
                    <td><pre>$line";
            $firsttime = 0;
        }
        else
        {
            echo "</pre></td></tr>\n
                  <tr>
                     <td align=center><button type = button onclick=alert('$resultGood')>Good</button><br><button type = button onclick=alert('$resultBad')>Bad</button></td>
                     <td><pre>$line";
        }
    }
    else
    {
        echo $line;
        if(preg_match('{^[(.*)]$}', $line))
        {
            $lastChar=array_pop($line);
            echo "lastChar = $lastChar";
            echo $line;
        }
        else
        {
            echo $line;
        }
    }
}
?>


</table>
</body>
</html>
