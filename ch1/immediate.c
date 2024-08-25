#include <stdio.h>
#include <termios.h>
#include <unistd.h>

// Function to configure terminal
void configure_terminal(int reset) {
    static struct termios old, new;
    if (!reset) {
        // Backup old settings
        tcgetattr(STDIN_FILENO, &old);
        // Start with old settings
        new = old;
        // Disable canonical mode and echo
        new.c_lflag &= ~(ICANON | ECHO);
        // Set new settings
        tcsetattr(STDIN_FILENO, TCSANOW, &new);
    } else {
        // Restore old settings
        tcsetattr(STDIN_FILENO, TCSANOW, &old);
    }
}

int main() {
    char c;

    printf("Enter characters (press 'q' to quit):\n");

    // Set terminal to non-canonical mode
    configure_terminal(0);

    // Read and process each character immediately
    while ((c = getchar()) != 'q') {
        printf("You entered: %c\n", c);
    }

    // Reset terminal to original state
    configure_terminal(1);

    printf("Program ended.\n");
    return 0;
}
