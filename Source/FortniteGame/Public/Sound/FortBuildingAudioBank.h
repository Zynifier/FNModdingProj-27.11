// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortBuildingAudioBank.generated.h"

class USoundBase;

UENUM()
namespace EFortBuildingSoundType
{
	enum Type
	{
		Construction = 0,
		GenericDestruction = 1,
		PlayerBuiltDestruction = 2,
		None = 3,
	};
}

USTRUCT()
struct FFortBuildingSoundsPerAffiliation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> SoundFriendly;

	UPROPERTY(EditDefaultsOnly, Category="Sound")
	TObjectPtr<USoundBase> SoundEnemy;

};

USTRUCT()
struct FFortBuildingSoundsPerResourceType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Sound", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceLevel"))
	FFortBuildingSoundsPerAffiliation OnConstruction[6];

	UPROPERTY(EditDefaultsOnly, Category="Sound", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceLevel"))
	FFortBuildingSoundsPerAffiliation OnGenericDestruction[6];

	UPROPERTY(EditDefaultsOnly, Category="Sound", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceLevel"))
	FFortBuildingSoundsPerAffiliation OnPlayerBuiltDestruction[6];

};

UCLASS()
class UFortBuildingAudioBank : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Sound", meta=(ArraySizeEnum="/Script/FortniteGame.EFortResourceType"))
	FFortBuildingSoundsPerResourceType Sounds[6];

};

