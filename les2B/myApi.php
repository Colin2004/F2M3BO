<?php
        
        // Report all errors
        // Dit is nu handig bij het testen
        // In een productie omgeving doe je dit niet of anders
        error_reporting(E_ALL);


        
        // my API reageert op GET en POST requests
        print "<h3>hello from myAPI !!</h3>"; // say hello to client
     
        
        $myTime = time(); // get the server time

		if (!empty($_GET['data'])){  
            $dataFromGet= $_GET['data'];
            print "<h4>GET request ontvangen</h4>";
            print "de data uit het GET request is: " . $dataFromGet;
            switch($dataFromGet){
                case "server":
                    print "<pre>my server variables are:  " ;
                    print_r($_SERVER);  // show server data
                    print "</pre>"; 
                break;
                
                case "tijd":
                    print "<br>server tijd: " . date("h:i:s",$myTime);
                break;

                 // hier moet jij zelf code schrijven
                    
                case "easter egg":
                    echo '<br> <a href="https://www.youtube.com/watch?v=QtBDL8EiNZo">klik hier!</a>';
                break;
                
                case "pi":
                    echo(pi());
                    break;

                case "Ip":
                    echo 'User IP Address - '. $_SERVER['REMOTE_ADDR'];
                break;
                  // einde eigen code  
                default:
                    print " <h3><br>please read the manual for valid requests &#128540; <br>probeer anders: server, tijd, easter egg, pi of Ip tijd</h3>";
            }
        }     
?>
