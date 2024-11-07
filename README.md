# CAN_CubeMars_Motor
Test of the CubeMars (AK10-9 KV100)
## Instruction pour faire tourner le moteur
1. Assurer vous que le moteur soit bien stabilisé/solide pour éviter qu'il arrive un accident (utiliser les serre-joints de la salle de travail au bois, il fonctionne bien)
2. Connecter les fils d'alimentation a la source et l'ouvrir afin de la configurer (la limité a 24V et 1A). Connecter le connecteur d'alimentation au moteur. NE PAS OUVRIR LE CHANNEL D'ALIMENTATION TOUT DE SUITE.
3. Connecter le CAN Tranceiver (petit breakout board bleu avec le header qui contient le CANL et CANH) au moteur. Idéalement, valider que votre connection CANL et CANH sont bien reliés au bornier a vis bleu.
4. Une fois que votre connection est faite, vous pouvez allumer le channel de votre source et commencer a programmer le moteur. Il faut que vous soyer dans le folder qui s'appel "MotorCanTest" dans VS Code (que ce soit votre fichier root) pour que PlatformIO reconnaisent les librairies C++ et qu'il reconnaisent que tu es dans un projet PlatformIO.

## Objectif attendu pour le moteur
1. Set sont origine et pouvoir lui demander d'aller a une position.
2. Être capable de le faire revenir a son origine (théoriquement, c'est la fonction "zero" qui permet de packager le message pour faire cela.
3. Être capable de lui donner une vitesse et éventuellement la changer en cours de route. ATTENTION**: dans la doc, il est écrit que la position maximal a laquelle le moteur peux théoriquement aller en MIT est entre -12.5 et 12.5 RAD. Peux-être que cv fonctionner quand même, mais il faut quand même faire attention a cela. Vérifier la page 52 de la datasheet en cas de doute
