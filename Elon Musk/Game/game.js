// 🔹 ক্যানভাস সেটআপ
const canvas = document.getElementById("gameCanvas");
const ctx = canvas.getContext("2d");
canvas.width = 800;
canvas.height = 600;

// 🔹 প্লেয়ার সেটআপ
let player = {
    x: canvas.width / 2 - 25,
    y: canvas.height - 70,
    width: 50,
    height: 50,
    speed: 7
};

// 🔹 বুলেট ও শত্রুদের জন্য অ্যারে
let bullets = [];
let enemies = [];
let score = 0;
let gameOver = false;

// 🔹 প্লেয়ার আঁকা ফাংশন
function drawPlayer() {
    ctx.fillStyle = "blue";
    ctx.fillRect(player.x, player.y, player.width, player.height);
}

// 🔹 বুলেট আঁকা ফাংশন
function drawBullets() {
    ctx.fillStyle = "red";
    bullets.forEach((bullet, index) => {
        bullet.y -= 5;
        ctx.fillRect(bullet.x, bullet.y, 5, 10);

        if (bullet.y < 0) {
            bullets.splice(index, 1); // স্ক্রিনের বাইরে গেলে মুছে ফেলবে
        }
    });
}

// 🔹 শত্রুদের আঁকা ফাংশন
function drawEnemies() {
    ctx.fillStyle = "green";
    enemies.forEach((enemy, index) => {
        enemy.y += 2; // শত্রুর নিচে নামা
        ctx.fillRect(enemy.x, enemy.y, 40, 40);

        if (enemy.y > canvas.height) {
            gameOver = true; // যদি প্লেয়ারের কাছে পৌঁছে যায়, গেম শেষ
        }
    });
}

// 🔹 শত্রু তৈরির ফাংশন
function spawnEnemies() {
    if (Math.random() < 0.02) { // প্রতি ফ্রেমে ২% চান্স শত্রু আসার
        enemies.push({ x: Math.random() * (canvas.width - 40), y: 0 });
    }
}

// 🔹 কীবোর্ড ইভেন্ট হ্যান্ডলার
window.addEventListener("keydown", (e) => {
    if (e.key === "ArrowLeft" && player.x > 0) {
        player.x -= player.speed; // বাঁ দিকে যাওয়া
    }
    if (e.key === "ArrowRight" && player.x < canvas.width - player.width) {
        player.x += player.speed; // ডান দিকে যাওয়া
    }
    if (e.key === " ") {
        bullets.push({ x: player.x + 22, y: player.y }); // স্পেসবার চাপলে গুলি ছোড়ে
    }
});

// 🔹 বুলেট ও শত্রুর কোলিশন ডিটেকশন
function checkCollisions() {
    bullets.forEach((bullet, bIndex) => {
        enemies.forEach((enemy, eIndex) => {
            if (
                bullet.x < enemy.x + 40 &&
                bullet.x + 5 > enemy.x &&
                bullet.y < enemy.y + 40 &&
                bullet.y + 10 > enemy.y
            ) {
                // বুলেট শত্রুকে আঘাত করলে
                bullets.splice(bIndex, 1);
                enemies.splice(eIndex, 1);
                score += 10; // স্কোর বাড়ানো
            }
        });
    });
}

// 🔹 স্কোর দেখানোর ফাংশন
function drawScore() {
    ctx.fillStyle = "white";
    ctx.font = "20px Arial";
    ctx.fillText("Score: " + score, 20, 30);
}

// 🔹 গেম আপডেট ফাংশন
function updateGame() {
    if (gameOver) {
        ctx.fillStyle = "white";
        ctx.font = "40px Arial";
        ctx.fillText("Game Over", canvas.width / 2 - 100, canvas.height / 2);
        return;
    }

    ctx.clearRect(0, 0, canvas.width, canvas.height);
    drawPlayer();
    drawBullets();
    drawEnemies();
    drawScore();
    spawnEnemies();
    checkCollisions();
    
    requestAnimationFrame(updateGame);
}

updateGame();
