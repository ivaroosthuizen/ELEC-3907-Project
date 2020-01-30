/*
 * author: Ethan Borduas
 * date: 01-23-2020
 * 
 * Maze Solving robot
 * 
 * Code for a robot that navigates a maze to make an internal map of the maze.
 * The maze is represented by a plannar graph where each node is a tile on the maze
 * 
 * A flood fill algorithm is used to find the shortest path between two points
 * 
 */

const int MAZE_X = 8;//The size of the maze in the x direction
const int MAZE_Y = 8;//The size of the maze in the y direction



/* 
 * the structure node erpresents a tile in the maze.
 * it has the ability to keep strack of neighbouring nodes
 */
 struct node {
    bool visited;   //boolean keeping track of if the tile has been visited
    int floodBox;  //used to keep track of how far away the tile is from a given tile
    node* north;    //points to the node above
    node* east;     //points to the node on the right
    node* south;    //points to the node bellow
    node* west;     //points to the node on the left
};

/* 
 * a node representing a wall
 * this node will the used to keep track of where walls are and will be used to deny pathways
 * visited=true to avoid trying to go to it
 * floodbox is negative to avoid pathing through it
 * wall points to itself in all directions to avoid pathing through it
 */
node wall = {true, -1, &wall, &wall, &wall, &wall};

node* current;//points to the current position of the robot
node* destination;// points to where the robot is trying to go

//Define constants for facing directions
//these are absolute and are independant of the robot's current facing or direction
int facing;
const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

node maze [MAZE_X] [MAZE_Y]; //Creates an array of nodes that represent each node within the maze.

 
void setup() {
  initializeMaze();
  facing = NORTH;
}

void loop() {
}



/* 
 * Recursive function that will map the maze until all tiles are visited
 * function will map one tile at a time before looking for the next tile
 */
void mapMaze(){
  if (!current->visited) {  // if the current tile is unvisited, make it visited and map the tiles on the right, left, and in front
    current->visited = true;
    mapRight();
    mapFront();
    mapLeft();
  }
  if (findNextNode()){      //if the program finds another tile that needs to be visited
    goTo(destination);
    mapMaze();
  }
  else goTo(&maze[0][0]);
};


/* 
 * Initializes the maze to have all nodes be unvisited and point to NULL
 * sets the current position to position maze [0][0]. This is the starting position of the bot reguardless of where that is relative to the maze
 */
void initializeMaze(){
  for (int i=0; i<MAZE_X; i++){
    for (int j=0; j<MAZE_Y; i++){
      maze[i][j]={false,
                  0,
                  NULL,
                  NULL,
                  NULL,
                  NULL};
    }
  }
  current = &maze [0][0];
}


/*
 * The algorithm that will locate the next node to find
 */
bool findNextNode(){
  bool noNew = false;
  int flood = 1;
  current->floodBox = flood;
  while (!noNew){
    for (int i=0; i<MAZE_X; i++){
      for (int j=0; j<MAZE_Y; j++){
        if (maze[i][j].floodBox ==flood){
          if(maze[i][j].north->visited){
            if(maze[i][j].north->floodBox==0){
              maze[i][j].north->floodBox=flood+1;
            }
          }
          else{
            destination = &maze[i][j];
            return true;
          }
          if(maze[i][j].east->visited){
            if(maze[i][j].east->floodBox==0){
              maze[i][j].east->floodBox=flood+1;
            }
          }
          else{
            destination = &maze[i][j];
            return true;
          }
          if(maze[i][j].south->visited){
            if(maze[i][j].south->floodBox==0){
              maze[i][j].south->floodBox==flood+1;
            }
          }
          else{
            destination = &maze[i][j];
            return true;
          }
          if(maze[i][j].west->visited){
            if(maze[i][j].west->floodBox==0){
              maze[i][j].west->floodBox=flood+1;
            }
          }
          else{
            destination = &maze[i][j];
            return true;
          }
        }
      }
    }
    flood++;
    noNew=true;
    for (int i = 0; i<MAZE_X; i++){
      for (int j=0; j<MAZE_Y; j++){
        if (maze[i][j].floodBox==flood){
          noNew=false;
          return false;
        }
      }
    }
  }
}
void goTo(node* aNode){
}
void mapRight(){}
void mapFront(){}
void mapLeft(){}
void turnRight(){}
void turnLeft(){}
void turnAround(){}
void goStraight(){}
