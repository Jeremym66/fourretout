import { getCookie } from '../main.js';
import { actions_f2a_for_multi } from './multiplayer.js';

// $(function () {
// 	$('[data-toggle="popover"]').popover();
// });

export function showF2Apopup(caller) {
	if (!document.getElementById('f2a-window').classList.contains('active'))
		document.getElementById('f2a-window').classList.add('active');
    document.getElementById('caller-f2a').innerHTML = caller;
    setTimeout(function() { document.getElementById('code2fa').focus();}, 400);
}

export function hideF2Apopup() {
	document.getElementById('f2a-window').classList.remove('active');
}

export function cancelF2A() {
    hideF2Apopup();
}

export function checkCodeF2A() {
	var code = document.getElementById('code2fa').value;
	var code_box = document.getElementById('code2fa');
    var caller = document.getElementById('caller-f2a').innerText;

    $.ajax({
        url: '/api/check_double_auth/',  // URL of your Django view
        type: 'POST',
        data: {'code': code,
			   'user': document.getElementById('f2a-login').innerText,
               'caller': caller},
        beforeSend: function(xhr) {
            xhr.setRequestHeader("X-CSRFToken", getCookie("csrftoken"));
        },
        success: function(data) {
            if (data.error) {
				code_box.style.backgroundColor = "#fe7f7f";
				$('#code2fa').addClass('shake');
				setTimeout(function() {
					$('#code2fa').removeClass('shake');
				}, 1000);
			}
            else {
                if (caller === "login") {
                    actions_f2a_for_login(data);
                } else if (caller === "multi") {
                    actions_f2a_for_multi(data);
                } else if (caller === "enable-f2a") {
                    actions_f2a_for_enable_f2a(data);
                }
			}
        },
        error: function(xhr, status, error) {
        }
    });
};

function actions_f2a_for_login(data) {
    document.getElementById('f2a-window').classList.remove('active');
    document.getElementById('code2fa').value = "";

    document.getElementById('popup-text').innerText = "Welcome " + data.user;
    document.getElementById('popup-window').classList.add('active');
    document.getElementById('popup-window').classList.add('pop_to_connected');
    document.getElementById('profil-Btn').innerHTML = "<img src='" + data.img + "'/> " + data.user;
}



export function actions_f2a_for_enable_f2a(data) {

}



export function display_qrcode()
{
    var button2fa = document.getElementById("qrcode-container");
        if (button2fa.classList.contains("hidden")) {
        button2fa.classList.remove("hidden");
        } else {
        button2fa.classList.add("hidden");
        }
};



export function createQRcode() {
	$.ajax({
		url: '/api/get_saved_qr_code/',  // URL of your Django view
		type: 'POST',
		data: {generate_qrcode: true},
		beforeSend: function(xhr) {
			xhr.setRequestHeader("X-CSRFToken", getCookie("csrftoken"));
		},
        success: function(data) {
			if (data.error)
				console.log("Error: ", data);

			console.log('QR code data:', data);
            $('#qrcode-container').html(data); // Afficher le QR code dans la div
        },
        error: function(jqXHR, textStatus, errorThrown) {
            console.error('Error:', errorThrown);
        }
    });
};

export function switchDoubleAuth(){
    var switchButton = document.getElementById('2fa-switch');
    var state;
	if (switchButton.checked)
		state = 1;
	else
		state = 0;

    $.ajax({
        url: '/api/switch_double_auth/',  // URL of your Django view
        type: 'POST',
        data: {'state': state},
        beforeSend: function(xhr) {
            xhr.setRequestHeader("X-CSRFToken", getCookie("csrftoken"));
        },
        success: function(data) {
            // if (data.error)
            //     console.log("Error: ", data.error);
            // else
            //     console.log('Double auth status:', data.new_state);
        },
        error: function(xhr, status, error) {
        }
    });
}
