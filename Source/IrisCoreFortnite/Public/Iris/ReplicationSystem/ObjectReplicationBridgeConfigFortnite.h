// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ObjectReplicationBridgeConfigFortnite.generated.h"

USTRUCT()
struct FObjectReplicatedBridgeCriticalClassConfig
{
	GENERATED_BODY()

public:
	/** Instances of this class or its subclasses will force a client disconnection when it detects a protocol mismatch.*/
	UPROPERTY()
	FName ClassName;

	/** When true we force the client to disconnect when a protocol mismatch prevents it from instantiating replicated objects of this class. */
	UPROPERTY()
	bool bDisconnectOnProtocolMismatch;

};

USTRUCT()
struct FObjectReplicationBridgeTypeStatsConfig
{
	GENERATED_BODY()

public:
	/** Instances of this class or derived from this class should use delta compression */
	UPROPERTY()
	FName ClassName;

	/** The TypeStatsName this class should use. */
	UPROPERTY()
	FName TypeStatsName;

	/** If set to true this type will be reported even in configs with minimal stats reporting */
	UPROPERTY()
	bool bIncludeInMinimalCSVStats;

};

