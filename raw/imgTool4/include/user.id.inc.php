<?php

    function getUserIDfromAPI()
    {

      $session_cookie = 'janbrueghel_net_mw__session';
      if(!isset($_COOKIE[$session_cookie]))
      {
        return false;
      }

      $url = ((isset($_SERVER['HTTPS']))?'https://':'http://') .
             $_SERVER['HTTP_HOST'] .
             (($_SERVER['SERVER_PORT'] != 80)?':' . $_SERVER['SERVER_PORT']:'') .
             '/api.php?action=query&format=php&meta=userinfo';
             
      
      $ch = curl_init($url);
      curl_setopt($ch, CURLOPT_COOKIE, $session_cookie . '=' . $_COOKIE[$session_cookie]);
      curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
      curl_setopt($ch, CURLOPT_FOLLOWLOCATION, true);
      $ret = curl_exec($ch);
      curl_close($ch);

      $userinfo = unserialize($ret);
      $userID = intval($userinfo['query']['userinfo']['id']); 

      return $userID;
    }

    function gestUserIDfromCookie()
    {
       $userIDCookie='janbrueghel_net_mw_UserID'; 
       
       if(!isset($_COOKIE[$userIDCookie]))
      {
        return false;
      }
      
      $userID = intval($_COOKIE[$userIDCookie]);

      return $userID;
    }
    
    function checkUserID($userID)
    {
        if($userID < 1)
        {
            die ("You must be logged in to use favorites.");
            
        }
    }

?>


