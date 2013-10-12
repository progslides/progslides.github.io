function animateCode() {
  divs = document.getElementsByTagName("div");
  var id = 0;
  
  for(i = 0; i < divs.length; i++) {
    // we found a codeAnimator tag, lets look at the inner divs
    if(divs[i].className == "codeAnimator") {
      id++;
      divs[i].id = "ca_" + id;
      inner_divs = divs[i].getElementsByTagName("div");
      for(j = 0; j < inner_divs.length; j++) {
        // there is the code :)
        if(inner_divs[j].className == "code") {
          code = inner_divs[j].innerHTML.split("\n");
          // build the formatted code table
          var table = "<table class=\"prettyprint code_animator\">";
          var max_step = 0;
          for(k = 0; k < code.length; k++) {
            state = code[k].charAt(0);
            // if we have a state, increase nr of stats and hide stat
            if(state != ' ') {
              max_step++;
              // find state div
              for(m = 0; m < inner_divs.length; m++) {
                if(inner_divs[m].className == "code_" + state) {
                  if(state != 1) inner_divs[m].style.display = "none"; 
                  inner_divs[m].id = "ca_" + id + "_stat_" + state;
                }
              }
            }
            code[k] = code[k].substring(1).replace(" ", "&nbsp;");
            var tr_id = " id=\"ca_" + id + "_" + state + "\" ";
            if(code[k].length > 0) table += "<tr><td" + ((state != ' ') ? tr_id : "") + (state == 1 ? " class=\"code_animator_active\" " : "") + ">" + prettyPrintOne(code[k], "c", 0) + "</td></tr>";
          }
          table += "</table>";
          table += "<input type=\"button\" value=\"&laquo; back\" onclick=\"animateCodeStep(" + id + ", -1);\" class=\"code_animator_button\">";
          table += "<input type=\"button\" value=\"&raquo; step\" onclick=\"animateCodeStep(" + id + ", 1);\" class=\"code_animator_button\">";
          table += "<input type=\"hidden\" id=\"ca_" + id + "_step\" value=\"1\">";
          table += "<input type=\"hidden\" id=\"ca_" + id + "_max_step\" value=\"" + (max_step - 1) + "\">";
          inner_divs[j].innerHTML = table;
        }
      }
    }
  }

}


function animateCodeStep(block, dir) {
  var step = document.getElementById("ca_" + block + "_step").value;
  var max_step = document.getElementById("ca_" + block + "_max_step").value;
  // reset current line
  if(step < max_step && step > 0) {
    if(!(step == max_step - 1 && dir == 1)) {
      var c_line = document.getElementById("ca_" + block + "_" + step);
      if(c_line != null) c_line.className = "";
      var c_block = document.getElementById("ca_" + block + "_stat_" + step);
      if(c_block != null) c_block.style.display = "none";
    }
  }
  
  // highlight current line
  if(step >= 1 && step < max_step) step = parseInt(step) + dir;
  if(step == 0) step = 1;
  if(step < max_step) {
    var c_line = document.getElementById("ca_" + block + "_" + step);
    if(c_line != null) c_line.className = "code_animator_active";
    var c_step = document.getElementById("ca_" + block + "_step");
    if(c_step != null) c_step.value = step;
    var c_block = document.getElementById("ca_" + block + "_stat_" + step);
    if(c_block != null) c_block.style.display = "";
  }
}

