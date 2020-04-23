<?php
$fileHandle = fopen("UserInput.txt", "w");
fwrite($fileHandle, $_POST["input"]);
fclose($fileHandle);
sleep(1);
header("Location: " . $_SERVER["HTTP_REFERER"]);
?>
