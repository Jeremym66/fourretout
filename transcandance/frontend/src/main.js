import { normalLogin } from './components/nav.js';
import { menubtn } from './components/nav.js';
import { navigate } from './components/nav.js';
import { logout } from './components/nav.js';
import { createNewUser } from './components/login.js';
import { switchToRegistrationForm } from './components/login.js';
import { changeMenuAfterLogin } from './components/nav.js';
import { showLoginWindow } from './components/nav.js';
import { switchDoubleAuth } from './components/identificator.js';
import { checkCodeF2A } from './components/identificator.js';
import { cancelF2A } from './components/identificator.js';
import { showMultiplayer } from './components/multiplayer.js';
import { hideMultiplayer } from './components/multiplayer.js';
import { multiAddPlayer } from './components/multiplayer.js';
import { init_page } from './components/menus.js';
import { display_qrcode } from './components/identificator.js';

import { login_with_42 } from './components/api42.js';


document.addEventListener('DOMContentLoaded', () => {
	const loginWith42Button = document.getElementById('login_with_42_Button')
	const mainmenu = document.getElementById('menu_Button');
	const firstMenu = document.getElementById('first-menu');
	const secondMenu = document.getElementById('second-menu');
	const normalLoginBtn = document.getElementById('normal_login_Button');
	const logoutButton = document.getElementById('logout_Button');
	const adminButton = document.getElementById("admin_Button");

	document.getElementById('createAccount-Button').addEventListener('click', switchToRegistrationForm);
	document.getElementById('register-Button').addEventListener('click', createNewUser);
	document.getElementById('popup-window').addEventListener('click', closePopup);

	// document.getElementById('generate-qrcode').addEventListener('click', createQRcode);
	document.getElementById('2fa-switch').addEventListener('change', switchDoubleAuth);
	document.getElementById('submit-2fa').addEventListener('click', checkCodeF2A);
	document.getElementById('cancel-2fa').addEventListener('click', cancelF2A);

	document.getElementById('multi_Button').addEventListener('click', showMultiplayer);
	document.getElementById('multi-btn').addEventListener('click', hideMultiplayer);
	document.getElementById('add-player-btn').addEventListener('click', multiAddPlayer);

	document.getElementById("2fa-switch").addEventListener("input", display_qrcode);

	adminButton.addEventListener('click', function() {
		window.location.href = 'https://localhost/api/admin';
	});

	loginWith42Button.addEventListener('click', login_with_42);
	normalLoginBtn.addEventListener('click', normalLogin);
	mainmenu.addEventListener('click', menubtn);
	logoutButton.addEventListener('click', logout);

	document.querySelectorAll('.menu-btn').forEach(button => {
		button.addEventListener('click', function() {
			if (this.disabled) return; // Si le bouton est désactivé, ne rien faire (évite les clics multiples
			const content = this.getAttribute('data-content');
			if (content != 'logout') {
				navigate(content);
			}
		});
	});

	navigate('home'); // Afficher le contenu d'accueil par défaut
	init_page();
});

function closePopup() {
	var popup = document.getElementById('popup-window');
	popup.classList.remove('active');
	if (popup.classList.contains('pop_to_connected')) {
		popup.classList.remove('pop_to_connected');
		changeMenuAfterLogin();
	} else if (popup.classList.contains('pop_registered')) {
		popup.classList.remove('pop_registered');
		showLoginWindow();
	}
}

export function getCookie(name) {
    var cookieValue = null;
    if (document.cookie && document.cookie !== '') {
        var cookies = document.cookie.split(';');
        for (var i = 0; i < cookies.length; i++) {
            var cookie = jQuery.trim(cookies[i]);
            if (cookie.substring(0, name.length + 1) === (name + '=')) {
                cookieValue = decodeURIComponent(cookie.substring(name.length + 1));
                break;
            }
        }
    }
    return cookieValue;
}
