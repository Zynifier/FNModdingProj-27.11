// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortPlaylistData.generated.h"

class UFortPlaylistAthena;

USTRUCT()
struct FPropertyOverride : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FString PropertyScope;

	UPROPERTY(Transient)
	FString PropertyName;

	UPROPERTY(Transient)
	FString PropertyData;

};

USTRUCT()
struct FPropertyOverrideScope
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FPropertyOverride> PropertyOverrides;

};

USTRUCT()
struct FPlaylistPropertyArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FPropertyOverride> PropertyOverrides;

private:
	UPROPERTY(Transient, NotReplicated)
	int32 PlaylistReplicationKey;

	UPROPERTY(Transient)
	TObjectPtr<UFortPlaylistAthena> BasePlaylist;

	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UFortPlaylistAthena> OverridePlaylist;

	UPROPERTY(Transient, NotReplicated)
	TMap<FString, FPropertyOverrideScope> PropertyOverrideScopes;

};

