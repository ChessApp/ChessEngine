function getInputValue(xml) {
  var xmlDoc = xml.responseXML;
  var txt = xmlDoc.children[0].children[0].attributes[1].nodeValue;
  console.log(txt);

  // Select the input element and get its value 
  var inputVal = document.getElementById("input").value;
  xmlDoc.children[0].children[1].attributes[0].nodeValue = inputVal;
  
  xml.open("POST", "http://ec2-3-21-232-145.us-east-2.compute.amazonaws.com/index.php", true);
  // xml.open("POST", "http://localhost:8080/index.php", true);
  xml.send(xmlDoc);

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
  xmlhttp.open("GET", "http://ec2-3-21-232-145.us-east-2.compute.amazonaws.com/GameState.xml", true);
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

// console.log("Chess");

// function createCircle(radius) {
//   return {
//     radius,
//     draw: function() {
//       console.log('draw');
//     }
//   };
// }

// const circle = createCircle(1);

// function Circle(radius) {
//   console.log('this', this);
//   this.radius = radius;
//   this.draw = function() {
//     console.log('draw');
//   }
// }

// const another = new Circle(1);

// var socket = new WebSocket('ws://ec2-3-22-95-184.us-east-2.compute.amazonaws.com');
