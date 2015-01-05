<?php

    $head = '
        <head>
            <title>Krzysztof Jusiak</title>
            <link rel="stylesheet" type="text/css" media="all" href="style.css" />
        </head>
    ';

    $html = '
        <html>
            %s %s %s %s %s

        </div></html>
    ';

    function menu($aboutme, $profile, $projects, $blog, $resume) {
        $menu = '
            <div id="page" class="hfeed">

            <a href="http://krzysztof.jusiak.net"><img src="img/logo.jpg" width="100%" height="240"/></a>

            <nav id="access">
                <div class="menu">
                    <ul>
                        <li class="home">
                            <a href="index.php">'.$aboutme.'</a>
                        </li>

                        <li class="profile">
                            <a href="profile.php">'.$profile.'</a>
                        </li>

                        <li class="projects">
                            <a href="projects.php">'.$projects.'</a>
                        </li>

                        <li class="blog">
                            <a href="blog.php">'.$blog.'</a>
                        </li>

                        <li class="cv">
                            <a href="cv.php">'.$resume.'</a>
                        </li>
                    </ul>
                </div>
            </nav>
        ';

        return $menu;
    }

?>

