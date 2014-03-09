function Game(width, height) {
 this.width = width;
 this.height = height;
 this.board = null;
 
 this.init = function() {
   var can = document.getElementById("game");
   this.board = can.getContext("2d");
   //Lets resize the canvas to occupy the full page
   can.width = this.width;
   can.height = this.height;
        
   this.clear();
 };
 
 this.clear = function() {
    this.board.fillStyle = "white";
    this.board.fillRect(0, 0, this.width, this.height);
 };
}

function Ball(game, x, y, radius, dir, speed, bid, crazy) {
 this.x = x;
 this.y = y;
 this.dir = dir * Math.PI / 180;
 this.speed = speed;
 this.game = game;
 this.radius = radius;
 this.bid = bid;
 this.crazy = crazy;
 
 this.move = function() {
  this.x += Math.cos(this.dir) * this.speed;
  if(this.crazy) {
    this.y += (Math.tan((this.x % 180) * Math.PI / 180) % 4) * this.speed;
  } else {
    this.y += Math.sin(this.dir) * this.speed;
  }
  
  if(this.x <= this.radius*2 || this.x > this.game.width - this.radius * 2) 
    this.dir = Math.atan2(Math.sin(this.dir), -Math.cos(this.dir));
  if(this.y <= this.radius*2 || this.y > this.game.height - this.radius * 2) 
    this.dir = Math.atan2(-Math.sin(this.dir), Math.cos(this.dir));
  
  if(this.y > this.game.height - this.radius * 2 + 1) this.y = this.game.height - this.radius * 2 + 1;
  if(this.y < this.radius * 2) this.y = this.radius * 2;
  
 };
 
 this.draw = function() {
  this.game.board.beginPath();
  this.game.board.arc(this.x, this.y, 24, 0, 2*Math.PI, false);
  this.game.board.fillStyle = (this.crazy ? "#0000ff" : "#ff0000");
  this.game.board.strokeStyle = "#404040";
  this.game.board.lineWidth = 1;
  this.game.board.fill();
  this.game.board.stroke();
  this.game.board.fillStyle = "#000000";
  var ball_text = (this.crazy ? "CrazyBall" : "Ball") + " #" + this.bid;
  var text_w = this.game.board.measureText(ball_text).width;
  this.game.board.fillText(ball_text, this.x - text_w / 2, this.y + this.radius + 18);
 };

}

var Example2 = new function() {

this.g = null;
this.b_id = 1;
this.balls = [];
this.d_int = 1;
 
this.addBall = function(nr, x, y, spd, dir, type) {
  var ball = '<span class="pln">  </span><span class="typ">' + (type == 0 ? "Normalball" : "Crazyball") + '</span><span class="pln"> b' + nr +'</span><span class="pun">(</span><span class="lit">' + x + '</span><span class="pun">,</span><span class="pln"> </span><span class="lit">' + y + '</span><span class="pun">,</span><span class="pln"> </span><span class="lit">' + spd + '</span><span class="pun">,</span><span class="pln"> </span><span class="lit">' + dir + '</span><span class="pun">,</span> <span class="str">"#' + nr + '"</span><span class="pun">);</span><span class="pln">\n</span><span class="pln">  balls</span><span class="pun">.</span><span class="pln">push_back</span><span class="pun">(&</span><span class="pln">b' + nr + '</span><span class="pun">);</span>\n';
  document.getElementById("balls").innerHTML += ball;
};

this.addRandomBall = function() {
  Example2.b_id++;
  var x = Math.floor(25 + Math.random() * 650);
  var y = Math.floor(25 + Math.random() * 380);
  var spd = Math.floor(4 + Math.random() * 8);
  var dir = Math.floor(Math.random() * 359);
  Example2.addBall(Example2.b_id, x, y, spd, dir, 0);
  Example2.balls.push(new Ball(Example2.g, x, y, 16, dir, spd, Example2.b_id, 0));  
};

this.addRandomCrazyball = function() {
  Example2.b_id++;
  var x = Math.floor(25 + Math.random() * 650);
  var y = Math.floor(25 + Math.random() * 380);
  var spd = Math.floor(4 + Math.random() * 8);
  var dir = Math.floor(Math.random() * 359);
  Example2.addBall(Example2.b_id, x, y, spd, dir, 1);
  Example2.balls.push(new Ball(Example2.g, x, y, 16, dir, spd, Example2.b_id, 1));  
};

this.draw = function() {
 Example2.g.clear();
 for(var i = 0; i < Example2.balls.length; i++) {
   if(i == 1) {
    Example2.balls[i].dir += 2 * Math.PI / 180; 
   }
   Example2.balls[i].move();
   Example2.balls[i].draw();
 }
};

this.init = function() {
  Example2.g = new Game(700, 430);
  Example2.g.init();
  Example2.balls.push(new Ball(Example2.g, 200, 225, 16, 45, 10, 1));
}

this.run = function() {
 Example2.d_int = window.setInterval("Example2.draw()", 100); 
}

this.stop = function() {
 window.clearInterval(Example2.d_int); 
}


this.compile = function() {
  document.getElementById("popup").style.display = "";
  Example2.balls[0].speed = 10;
  Example2.run();
}

this.kill = function() {
  document.getElementById("popup").style.display = "none";
  Example2.stop();
}

};
