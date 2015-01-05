<?php 
    require_once 'aux.php';

    $body = '
        <style type="text/css">
        .gallerycontainer{
        position: relative;
        }

        .thumbnail img{
        border: 1px solid white;
        margin: 0 5px 5px 0;
        }

        .thumbnail:hover{
        background-color: transparent;
        }

        .thumbnail:hover img{
        border: 1px solid blue;
        }

        .thumbnail span{ /*CSS for enlarged image*/
        position: absolute;
        background-color: lightyellow;
        padding: 5px;
        left: -1000px;
        border: 1px dashed gray;
        visibility: hidden;
        color: black;
        text-decoration: none;
        }

        .thumbnail span img{ /*CSS for enlarged image*/
        border-width: 0;
        padding: 2px;
        }

        .thumbnail:hover span{ /*CSS for enlarged image*/
        visibility: visible;
        top: 0;
        left: 230px; /*position where enlarged image should offset horizontally */
        z-index: 50;
        }

        </style>
        <div class="gallerycontainer">
        Hi, I\'m  <a class="thumbnail" href="">Krzysztof/Kris<span><img width="250" height="250" src="img/krzysztof_jusiak.jpg" /></span></a> and I\'m really happy to see you on my personal website :)<br/>
        </div>

        <hr/>

        I\'m a software engineer, graduated from <a target="_blank" href="http://www.portal.pwr.wroc.pl/index,242.dhtml">Wroclaw University of Technology</a> in <a target="_blank" href="https://maps.google.com/maps?f=q&source=embed&hl=en&geocode=&q=Wroclaw,+Poland&aq=0&oq=wroclaw&t=h&ie=UTF8&hq=&hnear=Wroc%C5%82aw,+Wroc%C5%82aw+County,+Lower+Silesian+Voivodeship,+Poland&ll=51.104815,17.050781&spn=0.064671,0.137329&z=11&iwloc=A">Poland</a>.<br />
        I\'ve been programming in various languages since childchood, but C++ is the one which won me over by its scalability, efficiency and potential. <br />
        <a target="_blank" href="http://www.boost.org/">Boost libraries</a> on the other hand, amazed me from day dot and I really do enjoy using them all the time. <br />
        I\'m <a target="_blank" href="https://www.kernel.org/">linux</a> enthusiast and user for many years, currently <a target="_blank" href="http://www.sabayon.org/">sabayon</a>
        is the distrubution I\'m using the most with <a target="_blank" href="http://gcc.gnu.org/">gcc</a> and <a target="_blank" href="http://clang.llvm.org/">clang</a> as a compilers,
        can\'t imagine my daily life without <a target="_blank" href="http://www.vim.org/">vim</a> and <a target="_blank" href="http://git-scm.com/">git</a> tho.<br />
        Really enjoy being a part of the <a target="_blank" href="http://en.wikipedia.org/wiki/Open_source">open source</a> community and I\'m supporting it with all my strength.<br />
        Besides technical interests, I enjoy playing basketball, swimming, <a target="_blank" href="http://www.strava.com/athletes/kjusiak">cycling</a>, traveling and reading books.
        
        <br />
        <br />
        <hr />

        contact<br />
        <ul>
            <li>e-mail: <a href="mailto:krzysztof@jusiak.net">krzysztof@jusiak.net</a></li>
            <li>gtalk:&nbsp;&nbsp; <a href="gtalk:chat?jid=krzysztof@jusiak.net">krzysztof@jusiak.net</a></li>
            <li>skype: <a href="skype:krzysztof.jusiak?chat">krzysztof.jusiak</a></li>
        </ul>

        <hr />
        <a href="https://www.facebook.com/jusiak.krzysztof" target="_blank" title="Krzysztof Jusiak"><img src="https://badge.facebook.com/badge/100004049881447.335.233195810.png" style="border: 0px;" /></a>
    ';

    printf(
        $html
      , $head
      , '<body>'
      , menu('<u>About Me</u>', 'Profile', 'Projects', 'Blog', 'Resume / CV')
      , '<div class="rounded"><div class="inner">'.$body.'</div></div>'
      , '</body>'
    );

?>
