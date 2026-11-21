// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlaylistUserOptions.h"
#include "FortUserOptionDefinitions.h"
#include "FMOutgoingConnectionOption.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FMINWORLDKNOBSRUNTIME_API FFMOutgoingCableConnection
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="Cable Connection")
	FName OutputPortName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="Cable Connection")
	TSoftObjectPtr<UObject> Device;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="Cable Connection")
	FName ComponentName;

};

USTRUCT(BlueprintType)
struct FUserOptionDefinitionFMOutgoingConnectionMetaData : public FUserOptionDefinitionMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="OptionMetaData")
	FFMOutgoingCableConnection DefaultValue;

};

UCLASS(MinimalAPI, BlueprintType)
class UPlaylistUserOptionFMOutgoingCableConnection : public UPlaylistUserOptionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlaylistUserOptionFMOutgoingCableConnection")
	FFMOutgoingCableConnection DefaultValue;

};

