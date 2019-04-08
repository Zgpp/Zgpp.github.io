//Executes when page loads and it's ready to view
var step = 0;


var titles = [
  'Draw the type of face.', //0 title[0]
  'Add collar.', //1 title[1]
  'Add the hair to his head', //2 title[3]
  'Add his eyes and eyebrow.', //3
  'Add some detils' //4
  ];



$(function(){
 $('#stepinfo, section, footer, .prev').hide();
 $('body').css('background-color','white');
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
    $('#final').html('Would you like to <strong>Start again?</strong>')
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
