<?php
session_start();

if($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST['username'];

    // Store session : session is stored on server
    $_SESSION['username'] = $username;

    header("Location: welcome.php");
    exit();
}
?>