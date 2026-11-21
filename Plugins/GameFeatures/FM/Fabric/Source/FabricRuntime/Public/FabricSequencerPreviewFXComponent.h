// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricStepSequencerComponent.h"
#include "FabricSteppedPreviewFXComponent.h"
#include "FabricSequencerPreviewFXComponent.generated.h"

class UFabricStepSequencerComponent;
class UFabricStepSequencerGridComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Activation", "Components|Activation", "Trigger"), meta=(BlueprintSpawnableComponent))
class UFabricSequencerPreviewFXComponent : public UFabricSteppedPreviewFXComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	void InitializePreviewFXComponent(UFabricStepSequencerComponent* InStepSequencer, UFabricStepSequencerGridComponent* InStepSequencerGrid, bool bInTestNotesOn);

protected:
	UFUNCTION()
	void OnFullTableChanged();

	UFUNCTION()
	void OnStepChanged(const FFabricSequencerStepChangedInfo& StepInfo);

private:
	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	void SetSingleTrackNoteOn(int32 InstanceIndex, int32 TrackPICDIndex, float NoteOn, bool bMarkRenderStateDirty = false);

	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	void SetSustainLength(int32 InstanceIndex, float SustainLengthBeats);

	UFUNCTION(BlueprintCallable, Category="FabricSteppedPreviewFX")
	void UpdateNoteOn(int32 Index, int32 NumSteps, bool bMarkRenderStateDirty = false);

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFabricStepSequencerComponent> StepSequencer;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFabricStepSequencerGridComponent> StepSequencerGrid;

};

