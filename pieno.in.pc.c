<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<title>Touch Piano</title>
<style>
    body {
        margin: 0;
        height: 100vh;
        display: flex;
        justify-content: center;
        align-items: center;
        background-color: #0b1c3d;
        overflow: hidden;
        font-family: Arial, sans-serif;
    }

    /* Gold stars */
    body::before {
        content: "";
        position: absolute;
        width: 100%;
        height: 100%;
        background-image:
            radial-gradient(gold 1px, transparent 1px),
            radial-gradient(gold 1px, transparent 1px);
        background-size: 60px 60px;
        background-position: 0 0, 30px 30px;
        opacity: 0.5;
    }

    .piano {
        position: relative;
        display: flex;
        z-index: 1;
    }

    .white-key {
        width: 50px;
        height: 220px;
        background: white;
        border: 1px solid #000;
        box-sizing: border-box;
        cursor: pointer;
        position: relative;
    }

    .white-key:active {
        background: #ddd;
    }

    .black-key {
        width: 30px;
        height: 140px;
        background: black;
        position: absolute;
        top: 0;
        right: -15px;
        z-index: 2;
        cursor: pointer;
    }

    .black-key:active {
        background: #444;
    }
</style>
</head>
<body>

<div class="piano">
    <!-- White keys with black keys -->
    <div class="white-key" data-note="261.63">
        <div class="black-key" data-note="277.18"></div>
    </div>
    <div class="white-key" data-note="293.66">
        <div class="black-key" data-note="311.13"></div>
    </div>
    <div class="white-key" data-note="329.63"></div>
    <div class="white-key" data-note="349.23">
        <div class="black-key" data-note="369.99"></div>
    </div>
    <div class="white-key" data-note="392.00">
        <div class="black-key" data-note="415.30"></div>
    </div>
    <div class="white-key" data-note="440.00">
        <div class="black-key" data-note="466.16"></div>
    </div>
    <div class="white-key" data-note="493.88"></div>

    <!-- Second octave -->
    <div class="white-key" data-note="523.25">
        <div class="black-key" data-note="554.37"></div>
    </div>
    <div class="white-key" data-note="587.33">
        <div class="black-key" data-note="622.25"></div>
    </div>
    <div class="white-key" data-note="659.25"></div>
    <div class="white-key" data-note="698.46">
        <div class="black-key" data-note="739.99"></div>
    </div>
    <div class="white-key" data-note="783.99">
        <div class="black-key" data-note="830.61"></div>
    </div>
    <div class="white-key" data-note="880.00">
        <div class="black-key" data-note="932.33"></div>
    </div>
    <div class="white-key" data-note="987.77"></div>
</div>

<script>
    const AudioContext = window.AudioContext || window.webkitAudioContext;
    const audioCtx = new AudioContext();

    function playNote(freq) {
        const osc = audioCtx.createOscillator();
        const gain = audioCtx.createGain();

        osc.type = "sine";
        osc.frequency.value = freq;

        osc.connect(gain);
        gain.connect(audioCtx.destination);

        gain.gain.setValueAtTime(0.3, audioCtx.currentTime);
        gain.gain.exponentialRampToValueAtTime(0.001, audioCtx.currentTime + 1);

        osc.start();
        osc.stop(audioCtx.currentTime + 1);
    }

    document.querySelectorAll(".white-key, .black-key").forEach(key => {
        key.addEventListener("mousedown", e => {
            e.stopPropagation();
            playNote(key.dataset.note);
        });

        key.addEventListener("touchstart", e => {
            e.preventDefault();
            playNote(key.dataset.note);
        });
    });

    // Keyboard support
    document.addEventListener('keydown', function(event) {
        const key = event.key.toLowerCase();
        let freq;
        switch(key) {
            case 'a': freq = 261.63; break; // C4
            case 'w': freq = 277.18; break; // C#4
            case 's': freq = 293.66; break; // D4
            case 'e': freq = 311.13; break; // D#4
            case 'd': freq = 329.63; break; // E4
            case 'f': freq = 349.23; break; // F4
            case 't': freq = 369.99; break; // F#4
            case 'g': freq = 392.00; break; // G4
            case 'y': freq = 415.30; break; // G#4
            case 'h': freq = 440.00; break; // A4
            case 'u': freq = 466.16; break; // A#4
            case 'j': freq = 493.88; break; // B4
            case 'k': freq = 523.25; break; // C5
            case 'o': freq = 554.37; break; // C#5
            case 'l': freq = 587.33; break; // D5
            case 'p': freq = 622.25; break; // D#5
            case ';': freq = 659.25; break; // E5
            case "'": freq = 698.46; break; // F5
            case ']': freq = 739.99; break; // F#5
            case 'z': freq = 783.99; break; // G5
            case 'x': freq = 830.61; break; // G#5
            case 'c': freq = 880.00; break; // A5
            case 'v': freq = 932.33; break; // A#5
            case 'b': freq = 987.77; break; // B5
            default: return;
        }
        playNote(freq);
    });
</script>

</body>
</html>
