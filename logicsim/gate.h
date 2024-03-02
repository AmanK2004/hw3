#ifndef GATE_H
#define GATE_H
#include <vector>
#include <queue>
#include <tuple>
#include "event.h"
#include "wire.h"

class Gate 
{
    public:
        Gate(int, Wire*);
        virtual ~Gate();
        virtual Event* update(uint64_t) =0;
        void wireInput(unsigned int,Wire*);
        
    protected:
      Wire* m_output;
      std::vector<Wire*> m_inputs;
			uint32_t m_delay;
			char m_current_state;
};

class And2Gate : public Gate
{
  public:
      And2Gate(Wire*, Wire*, Wire*);
      Event* update(uint64_t);  
};

class Or2Gate : public Gate
{
  public:
      Or2Gate(Wire*, Wire*, Wire*);
      Event* update(uint64_t);
};

// Define the NotGate class, inheriting from the Gate class
class NotGate : public Gate
{
  public:
      // Constructor: Initializes a NotGate with input and output wires
      NotGate(Wire* input_wire, Wire* output_wire);

      // Update function: Calculates the output state based on input state changes
      // Returns a pointer to an Event object if the output state changes, nullptr otherwise
      Event* update(uint64_t current_time);  
};

#endif