const canvas = document.querySelector('canvas');
const c = canvas.getContext('2d');

const canvasOffset = document.querySelector('nav');

canvas.width = window.innerWidth;
canvas.height = window.innerHeight - canvasOffset.offsetHeight;

canvas.addEventListener('mousemove', MouseMove, false);
canvas.addEventListener('click', MousePressed, false);

var circles = [];
var projectSubject = ["C#", "C#", "WEB", "JAVA"];
var projectName = ["Car tuner app", "Spaflash", "This webpage", "Sleep schedule improver"];

var mouseX;
var mouseY;

function RandomIntFromRange (min, max) {
    return Math.floor(Math.random() * (max - min + 1) + min)
}

function RandomIntExceptOneInt (min, max, except) {
    let number = RandomIntFromRange(min, max);
    
    while (number == except) {
        number = RandomIntFromRange(min, max);
    }

    return number;
}

function Distance (x1, y1, x2, y2) {
    let xDist = x2 - x1;
    let yDist = y2 - y1;

    return Math.sqrt(Math.pow(xDist, 2) + Math.pow(yDist, 2));
}

function Rotate(velocity, angle) {
    const rotatedVelocities = {
        x: velocity.x * Math.cos(angle) - velocity.y * Math.sin(angle),
        y: velocity.x * Math.sin(angle) + velocity.y * Math.cos(angle)
    };

    return rotatedVelocities;
}

function ResolveCollision(particle, otherParticle) {
    const xVelocityDiff = particle.velocity.x - otherParticle.velocity.x;
    const yVelocityDiff = particle.velocity.y - otherParticle.velocity.y;

    const xDist = otherParticle.x - particle.x;
    const yDist = otherParticle.y - particle.y;

    // Prevent accidental overlap of particles
    if (xVelocityDiff * xDist + yVelocityDiff * yDist >= 0) {

        // Grab angle between the two colliding particles
        const angle = -Math.atan2(otherParticle.y - particle.y, otherParticle.x - particle.x);

        // Store mass in var for better readability in collision equation
        const m1 = particle.mass;
        const m2 = otherParticle.mass;

        // Velocity before equation
        const u1 = Rotate(particle.velocity, angle);
        const u2 = Rotate(otherParticle.velocity, angle);

        // Velocity after 1d collision equation
        const v1 = { x: u1.x * (m1 - m2) / (m1 + m2) + u2.x * 2 * m2 / (m1 + m2), y: u1.y };
        const v2 = { x: u2.x * (m1 - m2) / (m1 + m2) + u1.x * 2 * m2 / (m1 + m2), y: u2.y };

        // Final velocity after rotating axis back to original location
        const vFinal1 = Rotate(v1, -angle);
        const vFinal2 = Rotate(v2, -angle);

        // Swap particle velocities for realistic bounce effect
        if (particle.velocity.x == 0) {
            otherParticle.velocity.x = vFinal2.x;
            otherParticle.velocity.y = vFinal2.y;
        }else if (otherParticle.velocity.x == 0) {
            particle.velocity.x = vFinal1.x;
            particle.velocity.y = vFinal1.y;
        }else {
            particle.velocity.x = vFinal1.x;
            particle.velocity.y = vFinal1.y;
    
            otherParticle.velocity.x = vFinal2.x;
            otherParticle.velocity.y = vFinal2.y;
        }
    }
}

function MouseMove (event) {
    mouseX = event.pageX;
    mouseY = event.pageY;

    for (var i = 0; i < circles.length; i++) {
        circles[i].interacted();
    }
}

function MousePressed () {
    for (var i = 1; i < circles.length; i++) {
        circles[i].imagesPressed();
    }
}

