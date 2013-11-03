
#include "testApp.h"

void testApp::setup(){
    // 画面設定
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(31);
    // 照明とカメラ
    ofEnableLighting();
    light.setPosition(200, 300, 50);
    light.enable();
    cam.setOrientation(ofPoint(-20, 0, 0));
    // GL設定
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    // Leap Motion開始
    leap.open();
    
    ofSetVerticalSync(true);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    pimg.loadImage("particle32.png");
}

void testApp::update(){
    // 検出された手の数だけ、ofxLeapMotionSimpleHandのvector配列に追加
    simpleHands = leap.getSimpleHands();
    
    // フレーム更新して、手が検出されたら
    if( leap.isFrameNew() && simpleHands.size() ){
        // 画面の大きさにあわせて、スケールをマッピング
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
    }
    
    // 検出された手の数だけくりかえし
    particles.clear();
    for(int i = 0; i < simpleHands.size(); i++){
        // 検出された指の数だけくりかえし
        for(int j = 0; j < simpleHands[i].fingers.size(); j++){
            
            ofVec3f pos = simpleHands[i].fingers[j].pos;
            fingerPos.push_back(pos);
            
            //新規にパーティクルを作成、計算したベクトルを付与
            particle myParticle;
            myParticle.setInitialCondition(pos.x, pos.y);
            
            particles.push_back(myParticle);
            
        }
    }
    
    // ofxLeapMotionに現在のフレームは古くなったことを通知
    leap.markFrameAsOld();
    
}

void testApp::draw(){
    // 検出された数だけ、手を描画
    cam.begin();
    
    // 手を描画
    for(int i = 0; i < simpleHands.size(); i++){
        //simpleHands[i].debugDraw();
    }
    
    // 指を描画
    ofNoFill();
	ofEnableSmoothing();
	ofBeginShape();
    for(int i = 0; i < particles.size(); i++){
        //pimg.draw(particles[i].pos.x, particles[i].pos.y);
        ofCurveVertex(particles[i].pos.x, particles[i].pos.y);
    }
    ofEndShape();
    
    
    
    
    // particle描画
    for(int i = 0; i < particles.size(); i++){
        pimg.draw(particles[i].pos.x, particles[i].pos.y);
    }
    
    cam.end();
}