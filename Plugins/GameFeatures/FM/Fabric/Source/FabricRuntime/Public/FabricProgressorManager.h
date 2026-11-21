// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "LevelSaveSpawnableInterface.h"
#include "MusicKey.h"
#include "FabricProgressorManager.generated.h"

USTRUCT(BlueprintType)
struct FABRICRUNTIME_API FFabricProgressionPreset : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricProgressionPreset")
	FText ProgressionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricProgressionPreset")
	EHarmonicProgression Interval0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricProgressionPreset")
	EHarmonicProgression Interval1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricProgressionPreset")
	EHarmonicProgression Interval2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricProgressionPreset")
	EHarmonicProgression Interval3;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent, DisplayName="Fabric Progressor Manager"))
class FABRICRUNTIME_API UFabricProgressorManager : public UActorComponent, public ILevelSaveSpawnable
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnProgressionChanged);

public:
	UFUNCTION(BlueprintPure)
	int32 GetGlobalPresetNumber() const;

	UFUNCTION(BlueprintPure)
	const FFabricProgressionPreset& GetGlobalProgression() const;

	UFUNCTION(BlueprintPure)
	bool HasActiveGlobalProgression() const;

	UFUNCTION(BlueprintPure)
	bool IsProgressionGlobal(const FFabricProgressionPreset& InProgression);

	UFUNCTION(BlueprintCallable)
	void SetGlobalProgression(const FFabricProgressionPreset& InProgression, int32 InPresetNumber);

	UPROPERTY(BlueprintAssignable)
	FOnProgressionChanged OnGlobalProgressionChanged;

protected:
	UPROPERTY(Transient)
	bool bHasActiveGlobalProgression;

	UPROPERTY(Transient)
	int32 GlobalPresetNumber;

	UPROPERTY(Transient)
	FFabricProgressionPreset GlobalProgression;

};