function Circle (xPos, yPos, subject, name, strokeColor, radius, circleSpotInArray) {
    this.x = xPos;
    this.y = yPos;
    this.velocity = {
        x: RandomIntExceptOneInt(-1, 1, 0),
        y: RandomIntExceptOneInt(-1, 1, 0)
    };
    this.radius = radius;
    this.color = strokeColor;
    this.mass = 1;
    this.subject = subject;
    this.name = name;
    this.toggle = false;
    this.circleSpotInArray = circleSpotInArray;

    this.update = circles => {
        this.draw();

        for (var i = 0; i < circles.length; i++) {
            if (circles[i] != this) {
                if (Distance(this.x, this.y, circles[i].x, circles[i].y) - this.radius * 2 <= 0 ) {
                    ResolveCollision(this, circles[i]);
                }
            }
        }

        if (this.x - this.radius <= 0 || this.x + this.radius >= canvas.width) {
            this.velocity.x = -this.velocity.x;
        }

        if (this.y - this.radius <= 0 || this.y + this.radius >= canvas.height) {
            this.velocity.y = -this.velocity.y;
        }

        if (this.velocity.x < 0 && -this.velocity.x < 1) {
            this.velocity.x -= RandomIntFromRange(0, 1);
        }else if (this.velocity.x > 0 && this.velocity.x < 1) {
            this.velocity.x += RandomIntFromRange(0, 1);
        }   

        if (this.velocity.y < 0 && -this.velocity.y < 1) {
            this.velocity.y -= RandomIntFromRange(0, 1);
        }else if (this.velocity.y > 0 && this.velocity.y < 1) {
            this.velocity.y += RandomIntFromRange(0, 1);
        }  

        if (this.velocity.x > 1)
        {
            this.velocity.x = 1;
        }else if (this.velocity.x < -1)
        {
            this.velocity.x = -1;
        }

        if (this.velocity.y > 1)
        {
            this.velocity.y = 1;
        }else if (this.velocity.y < -1)
        {
            this.velocity.y = -1;
        }

        this.x += this.velocity.x;
        this.y += this.velocity.y;
    }

    this.interacted = () => {
        if (Distance(this.x, this.y + canvasOffset.offsetHeight, mouseX, mouseY) - this.radius < 0) {
            this.toggle = true;
            this.color = 'rgb(187, 13, 13)';      
        }else {
            this.toggle = false;
            this.color = strokeColor;
        }

        this.draw();
    }

    this.imagesPressed = () => {
        if (this.toggle) {
            
        }        
    }

    this.linkPressed = () => {
        
    }

    this.draw = () => {
        c.beginPath();
        c.arc(this.x, this.y, this.radius, 0, Math.PI * 2, false)
        c.strokeStyle = this.color;
        c.stroke();
        c.textAlign = 'center';
        c.textBaseline = 'middle';
        c.font = '50px Fira Code';
        c.fillStyle = this.color;
        c.lineWidth = 5;
        c.fillText(this.subject, this.x, this.y);
        if (this.toggle) {
            
        }
        c.closePath();
    }
}

function Init () {
    let color = 'white';
    let smallCircleRadius = 100;

    for (let i = 0; i < projectSubject.length; i++) {
        let x = RandomIntFromRange(smallCircleRadius, canvas.width - smallCircleRadius);
        let y = RandomIntFromRange(smallCircleRadius, canvas.height - smallCircleRadius);
        let subject = projectSubject[i];
        let name = projectName[i];

        for (let j = 0; j < circles.length; j++) {
            while (Distance(x, y, circles[j].x, circles[j].y) - smallCircleRadius * 2 <= 0)
            {
                x = RandomIntFromRange(smallCircleRadius, canvas.width - smallCircleRadius);
                y = RandomIntFromRange(smallCircleRadius, canvas.height - smallCircleRadius);
            }
        }

        circles.push(new Circle(x, y, subject, name, color, smallCircleRadius, i));
    }
}

function Animate () {
    requestAnimationFrame(Animate);

    c.clearRect(0, 0, canvas.width, canvas.height);

    circles.forEach(circle => {
        circle.update(circles);
    });
}

Init();
Animate();