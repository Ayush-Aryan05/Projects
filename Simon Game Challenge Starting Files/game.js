var buttonColours=["red", "blue", "green", "yellow"];
var gamePattern=[];

var userClickedPattern=[];

var stared=false ;

var level=0;

$(document).keypress(function (){
    if(!stared){
        $("#level-title").text("Level "+level);
        nextSequence();
        stared=true;
    }
} );
function nextSequence(){
    userClickedPattern = [];
    level++;
    $("#level-title").text("Level " + level);

    var randomNumber = Math.floor(Math.random()*4);
    randomChosenColour = buttonColours[randomNumber];
    gamePattern.push(randomChosenColour);

    // jQuery to select the button with same color id as randomChosenColour

    
    $("#"+randomChosenColour).fadeIn(100).fadeOut(100).fadeIn(100);

    playSound(randomChosenColour);


}

$(".btn").click(function (){
    var userChosenColour = $(this).attr("id");
    userClickedPattern.push(userChosenColour);
    playSound(userChosenColour);
    animatePress(userChosenColour);
    checkAnswer(userClickedPattern.length-1);
   // console.log(userClickedPattern);
});

function playSound(name ){
    var audio = new Audio("sounds/" + name + ".mp3");
    audio.play();
}

function animatePress(currentColour){
    $("#"+currentColour).addClass("pressed");
    
    function remove(){
        $("#"+currentColour).removeClass("pressed");
    }

    setTimeout(remove,100);
}
function checkAnswer(currentLevel){
    if(userClickedPattern[currentLevel]===gamePattern[currentLevel]) {
        console.log("success");

        if(gamePattern.length===userClickedPattern.length){
            setTimeout(function () {
                nextSequence();
              }, 1000);
      
        }
    }
    else {
        console.log("wrong");
        startover();
      //1. In the sounds folder, there is a sound called wrong.mp3, play this sound if the user got one of the answers wrong.
      playSound("wrong");

      //2. In the styles.css file, there is a class called "game-over", apply this class to the body of the website when the user gets one of the answers wrong and then remove it after 200 milliseconds.
      $("body").addClass("game-over");
      setTimeout(function () {
        $("body").removeClass("game-over");
      }, 200);

      //3. Change the h1 title to say "Game Over, Press Any Key to Restart" if the user got the answer wrong.
      $("#level-title").text("Game Over, Press Any Key to Restart");
    }

}


function startover(){
    level=0;
    gamePattern=[];
    stared=false;
}