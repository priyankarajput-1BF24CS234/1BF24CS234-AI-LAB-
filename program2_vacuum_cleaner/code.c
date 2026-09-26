# AI Vacuum Cleaner Agent

rooms = {
    "A": "Dirty",
    "B": "Dirty"
}

current_location = "A"


def ai_agent(location, rooms):
    """
    AI decides what action to take based on
    the current location and room conditions.
    """

    # If the current room is dirty, clean it
    if rooms[location] == "Dirty":
        return "SUCK"

    # If current room is clean, decide where to move
    if location == "A":
        return "MOVE_RIGHT"
    else:
        return "MOVE_LEFT"


while True:

    print("\n-------------------------")
    print("Current Location:", current_location)
    print("Room Status:", rooms)

    # AI makes a decision
    action = ai_agent(current_location, rooms)

    print("AI Decision:", action)

    # Perform the AI's action
    if action == "SUCK":

        print("AI: Cleaning room", current_location)
        rooms[current_location] = "Clean"

    elif action == "MOVE_RIGHT":

        print("AI: Moving from A to B")
        current_location = "B"

    elif action == "MOVE_LEFT":

        print("AI: Moving from B to A")
        current_location = "A"

    # Check whether all rooms are clean
    if rooms["A"] == "Clean" and rooms["B"] == "Clean":

        print("\n-------------------------")
        print("AI: All rooms are clean!")
        print("Task completed.")
        break
