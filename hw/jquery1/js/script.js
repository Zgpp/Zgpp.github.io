//Executes when page loads and it's ready to view
var step = 0;

var titles = [
  'Prepare for take-off', //0 title[0]
  'Put seatbelt on', //1 title[1]
  'Turn on the engines', //2 title[3]
  'Turn the lights on', //3
  'Press go!' //4
  ];



$(function(){
 $('#stepinfo, section, footer, .prev').hide();
 $('body').css('background-color','red');
});

//We use the start button to begin our tutorial
$('.start').on('click', function(){
  //do stuff when the button is clicked
  $('.intro').hide();
  $('footer, #stepinfo').show();
  step = 1;

  $('#step'+step).show();
  //set the title for our current step
  $('#stepinfo').text('Step'+step+': '+titles[step-1]);
});

//Next to advance each slide
$('.next').on('click', function(){
  $('#step'+step).hide();
  //step = step + 1;
  step++;
  if(step == 2) {
    $('.prev').show();
  }

  if(step == 5) {
    $('.next').hide();
    $('#final').html('We are dont <strong>Start again?</strong>')
  }

  //make the change only if we are under our number of 6
  if (step <= 5){
    $('#step'+step).show();
    $('#stepinfo').text('Step'+step+': '+titles[step-1]);
  }
  else {
      step--;
      $('#step'+step).show();
      $('.next').hide();
    }


});

//Previous
$('.prev').on('click', function(){
  $('#step'+step).hide();
  //step = step + 1;
  step--;
  if(step == 1) {
    $('.prev').hide();
  } else {
    $('.next').show();
  }

  if(step == 5) {
    $('.next').hide();
  }

  //make the change only if we are under our number of 6
  if (step >= 1){
    $('#step'+step).show();
    $('#stepinfo').text('Step'+step+': '+titles[step-1]);
  }
  else {
      step--;
      $('#step'+step).show();
    }


});
