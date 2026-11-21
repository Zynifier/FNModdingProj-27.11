// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityActorComponent.h"
#include "AudioComponentBase.generated.h"

class UVerseAssetPtr;

USTRUCT()
struct FActiveSoundInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bActive;

	UPROPERTY()
	float StartTime;

};

UCLASS(Abstract)
class UAudioComponentBase : public UEntityActorComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_ActiveSoundInfo();

	UFUNCTION()
	void OnRep_SoundAsset();

	UPROPERTY(ReplicatedUsing=OnRep_SoundAsset)
	TObjectPtr<UVerseAssetPtr> SoundAsset;

	UPROPERTY(ReplicatedUsing=OnRep_ActiveSoundInfo)
	FActiveSoundInfo ActiveSoundInfo;

};

