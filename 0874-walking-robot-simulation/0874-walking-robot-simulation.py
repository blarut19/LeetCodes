class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        self.pos = [0, 0]
        self.m_d = 0
        self.dir = [0, 1]
        obstacles = set([(x, y) for x, y in obstacles])
        move_amount = 0
        for command in commands:
            if command == -1:
                self.move(move_amount, obstacles)
                self.turn_right()
                move_amount = 0
            elif command == -2:
                self.move(move_amount, obstacles)
                self.turn_left()
                move_amount = 0
            else:
                move_amount += command
        self.move(move_amount, obstacles)
        return self.m_d

    def update_distance(self):
        self.m_d = max(self.m_d, self.pos[0]*self.pos[0] +  self.pos[1]*self.pos[1])
    def turn_left(self):
        self.dir = [-self.dir[1], self.dir[0]]
    def turn_right(self):
        self.dir = [self.dir[1], -self.dir[0]]
    def move(self, amount, obstacles):
        x, y = self.pos
        for step in range(amount):
            x += self.dir[0]
            y += self.dir[1]
            if (x, y) in obstacles:
                break
            self.pos = [x, y]
        self.update_distance()