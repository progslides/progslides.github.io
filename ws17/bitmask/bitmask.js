
var nrOfBits;
var operation = "and";

function addBit(parent_elem, id_prefix, clickable) {
  var bit = document.createElement("div");
  bit.innerHTML = "0";
  bit.className = "bit_off";
  bit.id = id_prefix + i;
  if(clickable) bit.onclick = function() {toggleBit(this);}
  parent_elem.appendChild(bit);
}

function init(bits) {
  nrOfBits = bits;
  first_binary_row = document.getElementById("first_binary");
  second_binary_row = document.getElementById("second_binary");
  result_binary_row = document.getElementById("result_binary");
  
  for(i = 0; i < bits; i++) {
    addBit(first_binary_row, "first_binary_", 1);
    addBit(second_binary_row, "second_binary_", 1);
    addBit(result_binary_row, "result_binary_", 0);
  }
}

function setBit(elem, value) {
  bit_nr = parseInt(elem.id.substring(elem.id.lastIndexOf('_') + 1, elem.id.length));
  bit_val = document.getElementById(elem.id.substring(0, elem.id.lastIndexOf('_')) + "_nr");
  cur_val = parseInt(bit_val.value);
  
  if(value) {
    elem.innerHTML = "1"; 
    elem.className = "bit_on";
    cur_val |= 1 << (nrOfBits - bit_nr - 1);
  } else {
    elem.innerHTML = "0";  
    elem.className = "bit_off";
    cur_val &=~(1 << (nrOfBits - bit_nr - 1));
  }
  
  bit_val.value = cur_val;
  //if(elem.id.indexOf("result_") != 0) updateResult();
}

function toggleBit(elem) {
  if(elem.innerHTML.indexOf("0") != -1) {
    setBit(elem, 1);
  } else {
    setBit(elem, 0);
  }
  updateResult();
}

function setValue(prefix, value) {
  if(value > (1 << nrOfBits) - 1 || value < 0) value = 0;
  for(i = 0; i < nrOfBits; i++) {
    setBit(document.getElementById(prefix + i), value & (1 << (nrOfBits - i - 1))); 
  }
}


function updateResult() {
 val_1 = parseInt(document.getElementById("first_binary_nr").value);
 val_2 = parseInt(document.getElementById("second_binary_nr").value);  
 result = 0;
 if(operation == "and") result = val_1 & val_2;
 else if(operation == "or") result = val_1 | val_2;
 else if(operation == "xor") result = val_1 ^ val_2;
 setValue("result_binary_", result); 
}

function setValueAndUpdate(prefix, value) {
  setValue(prefix, value);
  updateResult();
}

function invert(prefix) {
  val = parseInt(document.getElementById(prefix + "nr").value);
  val = ~val;
  if(val < 0) val += (1 << nrOfBits);
  setValueAndUpdate(prefix, val);
}

function changeOperation(oper) {
  operation = oper;
  document.getElementById("op_and").className = "button_inactive";
  document.getElementById("op_or").className = "button_inactive";
  document.getElementById("op_xor").className = "button_inactive";
  document.getElementById("op_" + oper).className = "button_active";
  updateResult();
}

