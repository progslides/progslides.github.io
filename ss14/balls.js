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

function Ball(game, x, y, radius, dir, speed) {
 this.x = x;
 this.y = y;
 this.dir = dir * Math.PI / 180;
 this.speed = speed;
 this.game = game;
 this.radius = radius;
 
 this.move = function() {
  this.x += Math.cos(this.dir) * this.speed;
  this.y += Math.sin(this.dir) * this.speed;
  
  if(this.x <= this.radius*2 || this.x > this.game.width - this.radius * 2) 
    this.dir = Math.atan2(Math.sin(this.dir), -Math.cos(this.dir));
  if(this.y <= this.radius*2 || this.y > this.game.height - this.radius * 2) 
    this.dir = Math.atan2(-Math.sin(this.dir), Math.cos(this.dir));
  
 };
 
 this.draw = function() {
  this.game.board.beginPath();
  this.game.board.arc(this.x, this.y, 24, 0, 2*Math.PI, false);
  this.game.board.fillStyle = "#ff0000";
  this.game.board.strokeStyle = "#404040";
  this.game.board.lineWidth = 1;
  this.game.board.fill();
  this.game.board.stroke();
 };

}

var Example = new function() {

this.g = null;
this.b_id = 1;
this.balls = [];
this.d_int = 1;
 
this.addBall = function(nr, x, y, spd, dir) {
  var ball = '<span class="pln">  </span><span class="typ">Ball</span><span class="pln"> b' + nr +'</span><span class="pun">(</span><span class="lit">' + x + '</span><span class="pun">,</span><span class="pln"> </span><span class="lit">' + y + '</span><span class="pun">,</span><span class="pln"> </span><span class="lit">' + spd + '</span><span class="pun">,</span><span class="pln"> </span><span class="lit">' + dir + '</span><span class="pun">);</span><span class="pln">\n</span>';
  document.getElementById("balls").innerHTML += ball;

  var ball_move = '<span class="pln">    b' + nr + '</span><span class="pun">.</span><span class="pln">move</span><span class="pun">();</span><span class="pln">\n</span>';
  document.getElementById("ball_move").innerHTML += ball_move;
};

this.addRandomBall = function() {
  Example.b_id++;
  var x = Math.floor(25 + Math.random() * 650);
  var y = Math.floor(25 + Math.random() * 380);
  var spd = Math.floor(4 + Math.random() * 8);
  var dir = Math.floor(Math.random() * 359);
  Example.addBall(Example.b_id, x, y, spd, dir);
  Example.balls.push(new Ball(Example.g, x, y, 16, dir, spd));  
};

this.draw = function() {
 Example.g.clear();
 for(var i = 0; i < Example.balls.length; i++) {
   if(i == 0) {
    if(Example.balls[0].speed < 20) Example.balls[0].speed += 0.1; 
   }
   Example.balls[i].move();
   Example.balls[i].draw();
 }
};

this.init = function() {
  Example.g = new Game(700, 430);
  Example.g.init();
  Example.balls.push(new Ball(Example.g, 200, 225, 16, 45, 10));
}

this.run = function() {
 Example.d_int = window.setInterval("Example.draw()", 100); 
}

this.stop = function() {
 window.clearInterval(Example.d_int); 
}


this.compile = function() {
  document.getElementById("popup").style.display = "";
  Example.balls[0].speed = 10;
  Example.run();
}

this.kill = function() {
  document.getElementById("popup").style.display = "none";
  Example.stop();
}

};
