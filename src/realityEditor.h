#pragma once

//#include "ofMain.h"
//#include "ofxiOS.h"
//#include "ofxiOSExtras.h"

#include "ofxVuforia.h"
#include "ofxJSON.h"
#include "ofxNetwork.h"
#include "ofxXmlSettings.h"

//#include "ofxWKWebViewInterfaceJavaScript.h"
//#include "ofxUIWebViewInterfaceJavaScript.h"

#include "ofxWebViewInterface.h"

#include "Poco/Base64Encoder.h"
#include "Poco/Net/FilePartSource.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/StreamCopier.h"
#include "Poco/Timespan.h"
#include "Poco/URI.h"

#include "ImagePartSource.h"
#include "VuforiaState.h"

class realityEditor : public ofxVuforia_App, ofxWebViewDelegateCpp /*ofxWKWebViewDelegateCpp, ofxUIWebViewDelegateCpp*/ {
public:
    void setup();
    
    void update();
    
    void draw();
    
    void deviceOrientationChanged(int newOrientation);
    
    void exit();
    
    void renderJavascript();
    
    void downloadTargets();
    
    void cons();
    
    void urlResponse(ofHttpResponse &response);
    
    ofFile files_;
    ofxUDPManager udpConnection, udpConnection2;
    // HeartbeatListener* heartbeatListener;
    // 0 -> name/id
    // 1 -> ip
    // 2 -> version
    // 3 -> TCS
    // 4 -> state thing
    // 5 -> state thing
    // 6 -> state thing
    // 7 -> state thing
    vector<vector<string> > nameCount;
    vector<vector<string> > targetsList;
    
    //    ofxWKWebViewInterfaceJavaScript interface;
    //    ofxUIWebViewInterfaceJavaScript interface;
    
    ofxWebViewInterfaceJavaScript interface;

    void handleCustomRequest(NSString *request, NSURL *url);

    ofxJSONElement json;
    bool waitUntil;
    bool onlyOnce;
    bool waitGUI;
    char udpMessage[256];
    bool nameExists = false;
    bool targetExists = false;
    int numbersToMuch;
    
    string arrayList[3] = {"dat", "xml", "jpg"};
    
    int datasetHolder = 100000;
    
    ofxXmlSettings XML;
    ofxXmlSettings XMLTargets;
    
    int interfaceCounter = 0;
    string xmlStructure;
    
    ofHttpResponse ofSaveURLTo(string url, string path);
    
    ofBuffer dataBuffer;
    
    ofMatrix4x4 tempMatrix;
    
    vector<ofMatrix4x4> matrixTemp;
    vector<string> nameTemp;
    
    shared_ptr<VuforiaState> currentMemory = nullptr;
    
    vector<Vuforia::DataSet *>  datasetList;

    float matrixOld = 0.0;

    int foundMarker;
    bool reloader = false;
    bool extendedTracking = false;
    float cameraRatio = 1;
    
    bool updateSwitch =true;

    ofImage imgInterface, imgObject;
    // NSMutableString *stringforTransform;
    
    //vector<ofxVuforia_Marker>tempMarker;
    bool projectionMatrixSend = false;
    
    NSString *pMatrix;
    
    NSMutableString *stringforTransform = [NSMutableString stringWithCapacity:2000];
    
    ofAppiOSWindow thisWindow =  *ofxiPhoneGetOFWindow();
    int screenScale = 1;
    
    int haveChangedUIwithURL = 0;
    bool changedURLOk = false;
    
    
    int developerState = 0;
    int extTrackingState = 0;
    int clearSkyState = 0;
    string externalState = "";
    
    bool sendAccelerationData = false;
    
    ofVec3f accel;
    ofVec2f orientation;
    bool inSync = false;
    
    bool everySecond = false;
    
    string lastTracker;
    
    int32_t crc32(const void* data, size_t length);
    long bitNumber (bool bits[21]);
    string itob62( long i );
    uint32_t crc = 0xffffffff;
    void crc32reset();
    
    ofFile file;
    ofBuffer buff;
    
    map<int, shared_ptr<VuforiaState>> memories;
    // The memory that will be made permanent by memorize() or thrown away by clearMemory()
    shared_ptr<VuforiaState> tempMemory;
    void memorize(int memoryIndex);
    void remember(int memoryIndex);
    void unfreeze();
    void freeze();
    
    const int thumbnailWidth = 134;
    const int thumbnailHeight = 75;

    ofImage getCameraImage();
    void sendThumbnail(shared_ptr<VuforiaState> memory);
    void uploadMemory(shared_ptr<VuforiaState> memory);
    NSString* convertImageToBase64(ofImage image);
    bool getDataFromReq(string req, string reqName, string* data);
    /* void touchDown(ofTouchEventArgs & touch);
     void touchMoved(ofTouchEventArgs & touch);
     void touchUp(ofTouchEventArgs & touch);
     void touchDoubleTap(ofTouchEventArgs & touch);
     void touchCancelled(ofTouchEventArgs & touch);*/
    
    /*  void lostFocus();
     void gotFocus();
     void gotMemoryWarning();
     void deviceOrientationChanged(int newOrientation);*/
    
    
};


