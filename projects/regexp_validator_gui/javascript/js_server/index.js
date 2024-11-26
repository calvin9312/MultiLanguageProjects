const check_button = document.getElementById("check_button");
const clear_button = document.getElementById("clear_button");

const text_input = document.getElementById("text_input");
const pattern_input = document.getElementById("pattern_input");

check_button.addEventListener("click", function() {
  pattern = pattern_input.value
  text = text_input.value
  console.log("Check Button clicked!");
  console.log("Pattern = " + pattern);
  console.log("Text = " + text);

  apiUrl = '/text_match?pattern=' + pattern + '&text=' + text;
  fetch(apiUrl)
  .then(response => {
    if (!response.ok) {
      throw new Error('Network response was not ok');
    }
    return response.json();
  })
  .then(data => {
    success=data
    if (text && pattern) {
      if(success) {
        text_input.style.backgroundColor = "green";
      } else {
        text_input.style.backgroundColor = "red";
      }
    } else {
      text_input.style.backgroundColor = "";
    }
  })
  .catch(error => {
    console.error('Error:', error);
    text_input.style.backgroundColor = "";
  });

});

clear_button.addEventListener("click", function() {
  console.log("Clear Button clicked!");
  text_input.value = ""
  pattern_input.value = ""
  text_input.style.backgroundColor = "";
});
