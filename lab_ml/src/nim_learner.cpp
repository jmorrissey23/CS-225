/**
 * @file NimLearner.cpp
 * CS 225: Data Structures
 */

#include "nim_learner.h"
#include <ctime>


/**
 * Constructor to create a game of Nim with `startingTokens` starting tokens.
 *
 * This function creates a graph, `g_` representing all of the states of a
 * game of Nim with vertex labels "p#-X", where:
 * - # is the current player's turn; p1 for Player 1, p2 for Player2
 * - X is the tokens remaining at the start of a player's turn
 *
 * For example:
 *   "p1-4" is Player 1's turn with four (4) tokens remaining
 *   "p2-8" is Player 2's turn with eight (8) tokens remaining
 *
 * All legal moves between states are created as edges with initial weights
 * of 0.
 *
 * @param startingTokens The number of starting tokens in the game of Nim.
 */
NimLearner::NimLearner(unsigned startingTokens) : g_(true, true) {
    /* Your code goes here! */
    startingVertex_ = "p1-" + std::to_string(startingTokens);
    int start = startingTokens;
    int tokens = startingTokens;
    while(tokens >= 0) {
      Vertex v1 = "p1-" + std::to_string(tokens);
      Vertex v2 = "p2-" + std::to_string(tokens);
      g_.insertVertex(v1);
      g_.insertVertex(v2);
      if (tokens <= start - 1) { // if one past the starting vertex
        g_.insertEdge("p1-" + std::to_string(tokens + 1), v2);
        g_.setEdgeWeight("p1-" + std::to_string(tokens + 1), v2, 0);
        g_.insertEdge("p2-" + std::to_string(tokens + 1), v1);
        g_.setEdgeWeight("p2-" + std::to_string(tokens + 1), v1, 0);
      }
      if (tokens <= start - 2) { // if two past the starting vertex
        g_.insertEdge("p1-" + std::to_string(tokens + 2), v2);
        g_.setEdgeWeight("p1-" + std::to_string(tokens + 2), v2, 0);
        g_.insertEdge("p2-" + std::to_string(tokens + 2), v1);
        g_.setEdgeWeight("p2-" + std::to_string(tokens + 2), v1, 0);
      }
      tokens--;
    }
}

/**
 * Plays a random game of Nim, returning the path through the state graph
 * as a vector of `Edge` classes.  The `origin` of the first `Edge` must be
 * the vertex with the label "p1-#", where # is the number of starting
 * tokens.  (For example, in a 10 token game, result[0].origin must be the
 * vertex "p1-10".)
 *
 * @returns A random path through the state space graph.
 */
std::vector<Edge> NimLearner::playRandomGame() const {
  vector<Edge> path;
 /* Your code goes here! */
  Vertex looper = startingVertex_;
  //path.push_back(startingVertex_);
  int player = 1;
  int tokens = std::stoi(startingVertex_.substr(3));
  while (g_.getAdjacent(looper).size() != 0) {
    int move = rand() % 2;
    if (move == 0) { // take 1 token
      tokens -= 1;
      if (player == 1) { // player 1's turn
        if (g_.edgeExists(looper, "p2-" + std::to_string(tokens))) {
          path.push_back(g_.getEdge(looper, "p2-" + std::to_string(tokens)));
          looper = "p2-" + std::to_string(tokens);
          player = 2;
        } else {
          tokens++;
        }
      } else { // player 2's turn
        if (g_.edgeExists(looper,  "p1-" + std::to_string(tokens))) {
          path.push_back(g_.getEdge(looper, "p1-" + std::to_string(tokens)));
          looper = "p1-" + std::to_string(tokens);
          player = 1;
        } else {
          tokens++;
        }
      }
      
    } else { // take 2 tokens
        tokens -= 2;
        if (player == 1) {
          if (g_.edgeExists(looper, "p2-" + std::to_string(tokens))) {
            path.push_back(g_.getEdge(looper, "p2-" + std::to_string(tokens)));
            looper = "p2-" + std::to_string(tokens);
            player = 2;
          } else {
            tokens +=2;
          }
        } else {
          if (g_.edgeExists(looper,"p1-" + std::to_string(tokens))) {
            path.push_back(g_.getEdge(looper, "p1-" + std::to_string(tokens)));
            looper = "p1-" + std::to_string(tokens);
            player = 1;
          } else {
            tokens +=2;
          }
        }
    }
  }
  return path;
}

/*
 * Updates the edge weights on the graph based on a path through the state
 * tree.
 *
 * If the `path` has Player 1 winning (eg: the last vertex in the path goes
 * to Player 2 with no tokens remaining, or "p2-0", meaning that Player 1
 * took the last token), then all choices made by Player 1 (edges where
 * Player 1 is the source vertex) are rewarded by increasing the edge weight
 * by 1 and all choices made by Player 2 are punished by changing the edge
 * weight by -1.
 *
 * Likewise, if the `path` has Player 2 winning, Player 2 choices are
 * rewarded and Player 1 choices are punished.
 *
 * @param path A path through the a game of Nim to learn.
 */
void NimLearner::updateEdgeWeights(const std::vector<Edge> & path) {
 /* Your code goes here! */
  int winner = 0;
  if (path.back().dest[1] == '2') {
    winner = 1;
  } else {
    winner = 2;
  }

  for (size_t i = 0; i < path.size(); i++) {
    int weight = g_.getEdgeWeight(path[i].source, path[i].dest);
    if (winner == 1) { // player 1 won
      if (path[i].source[1] == '1') { //player 1's turn
        g_.setEdgeWeight(path[i].source, path[i].dest, g_.getEdgeWeight(path[i].source, path[i].dest) + 1);
      } else { // player 2's turn
        g_.setEdgeWeight(path[i].source, path[i].dest, g_.getEdgeWeight(path[i].source, path[i].dest) - 1);
      }
    } else {  //player 2 won
      if (path[i].source[1] == '1') { //player 1's turn
        g_.setEdgeWeight(path[i].source, path[i].dest, g_.getEdgeWeight(path[i].source, path[i].dest) - 1);
      } else { // player 2's turn
        g_.setEdgeWeight(path[i].source, path[i].dest, g_.getEdgeWeight(path[i].source, path[i].dest) + 1);
      }
    }
  }

}

/**
 * Label the edges as "WIN" or "LOSE" based on a threshold.
 */
void NimLearner::labelEdgesFromThreshold(int threshold) {
  for (const Vertex & v : g_.getVertices()) {
    for (const Vertex & w : g_.getAdjacent(v)) {
      int weight = g_.getEdgeWeight(v, w);

      // Label all edges with positve weights as "WINPATH"
      if (weight > threshold)           { g_.setEdgeLabel(v, w, "WIN"); }
      else if (weight < -1 * threshold) { g_.setEdgeLabel(v, w, "LOSE"); }
    }
  }
}

/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & NimLearner::getGraph() const {
  return g_;
}
