/*
Casey Rock
Alex Arnell

8 May 2019
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sense/sense.h>
#define UP 1
#define DOWN 0
#define RIGHT 2
#define LEFT 3


int run = 1;

int win = 0;

typedef struct
{
	int platformX;
	int platformX_1;
	int platformX_2;
	int platformX_1Previous;
	int platformX_2Previous;
	int platformXPrevious;
	int platformY;
	int platformYPrevious;
} platformState;

typedef struct
{
	int ballX;
	int ballY;
	int ballXPrevious;
	int ballYPrevious;
}BallState;

typedef struct
{
	int block1;
	int block1X;
	int block1Y;

	int block2;
	int block2X;
	int block2Y;

	int block3;
	int block3X;
	int block3Y;

	int block4;
	int block4X;
	int block4Y;

	int block5;
	int block5X;
	int block5Y;

	int block6;
	int block6X;
	int block6Y;

	int block7;
	int block7X;
	int block7Y;

	int block8;
	int block8X;
	int block8Y;

	int block9;
	int block9X;
	int block9Y;

	int block10;
	int block10X;
	int block10Y;

	int block11;
	int block11X;
	int block11Y;

	int block12;
	int block12X;
	int block12Y;

	int block13;
	int block13X;
	int block13Y;

	int block14;
	int block14X;
	int block14Y;

}blockState;

void handler(int sig)
{
	printf("\nExiting...\n");
	run = 0;
}

//take a platformState and set the platform at the start of the game
void initPlatform(platformState *plat){
	plat->platformX = plat->platformXPrevious = 3;
	plat->platformX_1 = plat->platformX_1Previous = plat->platformX-1;
	plat->platformX_2 = plat->platformX_2Previous = plat->platformX+1;
	plat->platformY = plat->platformYPrevious = 7;
}

//takes a ball state and sets the ball at the start of the game
void initBall(BallState* ball){
	ball->ballY = ball->ballYPrevious = 5;
	ball->ballX = ball->ballXPrevious =  5;
}

//takes a block state and sets all the blocks at the start of the game
void initBlocks(blockState* block){
	block->block1X = 1;
	block->block1Y = 1;
	block->block1 = 1;

	block->block2X = 2;
	block->block2Y = 1;
	block->block2 = 1;

	block->block3X = 3;
	block->block3Y = 1;
	block->block3 = 1;

	block->block4X = 4;
        block->block4Y = 1;
	block->block4 = 1;

	block->block5X = 5;
        block->block5Y = 1;
        block->block5 = 1;

        block->block6X = 6;
        block->block6Y = 1;
        block->block6 = 1;

        block->block7X = 1;
        block->block7Y = 2;
        block->block7 = 1;

        block->block8X = 6;
        block->block8Y = 2;
        block->block8 = 1;

	block->block9X = 1;
        block->block9Y = 3;
        block->block9 = 1;

        block->block10X = 2;
        block->block10Y = 3;
        block->block10 = 1;

        block->block11X = 3;
        block->block11Y = 3;
        block->block11 = 1;

        block->block12X = 4;
        block->block12Y = 3;
        block->block12 = 1;

        block->block13X = 5;
        block->block13Y = 3;
        block->block13 = 1;

        block->block14X = 6;
        block->block14Y = 3;
        block->block14 = 1;

}


/*
takes a bitmap and a ball states and modifies the bitmap to draw the ball on the screen.
Print the x and y position of the ball
*/
void drawBall(sense_fb_bitmap_t * screen, BallState* ball){
	setPixel(screen, ball->ballXPrevious, ball->ballYPrevious,  getColor(0,0,0));
	setPixel(screen, ball->ballX, ball->ballY, getColor(160,32,240));
	printf("ball X: %d ball Y: %d -- ", ball->ballX , ball->ballY);
}

