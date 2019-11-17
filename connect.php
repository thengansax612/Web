<?php 
    $servername = "localhost";
    $username = "root";
    $password = "";
    $database  = "web";

    $conn = mysqli_connect($servername, $username, $password,$database) or die("lỗi");

    mysqli_set_charset($conn, 'UTF8');
?>