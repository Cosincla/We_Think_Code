var video = document.getElementById('video');
var sticker = document.getElementById('sticker');
var uphoto = document.getElementById('uphoto');
var img1 = new Image();
var img2 = new Image();
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
canvas.height = 220;
var context = canvas.getContext('2d');
var video = document.getElementById('video');
document.getElementById('capture').addEventListener("click", function(){
  var video = document.getElementById('video');
  context.drawImage(video, 0, 0, 320, 220);
  context.drawImage(img2, 0, 0, 320, 220);
  context.drawImage(img1, 0, 0, 320, 220);
});

function loadPicture(e) {
  img1.src = e.target.src;
  if (sticker.style.backgroundImage === 'url("'+img1.src+'")') {
    sticker.style.backgroundImage = "none";
  }
  else {
    sticker.style.backgroundImage = "url('"+e.target.src+"')";
  }
}

function upload(e) {
  img2.src = e.target.src;
  uphoto.style.backgroundImage = crap;
}