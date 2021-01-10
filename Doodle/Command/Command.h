#pragma once

#ifndef COMMAND_H
#define COMMAND_H

class Command {

protected:
	

public:
	Command();
	virtual void redo() = 0;
	virtual void undo() = 0;
	virtual ~Command() = 0;

protected:


public:

};

#endif // COMMAND_H

