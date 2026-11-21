// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "UObject/NoExportTypes.h"
#include "AI/FortAITypes.h"
#include "FortAIDirectorCommonTypes.generated.h"

USTRUCT(BlueprintType)
struct FFortAIDirectorPerLODConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AILOD")
	FScalableFloat MaxNPCCosts;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AILOD")
	EFortAILODLevel FortAILODLevel;

};

USTRUCT(BlueprintType)
struct FPlayerLODViewConeConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlayerLODViewConeConfig")
	FScalableFloat ObserverVisionAngleDeg;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PlayerLODViewConeConfig")
	FScalableFloat ViewConeMaxRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlayerLODViewConeConfig")
	FScalableFloat AlwaysVisibleRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlayerLODViewConeConfig")
	EFortAILODLevel FortAILODLevel;

};

USTRUCT(BlueprintType)
struct FPlayerLODViewConeHysteresisConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlayerLODViewConeConfig")
	FScalableFloat AdditionalObserverVisionAngleDeg;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="PlayerLODViewConeConfig")
	FScalableFloat AdditionalRadius;

};

UCLASS(Abstract, Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class UFortAIDirectorLODAIConfig : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AILOD")
	FScalableFloat SingleAIUnitCost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="AILOD")
	FScalableFloat Priority;

};

