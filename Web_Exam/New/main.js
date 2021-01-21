var nav0 = document.getElementById("home-a");
var nav1 = document.getElementById("about-a");
var nav2 = document.getElementById("projects-a");
var nav3 = document.getElementById("contact-a");

let url = window.location.href;
let sectionName = url.split("#");

ChangeTitle(sectionName[1]);

var moreExpanded = false;

function More () {
    if (!moreExpanded) {
        document.getElementById("more").style.display = "block";
        document.getElementById("more-button-icon").className = "fas fa-arrow-up";

        moreExpanded = true;
    }else {
        document.getElementById("more").style.display = "none";
        document.getElementById("more-button-icon").className = "fas fa-arrow-down";
        
        moreExpanded = false;
    }
}

function ChangeTitle (name) {
    let newNav0;
    let newNav1;
    let newNav2;
    let newNav3;

    newNav0 = nav0;
    newNav1 = nav1;
    newNav2 = nav2;
    newNav3 = nav3;

    switch (name) 
    {
        case "home":
            newNav0.style.color = "rgb(183, 13, 13)";
            newNav1.style.color = "white";
            newNav2.style.color = "white";
            newNav3.style.color = "white";

            document.title = "George T. - Home";
            break;
        case "about":
            newNav0.style.color = "white";
            newNav1.style.color = "rgb(183, 13, 13)";
            newNav2.style.color = "white";
            newNav3.style.color = "white";

            document.title = "George T. - About Me";
            break;
        case "projects":
            newNav0.style.color = "white";
            newNav1.style.color = "white";
            newNav2.style.color = "rgb(183, 13, 13)";
            newNav3.style.color = "white";

            document.title = "George T. - Projects";
            break;
        case "contact":
            newNav0.style.color = "white";
            newNav1.style.color = "white";
            newNav2.style.color = "white";
            newNav3.style.color = "rgb(183, 13, 13)";

            document.title = "George T. - Contact";
            break;
        default:
            newNav0.style.color = "rgb(183, 13, 13)";
            newNav1.style.color = "white";
            newNav2.style.color = "white";
            newNav2.style.color = "white";

            document.title = "George T. - Home";
    }
}