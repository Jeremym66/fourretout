import { changeMenuAfterLogin } from './nav.js';

export function login_with_42() {
	// Make AJAX request to retrieve session data
	$.ajax({
		url: '/api/get-session/',  // URL of your Django view
		type: 'GET',
		success: function(data) {
			if (data.error)
				window.location.href = 'https://localhost/api/data';
		},
		error: function(xhr, status, error) {
		}
	});
}

export function remove_session() {
	$.ajax({
		url: '/api/remove-session/',  // URL of your Django view
		type: 'GET',
		success: function(data) {
			var loginWith42Button = document.getElementById('login_with_42_Button')
			loginWith42Button.innerText = "Login with 42";
			document.getElementById('profil-Btn').innerHTML = '<i class="fas fa-user fontawesome_style"></i>';
		},
		error: function(xhr, status, error) {
		}
	});
}
