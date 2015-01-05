<?php 
    require_once 'aux.php';
    require_once 'simple_html_dom.php';

    function get_github($url) {
        $base = "https://api.github.com/";
        $curl = curl_init();
        curl_setopt($curl, CURLOPT_URL, $base . $url);
        curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
        curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);
        $content = curl_exec($curl);
        curl_close($curl);
        return json_decode($content, true);
    }

    $linkedin = file_get_html('http://www.linkedin.com/in/krzysztofjusiak');

	foreach ($linkedin->find('h3') as $element) {
		$element->innertext = '';
	}

	foreach ($linkedin->find('span[class=external-link-indicator]') as $element) {
		$element->innertext = '';
	}

    $body = 
        '<div class="rounded"><div class="inner"><hr />'
		.$linkedin->find('div[id=background-projects-container]', 0)->innertext
        .'<hr />'
        .'<iframe src="http://githubbadge.appspot.com/badge/krzysztof-jusiak?a=0" style="border: 0;height: 112px;width: 200px;overflow: hidden;" frameBorder=0></iframe>'
        .'</div></div>';

    printf(
        $html
      , $head
      , '<body>'
      , menu('About Me', 'Profile', '<u>Projects</u>', 'Blog', 'Resume / CV')
      , $body
      , '</body>'
    );
?>

