#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	verdana14.load("Pixellettersfull.ttf", 28, true, true);
	verdana14.setLineHeight(35.0f);
	verdana14.setLetterSpacing(1.037);

	ofTrueTypeFont::setGlobalDpi(72);

	setupAudio(directoryIterator("data/audio/"));
	setupImages(directoryIterator("data/images/"));

	story = Handlung();

	lesezeichen = 0;
	letzteinstanz = 0;

	//Versuch Typewritereffekt

	text = "Dies ist ein Test"; // Replace with your desired text
	textIndex = 0;
	timer = 0;
	ofSetWindowShape(800, 600);

}

//--------------------------------------------------------------
void ofApp::update()
{

	timer += ofGetLastFrameTime();

	// Check if the timer has reached a certain threshold
	// to add a character to the displayed text
	if (timer >= 0.1 && textIndex < text.length()) {
		displayedText += text[textIndex];
		textIndex++;
		timer = 0;
	}

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(255);
	if (lesezeichen < imgFiles.size() && lesezeichen >= 0)
	{
		displayImage(lesezeichen);
	}

	
	int rectangleWidth = 1920;
	int rectangleHeight = 400;
	/*ofSetColor(0, 0, 0, 150);
	ofDrawRectangle(0, ofGetHeight() / 2 - rectangleHeight / 2, rectangleWidth, rectangleHeight);*/

	ofSetColor(220, 190, 200);
	verdana14.drawString(story[lesezeichen], ofGetWidth() - rectangleWidth + rectangleWidth / 8, ofGetHeight() / 2 - rectangleHeight / 2);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
	lesezeichen = mechanismus(lesezeichen, key);

	if (lesezeichen != letzteinstanz)
	{
		sndFiles[letzteinstanz].stop();
	}
	letzteinstanz = lesezeichen;

	if (lesezeichen < sndFiles.size() && lesezeichen >= 0)
	{
		playSndFile(lesezeichen);
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
