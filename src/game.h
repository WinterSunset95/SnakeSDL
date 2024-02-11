void checkCollision(App *app, struct cell snake[], struct cell *food);
void drawFood(App *app, struct cell food);
void updateSnake(struct cell snake[]);
void moveSnake(struct cell snake[]);
void handleInput(SDL_Event *e, struct cell snake[]);