//takes a bitmap and blockstate and modifies the bitmap to draw all the blocks on the screen
void drawBlocks(sense_fb_bitmap_t *screen, blockState * block){
	if(block->block1 == 1)
		setPixel(screen, block->block1X, block->block1Y, getColor(0, 255, 0));
	else
		setPixel(screen, block->block1X, block->block1Y, 0);
	if(block->block2 == 1)
		setPixel(screen, block->block2X, block->block2Y, getColor(0, 255, 0));
        else
                setPixel(screen, block->block2X, block->block2Y, 0);
	if(block->block3 == 1)
		setPixel(screen, block->block3X, block->block3Y, getColor(0, 255, 0));
	else
		setPixel(screen, block->block3X, block->block3Y, 0);
	if(block->block4 == 1)
		setPixel(screen, block->block4X, block->block4Y, getColor(0, 255, 0));
	else
		setPixel(screen, block->block4X, block->block4Y, 0);
	if(block->block5 == 1)
                setPixel(screen, block->block5X, block->block5Y, getColor(0, 255, 0));
        else
                setPixel(screen, block->block5X, block->block5Y, getColor(0, 0, 0));
        if(block->block6 == 1)
                setPixel(screen, block->block6X, block->block6Y, getColor(0, 255, 0));
        else
                setPixel(screen, block->block6X, block->block6Y, getColor(0, 0, 0));
        if(block->block7 == 1)
                setPixel(screen, block->block7X, block->block7Y, getColor(0, 255, 0));
        else
                setPixel(screen, block->block7X, block->block7Y, getColor(0, 0, 0));
        if(block->block8 == 1)
                setPixel(screen, block->block8X, block->block8Y, getColor(0, 255, 0));
        else
                setPixel(screen, block->block8X, block->block8Y, getColor(0, 0, 0));
	if(block->block9 == 1)
                setPixel(screen, block->block9X, block->block9Y, getColor(0, 255, 0));
        else
                setPixel(screen, block->block9X, block->block9Y, getColor(0, 0, 0));
        if(block->block10 == 1)
                setPixel(screen, block->block10X, block->block10Y, getColor(0, 255, 0));
        else
                setPixel(screen, block->block10X, block->block10Y, getColor(0, 0, 0));
        if(block->block11 == 1)
                setPixel(screen, block->block11X, block->block11Y, getColor(0, 255, 0));
        else
                setPixel(screen, block->block11X, block->block11Y, getColor(0, 0, 0));
        if(block->block12 == 1)
                setPixel(screen, block->block12X, block->block12Y, getColor(0, 255, 0));
        else
                setPixel(screen, block->block12X, block->block12Y, getColor(0, 0, 0));
        if(block->block13 == 1)
                setPixel(screen, block->block13X, block->block13Y, getColor(0, 255, 0));
        else
                setPixel(screen, block->block13X, block->block13Y, getColor(0, 0, 0));
        if(block->block14 == 1)
                setPixel(screen, block->block14X, block->block14Y, getColor(0, 255, 0));
        else
                setPixel(screen, block->block14X, block->block14Y, getColor(0, 0, 0));

}

/*
takes a bitmap, platform state, and the coordinates of the gyro
 and updates the bitmap to draw the platform on the screen. Also
prints the x coordiantes of the right, left, and middle platform
*/
void drawPlatform(sense_fb_bitmap_t * screen, platformState * plat, coordinate_t *gyroData){
       	for(int i = 0; i < 8; i++)
		setPixel(screen, i, 7, 0);

	setPixel(screen, plat->platformX, plat->platformY, getColor(255,0,0));
        setPixel(screen, plat->platformX_1, plat->platformY, getColor(255,0,0));
        setPixel(screen, plat->platformX_2, plat->platformY, getColor(255,0,0));
        printf(" -- Middle:%d Left:%d Right:%d\n" , plat->platformX, plat->platformX_1,plat->platformX_2 );

}

/*
takes a platform state and the coordiantes of the gyro score and moves the platform
depending on which way the gyro is tilted. Updates the state of the  platform.
*/
void movePlatform(platformState *plat, coordinate_t*gyroData){
	int x = plat->platformX;
	int y = plat->platformX_1;
	int z = plat->platformX_2;
	plat->platformXPrevious = plat->platformX;
	if(gyroData->y > 5){
		x-=1;
		y-=1;
		z-=1;
	}
	else if(gyroData->y < -5){
		x +=1;
		y +=1;
		z +=1;
	}
	if(x!=plat->platformX && x >=1 && x <7){
		plat->platformX = x;
		plat->platformX_1 = y;
		plat->platformX_2 = z;
	}
}

