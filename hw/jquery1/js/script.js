//Executes when page loads and it's ready to view
var step = 0;

$(function(){
 $('#stepinfo, section, footer').hide();

});

$('.start').on('click', function(){
  //do stuff when the button is clicked
  $('.intro').hide();
  $('footer').show();
  step = 1;
  $('#step'+step).show();

});
