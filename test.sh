#!/bin/bash

# --- CONFIGURATION ---
PROGRAM="./push_swap"
CHECKER="./checker_linux" # Change to ./checker_Mac if needed
FILES=("test_5.txt" "test_50.txt" "test_100.txt" "test_500.txt" "test_1000.txt")

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

# Temporary files
OUT_FILE="moves.tmp"
RES_FILE="result.tmp"

# Cleanup function (runs when script exits)
cleanup() {
    rm -f "$OUT_FILE" "$RES_FILE"
}
trap cleanup EXIT

# Check files
if [ ! -f "$PROGRAM" ]; then echo -e "${RED}Error: $PROGRAM not found.${NC}"; exit 1; fi
if [ ! -f "$CHECKER" ]; then echo -e "${RED}Error: $CHECKER not found.${NC}"; exit 1; fi

for file in "${FILES[@]}"; do
    if [ ! -f "$file" ]; then continue; fi

    echo "=================================================="
    echo -e " 📂 ${BLUE}TESTING FILE: $file${NC}"
    echo "=================================================="

    line_number=0
    
    while IFS= read -r line; do
        ((line_number++))
        if [ -z "$line" ]; then continue; fi

        # 1. Run push_swap and save output strictly to a file
        #    This prevents Bash from messing up newlines
        $PROGRAM $line > "$OUT_FILE" 2>&1
        
        # 2. Count moves from the file
        MOVES_COUNT=$(wc -l < "$OUT_FILE" | tr -d ' ')

        # 3. Run checker reading from the file
        cat "$OUT_FILE" | $CHECKER $line > "$RES_FILE" 2>&1
        
        # Read the checker result
        CHECKER_RESULT=$(cat "$RES_FILE")

        # 4. Logic to determine success
        if [[ "$CHECKER_RESULT" == *"OK"* ]]; then
            echo -e "${GREEN}[OK]${NC} Moves: ${MOVES_COUNT} \t| File: $file:$line_number"
        else
            # If KO, we print the error message (checker output)
            echo -e "${RED}[KO]${NC} Moves: ${MOVES_COUNT} \t| File: $file:$line_number \t -> MSG: $CHECKER_RESULT"
        fi

    done < "$file"
    echo ""
done

echo "All tests finished."