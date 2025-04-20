const url = "https://api.openweathermap.org/data/2.5/weather";
const apiKey = "f00c38e0279b7bc85480c3fe775d518c";

$(document).ready(function () {
  weatherFn("Sambalpur");
});

async function weatherFn(cName) {
  const temp = `${url}?q=${cName}&appid=${apiKey}&units=metric`;
  try {
    const res = await fetch(temp);
    const data = await res.json();
    if (res.ok) {
      weatherShowFn(data);
    } else {
      alert("City not found. Please try again.");
    }
  } catch (error) {
    console.error("Error fetching weather data:", error);
  }
}

function weatherShowFn(data) {
  console.log(data);
  $("#city-name").text(data.name);
  $("#date").text(moment().format("MMMM Do YYYY, hh:mm:ss a"));
  let t = data.main.temp;
  t = t.toFixed(0);
  $("#temperature").html(`${t}°C`);
  $("#description").text(data.weather[0].description);
  let v = data.wind.speed;
  v *= 18 / 5;
  v = v.toFixed(2);
  $("#wind-speed").html(`Wind Speed: ${v} kmph`);
  $("#weather-icon").attr("src", `...`);
  $("#weather-info").fadeIn();
}
