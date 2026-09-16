class Solution:
    def fullJustify(self, words: list[str], maxWidth: int) -> list[str]:
        res = []
        currLine, currLineLength = [], 0
        i = 0

        while i < len(words):
            # currLineLength (length of all chars in the word)
            # len(currLine) = number of words which helps us identify the number of spaces req
            # SO length of all characters + number of spaces + length(next word) > maxWidth
            # Put in the spaces and go the next line (reset the currLine, currLinelength)
            
            # Here we do not subtract -1 from spaces (len(currLine))
            # Because when we are adding the new word (words[i]) we have to add an additional space in between.
            # So len(currLine in that case) holds the correct number of spaces
            if currLineLength + len(currLine) + len(words[i]) > maxWidth:
                extra_spaces = maxWidth - currLineLength

                # Equal spaces to be divided amongst words
                # Remember if there are 3 words - you divide the spaces amongst 2.
                # Edge - If there is only 1 word - then we will get a division 0 error so take max
                # At least one word will always be there
                spaces = extra_spaces // max(len(currLine) - 1, 1)
                # Remember we distribute the remainder spaces greedily
                remainder_spaces = extra_spaces % max(len(currLine) - 1, 1)

                # Now actually distribute the spaces. Again number of words -1. Since last word does not have spaces if not the last line
                for j in range(max(len(currLine) - 1, 1)):
                    # Add the spaces to the current line after the current word
                    # ["ate", "biriyani", "today"] -> becomes ["ate  ", "biriyani  ", "today"]
                    currLine[j] += " " * spaces

                    # If there are spaces to be distributed greedily
                    if remainder_spaces:
                        currLine[j] += " "
                        remainder_spaces -= 1
                
                res.append("".join(currLine))         # Join to form a single string
                # Reset for the next line
                currLine, currLineLength = [], 0
                continue

            # Easy Case - We can append the word as maxWidth is not realized
            # Not adding spaces here. Totally handled in the above
            currLine.append(words[i])
            currLineLength += len(words[i])
            i += 1              # Increment the point to look at the next word
        
        # Handle the Last Line separately (All extra spaces go to the end)
        # Last Line will already have words from the above loop. Just join with a single space if more than 1 word. If single word -> Python automatically handles the case. trailing spaces not tere
        # print(currLine)
        last_line = " ".join(currLine)
        extra_spaces_end = maxWidth - len(last_line)
        res.append(last_line + " " * extra_spaces_end)

        return res
