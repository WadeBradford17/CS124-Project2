/*
Wade Bradford
CS 124
Project 2
Septemeber 26, 2022
*/

1.) Information about data set:
My data set is a set containing data regarding the stream stastics and profiles of 1000 streamers on Twitch.Tv over the course of one year. There are 11 attributes to each streamer including: streamer name, watch time (minutes), stream time (minutes), peak viewers, average viewers, followers, followers gained, views gained, partnership status, maturity status, and the language the streamer broadcasts in.

2.) Time complexities of each method in the Stack and Queue classes:
Starting with the stack first, the time complexity of both the push and pop methods is O(1) (Constant Time) as they use get methods and have no loops. The print method has a time complexity of O(N) (Linear Time) as it has to loop through the entire stack. The print method is also O(N) (Linear Time) since it too has to loop through the entire stack to print each object. The queue class is nearly identical, with the enqueue and dequeue methods both being O(1) (Constant Time). As realized in the stack class, both the search and print methods have a time complexity of O(N) Linear Time as they each have a while loop that navigates through the entire queue.

3.) Justification of pointers:
The pointers in the Queue class point to the node above (as opposed to the node below in a stack). The usage of a temporary node pointer in the enqueue method is crucial to making the program run as the new node is set point to the back and then becomes the back. In the dequeue method, pointers are used to remove from the front and store a copy of the front before updating to the new front and destroying the original copy.

4.) Explanation of order change:
The streamer objects were originally in the order of a queue, with xQcOW on top and loltyler1 on the bottom. This changed during the loop to push the dequeued streamers onto the stack, essentially flipping the order, as the streamer on top of the Queue (xQcOW) was pushed to the bottom of the stack with the following streamers pushed on top. Ending with xQcOW now on bottom and loltyler1 now on top.
