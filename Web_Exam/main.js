var nav0 = document.getElementsByClassName("nav-projects");
var nav1 = document.getElementsByClassName("nav-about");
var nav2 = document.getElementsByClassName("nav-contact");

ChangeTitle("");

$("#nav-dropdown-menu").on("click", function() {
    $("nav").toggleClass("open");
});

$(document).ready(function() {
    $("button").on('click', function(event) {
        var hash = $(this).data("hash");
        if (hash) {
            $('html, body').stop().animate({
                scrollTop: $(document.getElementById(hash)).offset().top
            }, 800, function() {
                window.location.hash = hash;                
            });
        }
    });
});

function ChangeTitle (name) {
    let newNav0;
    let newNav1;
    let newNav2;

    if (screen.width <= 425)
    {
        newNav0 = nav0[0];
        newNav1 = nav1[0];
        newNav2 = nav2[0];
    }
    else
    {
        newNav0 = nav0[1];
        newNav1 = nav1[1];
        newNav2 = nav2[1];
    }

    switch (name) 
    {
        case "projects":
            newNav0.style.color = "rgb(183, 13, 13)";
            newNav1.style.color = "white";
            newNav2.style.color = "white";

            document.title = "George T. - Projects";
            break;
        case "about":
            newNav0.style.color = "white";
            newNav1.style.color = "rgb(183, 13, 13)";
            newNav2.style.color = "white";

            document.title = "George T. - About Me";
            break;
        case "contact":
            newNav0.style.color = "white";
            newNav1.style.color = "white";
            newNav2.style.color = "rgb(183, 13, 13)";

            document.title = "George T. - Contact";
            break;
        default:
            newNav0.style.color = "rgb(183, 13, 13)";
            newNav1.style.color = "white";
            newNav2.style.color = "white";

            document.title = "George T. - Projects";
    }
}