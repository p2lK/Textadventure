#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

		vector<string> Handlung()
		{
			vector<string> handlung;

			// Text 0
			handlung.push_back("\n\n \
			Murderhouse: hunt or be hunted\n \
			\n\n \
			Von: Kai, Emily, Yasemin, Linda, Nina\n \
			Game Design Student*Innen im 2.Semester\n \
			Anleitung: Druecke die Eingabetaste um fortzufahren.Wenn du gefragt wirst, antworte mit a, b oder c.\n \
			\n\n \
			Disclaimer: Dieses Spiel enthaelt gewalttaetige und brutale Entscheidungsmöglichkeiten.\n \
			");


			//Text 1
			handlung.push_back("\n\n \
			Willkommen.\n\n \
			In diesem Textadventure betritts du das sogenannte Murderhouse.\n \
			Entscheide dich zunaechst, welche Rolle du einnehmen moechtest:\n\n \
			a. Jaeger\n \
			b. Gejagte\n \
			");


			//Text 2 – Antwort 1a
			handlung.push_back("\n\n \
			Du hast dich für die Rolle des Moerders entschieden.\n \
			Dein Ziel besteht darin, dein Opfer zu manipulieren und es durch das Haus zu jagen.\n \
			Das „Murderhouse“ ist mit allerlei Fallen und geheimen Gaengen ausgestattet.\n \
			Manche fuehren dich zu deinem Ziel, andere versprechen den Tod.\n \
			Waehle weise, und vergiss nicht, deinem Opfer eine Nacht zu bescheren, die es mit Sicherheit nicht vergessen wird.\n \
			Viel Spass!\n \
			");


			//Text 3 – the hunt begins 
			handlung.push_back("\n\n \
			Es ist tiefste Nacht.\n \
			Blitze erleuchten draussen die Dunkelheit, und Donner hallt in den Hallen des Hauses wieder.\n \
			Du sitzt an deinem Schreibtisch im ersten Stock des Hauses und beobachtest aufmerksam das Ticken der Standuhr.\n \
			Es schlägt 23:00 Uhr.Die Jagd kann beginnen.\n\n \
			Zwei Monate lang hast du geplant, gedacht und getueftelt.\n \
			Nun ist die Zeit endlich gekommen.\n \
			Der Autor erfolgreicher Horror - und Thrillergeschichten befindet sich mit dir im Haus.\n \
			Du verehrst diesen Menschen abgoettisch und wuenschst dir nichts sehnlicher\n \
			als Teil seiner Romane zu werden.\n \
			So hast du eine Nacht voller Horror und Schrecken vorbereitet, eine Nacht die er nie vergessen wuerde.\n\n \
			Du stuelpst dir schwarze Handschuhe über die Haende und wirfst einen letzten Blick in den Spiegel,\n \
			bevor du den Raum verlaesst.\n \
			Eine Maske ziert und versteckt dein Gesicht.\n \
			Schliesst du ab ? \n \
			a.Ja\n \
			b.Nein\n \
			");


			// Handlungs-Text Nummer 4: Antwort auf Frage 2b
			handlung.push_back("\n\n \
			Du springst in den naechsten Busch, um Dich zu verstecken. \n \
			Die mit den Fackeln kommen naeher.\n\n \
			Was machst Du als naechstes?\n \
			a: Still sein!\n \
			b: Angreifen!\n \
			");

			// Handlungs-Text Nummer 5: Vorerst (!) das Ende der Geschichte.
			handlung.push_back("\n\n \
			Sie haben Dich gefunden und gefangen genommen! \n \
			Der Vorwurf lautet: Du hast einen Werwolf gefressen.\n\n \
			Wie antwortest Du?\n \
			a: Stimmt.\n \
			b: Der war lecker!\n \
			");

			// Handlungs-Text Nummer 6: Konsequenzen.
			handlung.push_back("\n\n \
			Fuer Dein Verbrechen, einen Werwolf zu verspeisen, wirst Du\n \
			dazu verurteilt, eine Pfuetze nass zu machen.\n \
			Fuege Dich Deinem Schicksal!\n \
			");

			return handlung;
		}


		int mechanismus(int position, int antwort)
		{
			if (position == 0)
			{
				return 1;
			}
			else if (position == 1)
			{
				return 2;
			}
			else if (position == 2 && antwort == 'a')
			{
				return 3;
			}
			else if (position == 2 && antwort == 'b')
			{
				return 4;
			}
			else if (position == 3 || position == 4)
			{
				return 5;
			}
			else if (position == 5)
			{
				return 6;
			}
			else if (position == 6)
			{
				ofExit();
			}

			return position;
		}

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofTrueTypeFont	verdana14;

		vector<string> story;
		string antwort;

		int lesezeichen;
		int letzteinstanz;

		int textIndex;
		float timer;
		string text;
		string displayedText;

		std::vector<std::string> directoryIterator(std::string pPath)
		{
			auto dirIter = std::filesystem::directory_iterator(pPath);

			std::vector<std::string> filenames;

			for (auto& entry : dirIter)
			{
				std::cout << "entry path: " << entry.path().string() << std::endl;

				filenames.push_back(entry.path().filename().string());
			}
			return filenames;
		}

		std::vector<ofSoundPlayer> sndFiles;

		void setupAudio(std::vector<string> filenames)
		{
			for (int n = 0; n < filenames.size(); n++)
			{
				std::cout << filenames[n] << std::endl;
				ofSoundPlayer tempSndFilePlayer;
				tempSndFilePlayer.load("audio/" + filenames[n]);
				sndFiles.push_back(tempSndFilePlayer);
			}

		}

		void playSndFile(int pSelSndFileIndex)
		{
			sndFiles[pSelSndFileIndex].play();
		}

		std::vector<ofImage> imgFiles;

		void setupImages(std::vector<string> filenames)
		{
			for (int n = 0; n < filenames.size(); n++)
			{
				std::cout << filenames[n] << std::endl;
				ofImage img;
				img.load("images/" + filenames[n]);
				imgFiles.push_back(img);
			}
		}

		void displayImage(int pSelImgFileIndex)
		{
			float imageSize = ofGetWidth() / imgFiles[pSelImgFileIndex].getWidth();
			float imageWidth = imageSize * imgFiles[pSelImgFileIndex].getWidth();
			float imageHeight = imageSize * imgFiles[pSelImgFileIndex].getHeight();
			imgFiles[pSelImgFileIndex].draw(0, 0, imageWidth, imageHeight);
		}
};
