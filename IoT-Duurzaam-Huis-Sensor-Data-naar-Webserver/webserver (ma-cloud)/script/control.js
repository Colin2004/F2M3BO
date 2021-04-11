let debug = true;
let timeDelay = 10000; // time delay refresh data

// uncomment for multi user
let refreshTimer = window.setInterval(ajaxReadJson, timeDelay); // timer get data from server
let arrayRemote;

function ajaxReadJson(){
  makeAjaxCall(jsonFileSensorData,"POST"). then(readJson2); // read sensor data
}

function readJson2(jsonString) {
   arrayRemote = JSON.parse(jsonString);//extract to JSON object
   
   // display numbers   
   document.getElementById('temperature').innerHTML=" " + arrayRemote[1];
   document.getElementById('humidity').innerHTML=" " + arrayRemote[3];
   document.getElementById('heatindex').innerHTML=" " + arrayRemote[5];
   document.getElementById('lightlevel').innerHTML=" " + arrayRemote[7];
   document.getElementById('yourId').innerHTML=" " + arrayRemote[9];


   // set gauges
   control1.setValue(arrayRemote[1] );
   control2.setValue(arrayRemote[3] );
   control3.setValue(arrayRemote[5] );
   control4.setValue(arrayRemote[7] );
}    
    
function init(){
    ajaxReadJson(); // get JSON string with values from server
}

init(); // start