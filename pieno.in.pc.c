<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Virtual Piano</title>
    <style>
        body {
            margin: 0;
            padding: 0;
            background-color: #000080; /* Navy blue */
            font-family: Arial, sans-serif;
            overflow: hidden;
            position: relative;
        }
        /* Starry background */
        .star {
            position: absolute;
            background-color: gold;
            border-radius: 50%;
            opacity: 0.8;
        }
        .star:nth-child(odd) {
            width: 2px;
            height: 2px;
        }
        .star:nth-child(even) {
            width: 1px;
            height: 1px;
        }
        #piano {
            display: flex;
            justify-content: center;
            align-items: flex-end;
            height: 100vh;
            position: relative;
        }
        .key {
            position: relative;
            border: 1px solid #000;
            box-sizing: border-box;
            cursor: pointer;
            user-select: none;
            display: flex;
            justify-content: center;
            align-items: flex-end;
            font-size: 12px;
            color: #000;
            transition: background-color 0.1s;
        }
        .white-key {
            width: 40px;
            height: 150px;
            background-color: #fff;
            margin: 0 -1px;
            z-index: 1;
        }
        .white-key:hover, .white-key.active {
            background-color: #ddd;
        }
        .black-key {
            width: 24px;
            height: 90px;
            background-color: #000;
            position: absolute;
            left: 50%;
            transform: translateX(-50%);
            z-index: 2;
            color: #fff;
        }
        .black-key:hover, .black-key.active {
            background-color: #333;
        }
        .note-label {
            position: absolute;
            bottom: 5px;
            font-size: 10px;
        }
    </style>
</head>
<body>
    <!-- Generate stars dynamically -->
    <script>
        for (let i = 0; i < 100; i++) {
            const star = document.createElement('div');
            star.className = 'star';
            star.style.left = Math.random() * 100 + '%';
            star.style.top = Math.random() * 100 + '%';
            star.style.animationDelay = Math.random() * 2 + 's';
            document.body.appendChild(star);
        }
    </script>

    <div id="piano">
        <!-- Octave 1 -->
        <div class="key white-key" data-note="C4" data-key="a">
            <div class="note-label">C</div>
        </div>
        <div class="key black-key" data-note="C#4" data-key="w">
            <div class="note-label">C#<br>Db</div>
        </div>
        <div class="key white-key" data-note="D4" data-key="s">
            <div class="note-label">D</div>
        </div>
        <div class="key black-key" data-note="D#4" data-key="e">
            <div class="note-label">D#<br>Eb</div>
        </div>
        <div class="key white-key" data-note="E4" data-key="d">
            <div class="note-label">E</div>
        </div>
        <div class="key white-key" data-note="F4" data-key="f">
            <div class="note-label">F</div>
        </div>
        <div class="key black-key" data-note="F#4" data-key="t">
            <div class="note-label">F#<br>Gb</div>
        </div>
        <div class="key white-key" data-note="G4" data-key="g">
            <div class="note-label">G</div>
        </div>
        <div class="key black-key" data-note="G#4" data-key="y">
            <div class="note-label">G#<br>Ab</div>
        </div>
        <div class="key white-key" data-note="A4" data-key="h">
            <div class="note-label">A</div>
        </div>
        <div class="key black-key" data-note="A#4" data-key="u">
            <div class="note-label">A#<br>Bb</div>
        </div>
        <div class="key white-key" data-note="B4" data-key="j">
            <div class="note-label">B</div>
        </div>
        <!-- Octave 2 -->
        <div class="key white-key" data-note="C5" data-key="k">
            <div class="note-label">C</div>
        </div>
        <div class="key black-key" data-note="C#5" data-key="o">
            <div class="note-label">C#<br>Db</div>
        </div>
        <div class="key white-key" data-note="D5" data-key="l">
            <div class="note-label">D</div>
        </div>
        <div class="key black-key" data-note="D#5" data-key="p">
            <div class="note-label">D#<br>Eb</div>
        </div>
        <div class="key white-key" data-note="E5" data-key=";">
            <div class="note-label">E</div>
        </div>
    </div>

    <script>
        const audioContext = new (window.AudioContext || window.webkitAudioContext)();
        const keys = document.querySelectorAll('.key');
        const keyMap = {};

        // Note frequencies (A4 = 440Hz)
        const noteFrequencies = {
            'C4': 261.63, 'C#4': 277.18, 'D4': 293.66, 'D#4': 311.13, 'E4': 329.63,
            'F4': 349.23, 'F#4': 369.99, 'G4': 392.00, 'G#4': 415.30, 'A4': 440.00,
            'A#4': 466.16, 'B4': 493.88, 'C5': 523.25, 'C#5': 554.37, 'D5': 587.33,
            'D#5': 622.25, 'E5': 659.25
        };

        // Build key map
        keys.forEach(key => {
            const note = key.dataset.note;
            const keyboardKey = key.dataset.key;
            keyMap[keyboardKey] = { element: key, note: note };
        });

        // Play note function
        function playNote(note) {
            const frequency = noteFrequencies[note];
            if (!frequency) return;

            const oscillator = audioContext.createOscillator();
            const gainNode = audioContext.createGain();

            oscillator.connect(gainNode);
            gainNode.connect(audioContext.destination);

            oscillator.frequency.setValueAtTime(frequency, audioContext.currentTime);
            oscillator.type = 'sine';

            gainNode.gain.setValueAtTime(0.3, audioContext.currentTime);
            gainNode.gain.exponentialRampToValueAtTime(0.01, audioContext.currentTime + 0.5);

            oscillator.start(audioContext.currentTime);
            oscillator.stop(audioContext.currentTime + 0.5);
        }

        // Keyboard event listeners
        document.addEventListener('keydown', (e) => {
            const key = e.key.toLowerCase();
            if (keyMap[key] && !keyMap[key].element.classList.contains('active')) {
                keyMap[key].element.classList.add('active');
                playNote(keyMap[key].note);
            }
        });

        document.addEventListener('keyup', (e) => {
            const key = e.key.toLowerCase();
            if (keyMap[key]) {
                keyMap[key].element.classList.remove('active');
            }
        });

        // Mouse click support
        keys.forEach(key => {
            key.addEventListener('mousedown', () => {
                key.classList.add('active');
                playNote(key.dataset.note);
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
