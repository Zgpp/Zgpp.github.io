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

});

$('.start').on('click', function(){
  //do stuff when the button is clicked
  $('.intro').hide();
  $('footer, #stepinfo').show();
  step = 1;
  $('#step'+step).show();
  //set the title for our current step
  $('#stepinfo').text('Step'+step+': 'titles[step-1]);
});

$('.next').on('click', function(){
  //step = step + 1;
  $('#step'+step).hide();
  step++;
  $('#step'+step).show();
  $('#stepinfo').text('Step'+step+': 'titles[step-1]);

});
