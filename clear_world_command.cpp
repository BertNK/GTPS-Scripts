else if (str == "/clear") { 
							if (!isOwner(peer))
							{
								sendWrongCmd(peer);
								continue;
							}
										
							else {
											WorldInfo* wrld = getPlyersWorld(peer);
											ENetPeer* currentPeer;
											for (currentPeer = server->peers;
												currentPeer < &server->peers[server->peerCount];
												++currentPeer)
											{
												if (currentPeer->state != ENET_PEER_STATE_CONNECTED)
													continue;
												if (((PlayerInfo*)(currentPeer->data))->currentWorld == wrld->name)
												{
													string act = ((PlayerInfo*)(peer->data))->currentWorld;
													//WorldInfo info = worldDB.get(act);
													// sendWorld(currentPeer, &info);
													int x = 3040;
													int y = 736;
													for (int i = 0; i < world->width * world->height; i++)
													{
														if (world->items[i].foreground == 6) {
															//world->items[i].foreground =0;
														}
														else if (world->items[i].foreground == 8) {
														}
														else if (world->items[i].foreground == 242 || world->items[i].foreground == 9308 || world->items[i].foreground == 2408 || world->items[i].foreground == 9504 || world->items[i].foreground == 1796 || world->items[i].foreground == 4428 || world->items[i].foreground == 7188 || world->items[i].foreground == 8470 || world->items[i].foreground == 9290 || world->items[i].foreground == 9170) {
														}
														else {
															world->items[i].foreground = 0;
															world->items[i].background = 0;
														}
													}
													sendPlayerLeave(currentPeer, (PlayerInfo*)(currentPeer->data));
													joinWorld(currentPeer, act, 0, 0);
													GamePacket p = packetEnd(appendString(appendString(createPacket(), "OnConsoleMessage"), "`^World Cleared!"));
													cout << "administrator " << static_cast<PlayerInfo*>(peer->data)->rawName << " used /Clear on " << " " << static_cast<PlayerInfo*>(peer->data)->currentWorld << endl; //console logs 
													ENetPacket* packet = enet_packet_create(p.data,
														p.len,
														ENET_PACKET_FLAG_RELIABLE);
													enet_peer_send(peer, 0, packet);
													delete p.data;
													continue;
												}
											}
										}
									}
