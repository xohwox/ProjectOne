#include "AppDelegate.h"
#include "./Scene101/Scene101.h"
//#include "./Scene101/Scene102.h"

#define SceneTransition 1

USING_NS_CC;

static cocos2d::Size screenResolutionSize = cocos2d::Size(1920, 1080);
static cocos2d::Size designResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);
float g_fScaleFactor=0;



AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("MyCocos2DX", Rect(0, 0, screenResolutionSize.width, screenResolutionSize.height),0.5f);
#else
        glview = GLViewImpl::create("MyCocos2DX");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60.0f);

    // Set the design resolution
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    Size frameSize = glview->getFrameSize();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
	director->setContentScaleFactor(MIN(screenResolutionSize.height / designResolutionSize.height, screenResolutionSize.width / designResolutionSize.width));
#else
	director->setContentScaleFactor(MIN(frameSize.height / designResolutionSize.height, frameSize.width / designResolutionSize.width));
#endif
	g_fScaleFactor = Director::getInstance()->getContentScaleFactor();

    register_all_packages();

    // create a scene. it's an autorelease object

#if SceneTransition == 0
	auto scene = Scene101::createScene();
	director->runWithScene(scene);
#elif SceneTransition == 1
	auto scene = TransitionMoveInL::create(0.6f, Scene101::createScene());
	director->runWithScene(scene);
#else
	auto scene = TransitionZoomFlipX::create(0.6f, Scene102::createScene());
	director->runWithScene(scene);
#endif
//	Director::getInstance()->replaceScene(scene);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
