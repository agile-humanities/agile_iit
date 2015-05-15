<?php
    $wgDBtype      = "mysql";
    $wgDBserver    = "mysql.janbrueghel.org";
    $wgDBname      = "janbrueghel_net";
    $wgDBuser      = "ahong_ls";
    $wgDBpassword  = "EX5ESvVr";
?>

<?php
    $connexion = mysql_pconnect($wgDBserver, $wgDBuser, $wgDBpassword );
    if (!$connexion)
    {
	    echo 'Erreur' ;
	    exit ;
    }
    
    mysql_query("SET NAMES UTF8");
    mysql_select_db($wgDBname, $connexion);


    $dbh = new PDO('mysql:host='.$wgDBserver.';dbname='.$wgDBname.';charset=UTF8', $wgDBuser, $wgDBpassword);
    $dbh->exec("SET NAMES UTF8");
?>