/*
takes a ball states, platform state, int represing the vertical direction of the ball, and an int representing
the diagonal direction of the ball. The ball starts off by falling down and then is modified by collsions (either
hitting the walls, roof, or floor). Changesvalues at of the ballY_direction, ballDia_direction, and the state of the ball
*/
void moveBall(BallState* ball, platformState *plat, int * bally_direction, int * ballDia_direction){
	usleep(2000);
	ball->ballXPrevious = ball->ballX;
	ball->ballYPrevious = ball->ballY;
	if((ball->ballX != plat->platformX  && ball->ballX != plat->platformX_1 && ball->ballX != plat->platformX_2) && ball->ballY >=7){
		ball->ballY = 6;
	}
	if(ball->ballY == 0){
                *bally_direction = DOWN;
        }
        if(ball->ballY <= 0 && *ballDia_direction == RIGHT){
                *bally_direction = DOWN;
		*ballDia_direction =  RIGHT;
        }
	if(ball->ballY <= 0 && *ballDia_direction == LEFT){
                *bally_direction = DOWN;
                *ballDia_direction =  LEFT;
        }
	if(ball->ballY <= 0 && *ballDia_direction == UP){
                *bally_direction = DOWN;
        }
	if(ball->ballX == plat->platformX &&  ball->ballY >=  6){
		*bally_direction = UP;
	}
	if(ball->ballX == 0){
		*ballDia_direction = RIGHT;
	}
	if(ball->ballX == 7){
		*ballDia_direction = LEFT;
	}
	if(ball->ballX == 0 && ball->ballY == 0){
		*bally_direction = DOWN;
		*ballDia_direction = RIGHT;
	}
        if(ball->ballX == 0 && ball->ballY == 7){
                ball->ballY =1;
		*bally_direction = UP;
                *ballDia_direction = RIGHT;
        }
        if(ball->ballX == 7 && ball->ballY == 0){
                *bally_direction = DOWN;
                *ballDia_direction = LEFT;
        }
        if(ball->ballX == 7 && ball->ballY == 7){
                ball->ballY =1;
                *bally_direction = UP;
                *ballDia_direction = LEFT;
        }
	if(ball->ballX ==1 && ball->ballY==7){
		*ballDia_direction = RIGHT;
	}
	if(ball->ballX == 6 && ball->ballY ==7){
		*ballDia_direction ==LEFT;
	}
	if(ball->ballX == plat->platformX_1 && ball->ballY >=6){
		*bally_direction = UP;
		*ballDia_direction = LEFT;
	}
	if((ball->ballX == plat->platformX_2 || ball->ballX == plat->platformX) && ball->ballX ==6 && ball->ballY >=6){
		ball->ballY = 5;
	}
	if((ball->ballX == plat->platformX_1 || ball->ballX == plat->platformX)  && ball->ballX == 1 && ball->ballY >= 6){
		ball->ballY= 5;
	}
	if(ball->ballX == 7 && plat->platformX_2 ==7  && ball->ballY >=6){
		ball->ballY = 5;
		ball->ballX = 5;
	}
	if(ball->ballX == 0 && plat->platformX_1 ==0  && ball->ballY >=6){
                ball->ballY = 5;
                ball->ballX = 1;
        }
	if(ball->ballX == plat->platformX_2 && ball->ballY >=6){
                *bally_direction = UP;
                *ballDia_direction = RIGHT;

        }


	if(*bally_direction == UP){
                ball->ballY--;
        }
        else{
                ball->ballY++;
        }
	if(*bally_direction == UP && *ballDia_direction == LEFT){
		ball->ballX--;

        }
	if(*bally_direction == UP && *ballDia_direction == RIGHT){
                ball->ballX++;
        }

	if(*bally_direction == DOWN && *ballDia_direction == LEFT){
                ball->ballX--;
        }
        if(*bally_direction == DOWN && *ballDia_direction == RIGHT){
                ball->ballX++;
        }

}


