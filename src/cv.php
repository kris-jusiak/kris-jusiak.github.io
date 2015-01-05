<?php 
    include 'aux.php';

    printf(
        $html
      , $head
      , '<body>'
      , menu('About Me', 'Profile', 'Projects', 'Blog', '<u>Resume / CV</u>')
      , '<div class="rounded"><div class="inner">
        <hr />

        <table>
            <tr><td style="text-align:right;">EuroPass</td><td> | <a href="#cv_europass">View</a></td> <td> | <a href="cv/krzysztof_jusiak_cv_europass.pdf">Download</a></td></tr>
            <tr><td style="text-align:right;">UK</td><td> | <a href="#cv_uk">View</a></td><td> | <a href="cv/krzysztof_jusiak_cv_uk.pdf">Download</a></td></tr>
            <tr><td style="text-align:right;">US</td><td> | <a href="#cv_us">View</a></td><td> | <a href="cv/krzysztof_jusiak_cv_us.pdf">Download</a></td></tr>
            <tr><td><hr /></td><td><hr /></td></tr>
            <tr><td style="text-align:right;">Github</td><td> | <a target="_blank" href="http://resume.github.io/?krzysztof-jusiak">View</a></td><td> | </td></tr>
        </table>

        <br />
        <hr />

        <iframe id="cv_europass" src="http://docs.google.com/viewer?url=http%3A%2F%2Fkrzysztof-jusiak.github.io%2Fcv%2Fkrzysztof_jusiak_cv_europass.pdf&embedded=true" width="100%" height="100%" style="border: none;"></iframe>
        <iframe id="cv_uk" src="http://docs.google.com/viewer?url=http%3A%2F%2Fkrzysztof-jusiak.github.io%2Fcv%2Fkrzysztof_jusiak_cv_uk.pdf&embedded=true" width="100%" height="100%" style="border: none;"></iframe>
        <iframe id="cv_us" src="" width="100%" height="100%" style="border: none;"></iframe>'

      .'</div></div>'
      , '</body>'
    );
?>

