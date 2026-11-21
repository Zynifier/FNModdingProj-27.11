// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "DataStores/FortDataStore_AudioComponentParameters.h"
#include "FortAnimNotify_AudioComponentParameters.generated.h"

UENUM(BlueprintType)
enum class EFortNotifyAudioParamsStoreSource : uint8
{
	/** 
	 * Audio param data will live on the weapon itself.
	 * useful for fire/impact effects, or weapon idles
	 **/
	Weapon = 0,
	/**
	 *	Audio param data will live on the pawn itself.
	 *	Useful for emote/GameplayCue effects, or CCPM particles
	 **/
	Pawn = 1 UMETA(Hidden),
	/** 
	 * 	Audio param data will live on the pawn's controller.
	 * 	... ???
	 **/
	Controller = 2 UMETA(Hidden),
};

UCLASS(HideCategories=("Object"))
class UFortAnimNotify_AudioComponentParameters : public UAnimNotify
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Parameters", meta=(AdvancedDisplay))
	EFortNotifyAudioParamsStoreSource Source;

	UPROPERTY(VisibleAnywhere, Category="Parameters", meta=(AdvancedDisplay))
	FName DataStoreName;

	UPROPERTY(EditAnywhere, Category="Parameters", meta=(AdvancedDisplay))
	FName ParameterGroupName;

	UPROPERTY(EditAnywhere, Category="Parameters")
	TArray<FFortBasicAudioParam> AudioParams;

};

