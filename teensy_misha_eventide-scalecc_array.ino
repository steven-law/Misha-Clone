int ledPin = 13;
int lastNote = 21;
int scale = 0;


int scaleNotes[127] [127] = {
  {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,84,85,86,87,88,89,90,91,92,93,94,95}, //Chromatic
  {0, 2, 4, 5, 7, 9, 11,   12, 14, 16, 17, 19, 21, 23,    24, 26, 28, 29, 31, 33, 35,    36, 38, 40, 41, 43, 45, 47,   48, 50, 52, 53, 55, 57, 59,   60, 62, 64, 65, 67, 69, 71,   72, 74, 76, 77, 79, 81, 83,   84, 86, 88, 89, 91, 93, 95}, //Major
  {0, 2, 3, 5, 7, 8, 10,   12, 14, 15, 17, 19, 20, 22,    24, 26, 27, 29, 31, 32, 34,    36, 38, 39, 41, 43, 44, 46,   48, 50, 51, 53, 55, 56, 58,   60, 62, 63, 65, 67, 68, 70,   72, 74, 75, 77, 79, 80, 82,   84, 86, 87, 89, 91, 92, 94}, //Natural Minor
  {0, 2, 3, 5, 7, 8, 11,   12, 14, 15, 17, 19, 20, 23,    24, 26, 27, 29, 31, 32, 35,    36, 38, 39, 41, 43, 44, 47,   48, 50, 51, 53, 55, 56, 59,   60, 62, 63, 65, 67, 68, 71,   72, 74, 75, 77, 79, 80, 83,   84, 86, 87, 89, 91, 92, 95}, //Harmonic Minor
  {0, 2, 3, 5, 7, 9, 11,   12, 14, 15, 17, 19, 21, 23,    24, 26, 27, 29, 31, 33, 35,    36, 38, 39, 41, 43, 45, 47,   48, 50, 51, 53, 55, 57, 59,   60, 62, 63, 65, 67, 69, 71,   72, 74, 75, 77, 79, 81, 83,   84, 86, 87, 89, 91, 93, 95}, //Melodic Minor
  {0, 2, 3, 5, 7, 9, 10,   12, 14, 15, 17, 19, 21, 22,    24, 26, 27, 29, 31, 33, 34,    36, 38, 39, 41, 43, 45, 46,   48, 50, 51, 53, 55, 57, 58,   60, 62, 63, 65, 67, 69, 70,   72, 74, 75, 77, 79, 81, 82,   84, 86, 87, 89, 91, 93, 94}, //Dorian
  {0, 2, 4, 5, 7, 9, 10,   12, 14, 16, 17, 19, 21, 22,    24, 26, 28, 29, 31, 33, 34,    36, 38, 40, 41, 43, 45, 46,   48, 50, 52, 53, 55, 57, 58,   60, 62, 64, 65, 67, 69, 70,   72, 74, 76, 77, 79, 81, 82,   84, 86, 88, 89, 91, 93, 94}, //Mixolydian
  {0, 1, 3, 5, 7, 8, 10,   12, 13, 15, 17, 18, 20, 22,    24, 25, 27, 29, 31, 32, 34,    36, 37, 39, 41, 43, 44, 46,   48, 49, 51, 53, 55, 56, 58,   60, 61, 63, 65, 67, 68, 70,   72, 73, 75, 77, 79, 80, 82,   84, 85, 87, 89, 91, 92, 94}, //Phrygian
  {0, 2, 4,    7, 9,       12, 14, 16,     19, 21,        24, 26, 28,     31, 33,        36, 38, 40,     43, 45,       48, 50, 51,     55, 57,       60, 62, 64,     67, 69,       72, 74, 76,     79, 81,       84, 86, 88,     91, 93    }, //Pentatonic Major
  {0, 3, 5, 7, 10,         12, 15, 17, 19, 22,            24, 27, 29, 31, 34,            36, 39, 41, 43, 46,           48, 51, 53, 55, 58,           60, 63, 65, 67, 70,           72, 75, 77, 79, 82,           84, 87, 89, 91, 94        }, //Pentatonic Minor
  {0, 3, 4, 7, 9, 10,      12, 15, 16, 19, 21, 22,        24, 27, 28, 31, 33, 34,        36, 39, 40, 43, 45, 46,       48, 51, 52, 55, 57, 58,       60, 63, 64, 67, 69, 70,       72, 75, 76, 79, 81, 82,       84, 87, 88, 91, 93, 94    }, //Blues Major
  {0, 3, 5, 6, 7, 10,      12, 15, 17, 18, 19, 22,        24, 27, 29, 30, 31, 34,        36, 39, 41, 42, 43, 46,       48, 51, 53, 54, 55, 58,       60, 63, 65, 66, 67, 70,       72, 75, 77, 78, 79, 82,       84, 87, 89, 90, 91, 94    }, //Blues Minor 
  {0, 2, 4, 6, 7, 9, 11,   12, 14, 16, 18, 19, 21, 23,    24, 26, 28, 30, 31, 33, 35,    36, 38, 40, 42, 43, 45, 47,   48, 50, 52, 54, 55, 57, 59,   60, 62, 64, 66, 67, 69, 71,   72, 74, 76, 78, 79, 81, 83,   84, 86, 88, 90, 91, 93, 95}, //Lydian
  {0, 2, 4, 6, 8, 10,      12, 14, 16, 18, 20, 22,        24, 26, 28, 30, 32, 34,        36, 38, 40, 42, 44, 46,       48, 50, 52, 64, 56, 58,       60, 62, 64, 66, 68, 70,       72, 74, 76, 78, 80, 82,       84, 86, 88, 90, 92, 94    }, //Whole Tone
  
};