/*
takes a ballstate, blockState, an int represing the vertical direction of the ball, and an
int represing the horizontal direction of the ball. Turns the values represing if the block is on to off
if the ball hits the block.Modifes the state of a ball if the ball
hit it if the block based on the proper collsion. note to modify the collsion the bally_direction interger and
the ballDia_direction int will be changed. Also prints whether the bricks are turned on or off
*/
void hitBrick(BallState* ball, blockState * block, int * bally_direction, int * ballDia_direction)
{
	if(ball->ballX == block->block1X && ball->ballY == block->block1Y && block->block1 == 1 && *bally_direction ==UP){
		block->block1 = 0;
		*bally_direction = DOWN;
	}
	if(ball->ballX == block->block2X && ball->ballY == block->block2Y && block->block2 == 1 && *bally_direction ==UP){
                block->block2 = 0;
                *bally_direction = DOWN;
        }
	if(ball->ballX == block->block3X && ball->ballY == block->block3Y && block->block3 == 1  && *bally_direction ==UP){
                block->block3 = 0;
                *bally_direction = DOWN;
        }
	if(ball->ballX == block->block4X && ball->ballY == block->block4Y && block->block4 == 1  && *bally_direction ==UP){
                block->block4 = 0;
                *bally_direction = DOWN;
        }
	if(ball->ballX == block->block5X && ball->ballY == block->block5Y && block->block5 == 1 && *bally_direction ==UP){
                block->block5 = 0;
                *bally_direction = DOWN;
        }
         if(ball->ballX == block->block6X && ball->ballY == block->block6Y && block->block6 == 1 && *bally_direction ==UP){
                block->block6 = 0;
                *bally_direction = DOWN;
        }
        if(ball->ballX == block->block7X && ball->ballY == block->block7Y && block->block7 == 1  && *bally_direction ==UP){
                block->block7 = 0;
                *bally_direction = DOWN;
        }
        if(ball->ballX == block->block8X && ball->ballY == block->block8Y && block->block8 == 1  && *bally_direction ==UP){
                block->block8 = 0;
                *bally_direction = DOWN;
        }
	if(ball->ballX == block->block9X && ball->ballY == block->block9Y && block->block9 == 1  && *bally_direction ==UP){
                block->block9 = 0;
                *bally_direction = DOWN;
        }
        if(ball->ballX == block->block10X && ball->ballY == block->block10Y && block->block10 == 1  && *bally_direction ==UP){
                block->block10 = 0;
                *bally_direction = DOWN;
        }
        if(ball->ballX == block->block11X && ball->ballY == block->block11Y && block->block11 == 1 && *bally_direction ==UP){
                block->block11 = 0;
                *bally_direction = DOWN;
        }
         if(ball->ballX == block->block12X && ball->ballY == block->block12Y && block->block12 == 1 && *bally_direction ==UP){
                block->block12 = 0;
                *bally_direction = DOWN;
        }
        if(ball->ballX == block->block13X && ball->ballY == block->block13Y && block->block13 == 1  && *bally_direction ==UP){
                block->block13 = 0;
                *bally_direction = DOWN;
        }
        if(ball->ballX == block->block14X && ball->ballY == block->block14Y && block->block14 == 1  && *bally_direction ==UP){
                block->block14 = 0;
                *bally_direction = DOWN;
        }

	if(ball->ballX == block->block1X && ball->ballY == block->block1Y && block->block1 == 1 && *bally_direction == DOWN){
                block->block1 = 0;
                *bally_direction = UP;
        }
        if(ball->ballX == block->block2X && ball->ballY == block->block2Y && block->block2 == 1 && *bally_direction ==DOWN){
                block->block2 = 0;
                *bally_direction = UP;
        }
        if(ball->ballX == block->block3X && ball->ballY == block->block3Y && block->block3 == 1  && *bally_direction == DOWN){
                block->block3 = 0;
                *bally_direction = UP;
        }
        if(ball->ballX == block->block4X && ball->ballY == block->block4Y && block->block4 == 1  && *bally_direction == DOWN){
                block->block4 = 0;
                *bally_direction = UP;
        }
	if(ball->ballX == block->block5X && ball->ballY == block->block5Y && block->block5 == 1 && *bally_direction == DOWN){
                block->block5 = 0;
                *bally_direction = UP;
        }
         if(ball->ballX == block->block6X && ball->ballY == block->block6Y && block->block6 == 1 && *bally_direction ==DOWN){
                block->block6 = 0;
                *bally_direction = UP;
        }
        if(ball->ballX == block->block7X && ball->ballY == block->block7Y && block->block7 == 1  && *bally_direction ==DOWN){
                block->block7 = 0;
                *bally_direction = UP;
        }
	if(ball->ballX == block->block8X && ball->ballY == block->block8Y && block->block8 == 1  && *bally_direction ==DOWN){
                block->block8 = 0;
                *bally_direction = UP;
        }
        if(ball->ballX == block->block9X && ball->ballY == block->block9Y && block->block9 == 1  && *bally_direction ==DOWN){
                block->block9 = 0;
                *bally_direction = UP;
        }
        if(ball->ballX == block->block10X && ball->ballY == block->block10Y && block->block10 == 1  && *bally_direction ==DOWN){
                block->block10 = 0;
                *bally_direction = UP;
        }
        if(ball->ballX == block->block11X && ball->ballY == block->block11Y && block->block11 == 1 && *bally_direction ==DOWN){
                block->block11 = 0;
                *bally_direction = UP;
        }
         if(ball->ballX == block->block12X && ball->ballY == block->block12Y && block->block12 == 1 && *bally_direction ==DOWN){
                block->block12 = 0;
                *bally_direction = UP;
        }
        if(ball->ballX == block->block13X && ball->ballY == block->block13Y && block->block13 == 1  && *bally_direction ==DOWN){
                block->block13 = 0;
                *bally_direction = UP;
        }
        if(ball->ballX == block->block14X && ball->ballY == block->block14Y && block->block14 == 1  && *bally_direction ==DOWN){
                block->block14 = 0;
                *bally_direction = UP;
        }


printf("\n\n\n block on or off --1:%d 2:%d 3:%d 4:%d 5:%d 6:%d 7:%d 8:%d 9:%d 10:%d 11:%d 12:%d 13:%d 14:%d\n", block->block1, block->block2, block->block3, block->block4,block->block5, block->block6, block->block7, block->block8,  block->block9, block->block10, block->block11, block->block12,  block->block13, block->block14);
}

