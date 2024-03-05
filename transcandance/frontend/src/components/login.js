import { hideLoginWindow } from './nav.js';
import { showRegistrationWindow } from './nav.js';
import { hideRegistrationWindow } from './nav.js';
import { getCookie } from '../main.js';
import { showF2Apopup } from './identificator.js';

export function createNewUser() {
	// console.log("Creating new user");

	var username = document.getElementById('username-reg');
    var password = document.getElementById('password-reg');
	var password2 = document.getElementById('password-repeat');
	var email = document.getElementById('email');
	var firstname = document.getElementById('firstname');

	if (username.value == "") {
		username.style.backgroundColor = "#fe7f7f"; username.focus(); return;
	}
	if (password.value.length < 8 || password.value == "") {
		document.getElementById('password-strength').style.display = "";
		password.style.backgroundColor = "#fe7f7f"; password.focus(); return;
	} else {
		document.getElementById('password-strength').style.display = "none";
	}
	if (password2.value != password.value) {
		password2.style.backgroundColor = "#fe7f7f"; password2.focus(); return;
	}
	if (firstname.value == "") {
		firstname.style.backgroundColor = "#fe7f7f"; firstname.focus(); return;
	}
	var re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    var emailTest = re.test(String(email.value).toLowerCase());
	if (email.value == "" || !emailTest) {
		email.style.backgroundColor = "#fe7f7f"; email.focus(); return;
	}

	var shaPassword = sha256(password.value);
	// Make AJAX request to retrieve session data
	$.ajax({
		url: '/api/register-new-user/',  // URL of your Django view
		type: 'POST',
		data: {
			username: username.value,
			password: shaPassword,
			email: email.value,
			firstname: firstname.value
		},
		beforeSend: function(xhr) {
			xhr.setRequestHeader("X-CSRFToken", getCookie("csrftoken"));
		},
		success: function(data) {
			if (data.error) {
				// console.log("Error: ", data.error);
				if (data.error === 'username'){
					username.style.backgroundColor = "#fe7f7f";
					$('#username-reg').addClass('shake');
					setTimeout(function() {
						$('#username-reg').removeClass('shake');
					}, 1000);
				}
				else if (data.error === 'email'){
					email.style.backgroundColor = "#fe7f7f";
					$('#email').addClass('shake');
					setTimeout(function() {
						$('#email').removeClass('shake');
					}, 1000);
				}
				return;
			}
			// empty all fields
			username.value = "";
			password.value = "";
			password2.value = "";
			email.value = "";
			firstname.value = "";

			hideRegistrationWindow();
			document.getElementById('popup-text').innerText = "You are registered !\nPlease login now";
			document.getElementById('popup-window').classList.add('active');
			document.getElementById('popup-window').classList.add('pop_registered');
			setTimeout(function() { document.getElementById('popup-Button').focus();}, 400);
		},
		error: function(xhr, status, error) {
		}
	});
};

export function switchToRegistrationForm() {
	// console.log("Switching to registration form");
	hideLoginWindow();
	showRegistrationWindow();
}

export function submitForm() {
    var username = document.getElementById('username');
    var password = document.getElementById('password');

	if (username.value == "") {
		username.style.backgroundColor = "#fe7f7f";
		username.focus();
		return;
	}
	if (password.value == "") {
		password.style.backgroundColor = "#fe7f7f";
		password.focus();
		return;
	}
	// sha256(password.value);
	var shaPassword = sha256(password.value);
	// Make AJAX request to retrieve session data
	$.ajax({
		url: '/api/normal_login/',  // URL of your Django view
		type: 'POST',
		data: {
			username: username.value,
			password: shaPassword
		},
		beforeSend: function(xhr) {
			xhr.setRequestHeader("X-CSRFToken", getCookie("csrftoken"));
		},
		success: function(data) {
			if (data.error) {
				// console.log("Error: ", data.error);
				if (data.error === 'username'){
					username.style.backgroundColor = "#fe7f7f";
					$('#username').addClass('shake');
					setTimeout(function() {
						$('#username').removeClass('shake');
					}, 1000);
				}
				else if (data.error === 'password'){
					password.style.backgroundColor = "#fe7f7f";
					$('#password').addClass('shake');
					setTimeout(function() {
						$('#password').removeClass('shake');
					}, 1000);
				}
				else if (data.error === 'api'){
					alert("Your account is registered with 42 API, please use the 42 login button");
				}
				return;
			}

			hideLoginWindow();
			if (data.f2a === true) {
				document.getElementById('f2a-login').innerText = username.value;
				showF2Apopup("login");
			} else {
				document.getElementById('popup-text').innerText = "Welcome " + data.user;
				document.getElementById('popup-window').classList.add('active');
				document.getElementById('popup-window').classList.add('pop_to_connected');
				document.getElementById('profil-Btn').innerHTML = "<img src='" + data.img + "'/> " + data.user;
			}
			// empty all fields
			username.value = "";
			password.value = "";
		},
		error: function(xhr, status, error) {
		}
	});

}

// Attach the submitForm function to the form submit event
window.addEventListener('load', (event) => {
    document.getElementById('login-form').addEventListener('submit', function(event) {
        event.preventDefault();
        submitForm();
    });
});

