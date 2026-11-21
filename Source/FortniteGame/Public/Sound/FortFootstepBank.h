// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/DataAsset.h"
#include "FortFootstepBank.generated.h"

class UFortFootstepSurfaceData;
class USoundAttenuation;
class USoundBase;

UENUM()
namespace EFortFootstepAudioType
{
	enum Type
	{
		Crouch = 0,
		CrouchSprint = 1,
		Walk = 2,
		Sprint = 3,
		Jump = 4,
		Land = 5,
		LandHard = 6,
		Max_None = 7 UMETA(DisplayName="None"),
	};
}

UENUM()
namespace EFortFootstepPosition
{
	enum Type
	{
		Parallel = 0,
		Above = 1,
		Below = 2,
		AboveOrBelowAndVisible = 3,
		Max_None = 4 UMETA(DisplayName="None"),
	};
}

UENUM()
namespace EFortFootstepSurfaceType
{
	enum Type
	{
		Default = 0,
		Wood = 1,
		Stone = 2,
		Metal = 3,
		Water = 4,
		Snow = 5,
		Ice = 6,
		Lava = 7,
		Dirt = 8,
		Grass = 9,
		Sand = 10,
		Cube = 11,
		Chrome = 12,
		ChromePetrified = 13,
		Mud = 14,
		WetConcrete = 15,
		TreeCanopy = 16,
		Max_None = 17 UMETA(DisplayName="None"),
	};
}

USTRUCT()
struct FFortFootstepAttenuationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Sound Data")
	TObjectPtr<USoundAttenuation> SoundAttenuation;

	UPROPERTY(EditDefaultsOnly, Category="Sound Data")
	TObjectPtr<USoundAttenuation> SoundAttenuationAbove;

	UPROPERTY(EditDefaultsOnly, Category="Sound Data")
	TObjectPtr<USoundAttenuation> SoundAttenuationBelow;

	UPROPERTY(EditDefaultsOnly, Category="Sound Data")
	TObjectPtr<USoundAttenuation> SoundAttenuationAboveOrBelowAndVisible;

	UPROPERTY(EditDefaultsOnly, Category="Sound Data")
	float VolumeMultiplier;

};

USTRUCT()
struct FFortFootstepSurfaceAudioData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Sound Data", meta=(ArraySizeEnum="/Script/FortniteGame.EFortFootstepAudioType"))
	TObjectPtr<USoundBase> SoundAssets[7];

	UPROPERTY(EditDefaultsOnly, Category="Sound Data", meta=(ArraySizeEnum="/Script/FortniteGame.EFortFootstepAudioType"))
	TObjectPtr<USoundBase> SoundAssetsAbove[7];

	UPROPERTY(EditDefaultsOnly, Category="Sound Data", meta=(ArraySizeEnum="/Script/FortniteGame.EFortFootstepAudioType"))
	TObjectPtr<USoundBase> SoundAssetsBelow[7];

};

USTRUCT()
struct FFortFootstepSurfaceInfo
{
	GENERATED_BODY()

};

UCLASS()
class UFortFootstepAudioBank : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION()
	USoundAttenuation* GetAttenuationAsset(bool bIsLocal, EFortFootstepAudioType::Type StepType, EFortFootstepPosition::Type StepPosition);

	UFUNCTION()
	float GetFootstepVolumeMultiplier(bool bIsLocal, bool bApplyTeammateVolume, EFortFootstepAudioType::Type StepType);

	UFUNCTION()
	USoundBase* GetSoundAsset(bool bIsLocal, EFortFootstepAudioType::Type StepType, EFortFootstepSurfaceType::Type SurfaceType, EFortFootstepPosition::Type StepPosition);

	UFUNCTION()
	void GetSurfaceInfo(FFortFootstepSurfaceInfo& OutInfo, EFortFootstepSurfaceType::Type InSurfaceType, bool bUse1PFootsteps) const;

	UPROPERTY(EditDefaultsOnly, Category="Misc", meta=(ArraySizeEnum="/Script/PhysicsCore.EPhysicalSurface"))
	TEnumAsByte<EFortFootstepSurfaceType::Type> PhysicalSurfaceMappings[35];

	UPROPERTY(EditDefaultsOnly, Category="Misc")
	float TeammateVolumeMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="Misc")
	float MaxFootstepDistance;

	UPROPERTY(EditDefaultsOnly, Category="Vertical")
	float VerticalPitchMaxBelow;

	UPROPERTY(EditDefaultsOnly, Category="Vertical")
	float VerticalPitchMaxAbove;

	UPROPERTY(EditDefaultsOnly, Category="Vertical")
	float VerticalPitchTileRange;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Assets", meta=(ArraySizeEnum="/Script/FortniteGame.EFortFootstepSurfaceType"))
	FFortFootstepSurfaceAudioData SurfaceData1P[17];

	UPROPERTY(EditDefaultsOnly, Category="Assets", meta=(ArraySizeEnum="/Script/FortniteGame.EFortFootstepSurfaceType"))
	FFortFootstepSurfaceAudioData SurfaceData3P[17];

	UPROPERTY(EditDefaultsOnly, Category="Assets", meta=(ArraySizeEnum="/Script/FortniteGame.EFortFootstepAudioType"))
	FFortFootstepAttenuationData AttenuationData1P[7];

	UPROPERTY(EditDefaultsOnly, Category="Assets", meta=(ArraySizeEnum="/Script/FortniteGame.EFortFootstepAudioType"))
	FFortFootstepAttenuationData AttenuationData3P[7];

	UPROPERTY()
	int32 VersionNumber;

};

UCLASS(BlueprintType)
class UFortFootstepSurfaceData : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void GetSurfaceInfo(FFortFootstepSurfaceInfo& OutInfo, bool bUse1PFootsteps) const;

	UPROPERTY(EditDefaultsOnly, Category="Assets")
	FFortFootstepSurfaceAudioData Surface1P;

	UPROPERTY(EditDefaultsOnly, Category="Assets")
	FFortFootstepSurfaceAudioData Surface3P;

	UPROPERTY(EditDefaultsOnly, Category="Vertical")
	float VerticalPitchMaxBelow;

	UPROPERTY(EditDefaultsOnly, Category="Vertical")
	float VerticalPitchMaxAbove;

	UPROPERTY(EditDefaultsOnly, Category="Vertical")
	float VerticalPitchTileRange;

};

UINTERFACE(MinimalAPI, BlueprintType)
class UFortSurfaceOverrideInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortSurfaceOverrideInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="FootstepSurface")
	const UFortFootstepSurfaceData* GetFootstepSurfaceData() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="SurfaceType")
	EPhysicalSurface GetSurfaceType() const;

};

