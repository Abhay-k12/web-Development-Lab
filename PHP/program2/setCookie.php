<?php
$cookieName = $_POST['name'];
$cookieValue = $_POST['value'];

// cookies are stored in browser
setcookie($cookieName, $cookieValue, time() + 3600, "/");
echo "Cookie has been set!";
?>