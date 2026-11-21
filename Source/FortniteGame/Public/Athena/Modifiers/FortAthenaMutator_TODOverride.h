// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_TODOverride.generated.h"

class AActor;

UENUM(BlueprintType)
enum class EAthenaFogDensityOverride : uint8
{
	NoOverride = 0 UMETA(DisplayName="Default"),
	Fog0 = 1 UMETA(DisplayName="0%"),
	Fog1 = 2 UMETA(DisplayName="10%"),
	Fog2 = 3 UMETA(DisplayName="20%"),
	Fog3 = 4 UMETA(DisplayName="30%"),
	Fog4 = 5 UMETA(DisplayName="40%"),
	Fog5 = 6 UMETA(DisplayName="50%"),
	Fog6 = 7 UMETA(DisplayName="60%"),
	Fog7 = 8 UMETA(DisplayName="70%"),
	Fog8 = 9 UMETA(DisplayName="80%"),
	Fog9 = 10 UMETA(DisplayName="90%"),
	Fog10 = 11 UMETA(DisplayName="100%"),
};

UENUM(BlueprintType)
enum class EAthenaLightIntensityOverride : uint8
{
	NoOverride = 0 UMETA(DisplayName="Default"),
	Intensity0 = 1 UMETA(DisplayName="0%"),
	Intensity1 = 2 UMETA(DisplayName="10%"),
	Intensity2 = 3 UMETA(DisplayName="20%"),
	Intensity3 = 4 UMETA(DisplayName="30%"),
	Intensity4 = 5 UMETA(DisplayName="40%"),
	Intensity5 = 6 UMETA(DisplayName="50%"),
	Intensity6 = 7 UMETA(DisplayName="60%"),
	Intensity7 = 8 UMETA(DisplayName="70%"),
	Intensity8 = 9 UMETA(DisplayName="80%"),
	Intensity9 = 10 UMETA(DisplayName="90%"),
	Intensity10 = 11 UMETA(DisplayName="100%"),
};

UENUM(BlueprintType)
enum class EAthenaTODColor : uint8
{
	NoOverride = 0 UMETA(DisplayName="Default"),
	Black = 1,
	White = 2,
	Red = 3,
	Green = 4,
	Blue = 5,
	Yellow = 6,
	Magenta = 7,
	Cyan = 8,
};

UENUM(BlueprintType)
enum class EAthenaTimeOfDayOverride : uint8
{
	NoOverride = 0 UMETA(DisplayName="Default"),
	ForceDay = 1,
	ForceNight = 2,
	Custom = 3,
	Hour0 = 4 UMETA(DisplayName="12:00 AM"),
	Hour1 = 5 UMETA(DisplayName="1:00 AM"),
	Hour2 = 6 UMETA(DisplayName="2:00 AM"),
	Hour3 = 7 UMETA(DisplayName="3:00 AM"),
	Hour4 = 8 UMETA(DisplayName="4:00 AM"),
	Hour5 = 9 UMETA(DisplayName="5:00 AM"),
	Hour6 = 10 UMETA(DisplayName="6:00 AM"),
	Hour7 = 11 UMETA(DisplayName="7:00 AM"),
	Hour8 = 12 UMETA(DisplayName="8:00 AM"),
	Hour9 = 13 UMETA(DisplayName="9:00 AM"),
	Hour10 = 14 UMETA(DisplayName="10:00 AM"),
	Hour11 = 15 UMETA(DisplayName="11:00 AM"),
	Hour12 = 16 UMETA(DisplayName="12:00 PM"),
	Hour13 = 17 UMETA(DisplayName="1:00 PM"),
	Hour14 = 18 UMETA(DisplayName="2:00 PM"),
	Hour15 = 19 UMETA(DisplayName="3:00 PM"),
	Hour16 = 20 UMETA(DisplayName="4:00 PM"),
	Hour17 = 21 UMETA(DisplayName="5:00 PM"),
	Hour18 = 22 UMETA(DisplayName="6:00 PM"),
	Hour19 = 23 UMETA(DisplayName="7:00 PM"),
	Hour20 = 24 UMETA(DisplayName="8:00 PM"),
	Hour21 = 25 UMETA(DisplayName="9:00 PM"),
	Hour22 = 26 UMETA(DisplayName="10:00 PM"),
	Hour23 = 27 UMETA(DisplayName="11:00 PM"),
	Random = 28,
};

USTRUCT()
struct FTimeOfDayPhase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Time;

	UPROPERTY()
	FText DisplayName;

};

USTRUCT()
struct FTimeOfDaySpeed
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Speed;

	UPROPERTY()
	FText DisplayName;

};

UCLASS(Config=Game, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_TODOverride : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static float GetFogStartDistance();

	UFUNCTION(BlueprintPure, Category="FortCreativeOptions")
	TArray<FText> GetTimeOfDayPhaseNames() const;

	UFUNCTION(BlueprintPure, Category="FortCreativeOptions")
	TArray<FText> GetTimeOfDaySpeedNames() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TimeOfDay")
	EAthenaTimeOfDayOverride TimeOfDayOverride;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TimeOfDay")
	float TimeOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="TimeOfDay")
	float SpeedOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Lighting")
	EAthenaLightIntensityOverride LightIntensityOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Lighting")
	EAthenaTODColor LightColorOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Lighting")
	EAthenaFogDensityOverride FogDensityOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Lighting")
	EAthenaTODColor FogColorOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Lighting")
	int32 PostProcessOverride;

private:
	UPROPERTY(EditAnywhere, Config, Category="CreativeOptions")
	TArray<FTimeOfDayPhase> TimeOfDayPhases;

	UPROPERTY(EditAnywhere, Config, Category="CreativeOptions")
	TArray<FTimeOfDaySpeed> TimeOfDaySpeeds;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_TODOverride", meta=(AllowPrivateAccess="TRUE"))
	TArray<TSoftClassPtr<AActor>> PostProcessOverrideActors;

};

