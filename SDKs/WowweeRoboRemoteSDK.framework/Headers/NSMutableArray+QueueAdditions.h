//
//  NSMutableArray+QueueAdditions.h
//
//  Created by Brant Young on 1/3/14.
//  Copyright (c) 2014 Codinn Studio. All rights reserved.
//

@import Foundation;

@interface NSMutableArray (QueueAdditions)

/** Add an object to the beginning of a queue.
 *
 * @param the object to add.
 */
- (void)enqueue:(id)obj;

/** Add objects to the beginning of a queue.
 *
 * @param the object to add.
 */
- (void)enqueueObjectsFromArray:(NSArray *)objects;

/** Remove an object from the end of a queue.
 *
 * @return the object that was removed.
 */
- (id)dequeue;

/** Peek the object at the specific index without removing the object.
 *
 * @return the object at the specific index.
 */
- (id)peek:(int)index;

/** Peek at the top of the queue without removing the object.
 *
 * @return the object at the top of the queue.
 */
- (id)peekHead;

/** Peek at the tail of the queue without removing the object.
 *
 * @return the object at the tail of the queue.
 */
- (id)peekTail;

/** Checks if the queue is empty.
 *
 * @return YES if queue is empty, otherwise return NO.
 */
- (BOOL)empty;

@end
