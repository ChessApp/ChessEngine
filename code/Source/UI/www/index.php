<?php
// In order to open/write to this file,
// be sure that the permissions of the enclosing
// directory allow for the web server user to write files!
$fileHandle = fopen("UserInput.txt", "w");
fwrite($fileHandle, $_POST["input"]);
fclose($fileHandle);
sleep(1);
?>
