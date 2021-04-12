/*
*  creates a knob
*  layout_element the html element wher the knob is locatated
*/
"use strict";
function createKnob(knob, layout_element) {
                
    // Create knob element, 300 x 300 px in size.

    // Set properties.
     knob.setProperty('angleStart', -0.75 * Math.PI);
     knob.setProperty('angleEnd', 0.75 * Math.PI);
     knob.setProperty('colorFG', '#88ff88');
     knob.setProperty('trackWidth', 0.4);
     knob.setProperty('valMin', 0);
     knob.setProperty('valMax', 100);

    // Set initial value.
     knob.setValue(50);

    /*
     * Event listener
     */
    const listener = function(knob, value) {
        // listener not used in this application
        // console.log(value); 
    };

     knob.addListener(listener);

    // Create element node.
    const node =  knob.node();

    // Add it to the DOM.
    const elem = document.getElementById(layout_element);
    elem.appendChild(node);
}

let control1, control2, control3, control4 ; // three indicators
/*
 * Lib. https://github.com/andrepxx/pure-knob
 */
function initKnobs() {
    console.log("init");
    // control1
    let width = 200;
    let height = 200;

    control1=pureknob.createKnob(width,height); //instance of pureknob, dimensions px
    createKnob(control1, "element1" ); // init instance + location in HTML
    control1.setProperty("label", "temperature \u00B0C"); 
    control1.setProperty("colorFG", "magenta"); // change color
    control1.setProperty("needle", true); // small indicator
    control1.setProperty("colorLabel", "black");
    control1.setProperty("readonly", true)

    // control2
    control2=pureknob.createKnob(width,height); //instance of pureknob, dimensions px
    createKnob(control2, "element2" ); // init instance + location in HTML
    control2.setProperty('label', "humidity");
    control2.setProperty("colorFG", "magenta"); // change color
    control2.setProperty("colorLabel", "black");

    control3=pureknob.createKnob(width,height); //instance of pureknob, dimensions px
    createKnob(control3, "element3" ); // init instance + location in HTML
    control3.setProperty('label', "heatindex \u00B0C");
    control3.setProperty("colorFG", "magenta"); // change color
    control3.setProperty("needle", true); // small indicator
    control3.setProperty("colorLabel", "black");

    control4=pureknob.createKnob(width,height); //instance of pureknob, dimensions px
    createKnob(control4, "element4" ); // init instance + location in HTML
    control4.setProperty('label', "light level %");
    control4.setProperty("colorFG", "yellow"); // change color
    control4.setProperty("colorLabel", "black");
    
}

document.addEventListener('DOMContentLoaded', initKnobs, false);