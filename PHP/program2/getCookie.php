<?php

$cookieName = $_POST['name'];

if(isset($_COOKIE[$cookieName])) {
    echo "Welcome, " . $_COOKIE[$cookieName];
} 
else {
    echo "Cookie not found!";
}
?>