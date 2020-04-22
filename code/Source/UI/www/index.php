<?php
$fileHandle = fopen("UserInput.txt", "w");
fwrite($fileHandle, $_POST["input"]);
fclose($fileHandle);
?>
