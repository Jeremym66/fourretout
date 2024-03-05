import { get_highscores } from './highscores.js';
import { get_player_infos } from './profil_infos.js';
import { remove_session } from './api42.js';
import { activate_buttons } from './menus.js';
import { hideF2Apopup } from './identificator.js';
import { get_player_infos_settings } from './settings.js';

export function normalLogin() {
	var loginWindow = document.getElementById('login-window');
	if (loginWindow.classList.contains('active')) {
		hideLoginWindow();
	} else {
		hideRegistrationWindow();
		hideF2Apopup();
		showLoginWindow();
	}
}

export function showLoginWindow() {
    document.getElementById('login-window').classList.add('active');
	document.getElementById('username').focus();
}

export function hideLoginWindow() {
    document.getElementById('login-window').classList.remove('active');
}

export function showRegistrationWindow() {
    document.getElementById('register-window').classList.add('active');
	document.getElementById('username-reg').focus();
}

export function hideRegistrationWindow() {
    document.getElementById('register-window').classList.remove('active');
}

export function menubtn() {
	document.getElementById('first-menu').classList.remove('slideIn');
	document.getElementById('second-menu').classList.remove('slideOut');
	document.getElementById('first-menu').classList.add('slideOut');
	document.getElementById('second-menu').classList.add('slideIn');
	hideF2Apopup();
	hideLoginWindow();
	hideRegistrationWindow();
}

export function changeMenuAfterLogin() {
	document.getElementById('first-menu').classList.add('slideOutDelay');
	document.getElementById('second-menu').classList.add('slideInDelay');
	activate_buttons(true);
}

export function navigate(content) {
	// Masquer toutes les sections
	document.querySelectorAll('#content > section').forEach(section => {
	section.style.display = 'none';
	});

	if (content) { // Vérifie si content n'est pas undefined avant de tenter d'afficher la section
		if (content != 'profil')
			document.getElementById(`${content}-content`).style.display = 'block';
		else
			document.getElementById('profil-content').style.display = '';
		if (content === 'leaderboard') {
			get_highscores();
		} else if (content === 'profil') {
			get_player_infos();
		} else if (content === 'settings') {
			get_player_infos_settings();
		}
	}
}

export function logout() {
	remove_session();
	navigate('home');
	activate_buttons(false);
	var firstMenu = document.getElementById('first-menu');
	var secondMenu = document.getElementById('second-menu');
	firstMenu.classList.remove('slideOutDelay');
	firstMenu.classList.remove('slideOut');
	firstMenu.classList.add('slideIn');
	secondMenu.classList.remove('slideInDelay');
	secondMenu.classList.remove('slideIn');
	secondMenu.classList.add('slideOut');
}
