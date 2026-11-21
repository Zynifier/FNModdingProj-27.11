// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/Color.h"
#include "UI/FortUIBaseClass.h"
#include "FortUIZone.generated.h"

class UFortSpottedActorIndicator;
class UReporterGraph;
class USlateBrushAsset;
class UTexture2D;

UENUM()
enum EFortContextualReticleTypes
{
	// Generic failure case

	FCR_GenericFailure = 0,
	// Building upgrade

	FCR_Upgrade = 1,
	// Building repair

	FCR_Repair = 2,
	// Building locked

	FCR_Locked = 3,
	// Building placement

	FCR_Placement = 4,
	// Building edit case

	FCR_Edit = 5,
	// No target

	FCR_NoTarget = 6,
	// Building is in construction/progress and preventing further operations

	FCR_InProgress = 7,
	FCR_None = 8,
};

UCLASS(MinimalAPI, HideCategories=("Rendering", "Actor", "Input", "Replication"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortUIZone : public AFortUIBaseClass
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="UI")
	FName GetCurrentCursorModeAction();

	UFUNCTION(Exec)
	void ToggleTargetInfo();

	UFUNCTION(Exec)
	void ToggleTargetInfoAI();

	UFUNCTION(Exec)
	void ToggleTargetInfoLock(bool bTraceComplex = true);

	UFUNCTION(Exec)
	void ToggleTargetInfoPaths();

	UFUNCTION(Exec)
	void ToggleTargetInfoSensing();

	UFUNCTION(Exec)
	void ToggleTimeOfDayDebugInfo();

	UPROPERTY()
	FFontRenderInfo TextRenderInfo;

	UPROPERTY()
	TObjectPtr<UReporterGraph> IntensityGraph;

	UPROPERTY()
	TObjectPtr<UReporterGraph> PIDValuesGraph;

	UPROPERTY()
	TObjectPtr<UReporterGraph> PIDContributionsGraph;

	UPROPERTY()
	TObjectPtr<UReporterGraph> UtilitiesGraph;

protected:
	UFUNCTION(BlueprintCallable)
	void CloseFullScreenMap();

	UPROPERTY(Transient)
	TEnumAsByte<EFortContextualReticleTypes> CurrentContextualReticleIconType;

	UPROPERTY(Transient)
	FColor CurrentContextualReticleColor;

	UPROPERTY(Transient, meta=(ArraySizeEnum="/Script/FortniteGame.EFortContextualReticleTypes"))
	TSoftObjectPtr<UTexture2D> ContextualReticleIcons[8];

	UPROPERTY(Transient)
	TSoftObjectPtr<USlateBrushAsset> ActorCanvasArrowBrush;

	UPROPERTY(Transient)
	TSoftObjectPtr<USlateBrushAsset> ActorCanvasElevationBrush;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortSpottedActorIndicator>> SpottedActorIndicators;

};

