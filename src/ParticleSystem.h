//
//  ParticleSystem.hpp
//  LiveSet01
//
//  Created by 高田 信一郎 on 2017/01/17.
//
//

#ifndef ParticleSystem_h
#define ParticleSystem_h

#include "ofMain.h"
#include "ofxBillboard.h"

#define	MAX_PARTICLES	1000


class ParticleSystem {
    
public:
    typedef struct						// Create A Structure For Particle
    {
        bool	active;					// Active (Yes/No)
        float	life;					// Particle Life
        float	fade;					// Fade Speed
        float	r;						// Red Value
        float	g;						// Green Value
        float	b;						// Blue Value
        float	x;						// X Position
        float	y;						// Y Position
        float	z;						// Z Position
        float	xi;						// X Direction
        float	yi;						// Y Direction
        float	zi;						// Z Direction
        float	xg;						// X Gravity
        float	yg;						// Y Gravity
        float	zg;						// Z Gravity
    }
    particles;
    particles particle[MAX_PARTICLES];
    
    GLfloat colors[12][3]=		// Rainbow Of Colors
    {
        {1.0f,0.5f,0.5f},{1.0f,0.75f,0.5f},{1.0f,1.0f,0.5f},{0.75f,1.0f,0.5f},
        {0.5f,1.0f,0.5f},{0.5f,1.0f,0.75f},{0.5f,1.0f,1.0f},{0.5f,0.75f,1.0f},
        {0.5f,0.5f,1.0f},{0.75f,0.5f,1.0f},{1.0f,0.5f,1.0f},{1.0f,0.5f,0.75f}
    };
    
    ofImage texture;
    ofTexture tex1;
    ofVec3f camPos;
    
    float	slowdown=2.0f;				// Slow Down Particles
    float	xspeed;						// Base X Speed (To Allow Keyboard Direction Of Tail)
    float	yspeed;						// Base Y Speed (To Allow Keyboard Direction Of Tail)
    float	zoom=-40.0f;				// Used To Zoom Out
    
    GLuint	col;						// Current Color Selection
    GLuint	delay;						// Rainbow Effect Delay
    //GLuint	texture[1];					// Storage For Our Particle Texture
    
    
    void loadTexture(){
        //ofLoadImage(texture, "Particle.bmp");
        texture.load("particle32.png");
    }
    
    void setup(){
        for (int loop=0;loop<MAX_PARTICLES;loop++)				// Initials All The Textures
        {
            particle[loop].active=true;								// Make All The Particles Active
            particle[loop].life=1.0f;								// Give All The Particles Full Life
            particle[loop].fade=float(rand()%100)/1000.0f+0.003f;	// Random Fade Speed
            particle[loop].r=colors[loop*(12/MAX_PARTICLES)][0];	// Select Red Rainbow Color
            particle[loop].g=colors[loop*(12/MAX_PARTICLES)][1];	// Select Red Rainbow Color
            particle[loop].b=colors[loop*(12/MAX_PARTICLES)][2];	// Select Red Rainbow Color
            particle[loop].xi=float((rand()%50)-26.0f)*10.0f;		// Random Speed On X Axis
            particle[loop].yi=float((rand()%50)-25.0f)*10.0f;		// Random Speed On Y Axis
            particle[loop].zi=float((rand()%50)-25.0f)*10.0f;		// Random Speed On Z Axis
            particle[loop].xg=0.0f;									// Set Horizontal Pull To Zero
            particle[loop].yg=-0.8f;								// Set Vertical Pull Downward
            particle[loop].zg=0.0f;									// Set Pull On Z Axis To Zero
        }
        
        loadTexture();
        
    }
    
    void update(){
        
    }
    
