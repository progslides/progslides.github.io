var cmdFirst = true;
var cmdType;

function cmdSave(elem) {
    elem.setAttribute("data-left", elem.style.left);
    elem.setAttribute("data-top", elem.style.top);
    elem.setAttribute("data-visibility", elem.style.visibility);
}

function cmdRestore(elem) {
    elem.style.left = elem.getAttribute("data-left");    
    elem.style.top = elem.getAttribute("data-top");   
    elem.style.visibility = elem.getAttribute("data-visibility");    
}

function cmdInit() {
  var elems = document.getElementsByTagName("table");
  for(i = 0; i < elems.length; i++) {
    cmdSave(elems[i]);
  }
  cmdSave(document.getElementById("cmdCall"));
}

function cmdReset() {
  var elems = document.getElementsByTagName("table");
  for(i = 0; i < elems.length; i++) {
    cmdRestore(elems[i]);
  }
  cmdRestore(document.getElementById("cmdCall"));
}

function cmdParse(e) {
  if(e.keyCode == 13) {
    if(cmdFirst) {
      cmdFirst = false;
      cmdInit();
    } else cmdReset();
    var cmd = document.getElementById("cmdPrompt").value;
    var cmd_obj = document.getElementById("cmdCmd");
    if(cmd == "light on") {
       cmdType = "on";
       document.getElementById("cmdTitle").innerHTML = "On";
       document.getElementById("cmdExCmd").innerHTML = "  light.turnOn();";
       
       cmd_obj.style.visibility = "visible";
       animate(cmd_obj, "top", 386, 10, function() {document.getElementById("cmdRun").style.visibility = "visible";});
    } else if(cmd == "light off") {
       cmdType = "off";
       document.getElementById("cmdTitle").innerHTML = "Off";
       document.getElementById("cmdExCmd").innerHTML = "  light.turnOff();";
       cmd_obj.style.visibility = "visible";
       animate(cmd_obj, "top", 386, 10, function() {document.getElementById("cmdRun").style.visibility = "visible";});
    }
    return false;
  } else {
    return true;    
  }
}

function cmdSend() {
 document.getElementById("cmdRun").style.visibility = "hidden";
 var cmd_obj = document.getElementById("cmdCmd");
 animate(cmd_obj, "left", 562, 10, function() {
   animate(cmd_obj, "top", 126, 10, function(){
     document.getElementById("cmdInv").style.backgroundColor = "#ffff33";
     animate(cmd_obj, "top", 6, 10, function() {
        document.getElementById("cmdInv").style.backgroundColor = "inherit";
	document.getElementById("cmdCall").style.visibility = "visible";
	animate(document.getElementById("cmdCall"), "left", 260, 10, function() {
	  if(cmdType == "on") {
	   document.getElementById("cmdOn").style.backgroundColor = "#ffff33";
	   document.getElementById("cmdOff").style.backgroundColor = "inherit";
	   document.getElementById("cmdBulb").src = "images/bulb_on.png";
	  } else {
    	   document.getElementById("cmdOn").style.backgroundColor = "inherit";
	   document.getElementById("cmdOff").style.backgroundColor = "#ffff33";
	   document.getElementById("cmdBulb").src = "images/bulb_off.png";	    
	  }
	});
     });
   });
 });
}

function animate(obj, attr, val, speed, callback) {
  if(attr == "top") {
   var cur = parseInt(obj.style.top);
   if(cur < val) obj.style.top = (cur + speed) + "px"; 
   else if(cur > val) obj.style.top = (cur - speed)  + "px"; 
   else {
     callback();
     return;
   }
   window.setTimeout(function(){animate(obj, attr, val, speed, callback);}, 100);
  }
  
  else if(attr == "left") {
   var cur = parseInt(obj.style.left);
   if(cur < val) obj.style.left = (cur + speed) + "px"; 
   else if(cur > val) obj.style.left = (cur - speed)  + "px"; 
   else {
     callback();
     return;
   }
   window.setTimeout(function(){animate(obj, attr, val, speed, callback);}, 100);
  }
}
