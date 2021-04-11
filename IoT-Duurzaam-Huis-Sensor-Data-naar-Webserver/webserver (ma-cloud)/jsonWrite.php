<?php
        $filePath1 = "control.json"; // path filename json control file from HTML
        $filePath2 = "data.json"; // path filename json data file from ESP
        $filePath = ""; // empty string
        $debug = true; // show data for debugging purposes
        
        // read HTTP request
        // determine source of command
        if (!empty($_GET['src'])){
            $source= $_GET['src'];
            // source is HTML client, write data to control.json
            if($source == "html"){$filePath = $filePath1;}
            // source is nodeMCU, write data to data.json  
            if($source == "esp"){$filePath = $filePath2;}
            // show source if debug = true
            if($debug){echo $source;}
        }
        // get the payload
		if (!empty($_GET['data'])){
                $control= $_GET['data'];
                if($debug){echo $control;}
                // write json string to harddisk
                jsonWrite($control, $filePath);
			}
        
        function jsonWrite($control, $filePath){
            // write json string to harddisk

            // show json string if debug = true
            if($debug){echo $control;}
            
            $file = fopen($filePath, "w") or die("can't open file");
            fwrite($file, $control); // overwrite existing file
            fclose($file);
        }
?>