    void draw(){
        col = 0;
        //ofEnablePointSprites();
        
        //enableBillboardRotation();
        ofxBillboardBeginSphericalCheat(
            ofVec3f(particle[0].x, particle[0].y, particle[0].z + 60.f)
        );
        for (int loop=0;loop<MAX_PARTICLES;loop++){					// Loop Through All The Particles
            if (particle[loop].active)							// If The Particle Is Active
            {
                float x=particle[loop].x;						// Grab Our Particle X Position
                float y=particle[loop].y;						// Grab Our Particle Y Position
                float z=particle[loop].z + 60;					// Particle Z Pos + Zoom
                
                ofMesh mesh;
                mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
                //mesh.setMode(OF_PRIMITIVE_POINTS);
                //mesh.addVertex(ofVec3f(x, y, z));
                
                
                mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
                //mesh.addTexCoord( ofPoint( 1, 1 ) );
                mesh.addTexCoord( ofPoint(32, 32));
                mesh.addVertex(ofVec3f(x+40.f,y+40.f,z));
                
                //mesh.addTexCoord( ofPoint( 0, 1 ) );
                mesh.addTexCoord( ofPoint( 0, 32 ) );
                mesh.addVertex(ofVec3f(x-40.f,y+40.f,z));
                

                //mesh.addTexCoord( ofPoint( 1, 0 ) );
                mesh.addTexCoord(ofPoint( 32, 0) );
                mesh.addVertex(ofVec3f(x+40.f,y-40.f,z));
                
                //mesh.addTexCoord( ofPoint( 0, 0 ) );
                mesh.addTexCoord( ofPoint( 0, 0 ) );
                mesh.addVertex(ofVec3f(x-40.f,y-40.f,z));
                 
                // Draw The Particle Using Our RGB Values, Fade The Particle Based On It's Life
                glColor4f(particle[loop].r,particle[loop].g,particle[loop].b,particle[loop].life);
                //glEnable(GL_TEXTURE_2D);
                texture.bind();
                //texture.draw(0, 0, 600, 600);
                mesh.draw();
                //glBegin(GL_TRIANGLE_STRIP);						// Build Quad From A Triangle Strip
                //glTexCoord2d(1,1); glVertex3f(x+0.5f,y+0.5f,z); // Top Right
                //glTexCoord2d(0,1); glVertex3f(x-0.5f,y+0.5f,z); // Top Left
                //glTexCoord2d(1,0); glVertex3f(x+0.5f,y-0.5f,z); // Bottom Right
                //glTexCoord2d(0,0); glVertex3f(x-0.5f,y-0.5f,z); // Bottom Left
                //glEnd();										// Done Building Triangle Strip
                texture.unbind();
                
                particle[loop].x+=particle[loop].xi/(slowdown*1000);// Move On The X Axis By X Speed
                particle[loop].y+=particle[loop].yi/(slowdown*1000);// Move On The Y Axis By Y Speed
                particle[loop].z+=particle[loop].zi/(slowdown*1000);// Move On The Z Axis By Z Speed
                
                particle[loop].xi+=particle[loop].xg;			// Take Pull On X Axis Into Account
                particle[loop].yi+=particle[loop].yg;			// Take Pull On Y Axis Into Account
                particle[loop].zi+=particle[loop].zg;			// Take Pull On Z Axis Into Account
                particle[loop].life-=particle[loop].fade;		// Reduce Particles Life By 'Fade'
                
                if (particle[loop].life<0.0f)					// If Particle Is Burned Out
                {
                    particle[loop].life=1.0f;					// Give It New Life
                    particle[loop].fade=float(rand()%100)/1000.0f+0.003f;	// Random Fade Value
                    particle[loop].x=0.0f;						// Center On X Axis
                    particle[loop].y=0.0f;						// Center On Y Axis
                    particle[loop].z=0.0f;						// Center On Z Axis
                    particle[loop].xi=xspeed+float((rand()%60)-32.0f);	// X Axis Speed And Direction
                    particle[loop].yi=yspeed+float((rand()%60)-30.0f);	// Y Axis Speed And Direction
                    particle[loop].zi=float((rand()%60)-30.0f);	// Z Axis Speed And Direction
                    particle[loop].r=colors[col][0];			// Select Red From Color Table
                    particle[loop].g=colors[col][1];			// Select Green From Color Table
                    particle[loop].b=colors[col][2];			// Select Blue From Color Table
                }
                
                // If Number Pad 8 And Y Gravity Is Less Than 1.5 Increase Pull Upwards
                /*
                if (keys[VK_NUMPAD8] && (particle[loop].yg<1.5f)) particle[loop].yg+=0.01f;
                
                // If Number Pad 2 And Y Gravity Is Greater Than -1.5 Increase Pull Downwards
                if (keys[VK_NUMPAD2] && (particle[loop].yg>-1.5f)) particle[loop].yg-=0.01f;
                
                // If Number Pad 6 And X Gravity Is Less Than 1.5 Increase Pull Right
                if (keys[VK_NUMPAD6] && (particle[loop].xg<1.5f)) particle[loop].xg+=0.01f;
                
                // If Number Pad 4 And X Gravity Is Greater Than -1.5 Increase Pull Left
                if (keys[VK_NUMPAD4] && (particle[loop].xg>-1.5f)) particle[loop].xg-=0.01f;
                
                if (keys[VK_TAB])										// Tab Key Causes A Burst
                {B
                    particle[loop].x=0.0f;								// Center On X Axis
                    particle[loop].y=0.0f;								// Center On Y Axis
                    particle[loop].z=0.0f;								// Center On Z Axis
                    particle[loop].xi=float((rand()%50)-26.0f)*10.0f;	// Random Speed On X Axis
                    particle[loop].yi=float((rand()%50)-25.0f)*10.0f;	// Random Speed On Y Axis
                    particle[loop].zi=float((rand()%50)-25.0f)*10.0f;	// Random Speed On Z Axis
                }
                */
            }
        }
        ofxBillboardEnd();
        //ofDisablePointSprites();
        //disableBillboardRotation();
    }
    
    void enableBillboardRotation(){
        ofxBillboardBeginSphericalCheat(camPos);
    }
    
    void disableBillboardRotation(){
        ofPopMatrix();
    }
    
    void setBillboardRotation(ofVec3f tmpCamPos){
        camPos = tmpCamPos;
    }
    
};




#endif /* ParticleSystem_h */
