//------------------------------------------------------------------------------
// hw4.c
//
// Rotating two dimensional matrices storing tetris blocks.
//
// Author: Max Mustermann, 123456
//------------------------------------------------------------------------------
//
#include <stdio.h>

#define NUM_BLOCKS 4
#define BLOCK_SIZE 4


//------------------------------------------------------------------------------
// rotateBlock rotates a single tetris block clockwise.
//
// @param block: the tetris block to rotate
//
void rotateBlock(char block[BLOCK_SIZE][BLOCK_SIZE])
{
  int row, col;
  char original[BLOCK_SIZE][BLOCK_SIZE];

  for (row = 0; row < BLOCK_SIZE; row++)
    for (col = 0; col < BLOCK_SIZE; col++)
      original[row][col] = block[row][col];

  for (row = 0; row < BLOCK_SIZE; row++)
      for (col = 0; col < BLOCK_SIZE; col++)
        block[row][col] = original[BLOCK_SIZE - col - 1][row];
}

//------------------------------------------------------------------------------
// printBlocks prints all blocks to the standard output.
//
// @param blocks: an array with all the blocks that should pe printed
//
void printBlocks(char blocks[NUM_BLOCKS][BLOCK_SIZE][BLOCK_SIZE])
{
  int block, row, col;
  for (row = 0; row < BLOCK_SIZE; row++)
  {
    for (block = 0; block < NUM_BLOCKS; block++)
    {
      printf("%s%c", block > 0 ? "  " : " ", blocks[block][row][0]);
      for (col = 1; col < BLOCK_SIZE; col++)
        printf(" %c", blocks[block][row][col]);
    }
    printf("\n");
  }
}

//------------------------------------------------------------------------------
// main initializes four tetris blocks and rotetes them four times. After each
// step, the blocks are printed to the standard output.
//
// @return: always 0 (success)
//
int main()
{
  char blocks[NUM_BLOCKS][BLOCK_SIZE][BLOCK_SIZE] = {
    {
      {'-', '-', '-', '-'},
      {'-', 'o', '-', '-'},
      {'o', 'o', 'o', '-'},
      {'-', '-', '-', '-'}
    },
    {
      {'-', '-', '-', '-'},
      {'-', 'o', 'o', '-'},
      {'o', 'o', '-', '-'},
      {'-', '-', '-', '-'}
    },
    {
      {'-', '-', '-', '-'},
      {'-', 'o', '-', '-'},
      {'-', 'o', '-', '-'},
      {'-', 'o', 'o', '-'}
    },
    {
      {'-', '-', 'o', '-'},
      {'-', '-', 'o', '-'},
      {'-', '-', 'o', '-'},
      {'-', '-', 'o', '-'}
    }
  };

  int rotations, block;
  printBlocks(blocks);
  for (rotations = 0; rotations < 4; rotations++)
  {
    printf("\n");
    printBlocks(blocks);
    for (block = 0; block < NUM_BLOCKS; block++)
      rotateBlock(blocks[block]);
  }
  
  return 0;
}
