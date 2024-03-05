import { changeMenuAfterLogin } from './nav.js';

export function init_page() {
	$.ajax({
		url: '/api/get-session/',
		type: 'GET',
		success: function(data) {
			// NO USER LOGGED IN
			if (data.error || data.user === "undefined"){
				activate_buttons(false);
				return;
			}

			// USER LOGGED IN
			activate_buttons(true);
			var loginWith42Button = document.getElementById('login_with_42_Button')

			if (data.user && data.user != "undefined"){
				if (data.img){
					loginWith42Button.innerHTML = '<img src="' + data.img + '"/> ' + data.user;
					document.getElementById('profil-Btn').innerHTML = "<img src='" + data.img + "'/> " + data.user;
				} else {
					loginWith42Button.innerHTML = data.user;
					document.getElementById('profil-Btn').innerHTML = data.user;
				}
			}
			changeMenuAfterLogin();
		},
	});
}

export function activate_buttons(active){
	var buttons = document.getElementsByClassName('menu-btn'); // Get all buttons with class 'menu-btn'

	for (var i = 0; i < buttons.length; i++) {
		var button = buttons[i];
		var dataContent = button.getAttribute('data-content'); // Get the value of data-content

		if (dataContent === 'profil' || dataContent === 'game' || dataContent === 'settings') {
			if (active){
				button.disabled = false;
				button.classList.remove('disabled_btn');
			} else {
				button.disabled = true;
				if (!button.classList.contains('disabled_btn'))
					button.classList.add('disabled_btn');
			}
		}
	}
}
