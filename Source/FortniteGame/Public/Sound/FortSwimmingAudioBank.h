// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortSwimmingAudioBank.generated.h"

class USoundBase;

UENUM()
namespace EFortSwimmingAudioType
{
	enum Type
	{
		Normal = 0,
		/** Normal tread water event, triggered when feet kick */
		Sprint = 1,
		/** Used during sprint anim, triggered when hands enter the water during freestyle */
		SprintStart = 2,
		/** Used for the initial push when sprinting */
		PickaxeSwing = 3,
		/** Event when swinging pickaxe */
		NormalDBNO = 4,
		/** Normal swimming while DBNO */
		SprintBoostStart = 5,
		/** Played when sprint boost begins */
		SwimStart = 6,
		/** Played when character enters swimmable water */
		SwimEnd = 7,
		/** Played when character exits swimmable water */
		Max_None = 8 UMETA(DisplayName="None"),
	};
}

UCLASS()
class UFortSwimmingAudioBank : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION()
	float GetRequiredImmersionDepth();

	UFUNCTION()
	USoundBase* GetSoundAsset(bool bIsLocal, EFortSwimmingAudioType::Type SwimType);

	UFUNCTION()
	float GetTeammateVolumeMultiplier();

	UPROPERTY(EditDefaultsOnly, Category="Assets", meta=(ArraySizeEnum="/Script/FortniteGame.EFortSwimmingAudioType"))
	TObjectPtr<USoundBase> SwimmingAssets1P[8];

	UPROPERTY(EditDefaultsOnly, Category="Assets", meta=(ArraySizeEnum="/Script/FortniteGame.EFortSwimmingAudioType"))
	TObjectPtr<USoundBase> SwimmingAssets3P[8];

	UPROPERTY(EditDefaultsOnly, Category="Misc")
	float TeammateVolumeMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Misc")
	float MaxSwimmingDistance;

	UPROPERTY(EditDefaultsOnly, Category="Misc")
	float RequiredImmersionDepth;

};

