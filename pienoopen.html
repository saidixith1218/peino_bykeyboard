<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Piano Keyboard Simulator</title>
    <style>
        body {
            margin: 0;
            padding: 0;
            background-color: navy;
            position: relative;
            overflow: hidden;
            font-family: Arial, sans-serif;
        }
        
        /* Create small gold stars using CSS */
        body::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background-image: radial-gradient(circle, gold 1px, transparent 1px);
            background-size: 50px 50px; /* Adjust size for star density */
            opacity: 0.5;
            pointer-events: none;
        }
        
        .piano {
            display: flex;
            justify-content: center;
            align-items: flex-end;
            height: 100vh;
            position: relative;
        }
        
        .white-key {
            width: 40px;
            height: 150px;
            background-color: white;
            border: 1px solid #ccc;
            border-radius: 0 0 5px 5px;
            margin: 0 1px;
            cursor: pointer;
            position: relative;
            display: flex;
            align-items: flex-end;
            justify-content: center;
            font-size: 12px;
            color: #333;
            padding-bottom: 10px;
        }
        
        .black-key {
            width: 25px;
            height: 90px;
            background-color: black;
            border: 1px solid #333;
            border-radius: 0 0 3px 3px;
            position: absolute;
            cursor: pointer;
            display: flex;
            align-items: flex-end;
            justify-content: center;
            font-size: 10px;
            color: white;
            padding-bottom: 5px;
            z-index: 1;
        }
        
        /* Position black keys */
        .black-key:nth-child(2) { left: 30px; }
        .black-key:nth-child(3) { left: 70px; }
        .black-key:nth-child(5) { left: 150px; }
        .black-key:nth-child(6) { left: 190px; }
        .black-key:nth-child(7) { left: 230px; }
        .black-key:nth-child(9) { left: 310px; }
        .black-key:nth-child(10) { left: 350px; }
        .black-key:nth-child(12) { left: 430px; }
        .black-key:nth-child(13) { left: 470px; }
        .black-key:nth-child(14) { left: 510px; }
        
        .key.active {
            background-color: #ddd;
        }
        
        .black-key.active {
            background-color: #555;
        }
        
        .instructions {
            position: absolute;
            top: 20px;
            left: 20px;
            color: white;
            font-size: 14px;
        }
    </style>
</head>
<body>
    <div class="instructions">
        <p>Use your computer keyboard to play the piano. Keys are mapped as follows:</p>
        <p>White keys (naturals): A S D F G H J K L ; ' (for C3 to C5)</p>
        <p>Black keys (sharps/flats): W E T Y U O P [ ] (for C#3, D#3, etc.)</p>
    </div>
    <div class="piano">
        <!-- White keys: C3 to C5 (15 keys) -->
        <div class="white-key" data-note="C3" data-key="a">C3</div>
        <div class="white-key" data-note="D3" data-key="s">D3</div>
        <div class="white-key" data-note="E3" data-key="d">E3</div>
        <div class="white-key" data-note="F3" data-key="f">F3</div>
        <div class="white-key" data-note="G3" data-key="g">G3</div>
        <div class="white-key" data-note="A3" data-key="h">A3</div>
        <div class="white-key" data-note="B3" data-key="j">B3</div>
        <div class="white-key" data-note="C4" data-key="k">C4</div>
        <div class="white-key" data-note="D4" data-key="l">D4</div>
        <div class="white-key" data-note="E4" data-key=";">E4</div>
        <div class="white-key" data-note="F4" data-key="'">F4</div>
        <div class="white-key" data-note="G4" data-key="z">G4</div>
        <div class="white-key" data-note="A4" data-key="x">A4</div>
        <div class="white-key" data-note="B4" data-key="c">B4</div>
        <div class="white-key" data-note="C5" data-key="v">C5</div>
        
        <!-- Black keys: Sharps/Flats -->
        <div class="black-key" data-note="C#3" data-key="w">C#3</div>
        <div class="black-key" data-note="D#3" data-key="e">D#3</div>
        <div class="black-key" data-note="F#3" data-key="t">F#3</div>
        <div class="black-key" data-note="G#3" data-key="y">G#3</div>
        <div class="black-key" data-note="A#3" data-key="u">A#3</div>
        <div class="black-key" data-note="C#4" data-key="o">C#4</div>
        <div class="black-key" data-note="D#4" data-key="p">D#4</div>
        <div class="black-key" data-note="F#4" data-key="[">F#4</div>
        <div class="black-key" data-note="G#4" data-key="]">G#4</div>
        <div class="black-key" data-note="A#4" data-key="\\">A#4</div>
    </div>

    <script>
        const audioContext = new (window.AudioContext || window.webkitAudioContext)();
        const keys = document.querySelectorAll('.white-key, .black-key');
        const keyMap = {};

        // Map computer keys to piano notes
        keys.forEach(key => {
            const note = key.dataset.note;
            const computerKey = key.dataset.key;
            keyMap[computerKey] = { element: key, note: note };
        });

        // Function to play a note
        function playNote(note) {
            const frequencies = {
                'C3': 130.81, 'C#3': 138.59, 'D3': 146.83, 'D#3': 155.56, 'E3': 164.81,
                'F3': 174.61, 'F#3': 185.00, 'G3': 196.00, 'G#3': 207.65, 'A3': 220.00,
                'A#3': 233.08, 'B3': 246.94, 'C4': 261.63, 'C#4': 277.18, 'D4': 293.66,
                'D#4': 311.13, 'E4': 329.63, 'F4': 349.23, 'F#4': 369.99, 'G4': 392.00,
                'G#4': 415.30, 'A4': 440.00, 'A#4': 466.16, 'B4': 493.88, 'C5': 523.25
            };
            
            const oscillator = audioContext.createOscillator();
            const gainNode = audioContext.createGain();
            
            oscillator.connect(gainNode);
            gainNode.connect(audioContext.destination);
            
            oscillator.frequency.setValueAtTime(frequencies[note], audioContext.currentTime);
            oscillator.type = 'sawtooth'; // Piano-like sound
            
            gainNode.gain.setValueAtTime(0.3, audioContext.currentTime);
            gainNode.gain.exponentialRampToValueAtTime(0.01, audioContext.currentTime + 1);
            
            oscillator.start(audioContext.currentTime);
            oscillator.stop(audioContext.currentTime + 1);
        }

        // Handle keyboard events
        document.addEventListener('keydown', (event) => {
            const key = event.key.toLowerCase();
            if (keyMap[key]) {
                const { element, note } = keyMap[key];
                element.classList.add('active');
                playNote(note);
            }
        });

        document.addEventListener('keyup', (event) => {
            const key = event.key.toLowerCase();
            if (keyMap[key]) {
                const { element } = keyMap[key];
                element.classList.remove('active');
            }
        });

        // Handle mouse clicks
        keys.forEach(key => {
            key.addEventListener('mousedown', () => {
                const note = key.dataset.note;
                key.classList.add('active');
                playNote(note);
            });
            key.addEventListener('mouseup', () => {
                key.classList.remove('active');
            });
            key.addEventListener('mouseleave', () => {
                key.classList.remove('active');
            });
        });
    </script>
</body>
</html>
