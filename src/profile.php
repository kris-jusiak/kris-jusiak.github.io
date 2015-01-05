<?php 
    require_once 'aux.php';
    require_once 'simple_html_dom.php';

    $linkedin = file_get_html('http://www.linkedin.com/in/krzysztofjusiak');

	foreach ($linkedin->find('h3') as $element) {
		$element->innertext = '';
	}

	foreach ($linkedin->find('span[class=external-link-indicator]') as $element) {
		$element->innertext = '';
	}

	foreach ($linkedin->find('span[class=experience-date-locale]') as $element) {
		$element->innertext = '';
	}

	$body = 
		'<div class="rounded"><div class="inner">'
		.'<table><tr><td>'
		.$linkedin->find('div[class=profile-picture]', 0)->innertext
		.'</td><td>'
		.'</td></tr></table><hr/>'
		.$linkedin->find('div[id=background-summary-container]', 0)->innertext
		.'<b>Experience</b><hr />'
		.$linkedin->find('div[id=background-experience-container]', 0)->innertext
		.'<b>Education</b><hr />'
		.$linkedin->find('div[id=background-education-container]', 0)->innertext
		.'<b>Courses</b><hr />'
		.$linkedin->find('div[id=background-courses-container]', 0)->innertext
		.'<hr />'
		.'<a target="_blank" href="http://pl.linkedin.com/in/krzysztofjusiak"><img src="http://www.linkedin.com/img/webpromo/btn_viewmy_120x33.png" width="120" height="33" border="0" alt="View Krzysztof Jusiak\'s profile on LinkedIn" ></a>'
		.'</div></div>';

	$body = str_replace("<br> <br>", "<br/>", $body);

    printf(
        $html
      , $head
      , '<body>'
      , menu('About Me', '<u>Profile</u>', 'Projects', 'Blog', 'Resume / CV')
      , $body
      , '</body>'
    );
?>