/*
updates the global variables win and run if all the blocks are turned off
*/
void winScreen(blockState * block){
if(block->block1 +  block->block2 +  block->block3 + block->block4 + block->block5 + block->block6 +  block->block7 +
	 block->block8 +  block->block9 +  block->block10 +  block->block11 +  block->block12 +  block->block13 + block->block14 ==0){
	run = 0;
	win = 1;}
}

int main(){
	int starting = 1;
	int cnt = 0;
	int bally_direction = DOWN;
	int ballDia_direction = UP;
	signal(SIGINT, handler);
	pi_i2c_t* device;
	coordinate_t data;
	platformState platform;
	BallState ball;
	blockState block;

	initPlatform(&platform);
	initBall(&ball);
	initBlocks(&block);

	printf("Set the pi flat to calibrate\n");
	pi_framebuffer_t *fb = getFBDevice();
	if(!fb)
		return 0;
	clearBitmap(fb->bitmap, 0);
	drawPlatform(fb->bitmap, &platform, &data);
	drawBall(fb->bitmap, &ball);
	drawBlocks(fb->bitmap, &block);
	device = geti2cDevice();
	if(device){
		configureAccelGyro(device);
		while(run){
			usleep(1000);
			while (run && getGyroPosition(device, &data)){
				if(data.y !=  0.0 && starting){
					starting = 0;
					printf("setup complete");
				}
				if (!(cnt % 10)){
					movePlatform(&platform, &data);
					drawPlatform(fb->bitmap, &platform, &data);
					hitBrick(&ball, &block, &bally_direction, &ballDia_direction);
					moveBall(&ball,&platform, &bally_direction, &ballDia_direction);
					drawBlocks(fb->bitmap, &block);
		 			drawBall(fb->bitmap, &ball);
					winScreen(&block);
					printf("ball direction: %d", bally_direction);
				}
				cnt++;
			}
		}
		if(win)
		clearBitmap(fb->bitmap, getColor(0,255,0));
		else
		clearBitmap(fb->bitmap, getColor(255,0,0));
	}
	usleep(1000000);
	clearBitmap(fb->bitmap, getColor(0,0,0));
	freeFrameBuffer(fb);
	freei2cDevice(device);
}

