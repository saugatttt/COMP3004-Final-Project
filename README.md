# COMP3004-Final-Project

========
Team 29
========

Rami Golea - 101264861
Saugat Shrestha - 101225868
Mahmoud Kazan - 101260175
Chak Tao Owen Chan - 101293709

____________________________
=============
Instructions
=============

To watch the demo video, click the link below:

https://www.youtube.com/watch?v=YsWPt0QAAIE


To view use cases, use case diagram, traceability matrix, and other design discussion:

1) Open COMP3004FinalProject.pdf, and read through it.


To view diagrams:

Diagrams are all made in draw.io, you can view them by:

1) Going to the website 'draw.io'

2) Importing the drawio file (Note: please move around once you are in the file - the 
UML class diagram, state machine diagrams, and sequence diagrams are all in the same file)


To build and run:

1) In the terminal, run 'sudo apt install libqt5charts5-dev'

2) Build the project as normal in Qt Creator

____________________________
==============
Contributions
==============

Design:

All design decisions were made and reviewed by all team members.


Documentation:

Use Cases - Mahmoud

UML Class Diagram - Owen/Rami

State Machine Diagrams - Saugat/Rami

Traceability Matrix - Mahmoud/Rami/Saugat

Sequence Diagrams - Mahmoud/Saugat


Implementation:

Creation, selection, updating, and deletion of user profiles 
(UserProfileManager, UserProfile, CreateProfileDialog, SelectProfileDialog, 
UpdateProfileDialog, DeleteProfileDialog) - Rami

Json persistence of user profiles and scan history data between runs
(JsonPersistence, HealthData) - Rami

Scan data generation and collection (RadoTechDevice, ScanWindow, 
Scan, DataGenerator, DataProcessor)  - Saugat

Displaying scans in list view - Saugat/Owen/Rami

Bar graph to display scan data (ChartWindow) - Owen

Battery functionality and charging (Battery) - Mahmoud

Recommendations tab - Mahmoud
