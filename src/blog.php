<?php
    require_once 'aux.php';
    include_once('geshi.php');

    function cpp_file($file) {
        return cpp_code(substr(file_get_contents($file), 0, -2));
    }

    function review_file($file) {
        return review(substr(file_get_contents($file), 0, -2));
    }

    function cpp_code($code) {
        $geshi = new GeSHi($code, 'cpp');
        $geshi->enable_line_numbers(true);
        return $geshi->parse_code();
    }

    function review($code) {
        $geshi = new GeSHi($code, 'html');
        return $geshi->parse_code();
    }

    function sh_code($code) {
        $geshi = new GeSHi($code, 'sh');
        return $geshi->parse_code();
    }

    eval(file_get_contents('blog.txt'));

    printf(
        $html
      , $head
      , '<body>'
      , menu('About Me', 'Profile', 'Projects', '<u>Blog</u>', 'Resume / CV')
      , '<div class="rounded"><div class="inner"><hr />'.$blog
      .'<a href="https://twitter.com/krzysztofjusiak" class="twitter-follow-button" data-show-count="false">Follow @krzysztofjusiak</a><script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?\'http\':\'https\';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+\'://platform.twitter.com/widgets.js\';fjs.parentNode.insertBefore(js,fjs);}}(document, \'script\', \'twitter-wjs\');</script>'
      .'</div></div>'
      , '</body>'
    );

?>

