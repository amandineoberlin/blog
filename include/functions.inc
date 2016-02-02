<?php
//Fonctions REGEX pour verification des donnees du formulaire d'inscription

	function checkDateFR($dateFR) {
		$motif = '#^([0-2]?[0-9]|3[01])/([01]?[0-9])/([0-9]{4})$#';
		
		if(preg_match($motif, $dateFR)) {
			$tabDate = explode('/', $dateFR);
			return checkdate($tabDate[1], $tabDate[0], $tabDate[2]);
		} else {
			return false;
		}
	}
	
	function checkDateISO($dateISO) {
		$motif = '#^([0-9]{4})-([01]?[0-9])-([0-2]?[0-9]|3[01])$#';
		
		if(preg_match($motif, $dateISO)) {
			$tabDate = explode('-', $dateISO);
			return checkdate($tabDate[1], $tabDate[2], $tabDate[0]);
		} else {
			return false;
		}
	}
	
	function dateFR2ISO($dateFR) {
		$motif = '#^([0-2]?[0-9]|3[01])/([01]?[0-9])/([0-9]{4})$#';
		$replace = '$3-$2-$1';
		
		$dateISO = preg_replace($motif, $replace, $dateFR);
		
		if(!checkDateISO($dateISO)) {
			return false;
		} else {
			return $dateISO;
		}
	}
	
	function checkEmail($email) {
		$motif = '/^[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+\.[a-zA-Z]{2,}$/';
		
		return !!preg_match($motif, $email);
	}
	
	function checkSecu($secu) {
		$motif = '/^[12] *[0-9]{2} *(0[1-9]|1[0-2]) *(0[1-9]|[1-9][0-9]|2[ABab]) *([0-9]{3} *){2}[0-9]{2}$/';
		
		return !!preg_match($motif, $secu);
	}
	
	function checkTel($tel) {
		$motif = '/^(0|\+33 *)[1-9][. \/-]*([0-9]{2}[. \/-]*){3}[0-9]{2}$/';
		
		return !!preg_match($motif, $tel);
	}
	
	function formatTel($tel) {
		return preg_replace('/[. \/-]/', '', $tel);
	}
?>