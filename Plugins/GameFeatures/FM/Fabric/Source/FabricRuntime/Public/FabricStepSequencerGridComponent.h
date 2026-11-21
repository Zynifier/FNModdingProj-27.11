// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Math/MathFwd.h"
#include "FabricStepSequencerComponent.h"
#include "FabricStepSequencerGridComponent.generated.h"

class APlayerController;
class UFabricStepSequencerComponent;
class UFabricStepSequencerGridSquareComponent;
enum class EFabricNoteStyle : uint8;

UENUM(BlueprintType)
namespace ESequencerType
{
	enum Type
	{
		// ModularSequencer

		MultiTrack = 0,
		// DrumSequencer

		SingleTrack = 1,
	};
}

USTRUCT(BlueprintType)
struct FTrackRow
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFabricStepSequencerGridSquareComponent>> GridSquares;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent, DisplayName="Fabric Step Sequencer Grid"))
class FABRICRUNTIME_API UFabricStepSequencerGridComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FVector GetGridSquareExtents(const int32 RowIndex, const int32 ColumnIndex) const;

	UFUNCTION(BlueprintPure)
	FVector2D GetGridSquareSize(const int32 NumSteps, const int32 NumRows) const;

	UFUNCTION(BlueprintPure)
	float GetGridSquareXPosition(const int32 NumSteps, const int32 StepIndex);

	UFUNCTION(BlueprintPure)
	float GetGridSquareYPosition(const int32 NumRows, const int32 RowIndex);

	UFUNCTION(BlueprintPure)
	bool IsBypassed();

	UFUNCTION(BlueprintPure)
	bool IsStepToggledOnForAnyTrack(int32 StepIndex) const;

	UFUNCTION(BlueprintCallable)
	void NotifyInteractionFocusTargetExternallyChanged(APlayerController* PlayerController, int32 SourceRowIndex, int32 SourceColumnIndex, int32 FocusRowIndex, int32 FocusColumnIndex, bool bIsFocused);

	UFUNCTION(BlueprintCallable)
	void SetActiveTrackIndex(int32 ActiveTrackIndex);

	UFUNCTION(BlueprintCallable)
	void SetBypassed(bool bBypassed);

	UFUNCTION(BlueprintCallable)
	void SetGridVisible(bool bInGridVisible, bool bForceRefresh = false);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FabricStepSequencerGridComponent")
	FVector2D GridExtents;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FabricStepSequencerGridComponent")
	FVector2D GridSpacing;

	UPROPERTY(EditAnywhere, Category="FabricStepSequencerGridComponent", meta=(ClampMax="16", ClampMin="1"))
	int32 SingleTrackNumItemsPerRow;

	UPROPERTY(EditAnywhere, Category="Editor")
	FVector2D EditorPreviewGridSize;

	UPROPERTY(EditAnywhere, Category="FabricStepSequencerGridComponent", meta=(MustImplement="/Script/FabricRuntime.FabricInteractable"))
	TSubclassOf<UFabricStepSequencerGridSquareComponent> GridSquareClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FabricStepSequencerGridComponent")
	TEnumAsByte<ESequencerType::Type> SequencerType;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FabricStepSequencerGridComponent")
	int32 ActiveTrack;

protected:
	UFUNCTION()
	void OnBeatOffsetChanged(float BeatOffset);

	UFUNCTION()
	void OnBeatScaleChanged(float BeatScale);

	UFUNCTION()
	void OnCurrentPageChanged(int32 NewPage);

	UFUNCTION()
	void OnFullTableChanged();

	UFUNCTION()
	void OnNoteStyleChanged(EFabricNoteStyle Style);

	UFUNCTION()
	void OnNumStepsChanged(int32 NumSteps);

	UFUNCTION()
	void OnNumTracksChanged(int32 NumTracks);

	UFUNCTION()
	void OnQuarterNotesLengthChanged(float QuarterNotesLength);

	UFUNCTION()
	void OnStepChanged(const FFabricSequencerStepChangedInfo& StepInfo);

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFabricStepSequencerComponent> StepSequencer;

	UPROPERTY(Transient)
	TArray<FTrackRow> GridRows;

};

