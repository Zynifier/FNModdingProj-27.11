// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MeshNetworkTypes.generated.h"

UENUM(BlueprintType)
enum class EMeshNetworkNodeType : uint8
{
	Root = 0 UMETA(DisplayName="Root Server"),
	//! Top level Mesh Node that acts as the absolute source of truth / controller.
//! TODO: At some point we may have support of "sub meshes" where there's a top level
//!			configuration like node, and then a bunch of sparse networks.
//!			In that case, it's likely the controller of each individual network would
//!			be the "Root" for its network.

	Inner = 1 UMETA(DisplayName="Intermediate Server"),
	//! An intermediate server node. This only connects to either the Root Node,
//! other Inner Nodes, or Edge Nodes.

	Edge = 2 UMETA(DisplayName="Game Server"),
	//! An edge server node, typically a Game Server.
//! May be connected directly to the Root Node in "shallow" networks or to
//! Inner nodes (but not other Edge nodes).

	Client = 3 UMETA(DisplayName="Client"),
	//! A normal game client. Typically, these aren't connected directly to other
//! Mesh Nodes. Instead the Game Server is connected to the mesh.

	Unknown = 4 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EMeshNetworkRelevancy : uint8
{
	NotRelevant = 0 UMETA(DisplayName="Not Replicated", Tooltip="The actor will not replicate at all."),
	//~ This is not relevant for any Nodes.

	RelevantToEdgeNodes = 1 UMETA(DisplayName="Replicate to Game Servers", Tooltip="The actor will replicate through the mesh network but not from game servers to clients."),
	//~ This is not relevant for any Nodes.
//~ This is only relevant to Edge Nodes.
//~ Useful for things like configuration or state that
//~ clients won't see directly.

	RelevantToClients = 2 UMETA(DisplayName="Replicate to Clients", Tooltip="The actor will replicate through the mesh and also to clients."),
};

