// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_PlayerSettingsBase.h"
#include "Athena/Modifiers/FortAthenaMutator_TODOverride.h"
#include "FortAthenaMutator_PlayerZoneSettings.generated.h"

class AActor;
class UFortPlayerZoneSettingsComponent;

UENUM(BlueprintType)
enum class EAthenaTODPostProcessOverride : uint8
{
	NoOverride = 0 UMETA(DisplayName="Default"),
	PostProcess0 = 1 UMETA(DisplayName="Comic"),
	PostProcess1 = 2 UMETA(Hidden),
	PostProcess2 = 3 UMETA(DisplayName="Film Noir"),
	PostProcess3 = 4 UMETA(Hidden),
	PostProcess4 = 5 UMETA(Hidden),
	PostProcess5 = 6 UMETA(Hidden),
	PostProcess6 = 7 UMETA(Hidden),
	PostProcess7 = 8 UMETA(DisplayName="Sepia"),
	PostProcess8 = 9 UMETA(Hidden),
	PostProcess9 = 10 UMETA(DisplayName="Retro"),
	PostProcess10 = 11 UMETA(DisplayName="Low Exposure"),
	PostProcess11 = 12 UMETA(DisplayName="Neon Party"),
	PostProcess12 = 13 UMETA(DisplayName="Horror Movie"),
	PostProcess13 = 14 UMETA(DisplayName="Old Cartoon"),
	PostProcess14 = 15 UMETA(DisplayName="Desolate"),
	PostProcess15 = 16 UMETA(DisplayName="Halftone"),
};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_PlayerZoneSettings : public AFortAthenaMutator_PlayerSettingsBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="ZoneSettings")
	TSubclassOf<UFortPlayerZoneSettingsComponent> ZoneSettingsClass;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_PlayerZoneSettings", meta=(AllowPrivateAccess="TRUE"))
	TArray<TSoftClassPtr<AActor>> PostProcessOverrideActors;

	UPROPERTY(Transient)
	FMutatorPlayerSettingsData ZoneSettingsData;

};

UCLASS(BlueprintType, Blueprintable)
class UFortPlayerZoneSettingsComponent : public UFortPlayerSettingsComponentBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Mutator|Post Process")
	EAthenaTimeOfDayOverride TimeOfDayOverride;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Post Process")
	EAthenaTODPostProcessOverride CameraFilter;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Post Process")
	int32 PostProcessOverride;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Post Process")
	EAthenaLightIntensityOverride LightIntensityOverride;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Post Process")
	EAthenaTODColor LightColorOverride;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Post Process")
	EAthenaFogDensityOverride FogDensityOverride;

	UPROPERTY(EditDefaultsOnly, Category="Mutator|Post Process")
	EAthenaTODColor FogColorOverride;

};

