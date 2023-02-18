for(let i = 0;i<10;i++){
    let rains = document.createElement("span");
    rains.style = `--i:${Math.random()}`;
    rain.append(rains)
}
var time = document.querySelector("#time");
function up(time_el) {
    let date = new Date();
    let h = date.getHours();
    let m = date.getMinutes();
    let s = date.getSeconds();
    let day_night = "AM";
    if (h > 12) {
        h = h - 12;
        day_night = "PM";
    }

    if (h < 10) { h = "0" + h; }
    if (m < 10) { m = "0" + m; }
    if (s < 10) { s = "0" + s; }
    time_el.textContent = h + ":" + m + ":" + s + " " + day_night;
}
   
setInterval(() => {
    up(time);
}, 1000);
