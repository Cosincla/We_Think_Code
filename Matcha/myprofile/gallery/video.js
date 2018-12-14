var video = document.getElementById('video');
var uphoto = document.getElementById('uphoto');
var img1 = new Image();
var img2 = new Image();
var img3 = new Image();
img1.src = '';
img2.src = '';
if(navigator.mediaDevices && navigator.mediaDevices.getUserMedia) {
    navigator.mediaDevices.getUserMedia({ video: true })
      .then(
        function(stream) {
          video.src = window.URL.createObjectURL(stream);
          video.play();
        }
      );
}

var canvas = document.getElementById('canvas');
var canvas_2 = document.getElementById('canvas_2');

canvas.height = 220;
var context = canvas.getContext('2d');
var context_2 = canvas_2.getContext('2d');
var video = document.getElementById('video');
var uphoto = document.getElementById('uphoto').style.backgroundImage;
var res = uphoto.slice(5, -2);
var image = document.getElementById('sub_image');

if (uphoto) 
  img3.src = res;
document.getElementById('capture').addEventListener("click", function(){
  context.drawImage(video, 0, 0, 320, 220);
  context_2.drawImage(video, 0, 0, 320, 220);
  context.drawImage(img3, 0, 0, 320, 220);
  var camera = canvas_2.toDataURL('image/png');
  if (img3.src == ''){
    image.value = camera;
  }
  else{
    image.value = img3.src;
  }
});

document.getElementById('clear').addEventListener("click", function(){
  uphoto.style.backgroundImage = "none";
});