void myControlChange(byte channel, byte control, byte value) {
  //  int CC;
  if (control == 74) {
    scale = value;
  }
};

void OnNoteOn(byte channel, byte note, byte velocity) {


  if (note == 32) {
    usbMIDI.sendNoteOn((scaleNotes[scale] [(lastNote - 4)]), velocity, channel);
    digitalWrite(ledPin, HIGH);
  };
  if (note == 33) {
    usbMIDI.sendNoteOn((scaleNotes[scale] [(lastNote - 3)]), velocity, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (note == 34) {
    usbMIDI.sendNoteOn((scaleNotes[scale] [(lastNote - 2)]), velocity, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (note == 35) {
    usbMIDI.sendNoteOn((scaleNotes[scale] [(lastNote - 1)]), velocity, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (note == 36) {
    usbMIDI.sendNoteOn((scaleNotes[scale] [lastNote]), velocity, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (note == 37) {
    usbMIDI.sendNoteOn((scaleNotes[scale] [(lastNote + 1)]), velocity, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (note == 38) {
    usbMIDI.sendNoteOn((scaleNotes[scale] [(lastNote + 2)]), velocity, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (note == 39) {
    usbMIDI.sendNoteOn((scaleNotes[scale] [(lastNote + 3)]), velocity, channel);
    digitalWrite(ledPin, HIGH);
  }
  if (note == 40) {
    usbMIDI.sendNoteOn((scaleNotes[scale] [(lastNote + 4)]), velocity, channel);
    digitalWrite(ledPin, HIGH);
  }
}


void OnNoteOff(byte channel, byte note, byte velocity) {

  if (note == 32) {
    usbMIDI.sendNoteOff((scaleNotes[scale] [(lastNote - 4)]), velocity, channel);
    digitalWrite(ledPin, LOW);
    lastNote = lastNote - 4;
  }
  if (note == 33) {
    usbMIDI.sendNoteOff((scaleNotes[scale] [(lastNote - 3)]), velocity, channel);
    digitalWrite(ledPin, LOW);
    lastNote = lastNote - 3;
  }
  if (note == 34) {
    usbMIDI.sendNoteOff((scaleNotes[scale] [(lastNote - 2)]), velocity, channel);
    digitalWrite(ledPin, LOW);
    lastNote = lastNote - 2;
  }
  if (note == 35) {
    usbMIDI.sendNoteOff((scaleNotes[scale] [(lastNote - 1)]), velocity, channel);
    digitalWrite(ledPin, LOW);
    lastNote = lastNote - 1;
  }
  if (note == 36) {
    usbMIDI.sendNoteOff((scaleNotes[scale] [lastNote]), velocity, channel);
    digitalWrite(ledPin, LOW);
  }
  if (note == 37) {
    usbMIDI.sendNoteOff((scaleNotes[scale] [(lastNote + 1)]), velocity, channel);
    digitalWrite(ledPin, LOW);
    lastNote = lastNote + 1;
  }
  if (note == 38) {
    usbMIDI.sendNoteOff((scaleNotes[scale] [(lastNote + 2)]), velocity, channel);
    digitalWrite(ledPin, LOW);
    lastNote = lastNote + 2;
  }
  if (note == 39) {
    usbMIDI.sendNoteOff((scaleNotes[scale] [(lastNote + 3)]), velocity, channel);
    digitalWrite(ledPin, LOW);
    lastNote = lastNote + 3;
  }
  if (note == 40) {
    usbMIDI.sendNoteOff((scaleNotes[scale] [(lastNote + 4)]), velocity, channel);
    digitalWrite(ledPin, LOW);
    lastNote = lastNote + 4;
  }
}
void setup() {
  pinMode(ledPin, OUTPUT);
  usbMIDI.setHandleNoteOff(OnNoteOff);
  usbMIDI.setHandleNoteOn(OnNoteOn);
  usbMIDI.setHandleControlChange(myControlChange);
  digitalWrite(ledPin, HIGH);
  delay(400);                 // Blink LED once at startup
  digitalWrite(ledPin, LOW);
}

void loop() {
  usbMIDI.read();
}
