
function getInputValue(xml) {
  var xmlDoc = xml.responseXML;
  var txt = xmlDoc.children[0].children[0].attributes[1].nodeValue;
  console.log(txt);

  // Selecting the input element and get its value 
  var inputVal = document.getElementById("input").value;
  xmlDoc.children[0].children[1].attributes[0].nodeValue = inputVal;
  
  fetch("http://127.0.0.1:8080/GameState.xml", {
    method: 'POST',
    mode: 'no-cors',
    body: xmlDoc,
  }).then(response => {
    console.log(response)
  })

  // Displaying the value
  console.log(inputVal);
}

function loadXMLDoc() {
  var xmlhttp = new XMLHttpRequest();
  xmlhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      readFresh(this);
      getInputValue(this)
      return this;
    }
  };
  xmlhttp.open("GET", "GameState.xml", true);
  // xmlhttp.open("GET", "http://localhost:8080/GameState.xml", true);
  xmlhttp.send();
}

function readFresh(xml) {
  var x, i, xmlDoc, txt;
  xmlDoc = xml.responseXML;
  txt = "";
  txt = xmlDoc.children[0].children[0].attributes[1].nodeValue;
  console.log(txt);
  xmlDoc.children[0].children[0].attributes[1].nodeValue = "0";
  txt = xmlDoc.children[0].children[0].attributes[1].nodeValue;
  console.log(txt);
}